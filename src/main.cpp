#include "headers/mmqlc.hpp"
#include <memory>

int main(int argc, char *argv[]) {
    try {
        const auto compiler = std::make_unique<compileMmQL>(argc, argv);
        try {
            compiler->startCompilation();
        } catch (const std::runtime_error &re) {
            std::cerr << "Exception(s) Thrown: " << hue::red << re.what() << hue::reset << std::endl;
            return EXIT_FAILURE;
        }
    } catch (const std::runtime_error &re) {
        std::cerr << "Exception Thrown: " << hue::red << re.what() << hue::reset << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
