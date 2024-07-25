#ifndef MMQLC_CALCANSWER_HPP
#define MMQLC_CALCANSWER_HPP

#include <vector>
#include <tuple>
#include <utility>
#include <string>
#include <numeric>
#include <stdexcept>
#include <cmath>

constexpr double PI = 3.14159265358;

long double answer(const std::tuple<std::string, double, double> &parsedQuery) {

    std::string gotKeyword = std::get<0>(parsedQuery);
    double gotFirstOperand = std::get<1>(parsedQuery);
    double gotSecondOperand = std::get<2>(parsedQuery);
    auto degrees = [](const double &rads) {
        double degs = rads * 180;
        degs /= PI;
        return degs;
    };
    auto radians = [](const double &degs) {
        double rads = degs * PI;
        rads /= 180;
        return rads;
    };
    auto logAnyBase = [](const double &x, const double &base) {
        double numerator = log10(x);
        double denominator = log10(base);
        return numerator / denominator;
    };
    auto factorial = [](double x) -> long double {
        return tgammal(x+1);
    };

    auto permutation = [&factorial](double n, double r) {
        return factorial(n) / factorial(n - r);
    };

    auto combination = [&factorial](double n, double r) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    };

    long double finalAnswer = -1;

    if (gotKeyword == "ADD") {
        finalAnswer = gotFirstOperand + gotSecondOperand;
    } else if (gotKeyword == "SUBTRACT") {
        finalAnswer = gotFirstOperand - gotSecondOperand;
    } else if (gotKeyword == "MULTIPLY") {
        finalAnswer = gotFirstOperand * gotSecondOperand;
    } else if (gotKeyword == "DIVIDE") {
        if (gotSecondOperand != 0) {
            finalAnswer = gotFirstOperand / gotSecondOperand;
        } else {
            finalAnswer = std::numeric_limits<long double>::infinity(); // handle division by zero
        }
    } else if (gotKeyword == "POWER") {
        finalAnswer = pow(gotFirstOperand, gotSecondOperand);
    } else if (gotKeyword == "ROOT") {
        if (gotSecondOperand != 0) {
            double index = 1.0 / gotSecondOperand;
            finalAnswer = pow(gotFirstOperand, index);
        } else {
            finalAnswer = std::numeric_limits<long double>::infinity(); // handle division by zero in root
        }
    } else if (gotKeyword == "FACTORIAL") {
        finalAnswer = factorial(gotFirstOperand);
    } else if (gotKeyword == "PERMUTATION") {
        finalAnswer = permutation(gotFirstOperand, gotSecondOperand);
    } else if (gotKeyword == "COMBINATION") {
        finalAnswer = combination(gotFirstOperand, gotSecondOperand);
    } else if (gotKeyword == "SINE") {
        finalAnswer = sin(radians(gotFirstOperand));
    } else if (gotKeyword == "COSINE") {
        finalAnswer = cos(radians(gotFirstOperand));
    } else if (gotKeyword == "TANGENT") {
        finalAnswer = tan(radians(gotFirstOperand));
    } else if (gotKeyword == "INVERSE_SINE") {
        if (gotFirstOperand >= -1 && gotFirstOperand <= 1) {
            finalAnswer = asin(gotFirstOperand);
            finalAnswer = finalAnswer * 180.0 / PI; // Convert radians to degrees
        } else {
            finalAnswer = std::numeric_limits<double>::quiet_NaN(); // Return NaN for out-of-range inputs
        }
    } else if (gotKeyword == "INVERSE_COSINE") {
        if (gotFirstOperand >= -1 && gotFirstOperand <= 1) {
            finalAnswer = acos(gotFirstOperand);
            finalAnswer = finalAnswer * 180.0 / PI; // Convert radians to degrees
        } else {
            finalAnswer = std::numeric_limits<double>::quiet_NaN(); // Return NaN for out-of-range inputs
        }
    } else if (gotKeyword == "INVERSE_TANGENT") {
        finalAnswer = degrees(atan(gotFirstOperand));
    } else if (gotKeyword == "HYP_SINE") {
        finalAnswer = sinh(gotFirstOperand);
    } else if (gotKeyword == "HYP_COSINE") {
        finalAnswer = cosh(gotFirstOperand);
    } else if (gotKeyword == "HYP_TANGENT") {
        finalAnswer = tanh(gotFirstOperand);
    } else if (gotKeyword == "INVERSE_HYP_SINE") {
        finalAnswer = asinh(gotFirstOperand);
    } else if (gotKeyword == "INVERSE_HYP_COSINE") {
        finalAnswer = acosh(gotFirstOperand);
    } else if (gotKeyword == "INVERSE_HYP_TANGENT") {
        finalAnswer = atanh(gotFirstOperand);
    } else if (gotKeyword == "LOGARITHM") {
        finalAnswer = gotFirstOperand <= 0 ? std::numeric_limits<double>::quiet_NaN() : logAnyBase(gotFirstOperand,
                                                                                                   gotSecondOperand);
    } else if (gotKeyword == "LCM") {
        finalAnswer = std::lcm(static_cast<int>(gotFirstOperand), static_cast<int>(gotSecondOperand));
    } else if (gotKeyword == "GCD") {
        finalAnswer = std::gcd(static_cast<int>(gotFirstOperand), static_cast<int>(gotSecondOperand));
    } else if (gotKeyword == "FLOOR") {
        finalAnswer = floor(gotFirstOperand);
    } else if (gotKeyword == "CEILING") {
        finalAnswer = ceil(gotFirstOperand);
    }else if (gotKeyword == "MODULUS") {
        finalAnswer = fmod(gotFirstOperand, gotSecondOperand);
    }else if (gotKeyword == "ABSOLUTE") {
        finalAnswer = abs(gotFirstOperand);
    }else if (gotKeyword == "ERROR"){
		std::string error = "\nSyntax Error: The selected query file either contains bad queries or possible empty line(s)!\nCompilation Stopped Due To Misunderstood Query(ies) !";
        throw std::runtime_error(error);
    }
    return finalAnswer;
}

#endif
