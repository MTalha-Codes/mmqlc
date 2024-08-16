#ifndef MMQLC_QUERYPARSER_HPP
#define MMQLC_QUERYPARSER_HPP

#include <regex>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>


/*
 * IDENTIFIERS
 *  R_ ======> REAL NUMBERS
 *  C_ ======> COMPLEX NUMBERS
 *  VCT_ ====> VECTORS
 *  MAT_ ====> MATRICES
 * */
std::vector<std::tuple<std::string, std::string,std::string>> parseQueries(std::vector<std::string> &queries) {
    std::unordered_set<std::string> R_singleOP_keywords = {
            "FACTORIAL", "SINE", "COSINE", "TANGENT", "HYP_SINE", "HYP_COSINE",
            "HYP_TANGENT", "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
            "FLOOR", "CEILING", "ABSOLUTE"
    };


    std::vector<std::tuple<std::string, std::string, std::string>> parsedQueries;
    std::regex R_singleOP_ptrn(R"(^(\w+)\s+(-?\d+(\.\d+)?))");
    std::regex R_doubleOP_ptrn(R"(^(\w+)\s+(-?\d+(\.\d+)?),\s*(-?\d+(\.\d+)?))");

    for (const auto &query : queries) {
        std::smatch matches;
        std::string keyWord;
        std::string firstOperand;
        std::string secondOperand;

        if (std::regex_match(query, matches, R_singleOP_ptrn) && matches.size() >= 3) {
            keyWord = matches[1].str();
            if (R_singleOP_keywords.find(keyWord) != R_singleOP_keywords.end()) {
                firstOperand = (matches[2]);
                parsedQueries.emplace_back(keyWord, firstOperand,"");
            } else {
                parsedQueries.emplace_back("ERROR", "", "");
            }
        } else if (std::regex_match(query, matches, R_doubleOP_ptrn) && matches.size() >= 5) {
            keyWord = matches[1].str();
            firstOperand = (matches[2]);
            secondOperand = (matches[4]);
            parsedQueries.emplace_back(keyWord, firstOperand, secondOperand);
        }
        else {
            parsedQueries.emplace_back("ERROR", "", "");
        }
    }
    // WORK IN PROGRESS
    return parsedQueries;
}

#endif // MMQLC_QUERYPARSER_HPP
