#ifndef LOAD_AND_VIEW_HPP
#define LOAD_AND_VIEW_HPP
//----------------------------------------------
#include "includes.hpp"
//----------------------------------------------
class ReadView_WriteSave
{
private:
   int argc;
   char **argv;
   bool readMode = false;
   bool writeMode = false;
   fs::path Query_filePath;
   fs::path Answer_filePath;
   std::string str;
   std::vector<std::string> vct;
   void handleCheck()
   {
       if(argv[1] == (std::string)"~rv")
           readMode = true;
       else if(argv[1] == (std::string)"~ws")
           writeMode = true;
       else
       {
           std::cout << "\nExpected Either ~rv or ~ws instead of " << argv[2] << std::endl;
           readMode = false;
           writeMode = false;
           throw std::runtime_error("Unknown Handle Has Been Used !");
       }
   }
   static void resetTerminal()
   {
       #ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
   }
    void Read_View()
    {
        auto chooseColour = []()
        {
            std::random_device myDev;
            std::uniform_int_distribution<int> collection_of_random_numbers(1,7); // generate random integers from 1--7
            int randomNum = collection_of_random_numbers(myDev);
            auto color = hue::light_yellow;
            if(randomNum == 1)
            {color = hue::light_blue;}
            else if(randomNum == 2)
            {color  = hue::light_green;}
            else if(randomNum == 3)

            {   color = hue::yellow;}
            else if(randomNum  == 4)
            {color = hue::light_red;}
            else if(randomNum == 5)
            {color =  hue::bright_white;}
            else if(randomNum == 6)
            {color =  hue::aqua;}
            return color;
        };
        Answer_filePath = argv[2];
        if(Answer_filePath.parent_path().empty())
        {
            auto crtPth = fs::current_path();
            Answer_filePath = crtPth / Answer_filePath;
        }
        if(!fs::exists(Answer_filePath))
        {
            throw std::runtime_error("Cannot Open Arbitrary Answer File That Does Not Exists !"); // error
        }
        if(Answer_filePath.extension() != ".ans")
        {
            throw std::runtime_error("Tried To Read Unsupported File Type !"); // error
        }
        std::ifstream answerFile(Answer_filePath);
        if(!answerFile.is_open())
        {
            throw std::runtime_error("Unable To Read Or Open Answer File !"); // error
        }
        // Load from file
        while(std::getline(answerFile , str))
        {
            vct.emplace_back(str); // add the line to the vector
        }
        // View or print to console
        resetTerminal();
        for(auto const &LINE : vct)
        {
            std::cout << chooseColour() << LINE << hue::reset << std::endl; // print each line in random color to console
        }
        std::cout << hue::light_green << "\nPress Any Key To Clear Screen !" << hue::reset << std::endl;
        std::cin.get();
        resetTerminal();
        answerFile.close(); // close file
        str.clear(); // clear line to free up memory
        vct.clear(); // clear vector to free up memory
    }
    void Write_Save() {
        Query_filePath = argv[2];
        if (Query_filePath.parent_path().empty()) {
            auto crtPth = fs::current_path();
            Query_filePath = crtPth / Query_filePath;
        }
        if (!fs::exists(Query_filePath.parent_path())) {
            fs::create_directories(Query_filePath.parent_path());
        }
        if (Query_filePath.extension() != ".mmql") {
            throw std::runtime_error("Tried To Read Unsupported File Type !"); // error
        }
        std::ofstream queryFile(Query_filePath);
        if (!queryFile.is_open()) {
            throw std::runtime_error("Unable To Read Or Open Query File !"); // error
        }
        std::string strPrev;
        resetTerminal();
        while (true) {
            std::cout << hue::green << ">>> Query: " << hue::reset;
            std::getline(std::cin, str);
            if (str == ":wq!") {
                vct.pop_back(); // to avoid duplication of lastly entered query
                vct.emplace_back(strPrev);
                break;
            }
            strPrev = str;
            vct.emplace_back(str + '\n'); // Append a newline character to the string
        }
        resetTerminal();
        for(auto const &LINE : vct)
        {
            queryFile << LINE;
        }
        queryFile.close(); // close file
        str.clear(); // clear line to free up memory
        vct.clear(); // clear vector to free up memory
    }
public:
    ReadView_WriteSave(int argumentCount , char **argumentVector)
    {
        argc = argumentCount;
        if(argc != 3)
        {
            std::cout << "\n\t******* HELP ******* \n";
            std::cout << "Command: " << hue::red <<"MmQL.exe " << hue::light_aqua << "~rv " << hue::light_blue << "PATH_TO_COMPILED_ANSWER_FILE\\\\file.ans\n" << hue::reset; // help 1
            std::cout << "Command: " << hue::red <<"MmQL.exe " << hue::light_aqua << "~ws " << hue::light_blue << "PATH_TO_GENERATE_QUERY_FILE\\\\file.mmql\n" << hue::reset; // help 2
            throw std::runtime_error("Incomplete Arguments Provided !"); // error
        }
        argv = argumentVector;
    }
    void MMQL_RV_WS()
    {
        handleCheck();
        if(readMode)
        {
            Read_View();
        }
        else if (writeMode)
        {
            Write_Save();
        }
    }
    ~ReadView_WriteSave(){delete argv;}
};
//--------------------------------------------------
#endif