#######################################################################################################################
set(SOURCE main.cpp) # main function is here
set(FORKED_LIB color.hpp) # downloaded from github
set(MY_HEADERS fileManager.hpp queryTokenizer.hpp calcAnswer.hpp compiler.hpp
        queryParser.hpp) # my own headers
#######################################################################################################################
add_executable(MmQLC ${SOURCE} ${FORKED_LIB} ${MY_HEADERS}) # name of executable
#######################################################################################################################
