#ifndef MMQLC_QUERYPARSER_HPP
#define MMQLC_QUERYPARSER_HPP

#include <regex>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>

std::vector<std::tuple<std::string, double, double>> parseQueries(std::vector<std::string> &queries) {
    std::unordered_set<std::string> singleOperandKeywords = {
            "FACTORIAL", "SINE", "COSINE", "TANGENT", "HYP_SINE", "HYP_COSINE",
            "HYP_TANGENT", "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
            "FLOOR", "CEILING", "ABSOLUTE"
    };

    std::vector<std::tuple<std::string, double, double>> parsedQueries;
    std::regex singleOperandPattern(R"(^(\w+)\s+(-?\d+(\.\d+)?))");
    std::regex doubleOperandPattern(R"(^(\w+)\s+(-?\d+(\.\d+)?),\s*(-?\d+(\.\d+)?))");

    for (const auto &query : queries) {
        std::smatch matches;
        std::string keyWord;
        double firstOperand, secondOperand;

        if (std::regex_match(query, matches, singleOperandPattern) && matches.size() >= 3) {
            keyWord = matches[1];
            if (singleOperandKeywords.find(keyWord) != singleOperandKeywords.end()) {
                firstOperand = std::stod(matches[2]);
                parsedQueries.emplace_back(keyWord, firstOperand, 0);
            } else {
                parsedQueries.emplace_back("ERROR", -1, -1);
            }
        } else if (std::regex_match(query, matches, doubleOperandPattern) && matches.size() >= 5) {
            keyWord = matches[1];
            firstOperand = std::stod(matches[2]);
            secondOperand = std::stod(matches[4]);
            parsedQueries.emplace_back(keyWord, firstOperand, secondOperand);
        } else {
            parsedQueries.emplace_back("ERROR", -1, -1);
        }
    }

    return parsedQueries;
}

#endif // MMQLC_QUERYPARSER_HPP
