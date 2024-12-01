/*
 * Filename: main.cpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repository: mmqlc
 * Copyright(C) - 2024
 * */

#include "headers/mmqlc.ui.hpp"
#include <memory>

int main(int argc, char *argv[]) {
    try {
        const auto compiler = std::make_unique<mmqlc_ui>(argc, argv);
        try {
            compiler->startCompilation();
        } catch (const std::runtime_error &re) {
            fmt::print(fg(fmt::color::red), "Exception(s) Thrown: {}\n", re.what());
            return EXIT_FAILURE;
        }
    } catch (const std::runtime_error &re) {
        fmt::print(fg(fmt::color::red), "Exception Thrown: {}\n", re.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
