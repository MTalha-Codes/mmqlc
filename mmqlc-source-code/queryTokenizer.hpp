#ifndef MMQLC_QUERYPARSER_HPP
#define MMQLC_QUERYPARSER_HPP

#include <regex>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>


std::vector<std::tuple<std::string, std::string, std::string>> tokenize(std::vector<std::string> &queries) {
    std::vector<std::tuple<std::string, std::string, std::string>> tokens;
    auto processReal = [&tokens](const std::string &query) {
        std::smatch matches;
        std::string keyWord;
        std::string firstOperand;
        std::string secondOperand;
        std::unordered_set<std::string> real_singleOP_keywords = {
                "FACTORIAL", "SINE", "COSINE", "TANGENT", "HYP_SINE", "HYP_COSINE",
                "HYP_TANGENT", "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
                "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
                "FLOOR", "CEILING", "ABSOLUTE"
        };
        std::regex real_singleOP_ptrn(R"((\w+)\s(-?\d+(\.\d+)?))");
        std::regex real_doubleOP_ptrn(R"((\w+)\s(-?\d+(\.\d+)?),(-?\d+(\.\d+)?))");
        if (std::regex_match(query, matches, real_singleOP_ptrn) && matches.size() >= 3) {
            keyWord = matches[1].str();
            if (real_singleOP_keywords.find(keyWord) != real_singleOP_keywords.end()) {
                firstOperand = matches[2].str();
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, real_doubleOP_ptrn) &&
                   matches.size() >= 5) {
            keyWord = matches[1].str();
            firstOperand = matches[2].str();
            secondOperand = matches[4].str();
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        }
        return false;
    };
    auto processComplex = [&tokens](const std::string &query) {
        std::smatch matches;
        std::string keyWord;
        std::string firstOperand;
        std::string secondOperand;
        std::unordered_set<std::string> cmplx_singleOP_keywords = {
                "CMPLX_MODULUS", "CMPLX_CONJUGATE", "CMPLX_ARGUMENT",
                "CMPLX_SINE", "CMPLX_COSINE", "CMPLX_TANGENT", "CMPLX_INVERSE_SINE",
                "CMPLX_INVERSE_COSINE", "CMPLX_INVERSE_TANGENT", "CMPLX_HYP_SINE",
                "CMPLX_HYP_COSINE", "CMPLX_HYP_TANGENT", "CMPLX_INVERSE_HYP_SINE",
                "CMPLX_INVERSE_HYP_COSINE", "CMPLX_INVERSE_HYP_TANGENT", "CMPLX_LN", "CMPLX_EXP"
        };
        std::regex cmplx_singleOP_ptrn(R"((\w+)\s(-?\d+(\.\d+)?[+-]-?\d+(\.\d+)?i))");
        std::regex cmplx_doubleOP_ptrn(R"((\w+)\s(-?\d+(\.\d+)?[+-]-?\d+(\.\d+)?i),(-?\d+(\.\d+)?[+-]-?\d+(\.\d+)?i))");
        if (std::regex_match(query, matches, cmplx_singleOP_ptrn) && matches.size() >= 3) {
            keyWord = matches[1].str();
            if (cmplx_singleOP_keywords.find(keyWord) != cmplx_singleOP_keywords.end()) {
                firstOperand = matches[2].str();
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, cmplx_doubleOP_ptrn) && matches.size() >= 5) {
            keyWord = matches[1].str();
            firstOperand = matches[2].str();
            secondOperand = matches[5].str();
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        }
        return false;
    };
    for (const auto &query: queries) {
        bool realCall = processReal(query);
        bool complexCall = processComplex(query);
        bool noError = realCall || complexCall;
        if (noError)
            continue; // if correct  then goto new query and pass it to tokens
        else {
            tokens.emplace_back("ERROR", "", "");
        }
    }
    return tokens;
}

#endif // MMQLC_QUERYPARSER_HPP
