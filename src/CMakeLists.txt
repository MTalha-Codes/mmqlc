set(MAIN main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
set(
        HEADERS
        headers/mmqlc.hpp
        headers/calculator.hpp
        headers/parser.hpp
        headers/tokenizer.hpp
        headers/filesystem.hpp
        headers/multiprecision.hpp
        headers/functions.hpp
        headers/constants.hpp
)
add_executable(mmqlc ${MAIN} ${HEADERS})
