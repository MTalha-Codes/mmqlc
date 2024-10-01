#ifndef MMQL_PACKAGE_QUERYPARSER_HPP
#define MMQL_PACKAGE_QUERYPARSER_HPP

#include "queryTokenizer.hpp"
#include<complex>
#include<sstream>
#include <utility>

class parser {
private:
    std::vector<std::tuple<std::string, std::string, std::string>> raw_tokens;
    std::vector<std::tuple<std::string, double, double>> realNum_parsed;
    std::vector<std::tuple<std::string, std::complex<double>, std::complex<double>>> complexNums_parsed;

    static double STOD(const std::string &num) {
        std::regex realNumberRegex(R"(^(-?\d+(\.\d+)?))");
        std::smatch matches;
        if (std::regex_match(num, matches, realNumberRegex))
            return std::stod(matches[0].str());
        else if (num.empty())
            return 0;
        else
            throw std::invalid_argument("No Number ??");
    }

    static std::complex<double> convert_to_complex(const std::string &cmplx_num) {
        std::regex complexNumberRegex(R"((^(-?\d+(\.\d+)?)([+]?(-?\d+(\.\d+)?)i)$))");
        std::smatch matches;
        if (std::regex_match(cmplx_num, matches, complexNumberRegex)) {

            double realPart = std::stod(matches[1].str());
            double imagPart = std::stod(matches[4].str());
            std::complex<double> complex1(realPart, imagPart);
            return complex1;
        } else if (cmplx_num.empty()) {
            return {0, 0};
        } else
            throw std::invalid_argument("No Complex Number ??");
    }

public:
    explicit parser(std::vector<std::string> &queries) {
        raw_tokens = tokenize(queries);
    }

    std::vector<std::tuple<std::string, double, double>> parse_RealNums() {
        for (const auto &raw_token: raw_tokens) {
            double fOperand = 0;
            double sOperand = 0;
            const double zero = 0;
            std::string queryToken = std::get<0>(raw_token);
            try {
                fOperand = STOD(std::get<1>(raw_token));
                sOperand = STOD(std::get<2>(raw_token));
            }
            catch (const std::invalid_argument &iva) {
                continue;
            }
            if (queryToken == "ERROR") {
                realNum_parsed.emplace_back(queryToken, zero, zero);
            }
            if (std::get<2>(raw_token).empty()) {
                realNum_parsed.emplace_back(queryToken, fOperand, zero);
            } else {
                realNum_parsed.emplace_back(queryToken, fOperand, sOperand);
            }
        }
        return realNum_parsed;
    }

    std::vector<std::tuple<std::string, std::complex<double>, std::complex<double>>> parse_cmplxNums() {
        for (const auto &raw_token: raw_tokens) {
            std::complex<double> fOperand, sOperand, zero(0, 0);
            std::string queryToken = std::get<0>(raw_token);
            try {
                fOperand = convert_to_complex(std::get<1>(raw_token));
                sOperand = convert_to_complex(std::get<2>(raw_token));
            }
            catch (const std::invalid_argument &i) {
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