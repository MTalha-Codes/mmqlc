/*
 * Filename: constants.hpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repo: mmqlc
 * Copyright(C) - 2024
 * */

// This file contains some mathematical constants for type double50 and complex50

#ifndef MMQLC_CONSTANTS_HPP
#define MMQLC_CONSTANTS_HPP
#include <limits>
#include "mmqlc.multiprecision.hpp"
const float1000 Pi(3.141592653589793238462643383279);
const float1000 ONE(1);
const float1000 ZERO(0);
const complex_float1000 one(ONE, ZERO);
const complex_float1000 zero(ZERO, ZERO);
const float1000 infinity(std::numeric_limits<double>::infinity());
const float1000 NaN(std::numeric_limits<double>::quiet_NaN());
#endif
