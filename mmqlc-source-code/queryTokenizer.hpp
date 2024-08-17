#ifndef MMQLC_QUERYPARSER_HPP
#define MMQLC_QUERYPARSER_HPP

#include <regex>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>


std::vector<std::tuple<std::string, std::string,std::string>> tokenize(std::vector<std::string> &queries) {
    std::vector<std::tuple<std::string, std::string, std::string>> tokens;
      std::unordered_set<std::string> real_singleOP_keywords = {
              "FACTORIAL", "SINE", "COSINE", "TANGENT", "HYP_SINE", "HYP_COSINE",
              "HYP_TANGENT", "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
              "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
              "FLOOR", "CEILING", "ABSOLUTE"
      };
      std::regex real_singleOP_ptrn(R"(^(\w+)\s+(-?\d+(\.\d+)?))");
      std::regex real_doubleOP_ptrn(R"(^(\w+)\s+(-?\d+(\.\d+)?),\s*(-?\d+(\.\d+)?))");
      for (const auto &query : queries) {
          std::smatch matches;
          std::string keyWord;
          std::string firstOperand;
          std::string secondOperand;

          if (std::regex_match(query, matches, real_singleOP_ptrn) && matches.size() >= 3) {
              keyWord = matches[1].str();
              if (real_singleOP_keywords.find(keyWord) != real_singleOP_keywords.end()) {
                  firstOperand = (matches[2]);
                  tokens.emplace_back(keyWord, firstOperand, "");
              } else {
                  tokens.emplace_back("ERROR", "", "");
              }
          } else if (std::regex_match(query, matches, real_doubleOP_ptrn) && matches.size() >= 5) {
              keyWord = matches[1].str();
              firstOperand = (matches[2]);
              secondOperand = (matches[4]);
              tokens.emplace_back(keyWord, firstOperand, secondOperand);
          }
          else {
              tokens.emplace_back("ERROR", "", "");
            }
         }
    // WORK IN PROGRESS
    return tokens;
}

#endif // MMQLC_QUERYPARSER_HPP
