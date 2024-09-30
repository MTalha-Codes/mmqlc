#ifndef MMQLC_FILEMANAGER_HPP
#define MMQLC_FILEMANAGER_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include "color.hpp"
#include <filesystem>
#include <iomanip>
#include <algorithm>
#include "queryTokenizer.hpp"
#include "calcAnswer.hpp"

class file {
private:
    std::ifstream queryFile;
    std::ofstream answerFile;
    std::vector<std::string> queries;
    std::unique_ptr<parser> parser_ptr;
    std::unique_ptr<answer_calc> calcAnswer_ptr;
    std::vector<std::string> answers;
public:
    void loadQueries(std::string &full_Path_To_Query_File) {
        std::filesystem::path p = full_Path_To_Query_File;
        if(p.extension() != ".mmql" && p.extension() != ".MMQL")
        {
            throw std::runtime_error("Tried to load queries from an unsupported file type !");
        }
        if(std::filesystem::file_size(p) == 0) {
            throw std::runtime_error("Compilation Error: " + p.filename().string() + " is empty !");
        }
        queryFile.open(full_Path_To_Query_File);

        if (!queryFile.is_open()) {
            std::cerr << " MmQLC: " << hue::red << "No Such File Or Directory !" << hue::reset << std::endl;
            exit(0xDEAD);
        } else {
             std::string singleQuery;
            while (!queryFile.eof())  {
				std::getline(queryFile , singleQuery);
                queries.emplace_back(singleQuery);
            }
            queryFile.close();
        }
        parser_ptr = std::make_unique<parser>(queries);
        auto parsed_real_tokens = parser_ptr->parse_RealNums();
        auto parsed_complex_tokens = parser_ptr->parse_cmplxNums();
        calcAnswer_ptr = std::make_unique<answer_calc>(parsed_real_tokens,parsed_complex_tokens);
    }

    void saveAnswers(std::string &full_path_to_answer_file) {
        std::filesystem::path p(full_path_to_answer_file);
        if(p.extension() != ".ans" && p.extension() != ".ANS")
        {
            throw std::runtime_error("Tried to create a file whose extension is not .ans !");
        }
       if (p.parent_path().empty()) {
            auto currentPathStr = std::filesystem::current_path().string() + "\\" + full_path_to_answer_file;
            p = currentPathStr;
        }
        if (!std::filesystem::exists(p.parent_path())) {
            std::filesystem::create_directories(p.parent_path());
		}
        try
        {
            answers = calcAnswer_ptr->calculateAnswers();
        }
        catch (std::runtime_error &re)
        {
            throw re;
        }
		answerFile.open(p.string());
        if(!answerFile.is_open())
        {
            throw std::runtime_error("Failed To Create Answer File !");
        }
        auto removeComments = [this]()
        {
            auto pred = [](const std::string &s)
            {
                return s.rfind("%%" , 0) == 0;
            };
            queries.erase(std::remove_if(queries.begin(),queries.end(),pred) , queries.end());
        };
        removeComments();
        int i = 0;
        for (const auto &answer: answers) {
                 answerFile << (queries[i] + "\n>>>Output: " + answer);
                 answerFile << std::endl;
                 i++;
        }
        answerFile.close();
    }
};

#endif
