#ifndef MMQLC_CALCANSWER_HPP
#define MMQLC_CALCANSWER_HPP

#include <utility>
#include <vector>
#include <memory>
#include <tuple>
#include <utility>
#include <string>
#include <numeric>
#include <stdexcept>
#include <cmath>
#include "queryParser.hpp"

class answer_calc {
private:
    std::vector<std::tuple<std::string, double, double>> realNums_parsed;
    std::vector<std::tuple<std::string, std::complex<double>, std::complex<double>>> cmplxNums_parsed;
    std::vector<std::string> answerStrings;

    static double degrees_to_radians(const double &degs) noexcept {
        const double pi = 3.14159265359;
        double rads = degs * pi;
        rads /= 180;
        return rads;
    }

    static double radians_to_degrees(const double &rads) noexcept {
        const double pi = 3.14159265359;
        double degs = rads * 180;
        degs /= pi;
        return degs;
    }

    static long double factorial(const double &param) {
        long double fact = tgammal(param + 1);
        return fact;
    }

    static long double nPr(const double &n, const double &r) {
        long double numerator = factorial(n);
        long double denominator = factorial(n - r);
        long double perm = numerator;
        perm /= denominator;
        return perm;
    }

    static long double nCr(const double &n, const double &r) {
        long double rFact = 1;
        rFact /= factorial(r);
        long double comb = rFact * nPr(n, r);
        return comb;
    }

    static double HCF(const double &a, const double &b) {
        int A = static_cast<int>(a);
        int B = static_cast<int>(b);
        int HCF = std::gcd(A, B);
        return HCF;
    }

    static double LCM(const double &a, const double &b) {
        int A = static_cast<int>(a);
        int B = static_cast<int>(b);
        int LCM = std::lcm(A, B);
        return LCM;
    }

    static std::string stringConvert(const std::complex<double> &complexArg) {
        double realP = complexArg.real();
        double imagP = complexArg.imag();

        std::ostringstream oss;
        oss << std::fixed << std::setprecision(6);
        oss << realP;

        if (imagP != 0) {
            std::string sign = imagP < 0 ? "" : "+";
            oss << sign << imagP << "i";
        } else {
            oss << "+0.000000i";
        }

        return oss.str();
    }

    static std::string stringConvert(const double &darg) {
        return std::to_string(darg);
    }

    static std::string stringConvert(const long double &ldarg) {
        return std::to_string(ldarg);
    }

public:
    answer_calc(std::vector<std::tuple<std::string, double, double>> const &parsedReal,
                std::vector<std::tuple<std::string, std::complex<double>, std::complex<double>>> const &parsedComplex) {
        realNums_parsed = parsedReal;
        cmplxNums_parsed = parsedComplex;
    }

