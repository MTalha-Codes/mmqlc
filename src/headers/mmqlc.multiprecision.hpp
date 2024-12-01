/*
 * Filename: mmqlc.multiprecision.hpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repository: mmqlc
 * Copyright(C) - 2024
 * */

#ifndef MMQLC_MULTIPRECISION_HPP
#define MMQLC_MULTIPRECISION_HPP

#include <complex>
#include <boost/multiprecision/mpfr.hpp>

namespace mp = boost::multiprecision; // namespace alias for boost::multiprecision;
using float1000 = mp::mpfr_float_1000; // our primary datatype class depending on mpfr
using complex_float1000 = std::complex<float1000>; // our complex number class with mpfr_1000 digits backend;
#endif
