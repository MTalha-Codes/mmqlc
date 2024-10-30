/*
 * Filename: calculator.hpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repo: mmqlc
 * Copyright(C) - 2024
 * */

// This file serve as main third organ of mmqlc.
#ifndef MMQLC_CALCULATOR_HPP
#define MMQLC_CALCULATOR_HPP

#include <utility>
#include<type_traits>
#include <vector>
#include <tuple>
#include <string>
#include <numeric>
#include <stdexcept>
#include "parser.hpp"
#include "multiprecision.hpp"
#include "functions.hpp"
#include "constants.hpp"

using namespace math::functions::imported_from_boost;
using namespace math::functions::real::trig;
using namespace math::functions::complex::trig;

class Calculator {
private:
    std::vector<std::tuple<std::string, double50, double50> > realNums_parsed;
    std::vector<std::tuple<std::string, complex50, complex50> > cmplxNums_parsed;
    std::vector<std::string> answerStrings;
    std::vector<std::string> error_messages;

    static bool isComplex(const std::string &q) {
        if (q.find("CMPLX", 0) != std::string::npos)
            return true;
        return false;
    }

    static double50 degrees_to_radians(const double50 &degs) noexcept {
        double50 rads(degs * Pi);
        rads /= 180;
        return rads;
    }

    static double50 radians_to_degrees(const double50 &rads) noexcept {
        double50 degs(rads * 180);
        degs /= Pi;
        return degs;
    }

    static double50 factorial(const double50 &param) {
        double50 fact(tgamma(param + ONE));
        return fact;
    }

    static double50 nPr(const double50 &n, const double50 &r) {
        double50 numerator(factorial(n));
        double50 denominator(factorial(n - r));
        double50 perm(numerator);
        perm /= denominator;
        return perm;
    }

    static double50 nCr(const double50 &n, const double50 &r) {
        double50 rFact = ONE;
        rFact /= factorial(r);
        double50 comb(rFact * nPr(n, r));
        return comb;
    }

    [[maybe_unused]] static std::string stringConvert(const complex50 &complexArg) {
        std::string realStr = complexArg.real().str();
        std::string imagStr = complexArg.imag().str() + "i";
        if (imagStr[0] != '-')
            imagStr.insert(0, 1, '+');
        std::string complexStr = realStr + imagStr;
        return complexStr;
    }

    static std::string stringConvert(const double50 &darg) {
        return darg.str();
    }

    template<typename T, typename U, typename R>
    std::enable_if_t<(std::is_same_v<T, double50> || std::is_same_v<T, complex50>) &&
                     (std::is_same_v<U, double50> || std::is_same_v<U, complex50>) &&
                     (std::is_same_v<R, double50> || std::is_same_v<R, complex50>), std::string>
    constructAnswer(const std::string &q, const T &f, const U &s, const R &r) {
        return q + " " + stringConvert(f) + "," + stringConvert(s) + " = " + stringConvert(r) + "\n";
    }

    template<typename T, typename R>
    std::enable_if_t<(std::is_same_v<T, double50> || std::is_same_v<T, complex50>) &&
                     (std::is_same_v<R, double50> || std::is_same_v<R, complex50>), std::string>
    constructAnswer(const std::string &q, const T &f, const R &r) {
        return q + " " + stringConvert(f) + " = " + stringConvert(r) + "\n";
    }

    void appendError(const std::string &err) {
        error_messages.emplace_back(err);
    }

    std::string get_string_errors() {
        std::ranges::sort(error_messages);
        auto l = std::ranges::unique(error_messages);
        error_messages.erase(l.begin(), error_messages.end());
        std::string allErrors;
        for (const auto &err: error_messages) {
            allErrors.append("\n");
            allErrors.append(err);
            allErrors.append("\n");
        }
        return allErrors;
    }

public:
    Calculator(std::vector<std::tuple<std::string, double50, double50> > const &parsedReal,
               std::vector<std::tuple<std::string, complex50, std::complex<double50> > > const &parsedComplex) {
        realNums_parsed = parsedReal;
        cmplxNums_parsed = parsedComplex;
    }

