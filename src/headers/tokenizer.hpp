#ifndef MMQLC_QUERYPARSER_HPP
#define MMQLC_QUERYPARSER_HPP

#include <regex>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>

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
        const std::regex singlePattern_noVariable(R"((\w+)\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
        const std::regex doublePattern_noVariable(
            R"((\w+)\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?),(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
        if (std::smatch matches; std::regex_match(query, matches, singlePattern_noVariable)) {
            if (std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                std::string firstOperand = matches[2].str();
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, doublePattern_noVariable)) {
            std::string keyWord = matches[1].str();
            std::string firstOperand = matches[2].str();
            std::string secondOperand = matches[6].str();
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        }
        return false;
    };
    auto processComplex = [&tokens](const std::string &query) {
        const std::unordered_set<std::string> SingleOperand_Queries = {
            "CMPLX_MODULUS", "CMPLX_CONJUGATE", "CMPLX_ARGUMENT",
            "CMPLX_SINE", "CMPLX_COSINE", "CMPLX_TANGENT",
            "CMPLX_COSECANT", "CMPLX_SECANT", "CMPLX_COTANGENT",
            "CMPLX_INVERSE_SINE", "CMPLX_INVERSE_COSINE", "CMPLX_INVERSE_TANGENT",
            "CMPLX_INVERSE_SECANT", "CMPLX_INVERSE_COSECANT", "CMPLX_INVERSE_COTANGENT",
            "CMPLX_HYP_SINE", "CMPLX_HYP_COSINE", "CMPLX_HYP_TANGENT",
            "CMPLX_HYP_SECANT", "CMPLX_HYP_COSECANT", "CMPLX_HYP_COTANGENT",
            "CMPLX_INVERSE_HYP_SINE", "CMPLX_INVERSE_HYP_COSINE", "CMPLX_INVERSE_HYP_TANGENT",
            "CMPLX_INVERSE_HYP_COSECANT", "CMPLX_INVERSE_HYP_SECANT", "CMPLX_INVERSE_HYP_COTANGENT",
            "CMPLX_NATURAL_LOGARITHM", "CMPLX_EXP"
        };
        const std::regex singlePattern_noVariable(
            R"((\w+)\s((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
        const std::regex doublePattern_noVariable(
            R"((\w+)\s((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)),((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
        if (std::smatch matches; std::regex_match(query, matches, singlePattern_noVariable)) {
            if (std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                std::string firstOperand = matches[2].str();
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, doublePattern_noVariable)) {
            std::string keyWord = matches[1].str();
            std::string firstOperand = matches[2].str();
            std::string secondOperand = matches[12].str();
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
