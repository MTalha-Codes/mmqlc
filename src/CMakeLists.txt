set(MAIN main.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies)
set(
        HEADERS
        headers/mmqlc.ui.hpp
        headers/mmqlc.calculator.hpp
        headers/mmqlc.parser.hpp
        headers/mmqlc.tokenizer.hpp
        headers/mmqlc.filesystem.hpp
        headers/mmqlc.multiprecision.hpp
        headers/mmqlc.functions.hpp
        headers/mmqlc.constants.hpp
        headers/mmqlc.regex.hpp
)
add_executable(mmqlc ${MAIN} ${HEADERS})
