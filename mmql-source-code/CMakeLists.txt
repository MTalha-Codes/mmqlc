################################################################################################
set(SOURCE main.cpp) # main function is here
set(HEADER ReadView__WriteSave.hpp) # class to load and view answer
set(NECESSARY_HEADERS includes.hpp) # necessary #includes<>
set(FORKED_LIB color.hpp) # downloaded from github
################################################################################################
add_executable(MmQL ${SOURCE} ${HEADER} ${FORKED_LIB} ${NECESSARY_HEADERS}) # exe name should be MmQL
################################################################################################