    std::vector<std::string> calculateAnswers() {
        for (const auto &parsedToken: realNums_parsed) {
            std::string query = std::get<0>(parsedToken);
            double fOperand = std::get<1>(parsedToken);
            double sOperand = std::get<2>(parsedToken);
            auto process_real_double = [this](const std::string &query, const double &fOperand,
                                              const double &sOperand) {
                if (query == "ADD") {
                    double result = fOperand + sOperand;
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "SUBTRACT") {
                    double result = fOperand - sOperand;
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "MULTIPLY") {
                    double result = fOperand * sOperand;
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "DIVIDE") {
                    if (sOperand != 0) {
                        double result = fOperand / sOperand;
                        answerStrings.emplace_back(stringConvert(result));
                        return true;
                    } else {
                        throw std::runtime_error("Cannot divide by zero");
                    }
                } else if (query == "POWER") {
                    double result = pow(fOperand, sOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "ROOT") {
                    if (sOperand != 0) {
                        double index = 1;
                        index /= sOperand;
                        double result = pow(fOperand, index);
                        answerStrings.emplace_back(stringConvert(result));
                        return true;
                    } else {
                        throw std::runtime_error("Zeroth root does not exist");
                    }
                } else if (query == "LCM") {
                    double result = LCM(fOperand, sOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "LOGARITHM") {
                    // using change of base formula
                    double n = log10(fOperand);
                    double d = log10(sOperand);
                    double log_result = n;
                    log_result /= d;
                    answerStrings.emplace_back(stringConvert(log_result));
                    return true;
                } else if (query == "PERMUTATION") {
                    long double result = nPr(fOperand, sOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "COMBINATION") {
                    long double result = nCr(fOperand, sOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "MODULUS") {
                    if (sOperand != 0) {
                        double result = fmod(fOperand, sOperand);
                        answerStrings.emplace_back(stringConvert(result));
                        return true;
                    } else {
                        throw std::runtime_error("Cannot divide by zero");
                    }
                } else if (query == "GCD") {
                    double result = HCF(fOperand, sOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else {
                    return false;
                }
            };
            auto process_real_single = [this](const std::string &query, const double &fOperand) {
                if (query == "FACTORIAL") {
                    long double result = factorial(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "ABSOLUTE") {
                    double result = fabs(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "FLOOR") {
                    double result = floor(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "CEILING") {
                    double result = ceil(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "SINE") {
                    double rads = degrees_to_radians(fOperand);
                    double result = sin(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "COSINE") {
                    double rads = degrees_to_radians(fOperand);
                    double result = cos(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "TANGENT") {
                    double rads = degrees_to_radians(fOperand);
                    double result = tan(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "INVERSE_SINE") {
                    double rads = asin(fOperand);
                    double result = radians_to_degrees(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "INVERSE_COSINE") {
                    double rads = acos(fOperand);
                    double result = radians_to_degrees(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "INVERSE_TANGENT") {
                    double rads = atan(fOperand);
                    double result = radians_to_degrees(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "HYP_SINE") {
                    double result = sinh(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "HYP_COSINE") {
                    double result = cosh(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "HYP_TANGENT") {
                    double result = tanh(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "INVERSE_HYP_TANGENT") {
                    double result = atanh(fOperand);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "INVERSE_HYP_SINE") {
                    double rads = asinh(fOperand);
                    double result = radians_to_degrees(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else if (query == "INVERSE_HYP_COSINE") {
                    double rads = acosh(fOperand);
                    double result = radians_to_degrees(rads);
                    answerStrings.emplace_back(stringConvert(result));
                    return true;
                } else {
                    return false;
                }
            };
            bool singleCall = process_real_single(query, fOperand);
            bool doubleCall = process_real_double(query, fOperand, sOperand);
            bool noError = singleCall || doubleCall;
            if (noError)
                continue;
            else
                throw std::runtime_error("MmQLC got struck with an unknown query.Compilation Halted !");
        }
        for (const auto &parsedToken: cmplxNums_parsed) {
            std::string query = std::get<0>(parsedToken);
            auto fOperand = std::get<1>(parsedToken);
            auto sOperand = std::get<2>(parsedToken);
            auto process_complex_double = [this](const std::string &query, const std::complex<double> &fOperand,
                                                 const std::complex<double> &sOperand) {
                if (query == "CMPLX_ADD") {
                    auto sum = fOperand + sOperand;
                    answerStrings.emplace_back(stringConvert(sum));
                    return true;
                } else if (query == "CMPLX_SUBTRACT") {
                    auto diff = fOperand - sOperand;
                    answerStrings.emplace_back(stringConvert(diff));
                    return true;
                } else if (query == "CMPLX_MULTIPLY") {
                    auto prod = fOperand * sOperand;
                    answerStrings.emplace_back(stringConvert(prod));
                    return true;
                } else if (query == "CMPLX_DIVIDE") {
                    auto zero = std::complex<double>(0,0);
                    if (sOperand == zero) {
                        throw std::runtime_error("Cannot divide complex number by zero !");
                    }
                    auto div = fOperand / sOperand;
                    answerStrings.emplace_back(stringConvert(div));
                    return true;
                } else if (query == "CMPLX_POWER") {
                    auto POW = std::pow(fOperand, sOperand);
                    answerStrings.emplace_back(stringConvert(POW));
                    return true;
                } else if (query == "CMPLX_ROOT") {
                    auto zero = std::complex<double>(0,0);
                    if (sOperand == zero) {
                        throw std::runtime_error("Zeroth root of complex number is undefined !");
                    }
                    auto one = std::complex<double>(1, 0);
                    auto ind = one / sOperand;
                    auto root = std::pow(fOperand, ind);
                    answerStrings.emplace_back(stringConvert(root));
                    return true;
                } else {
                    return false;
                }
            };
            auto process_complex_single = [this](const std::string &query, const std::complex<double> &fOperand) {
                if (query == "CMPLX_MODULUS") {
                    double MOD = std::abs(fOperand);
                    answerStrings.emplace_back(stringConvert(MOD));
                    return true;
                } else if (query == "CMPLX_ARGUMENT") {
                    double rads = std::arg(fOperand);
                    double degs = radians_to_degrees(rads);
                    answerStrings.emplace_back(stringConvert(degs));
                    return true;
                } else if (query == "CMPLX_SINE") {
                    auto sine = std::sin(fOperand);
                    answerStrings.emplace_back(stringConvert(sine));
                    return true;
                } else if (query == "CMPLX_COSINE") {
                    auto cosine = std::cos(fOperand);
                    answerStrings.emplace_back(stringConvert(cosine));
                    return true;
                } else if (query == "CMPLX_TANGENT") {
                    auto tang = std::tan(fOperand);
                    answerStrings.emplace_back(stringConvert(tang));
                    return true;
                } else if (query == "CMPLX_INVERSE_SINE") {
                    auto inverseSine = std::asin(fOperand);
                    answerStrings.emplace_back(stringConvert(inverseSine));
                    return true;
                } else if (query == "CMPLX_INVERSE_COSINE") {
                    auto inverseCosine = std::acos(fOperand);
                    answerStrings.emplace_back(stringConvert(inverseCosine));
                    return true;
                } else if (query == "CMPLX_INVERSE_TANGENT") {
                    auto inverseTangent = std::atan(fOperand);
                    answerStrings.emplace_back(stringConvert(inverseTangent));
                    return true;
                } else if (query == "CMPLX_HYP_SINE") {
                    auto hyperSine = std::sinh(fOperand);
                    answerStrings.emplace_back(stringConvert(hyperSine));
                    return true;
                } else if (query == "CMPLX_HYP_COSINE") {
                    auto hyperCosine = std::cosh(fOperand);
                    answerStrings.emplace_back(stringConvert(hyperCosine));
                    return true;
                } else if (query == "CMPLX_HYP_TANGENT") {
                    auto hyperTangent = std::tanh(fOperand);
                    answerStrings.emplace_back(stringConvert(hyperTangent));
                    return true;
                } else if (query == "CMPLX_HYP_INVERSE_SINE") {
                    auto inverseHypSine = std::asinh(fOperand);
                    answerStrings.emplace_back(stringConvert(inverseHypSine));
                    return true;
                } else if (query == "CMPLX_HYP_INVERSE_COSINE") {
                    auto inverseHypCosine = std::acosh(fOperand);
                    answerStrings.emplace_back(stringConvert(inverseHypCosine));
                    return true;
                } else if (query == "CMPLX_HYP_INVERSE_TANGENT") {
                    auto inverseHypTangent = std::atanh(fOperand);
                    answerStrings.emplace_back(stringConvert(inverseHypTangent));
                    return true;
                } else if (query == "CMPLX_LN") {
                    auto zero = std::complex<double>(0,0);
                    if (fOperand == zero) {
                        throw std::runtime_error("Cannot take log of zero !");
                    }
                    auto ln = std::log(fOperand);
                    answerStrings.emplace_back(stringConvert(ln));
                    return true;
                } else if (query == "CMPLX_EXP") {
                    auto expo = std::exp(fOperand);
                    answerStrings.emplace_back(stringConvert(expo));
                    return true;
                } else if (query == "CMPLX_CONJUGATE") {
                    auto conjg = std::conj(fOperand);
                    answerStrings.emplace_back(stringConvert(conjg));
                    return true;
                } else {
                    return false;
                }
            };
            bool singleCall = process_complex_single(query, fOperand);
            bool doubleCall = process_complex_double(query, fOperand, sOperand);
            bool noError = singleCall || doubleCall;
            if (noError)
                continue;
            else
                throw std::runtime_error("MmQLC got struck with an unknown query.Compilation Halted !");
        }
        return answerStrings;
    }

};

#endif
