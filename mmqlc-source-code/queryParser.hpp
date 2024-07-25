#ifndef MMQLC_QUERYPARSER_HPP
#define MMQLC_QUERYPARSER_HPP

#include <sstream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>

std::vector<std::tuple<std::string, double , double >> parseQueries(std::vector<std::string> &queries) {
    std::string keyWord;
    double firstOperand;
    double secondOperand;
    std::istringstream interpreter;

    std::unordered_set<std::string> singleOperandKeywords = {
            "FACTORIAL", "SINE", "COSINE", "TANGENT", "HYP_SINE", "HYP_COSINE",
            "HYP_TANGENT", "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
            "FLOOR", "CEILING" , "ABSOLUTE"
    };

    std::unordered_set<std::string> allKeywords = {
            "ADD", "SUBTRACT", "MULTIPLY", "DIVIDE", "POWER", "ROOT", "FACTORIAL",
            "PERMUTATION", "COMBINATION", "SINE", "COSINE", "TANGENT", "INVERSE_SINE",
            "INVERSE_COSINE", "INVERSE_TANGENT", "HYP_SINE", "HYP_COSINE", "HYP_TANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT", "LOGARITHM",
            "GCD", "LCM", "FLOOR", "CEILING" , "MODULUS" , "ABSOLUTE"
    };

    std::vector<std::tuple<std::string,double, double>> parsedQueries;

    for (const auto &query: queries) {
        interpreter.clear();
        interpreter.str(query);

        interpreter >> keyWord;
        interpreter.ignore();
        if (singleOperandKeywords.find(keyWord) != singleOperandKeywords.end()) {
            if (!(interpreter >> firstOperand)) {
                parsedQueries.emplace_back("ERROR", -1, -1);
            } else {
                parsedQueries.emplace_back(keyWord, firstOperand, 0);
            }
        } else {
            char comma;
            if (!(interpreter >> firstOperand >> comma >> secondOperand) || comma != ',') {
                parsedQueries.emplace_back("ERROR", -1, -1);
            } else {
                parsedQueries.emplace_back(keyWord, firstOperand, secondOperand);
            }
        }
    }

    return parsedQueries;
}

#endif // MMQLC_QUERYPARSER_HPP
