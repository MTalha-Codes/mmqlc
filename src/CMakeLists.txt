set(MAIN main.cpp)
set(GMP_MPFR_FMT_LIB_DIR "/usr/lib")
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
        headers/mmqlc.variables.hpp
)

add_executable(MmQLC ${MAIN} ${HEADERS})

find_library(GMP_LIB gmp PATHS ${GMP_MPFR_FMT_LIB_DIR} NO_DEFAULT_PATH)
find_library(GMPXX_LIB gmpxx PATHS ${GMP_MPFR_FMT_LIB_DIR} NO_DEFAULT_PATH)
find_library(MPFR_LIB mpfr PATHS ${GMP_MPFR_FMT_LIB_DIR} NO_DEFAULT_PATH)
find_library(FMT_LIB fmt PATHS ${GMP_MPFR_FMT_LIB_DIR} NO_DEFAULT_PATH)

target_link_libraries(MmQLC ${GMP_LIB} ${GMPXX_LIB} ${MPFR_LIB} ${FMT_LIB})
