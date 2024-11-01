#ifndef MMQLC_MMQLC_BODY_HPP
#define MMQLC_MMQLC_BODY_HPP

#include "filesystem.hpp"
#include <color.hpp>
#include <thread>
#include <cstring>



class compileMmQL : public file {
    int argc;
    char **argv;
    std::string inputPath,outputPath;
    static void generalError() noexcept {
        std::cerr << hue::bright_white << "mmqlc: " << hue::red << "error: " << hue::reset << " mmqlc invoked with unrecognised command-line option\ncompilation terminated.\n";
    }
    static  void blankError() noexcept {
        std::cerr << hue::bright_white << "mmqlc: " << hue::red << "fatal error: " << hue::reset << "no input files\ncompilation terminated.\n";
    }
    static void showHelp() {
        std::cout << "Usage: mmqlc [command-line-option]\n";
        std::cout << "Available Commands:\n";
        std::cout << "  --htu           Displays the full procedure for compilation\n";
        std::cout << "  --version       Displays the current version of mmqlc\n";
        std::cout << "  --help          Displays the list of all available mmqlc commands\n";
        exit(EXIT_SUCCESS);
    }
    static void r_hookError(const std::string& op) {
            std::cerr << hue::bright_white << "mmqlc: " << hue::red << "error: " << hue::reset << "unrecognised hook used " << hue::bright_white << "\'"<< op <<"\'" << hue::reset << "; did you mean \'-r\'?\n";
            blankError();
    }
    static void w_hookError(const std::string &op) {
        std::cerr << hue::bright_white << "mmqlc: " << hue::red << "error: " << hue::reset << "unrecognised hook used " << hue::bright_white << "\'"<< op <<"\'" << hue::reset << "; did you mean \'-w\'?\n";
        blankError();
    }

    static void show_howToUse() {
        std::cout << "mmqlc -r [path where query file exists] -w [path where answer file to be created]\n";
        exit(EXIT_SUCCESS);
    }
    static void showVersion() {
       std::cout << "MmQLC (MTalha-Codes) 2.1\nCopyright (C) 2024\nLicensed under the CC0-1.0 License\n";
        exit(EXIT_SUCCESS);
    }

public:
    compileMmQL(const int argsC, char **argvA) : argc(argsC), argv(argvA) {
        if (argc ==1)
        { blankError(); exit(EXIT_FAILURE);}
        else if(argc == 2 && (strcmp(argv[1], "--vers") == 0 || strcmp(argv[1],"--versi")==0 || strcmp(argv[1] , "--versio") ==0 || strcmp(argv[1] , "--version") ==0)) {
                showVersion();
        }
        else if (argc ==2 && strcmp(argv[1],"--htu")==0) {
            show_howToUse();
        }
        else if(argc == 2 && (strcmp(argv[1], "--h") == 0 || strcmp(argv[1],"--he")==0 || strcmp(argv[1] , "--hel") ==0 || strcmp(argv[1] , "--help") ==0)) {
            showHelp();
        }
        else if (argc != 5)
        { generalError(); exit(EXIT_FAILURE);}
    }

    void startCompilation() {
        using namespace std::chrono_literals;
        using namespace std::this_thread;
        std::vector<bool> correctHook(2);
        correctHook[0] = (std::string(argv[1]) == "-r");
        correctHook[1] = (std::string(argv[3]) == "-w");
        if (!correctHook[0]) {
            r_hookError(std::string(argv[1]));
            exit(EXIT_FAILURE);
        }
        else if (!correctHook[1]) {
            w_hookError(std::string(argv[3]));
            exit(EXIT_FAILURE);
        }
        if(strcmp(argv[2],"") != 0) inputPath = argv[2];
        if(strcmp(argv[4],"") != 0) outputPath = argv[4];
        try {
            loadQueries(inputPath);
        } catch (const std::runtime_error &re) {
            throw std::runtime_error(re);
        }
        hue::reset();
        const path out(outputPath);
        try {
            saveAnswers(outputPath);
        } catch (const std::runtime_error &re) {
            throw std::runtime_error(re);
        }
        std::cout << hue::green << "Compilation Successful !" << hue::reset;
        if (out.parent_path() == "") {
            outputPath = current_path().string() + "\\" + out.filename().string();
        } else { outputPath = out.parent_path().string() + "\\" + out.filename().string(); }
        std::cout << "\nAnswer file has been successfully generated !\nPath To Answer File:" << outputPath
                  << std::endl;
    }

    ~compileMmQL() {
        delete[] argv;
    }
};

#endif //MMQLC_MMQLC_BODY_HPP
