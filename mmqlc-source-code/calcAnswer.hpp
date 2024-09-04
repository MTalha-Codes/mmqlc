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

class answer_calc
{
private:
    std::vector<std::tuple<std::string ,double ,double>> realNums_parsed;
    std::vector<std::string> answerStrings;
    static double degrees_to_radians(const double &degs) noexcept
    {
        const double pi = 3.14159265359;
        double rads = degs*pi;
        rads /= 180;
        return rads;
    }
    static double radians_to_degrees(const double &rads) noexcept
    {
        const double pi = 3.14159265359;
        double degs = rads*180;
        degs /= pi;
        return degs;
    }
    static long double factorial(const double &param)
    {
        long double fact = tgammal(param+1);
        return fact;
    }
    static long double nPr(const double &n , const double &r)
    {
        long double numerator = factorial(n);
        long double denominator = factorial(n-r);
        long double perm = numerator; perm/= denominator;
        return perm;
    }
    static long double nCr(const double &n , const double &r)
    {
        long double rFact = 1;
        rFact /= factorial(r);
        long double comb = rFact * nPr(n,r);
        return comb;
    }
    static double HCF(const double &a , const double &b)
    {
        int A = static_cast<int>(a);
        int B = static_cast<int>(b);
        int HCF = std::gcd(A,B);
        return HCF;
    }
    static double LCM(const double &a , const double &b)
    {
        int A = static_cast<int>(a);
        int B = static_cast<int>(b);
        int LCM = std::lcm(A,B);
        return LCM;
    }

    template<typename T>
    static std::string stringConvert(const T &argument)
    {
        std::string str = std::to_string(argument);
        return str;
    }
public:
   explicit answer_calc(std::vector<std::tuple<std::string ,double ,double>> &parsedNumbers)
   {
       realNums_parsed = parsedNumbers;
   }
   std::vector<std::string> calculateAnswers_real()
   {
        for(const auto &parsedToken : realNums_parsed)
        {
            std::string query = std::get<0>(parsedToken);
            double fOperand = std::get<1>(parsedToken);
            double sOperand = std::get<2>(parsedToken);
            if(query == "ADD")
            {
                double result = fOperand + sOperand;
                answerStrings.emplace_back(stringConvert(result));
            }
            else if(query == "SUBTRACT")
            {
                double result = fOperand - sOperand;
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "MULTIPLY")
            {
                double result = fOperand * sOperand;
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "DIVIDE")
            {
                if(sOperand != 0)
                {
                    double result = fOperand / sOperand;
                    answerStrings.emplace_back(stringConvert(result));
                }
                else
                {
                    throw std::runtime_error("Cannot divide by zero");
                }
            }
            else if (query == "POWER")
            {
                double result = pow(fOperand,sOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "ROOT")
            {
                if(sOperand != 0)
                {
                    double index = 1;
                    index /= sOperand;
                    double result = pow(fOperand,index);
                    answerStrings.emplace_back(stringConvert(result));
                }
                else
                {
                    throw std::runtime_error("Zeroth root does not exist");
                }
            }
            else if(query == "FACTORIAL")
            {
                long double result = factorial(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "LCM")
            {
                double result = LCM(fOperand,sOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if(query == "LOGARITHM")
            {
                // using change of base formula
                double n = log10(fOperand);
                double d = log10(sOperand);
                double log_result = n;
                log_result /= d;
                answerStrings.emplace_back(stringConvert(log_result));
            }
            else if(query == "PERMUTATION")
            {
                long double result = nPr(fOperand,sOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "COMBINATION")
            {
                long double result = nCr(fOperand,sOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if(query == "ABSOLUTE")
            {
                double result = fabs(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if(query == "MODULUS")
            {
                if(sOperand != 0) {
                    double result = fmod(fOperand, sOperand);
                    answerStrings.emplace_back(stringConvert(result));
                }
                else
                {
                    throw std::runtime_error("Cannot divide by zero");
                }
            }
            else if (query == "FLOOR")
            {
                double result = floor(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if(query == "CEILING")
            {
                double result = ceil(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "GCD")
            {
                double result = HCF(fOperand,sOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "SINE")
            {
                double rads = degrees_to_radians(fOperand);
                double result = sin(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "COSINE")
            {
                double rads = degrees_to_radians(fOperand);
                double result = cos(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "TANGENT")
            {
                double rads = degrees_to_radians(fOperand);
                double result = tan(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "INVERSE_SINE")
            {
                double rads = asin(fOperand);
                double result = radians_to_degrees(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "INVERSE_COSINE")
            {
                double rads = acos(fOperand);
                double result = radians_to_degrees(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "INVERSE_TANGENT")
            {
                double rads = atan(fOperand);
                double result = radians_to_degrees(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "HYP_SINE")
            {
                double result = sinh(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if(query == "HYP_COSINE")
            {
                double result = cosh(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if(query == "HYP_TANGENT")
            {
                double result = tanh(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "INVERSE_HYP_TANGENT")
            {
                double result = atanh(fOperand);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "INVERSE_HYP_SINE")
            {
                double rads = asinh(fOperand);
                double result = radians_to_degrees(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else if (query == "INVERSE_HYP_COSINE")
            {
                double rads = acosh(fOperand);
                double result = radians_to_degrees(rads);
                answerStrings.emplace_back(stringConvert(result));
            }
            else
            {
                throw std::runtime_error("Unknown Queries or Empty Lines Error !");
            }
        }
        return answerStrings;
   }

};
#endif
