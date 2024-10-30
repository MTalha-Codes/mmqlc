#ifndef MMQLC_ARBITRARY_WRAPPER_BOOST_HPP
#define MMQLC_ARBITRARY_WRAPPER_BOOST_HPP

#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/cpp_dec_float.hpp>

using namespace boost::multiprecision;
using double50 = cpp_dec_float_50;
using complex50 = std::complex<double50>;
#endif
