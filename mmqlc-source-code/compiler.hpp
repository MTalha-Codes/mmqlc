#ifndef MMQLC_COMPILER_HPP
#define MMQLC_COMPILER_HPP

#include "fileManager.hpp"
#include <thread>


class compileMmQL : public file {
private:
    int argc;
    char **argv;
	static void showHelp()
	{
		using std::cout,std::endl;
		cout << "\n \t****** Help ******* \n";
		cout << "Command: " << hue::red << "MmQLC.exe " << hue::green << "~r " << hue::light_blue << "PATH_TO_QUERY_FILE\\\\QUERY.MMQL " <<hue::green << "~w "<< hue::light_blue << "PATH_TO_ANSWER_FILE\\\\ANSWER.ANS\n\n" <<hue::reset << endl;
	}
public:
    compileMmQL(int argsC, char **argvA) : argc(argsC), argv(argvA) {
        if (argc != 5) {
            std::cerr << "\nCompiler requires 5 arguments but only " << argc << " were provided" << std::endl;
			showHelp();
            throw std::runtime_error("Incomplete arguments provided !") ;
        }
    }

    void startCompilation() {
        using namespace std::chrono_literals;
        using namespace std::this_thread;
        /*
         * command line argument: MmQLC.exe ~i $path to mmql file$ ~o $path to generate ans file$
         * here
         * argv[0] = MmQLC.exe [Program Name]
         * argv[1] = ~i [Input handler]
         * argv[2] = $path to mmql file$ [must not have spaces]
         * argv[3] = ~o [output handler]
         * argv[4] = $path to generate ans file$ [must not have spaces]
         */
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
        } catch (const std::runtime_error& re)
        {
            throw re;
        }
        std::cout << "\nCompiling queries .....\n";

        // Optional UI element to show progress

        hue::reset();
        std::filesystem::path out(outputFilePath);
        try {
            saveAnswers(outputFilePath);
        } catch(const std::runtime_error &re)
        {
            throw re;
        }
        for (int i = 0; i <= 100; i += 2) {
            std::cout << hue::green << "\rDone: [" << i << " %]";
            sleep_for(25ms);
        }
        std::cout << hue::reset;
        if (out.parent_path() == "") {
            outputFilePath = std::filesystem::current_path().string() + "\\";
        } else { outputFilePath = out.parent_path().string() + "\\"; }
        std::cout << "\nCompilation Done!\nAnswer file has been successfully generated at " << outputFilePath << std::endl;
    }

    ~compileMmQL() {
        delete[] argv;
    }
};
#endif //MMQLC_COMPILER_HPP
