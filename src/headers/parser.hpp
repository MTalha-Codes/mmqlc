#ifndef MMQL_PACKAGE_QUERYPARSER_HPP
#define MMQL_PACKAGE_QUERYPARSER_HPP

#include "tokenizer.hpp"
#include "constants.hpp"
#include "multiprecision.hpp"
#include<complex>
#include <utility>

class parser {
    std::vector<std::tuple<std::string, std::string, std::string> > raw_tokens;
    std::vector<std::tuple<std::string, double50, double50> > realNum_parsed;
    std::vector<std::tuple<std::string, complex50, complex50> > complexNums_parsed;

    static double50 STOD(const std::string &num) {
        const std::regex realNumberRegex(R"((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
        if (std::smatch matches; std::regex_match(num, matches, realNumberRegex))
            return double50(matches[1].str());
        else if (num.empty())
            return {0};
        else
            throw std::invalid_argument("No Number ??");
    }

    static complex50 convert_to_complex(const std::string &cmplx_num) {
        const std::regex complexNumberRegex(
            R"(((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
        if (std::smatch matches; std::regex_match(cmplx_num, matches, complexNumberRegex)) {
            const double50 realPart(matches[2].str());
            const double50 imagPart(matches[7].str());
            complex50 complex1(realPart, imagPart);
            return complex1;
        } else if (cmplx_num.empty()) {
            return {double50(0), double50(0)};
        } else
            throw std::invalid_argument("No Complex Number ??");
    }

public:
    explicit parser(const std::vector<std::string> &queries) {
        raw_tokens = tokenize(queries);
    }

    explicit parser(const std::vector<std::tuple<std::string, std::string, std::string> > &token) {
        raw_tokens = token;
    }

    std::vector<std::tuple<std::string, double50, double50> > parse_RealNums() {
        for (const auto &raw_token: raw_tokens) {
            [[maybe_unused]]
                    double50 fOperand(0);
            [[maybe_unused]]
                    double50 sOperand(0);
            std::string queryToken = std::get<0>(raw_token);
            try {
                fOperand = STOD(std::get<1>(raw_token));
                sOperand = STOD(std::get<2>(raw_token));
            } catch (...) {
                continue;
            }
            if (queryToken == "ERROR") {
                realNum_parsed.emplace_back(queryToken, ZERO, ZERO);
            }
            if (std::get<2>(raw_token).empty()) {
                realNum_parsed.emplace_back(queryToken, fOperand, ZERO);
            } else {
                realNum_parsed.emplace_back(queryToken, fOperand, sOperand);
            }
        }
        return realNum_parsed;
    }

    std::vector<std::tuple<std::string, complex50, complex50> > parse_cmplxNums() {
        for (const auto &raw_token: raw_tokens) {
            complex50 fOperand(double50(0), double50(0));
            complex50 sOperand(double50(0), double50(0));
            std::string queryToken = std::get<0>(raw_token);
            try {
                fOperand = convert_to_complex(std::get<1>(raw_token));
                sOperand = convert_to_complex(std::get<2>(raw_token));
            } catch (...) {
                continue;
            }
            if (queryToken == "ERROR") {
                complexNums_parsed.emplace_back(queryToken, zero, zero);
            }
            if (std::get<2>(raw_token).empty()) {
                complexNums_parsed.emplace_back(queryToken, fOperand, zero);
            } else {
                complexNums_parsed.emplace_back(queryToken, fOperand, sOperand);
            }
        }
        return complexNums_parsed;
    }
};

#endif
