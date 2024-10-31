#ifndef MMQLC_FILESYSTEM_MMQLC_HPP
#define MMQLC_FILESYSTEM_MMQLC_HPP

#include <vector>
#include <fstream>
#include <filesystem>
#include "calculator.hpp"

using namespace std::filesystem;

class file {
    std::ifstream queryFile;
    std::ofstream answerFile;
    std::vector<std::string> queries;
    std::unique_ptr<parser> parser_ptr;
    std::unique_ptr<Calculator> calcAnswer_ptr;
    std::vector<std::string> answers;

    static bool if_comment(const std::string &str) {
        return str.rfind("%%", 0) == 0;
    }

    static bool if_empty(const std::string &str) {
        return str.empty();
    }

public:
    void loadQueries(const std::string &full_Path_To_Query_File) {
       const  path p = full_Path_To_Query_File;
        if (p.extension() != ".mmql" && p.extension() != ".MMQL") {
            throw std::runtime_error("Tried to load queries from an unsupported file type !");
        }
        if (file_size(p) == 0) {
            throw std::runtime_error("Compilation Error: " + p.filename().string() + " is empty !");
        }
        queryFile.open(full_Path_To_Query_File);

        if (!queryFile.is_open()) {
            throw std::runtime_error("No Such File or Directory !");
        } else {
            std::string singleQuery;
            while (!queryFile.eof()) {
                std::getline(queryFile, singleQuery);
                if (if_comment(singleQuery) || if_empty(singleQuery))
                    continue;
                queries.emplace_back(singleQuery);
            }
            queryFile.close();
        }
        parser_ptr = std::make_unique<parser>(queries);
        auto parsed_real_tokens = parser_ptr->parse_RealNums();
        auto parsed_complex_tokens = parser_ptr->parse_cmplxNums();
        calcAnswer_ptr = std::make_unique<Calculator>(parsed_real_tokens, parsed_complex_tokens);
    }

    void saveAnswers(const std::string &full_path_to_answer_file) {
        path p(full_path_to_answer_file);
        if (p.extension() != ".ans" && p.extension() != ".ANS") {
            throw std::runtime_error("Tried to create a file whose extension is not .ans !");
        }
        if (p.parent_path().empty()) {
           const std::string currentPathStr = current_path().string() + "\\" + full_path_to_answer_file;
            p = currentPathStr;
        }
        if (!exists(p.parent_path())) {
            create_directories(p.parent_path());
        }
        try {
            answers = calcAnswer_ptr->calculateAnswers();
        }
        catch (std::runtime_error &re) {
            throw std::runtime_error(re);
        }
        answerFile.open(p.string());
        if (!answerFile.is_open()) {
            throw std::runtime_error("Failed To Create Answer File !");
        }
        for (const auto &answer: answers) {
            answerFile << answer;
        }
        answerFile.close();
    }
};

#endif
