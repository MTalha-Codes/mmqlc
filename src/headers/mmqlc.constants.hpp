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
const double50 Pi(3.141592653589793238462643383279);
const double50 ONE(1);
const double50 ZERO(0);
const complex50 one(ONE, ZERO);
const complex50 zero(ZERO, ZERO);
const double50 infinity(std::numeric_limits<double>::infinity());
const double50 NaN(std::numeric_limits<double>::quiet_NaN());
#endif
