#ifndef MMQLC_QUERYPARSER_HPP
#define MMQLC_QUERYPARSER_HPP

#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>
#include "mmqlc.regex.hpp"


inline std::vector<std::tuple<std::string, std::string, std::string> >
tokenize(const std::vector<std::string> &queries) {
    std::vector<std::tuple<std::string, std::string, std::string> > tokens;
    auto processReal = [&tokens](const std::string &query) {
        const std::unordered_set<std::string> SingleOperand_Queries = {
            "FACTORIAL",
            "SINE", "COSINE", "TANGENT",
            "SECANT", "COSECANT", "COTANGENT",
            "HYP_SINE", "HYP_COSINE", "HYP_TANGENT",
            "HYP_SECANT", "HYP_COTANGENT", "HYP_COSECANT",
            "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
            "INVERSE_SECANT", "INVERSE_COSECANT", "INVERSE_COTANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
            "INVERSE_HYP_SECANT", "INVERSE_HYP_COTANGENT", "INVERSE_HYP_COSECANT",
            "FLOOR", "CEILING", "ABSOLUTE", "NATURAL_LOGARITHM", "BINARY_LOGARITHM", "COMMON_LOGARITHM"
        };
        if (std::smatch matches; std::regex_match(query, matches, regex::real::singlePattern_noVariable)) {
                if (const std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                    std::string firstOperand = matches[2].str();
                    tokens.emplace_back(keyWord, firstOperand, "");
                    return true;
                }
        } else if (std::regex_match(query, matches, regex::real::doublePattern_noVariable)) {
            const std::string keyWord = matches[1].str(); if(SingleOperand_Queries.contains(keyWord)) return false;
            const std::string firstOperand = matches[2].str();
            const std::string secondOperand = matches[6].str();
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        }
        return false;
    };
    auto processComplex = [&tokens](const std::string &query) {
        const std::unordered_set<std::string> SingleOperand_Queries = {
            "MODULUS", "CONJUGATE", "ARGUMENT",
            "SINE", "COSINE", "TANGENT",
            "COSECANT", "SECANT", "COTANGENT",
            "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
            "INVERSE_SECANT", "INVERSE_COSECANT", "INVERSE_COTANGENT",
            "HYP_SINE", "HYP_COSINE", "HYP_TANGENT",
            "HYP_SECANT", "HYP_COSECANT", "HYP_COTANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
            "INVERSE_HYP_COSECANT", "INVERSE_HYP_SECANT", "INVERSE_HYP_COTANGENT",
            "NATURAL_LOGARITHM", "POWER_E"
        };
        if (std::smatch matches; std::regex_match(query, matches, regex::complex::singlePattern_noVariable)) {
            if (const std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                const std::string firstOperand = matches[2].str();
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, regex::complex::doublePattern_noVariable)) {
            const std::string keyWord = matches[1].str(); if(SingleOperand_Queries.contains(keyWord)) return false;
            const std::string firstOperand = matches[2].str();
            const std::string secondOperand = matches[12].str();
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        }
        return false;
    };
    for (const auto &query: queries) {
        if (processReal(query) || processComplex(query))
            continue; // if correct  then goto new query and pass it to tokens
        else {
            tokens.emplace_back(query, "", "");
        }
    }
    return tokens;
}
#endif // MMQLC_QUERYPARSER_HPP
