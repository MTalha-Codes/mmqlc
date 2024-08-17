#ifndef MMQL_PACKAGE_QUERYPARSER_HPP
#define MMQL_PACKAGE_QUERYPARSER_HPP
#include "queryTokenizer.hpp"
#include "utility"
class parser
{
private:
    std::vector<std::tuple<std::string,std::string,std::string>> raw_tokens;
    std::vector<std::tuple<std::string,double,double>> num_parsed;
     /*
      * TODO: ADD Complex Tokens
      * TODO: ADD Matrix Tokens
      * TODO: ADD Vector Tokens
      */
public:
    explicit parser(std::vector<std::string> &queries) {
        raw_tokens = tokenize(queries);
    }
     std::vector<std::tuple<std::string, double, double>> parse_nums() {
        for(const auto &raw_token : raw_tokens) {
            if(std::get<0>(raw_token) == "ERROR")
            {
                num_parsed.emplace_back(std::get<0>(raw_token), -1 , -1);
                continue;
            }
           if(!std::get<2>(raw_token).empty())
           {
               double fOperand = std::stod(std::get<1>(raw_token));
               double sOperand = std::stod(std::get<2>(raw_token));
               num_parsed.emplace_back(std::get<0>(raw_token), fOperand, sOperand);
           }
           else
           {
               double fOperand = std::stod(std::get<1>(raw_token));
               num_parsed.emplace_back(std::get<0>(raw_token), fOperand, 0);
           }
        }
        return num_parsed;
    }
};
#endif