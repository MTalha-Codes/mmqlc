#include "compiler.hpp"
#include <memory> // for unique_ptr a smart pointer that handles new and delete by itself !

int main(int argc, char *argv[]) {
    std::unique_ptr<compileMmQL> compiler;
      try
      {
          compiler = std::make_unique<compileMmQL>(argc, argv);
              try
                 {
                     compiler->startCompilation();
                 }
                 catch (const std::runtime_error &re) {
                     std::cerr << "Exception Thrown: " << hue::red << re.what() << hue::reset << std::endl;
                     return -1;
                 }
      }
      catch (const std::runtime_error &re)
      {
          std::cerr << "Exception Thrown: "  << hue::red << re.what() << hue::reset << std::endl;
		  std::cout << hue::light_green << "\nPress Any Key To Quit MmQLC" << hue::reset <<  std::endl;
	  std::cin.get();
          return -1;
      }
    return 0;
}