    std::vector<std::string> calculateAnswers() {
        for (const auto &parsedToken: realNums_parsed) {
            std::string query = std::get<0>(parsedToken);
            if (isComplex(query)) { break; }
            double50 fOperand = std::get<1>(parsedToken);
            double50 sOperand = std::get<2>(parsedToken);
            auto calculate_real_double = [this](const std::string &query, const double50 &fOperand,
                                                const double50 &sOperand) {
                if (query == "ADD") {
                    double50 result(fOperand + sOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "SUBTRACT") {
                    double50 result(fOperand - sOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "MULTIPLY") {
                    double50 result(fOperand * sOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "DIVIDE") {
                    if (sOperand != 0) {
                        double50 result(fOperand / sOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else {
                        throw std::runtime_error("Cannot divide by zero");
                    }
                } else if (query == "POWER") {
                    double50 result(pow(fOperand, sOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "ROOT") {
                    if (sOperand != 0) {
                        double50 index(1);
                        index /= sOperand;
                        double50 result(pow(fOperand, index));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else {
                        throw std::runtime_error("Zeroth root does not exist");
                    }
                } else if (query == "LOGARITHM") {
                    // using change of base formula
                    double50 n(log10(fOperand));
                    double50 d(log10(sOperand));
                    double50 log_result(n);
                    log_result /= d;
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, log_result));
                    return true;
                } else if (query == "PERMUTATION") {
                    double50 result(nPr(fOperand, sOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "COMBINATION") {
                    double50 result(nCr(fOperand, sOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "MODULUS") {
                    if (sOperand != 0) {
                        double50 result(fmod(fOperand, sOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else {
                        throw std::runtime_error("Cannot divide by zero");
                    }
                } else
                    return false;
            };
            auto calculate_real_single = [this](const std::string &query, const double50 &fOperand) {
                if (query == "FACTORIAL") {
                    double50 result(factorial(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "ABSOLUTE") {
                    double50 result(fabs(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "FLOOR") {
                    double50 result(floor(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "CEILING") {
                    double50 result(ceil(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "SINE") {
                    double50 rads(degrees_to_radians(fOperand));
                    double50 result(sin(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "COSINE") {
                    double50 rads(degrees_to_radians(fOperand));
                    double50 result(cos(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "TANGENT") {
                    if (fOperand == 90) {
                        answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                        return true;
                    } else {
                        double50 rads(degrees_to_radians(fOperand));
                        double50 result(tan(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    }
                } else if (query == "COTANGENT") {
                    if (fOperand == 90) {
                        answerStrings.emplace_back(constructAnswer(query, fOperand, ZERO));
                        return true;
                    } else if (fOperand == 0) {
                        answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                        return true;
                    } else {
                        double50 rads(degrees_to_radians(fOperand));
                        double50 result(cot(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    }
                } else if (query == "COSECANT") {
                    if (fOperand == 0) {
                        answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                        return true;
                    } else {
                        double50 rads(degrees_to_radians(fOperand));
                        double50 result(csc(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    }
                } else if (query == "SECANT") {
                    if (fOperand == 90) {
                        answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                        return true;
                    } else {
                        double50 rads(degrees_to_radians(fOperand));
                        double50 result(sec(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    }
                } else if (query == "INVERSE_SINE") {
                    double50 rads(asin(fOperand));
                    double50 result(radians_to_degrees(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_COSINE") {
                    double50 rads(acos(fOperand));
                    double50 result(radians_to_degrees(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_TANGENT") {
                    double50 rads(atan(fOperand));
                    double50 result(radians_to_degrees(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_COTANGENT") {
                    double50 rads(acot(fOperand));
                    double50 result(radians_to_degrees(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_COSECANT") {
                    double50 rads(acsc(fOperand));
                    double50 result(radians_to_degrees(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_SECANT") {
                    double50 rads(asec(fOperand));
                    double50 result(radians_to_degrees(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "HYP_SINE") {
                    double50 result(sinh(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "HYP_COSINE") {
                    double50 result(cosh(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "HYP_TANGENT") {
                    double50 result(tanh(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "HYP_COTANGENT") {
                    double50 result_val(coth(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                    return true;
                } else if (query == "HYP_COSECANT") {
                    double50 result_val(csch(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                    return true;
                } else if (query == "HYP_SECANT") {
                    double50 result_val(sech(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                    return true;
                } else if (query == "INVERSE_HYP_TANGENT") {
                    double50 result(atanh(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_HYP_SINE") {
                    double50 result(asinh(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_HYP_COSINE") {
                    double50 result(acosh(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                    return true;
                } else if (query == "INVERSE_HYP_COTANGENT") {
                    double50 result_val(acoth(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                    return true;
                } else if (query == "INVERSE_HYP_COSECANT") {
                    double50 result_val(acsch(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                    return true;
                } else if (query == "INVERSE_HYP_SECANT") {
                    double50 result_val(asech(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                    return true;
                } else if (query == "NATURAL_LOGARITHM") {
                    double50 res(log(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, res));
                    return true;
                } else if (query == "BINARY_LOGARITHM") {
                    double50 res(log2(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, res));
                    return true;
                } else if (query == "COMMON_LOGARITHM") {
                    double50 res(log10(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, res));
                    return true;
                } else {
                    return false;
                }
            };
            if (calculate_real_single(query, fOperand) ||
                calculate_real_double(query, fOperand, sOperand))
                continue;
            else {
                std::string current_error = "Syntax Fault: MmQLC failed to process " + query;
                appendError(current_error);
            }
        }
        for (const auto &parsedToken: cmplxNums_parsed) {
            std::string query = std::get<0>(parsedToken);
            auto fOperand = std::get<1>(parsedToken);
            auto sOperand = std::get<2>(parsedToken);
            auto calculate_complex_double = [this](const std::string &query, const complex50 &fOperand,
                                                   const complex50 &sOperand) {
                if (query == "CMPLX_ADD") {
                    auto result = fOperand + sOperand;
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "CMPLX_SUBTRACT") {
                    auto result = fOperand - sOperand;
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "CMPLX_MULTIPLY") {
                    auto result = fOperand * sOperand;
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "CMPLX_DIVIDE") {
                    if (sOperand == zero) {
                        throw std::runtime_error("Cannot divide complex number by zero !");
                    }
                    auto result = fOperand / sOperand;
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "CMPLX_POWER") {
                    auto result = std::pow(fOperand, sOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else if (query == "CMPLX_ROOT") {
                    if (sOperand == zero) {
                        throw std::runtime_error("Zeroth root of complex number is undefined !");
                    }
                    auto ind = one / sOperand;
                    auto result = std::pow(fOperand, ind);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                    return true;
                } else {
                    return false;
                }
            };
            auto calculate_complex_single = [this](const std::string &query, const complex50 &fOperand) {
                if (query == "CMPLX_MODULUS") {
                    double50 MOD(std::abs(fOperand));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, MOD));
                    return true;
                } else if (query == "CMPLX_ARGUMENT") {
                    double50 rads(std::arg(fOperand));
                    double50 degs(radians_to_degrees(rads));
                    answerStrings.emplace_back(constructAnswer(query, fOperand, degs));
                    return true;
                } else if (query == "CMPLX_SINE") {
                    auto sine = std::sin(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, sine));
                    return true;
                } else if (query == "CMPLX_COSINE") {
                    auto cosine = std::cos(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, cosine));
                    return true;
                } else if (query == "CMPLX_TANGENT") {
                    auto tang = std::tan(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, tang));
                    return true;
                } else if (query == "CMPLX_COTANGENT") {
                    auto cotangent = cot(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, cotangent));
                    return true;
                } else if (query == "CMPLX_SECANT") {
                    auto secant = sec(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, secant));
                    return true;
                } else if (query == "CMPLX_COSECANT") {
                    auto cosecant = csc(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, cosecant));
                    return true;
                } else if (query == "CMPLX_INVERSE_SINE") {
                    auto inverseSine = std::asin(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseSine));
                    return true;
                } else if (query == "CMPLX_INVERSE_COSINE") {
                    auto inverseCosine = std::acos(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseCosine));
                    return true;
                } else if (query == "CMPLX_INVERSE_TANGENT") {
                    auto inverseTangent = std::atan(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseTangent));
                    return true;
                } else if (query == "CMPLX_INVERSE_COTANGENT") {
                    auto inverseCot = acot(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseCot));
                    return true;
                } else if (query == "CMPLX_INVERSE_SECANT") {
                    auto inverseSec = asec(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseSec));
                    return true;
                } else if (query == "CMPLX_INVERSE_COSECANT") {
                    auto inverseCsc = acsc(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseCsc));
                    return true;
                } else if (query == "CMPLX_HYP_SINE") {
                    auto hyperSine = std::sinh(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, hyperSine));
                    return true;
                } else if (query == "CMPLX_HYP_COSINE") {
                    auto hyperCosine = std::cosh(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, hyperCosine));
                    return true;
                } else if (query == "CMPLX_HYP_TANGENT") {
                    auto hyperTangent = std::tanh(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, hyperTangent));
                    return true;
                } else if (query == "CMPLX_HYP_COTANGENT") {
                    auto Cothan = coth(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, Cothan));
                    return true;
                } else if (query == "CMPLX_HYP_SECANT") {
                    auto Shek = sech(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, Shek));
                    return true;
                } else if (query == "CMPLX_HYP_COSECANT") {
                    auto CoShek = csch(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, CoShek));
                    return true;
                } else if (query == "CMPLX_INVERSE_HYP_SINE") {
                    auto inverseHypSine = std::asinh(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseHypSine));
                    return true;
                } else if (query == "CMPLX_INVERSE_HYP_COSINE") {
                    auto inverseHypCosine = std::acosh(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseHypCosine));
                    return true;
                } else if (query == "CMPLX_INVERSE_HYP_TANGENT") {
                    auto inverseHypTangent = std::atanh(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, inverseHypTangent));
                    return true;
                } else if (query == "CMPLX_INVERSE_HYP_COTANGENT") {
                    auto InvCOTH = acoth(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, InvCOTH));
                    return true;
                } else if (query == "CMPLX_INVERSE_HYP_SECANT") {
                    auto InvSheck = asech(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, InvSheck));
                    return true;
                } else if (query == "CMPLX_INVERSE_HYP_COSECANT") {
                    auto INV_CSCH = acsch(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, INV_CSCH));
                    return true;
                } else if (query == "CMPLX_NATURAL_LOGARITHM") {
                    if (fOperand == zero) {
                        throw std::runtime_error("Cannot take log of zero !");
                    }
                    auto ln = std::log(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, ln));
                    return true;
                } else if (query == "CMPLX_EXP") {
                    auto expo = std::exp(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, expo));
                    return true;
                } else if (query == "CMPLX_CONJUGATE") {
                    auto conjg = std::conj(fOperand);
                    answerStrings.emplace_back(constructAnswer(query, fOperand, conjg));
                    return true;
                } else {
                    return false;
                }
            };
            if (calculate_complex_single(query, fOperand) ||
                calculate_complex_double(query, fOperand, sOperand)) { continue; } else {
                std::string current_error = "Syntax Fault: MmQLC failed to process " + query;
                appendError(current_error);
            }
        }
        if (!error_messages.empty())
            throw std::runtime_error(get_string_errors());
        return answerStrings;
    }
};

#endif
