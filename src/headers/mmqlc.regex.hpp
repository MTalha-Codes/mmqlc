#ifndef MMQLC_REGEX_HPP
#define MMQLC_REGEX_HPP
#include <regex>

namespace  regex::real {
    const std::regex singlePattern_noVariable(R"((\w+)\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
    const std::regex doublePattern_noVariable(R"((\w+)\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?),(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
    const std::regex realNumberRegex(R"((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
}

namespace regex::complex {
    const std::regex singlePattern_noVariable(R"((\w+)\s((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    const std::regex doublePattern_noVariable(R"((\w+)\s((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)),((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    const std::regex complexNumberRegex(R"(((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
}
#endif //MMQLC_REGEX_HPP
