#ifndef MMQLC_MMQLC_BODY_HPP
#define MMQLC_MMQLC_BODY_HPP

#include "filesystem.hpp"
#include <thread>


class compileMmQL : public file {
private:
    int argc;
    char **argv;
    const std::string lessARGC_error = "Less than needed arguments were provided !";
    const std::string moreARGC_error = "More than needed arguments were provided !";

    static void showHelp() {
        using std::cout, std::endl;
        cout << "\n \t****** Help ******* \n";
        cout << "Command: " << hue::red << "MmQLC.exe " << hue::green << "~r " << hue::light_blue
             << "PATH_TO_QUERY_FILE\\\\QUERY.MMQL " << hue::green << "~w " << hue::light_blue
             << "PATH_TO_ANSWER_FILE\\\\ANSWER.ANS\n\n" << hue::reset << endl;
    }

public:
    compileMmQL(int argsC, char **argvA) : argc(argsC), argv(argvA) {
        if (argc < 5) {
            std::cerr << "\nCompiler requires 5 arguments but only " << argc << " were provided" << std::endl;
            showHelp();
            throw std::runtime_error(lessARGC_error);
        } else if (argc > 5) {
            std::cerr << "\nCompiler requires 5 arguments but " << argc << " were provided" << std::endl;
            showHelp();
            throw std::runtime_error(moreARGC_error);
        }
    }

    void startCompilation() {
        using namespace std::chrono_literals;
        using namespace std::this_thread;
        std::vector<bool> isCorrectHandlerUsed(2);
        isCorrectHandlerUsed[0] = (std::string(argv[1]) == "~r");
        isCorrectHandlerUsed[1] = (std::string(argv[3]) == "~w");
        if (!isCorrectHandlerUsed[0] || !isCorrectHandlerUsed[1]) {
            throw std::runtime_error("Invalid Handler(s) used !");
        }
        std::string inputFilePath = argv[2];
        std::string outputFilePath = argv[4];
        try {
            loadQueries(inputFilePath);
        } catch (const std::runtime_error &re) {
            throw re;
        }
        hue::reset();
        std::filesystem::path out(outputFilePath);
        try {
            saveAnswers(outputFilePath);
        } catch (const std::runtime_error &re) {
            throw re;
        }
        std::cout << hue::green << "Compilation Successful !" << hue::reset;
        if (out.parent_path() == "") {
            outputFilePath = std::filesystem::current_path().string() + "\\" + out.filename().string();
        } else { outputFilePath = out.parent_path().string() + "\\" + out.filename().string(); }
        std::cout << "\nAnswer file has been successfully generated !\nPath To Answer File:" << outputFilePath
                  << std::endl;
    }

    ~compileMmQL() {
        delete[] argv;
    }
};

#endif //MMQLC_MMQLC_BODY_HPP
