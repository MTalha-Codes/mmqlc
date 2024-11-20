#ifndef MMQLC_MMQLC_BODY_HPP
#define MMQLC_MMQLC_BODY_HPP

#include "mmqlc.filesystem.hpp"
#include "fmt/color.h"
#include <thread>
#include <cstring>

#if WIN32
#include <windows.h>
inline void enable_virtual_terminal_processing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    if (hOut == INVALID_HANDLE_VALUE)
        return;

    // Enable ANSI escape code support
    if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
}
#endif

class mmqlc_ui : public mmqlc_filesystem {
    int argc;
    char **argv;
    std::string inputPath, outputPath;

    static void generalError() noexcept {
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "mmqlc: ");
        fmt::print(fg(fmt::color::red), "error: ");
        fmt::print("mmqlc invoked with unrecognised command-line option\ninterpretation terminated.\n");
    }

    static void blankError() noexcept {
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "mmqlc: ");
        fmt::print(fg(fmt::color::red), "fatal error: ");
        fmt::print("no input files\ninterpretation terminated.\n");
    }

    static void showHelp() {
        std::cout << "Usage: mmqlc [command-line-option]\n";
        std::cout << "Available Commands:\n";
        std::cout << "  --htu                   Displays the full procedure for bulk interpretation [ .mmql --> .ans ]\n";
        std::cout << "  --version               Displays the current version of mmqlc\n";
        std::cout << "  --help                  Displays the list of all available mmqlc commands\n";
        std::cout << "  --live                  Starts a temporary interpretation session for real-time query evaluation\n";
        exit(EXIT_SUCCESS);
    }

    static void cross_platform_clrscr() {
#if WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    static void launch_live() {
        constexpr auto copyright_notice =
            "MmQLC (MTalha-Codes) 2.3\nCopyright (C) 2024\nLicensed under the CC0-1.0 License\n";
        constexpr auto quit_command = "QUIT";
        constexpr auto cls_command = "CLEAR";
        constexpr auto hlp_cmd  = "HELP";

        std::cout << copyright_notice;
        fmt::print("\n");
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "mmqlc: ");
        fmt::print(fg(fmt::color::green), "real-time query interpreter started!\n");

        fmt::print("'{}' to show session-specific commands. \n\n",
               fmt::format(fg(fmt::color::white) | fmt::emphasis::bold, hlp_cmd));
        std::string query;
        while (true) {
            fmt::print(fg(fmt::color::cyan), ">>> ");
            std::getline(std::cin, query);
            if(query == hlp_cmd) {
                std::cout << "Commands               Effect\n";
                std::cout << "CLEAR                  Clears and refreshes the console screen.\n";
                std::cout << "QUIT                   Exits the interpreter.\n\n";
                continue;
            }
            if (query.empty() || query.rfind("%%", 0) == 0) continue;
            if(query == cls_command) {
                cross_platform_clrscr();
                continue;
            }
            if (query == quit_command) break;

            const auto answer = [&]() {
                const auto token = tokenize({query});
                const auto parse_ptr = std::make_unique<parser>(token);
                const auto ansPTR = std::make_unique<mmqlc_calculator>(parse_ptr->parse_RealNums(), parse_ptr->parse_cmplxNums());
                return ansPTR->calculateAnswers()[0];
            }();
            if (const size_t pos = answer.find('='); pos != std::string::npos) {
                fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "{}\n", answer.substr(pos + 2));  // Skip "= "
            }
        }
    }

    static void r_hookError(const std::string &op) {
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "mmqlc: ");
        fmt::print(fg(fmt::color::red), "error: ");
        fmt::print("unrecognised hook used '");
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "{}' ", op);
        fmt::print(fg(fmt::color::red), "; did you mean '-r'?\n");
        blankError();
    }

    static void w_hookError(const std::string &op) {
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "mmqlc: ");
        fmt::print(fg(fmt::color::red), "error: ");
        fmt::print("unrecognised hook used '");
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "{}' ", op);
        fmt::print(fg(fmt::color::red), "; did you mean '-w'?\n");
        blankError();
    }

    static void show_howToUse() {
        std::cout << "mmqlc -r [path where query file exists] -w [path where answer file to be created]\n";
        exit(EXIT_SUCCESS);
    }

    static void showVersion() {
        std::cout << "MmQLC (MTalha-Codes) 2.3\nCopyright (C) 2024\nLicensed under the CC0-1.0 License\n";
        exit(EXIT_SUCCESS);
    }

public:
    mmqlc_ui(const int argsC, char **argvA) : argc(argsC), argv(argvA) {
#if WIN32
        enable_virtual_terminal_processing();
#endif
        if (argc == 1) {
            blankError();
            exit(EXIT_FAILURE);
        } else if (argc == 2 && (strcmp(argv[1], "--vers") == 0 || strcmp(argv[1], "--versi") == 0 ||
                                 strcmp(argv[1], "--versio") == 0 || strcmp(argv[1], "--version") == 0)) {
            showVersion();
        } else if (argc == 2 && strcmp(argv[1], "--htu") == 0) {
            show_howToUse();
        } else if (argc == 2 && strcmp(argv[1], "--live") == 0) { launch_live(); exit(1);} else if (
            argc == 2 && (strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "--he") == 0 || strcmp(argv[1], "--hel") == 0
                          || strcmp(argv[1], "--help") == 0)) {
            showHelp();
        } else if (argc != 5) {
            generalError();
            exit(EXIT_FAILURE);
        }
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
        } else if (!correctHook[1]) {
            w_hookError(std::string(argv[3]));
            exit(EXIT_FAILURE);
        }
        if (strcmp(argv[2], "") != 0) inputPath = argv[2];
        if (strcmp(argv[4], "") != 0) outputPath = argv[4];
        try {
            loadQueries(inputPath);
        } catch (const std::runtime_error &re) {
            throw std::runtime_error(re);
        }

        const path out(outputPath);
        try {
            saveAnswers(outputPath);
        } catch (const std::runtime_error &re) {
            throw std::runtime_error(re);
        }

        fmt::print(fg(fmt::color::green), "Compilation Successful!\n");
        if (out.parent_path() == "") {
            outputPath = current_path().string() + "\\" + out.filename().string();
        } else { outputPath = out.parent_path().string() + "\\" + out.filename().string(); }
        fmt::print("\nAnswer file has been successfully generated!\nPath To Answer File: {}\n", outputPath);
    }

    ~mmqlc_ui() {
        delete[] argv;
    }
};

#endif //MMQLC_MMQLC_BODY_HPP
