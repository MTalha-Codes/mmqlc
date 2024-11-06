/*
 * Filename: functions.hpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repo: mmqlc
 * Copyright(C) - 2024
 * */

// This file contains those functions that are not found in boost or c++ standard library
#ifndef MMQLC_FUNCTIONS_HPP
#define MMQLC_FUNCTIONS_HPP

#include "mmqlc.constants.hpp"
#include <cmath>
#include "mmqlc.multiprecision.hpp"


namespace math::functions::imported_from_boost {
    using boost::math::tgamma;
}

namespace math::functions::real::trig {
    inline double50 cot(const double50 &arg) {
        double50 tang = tan(arg);
        double50 coT = 1 / tang;
        return coT;
    }

    inline double50 sec(const double50 &arg) {
        double50 COS = cos(arg);
        double50 SEC = 1 / COS;
        return SEC;
    }

    inline double50 csc(const double50 &arg) {
        double50 SIN = sin(arg);
        double50 CSC = 1 / SIN;
        return CSC;
    }

    inline double50 acot(const double50 &arg) {
        double50 suitable_arg(1 / arg);
        double50 acotngt = atan(suitable_arg);
        return acotngt;
    }

    inline double50 asec(const double50 &arg) {
        double50 suitable_arg(1 / arg);
        double50 asecnt = acos(suitable_arg);
        return asecnt;
    }

    inline double50 acsc(const double50 &arg) {
        double50 suitable_arg(1 / arg);
        double50 cscnt = asin(suitable_arg);
        return cscnt;
    }

    inline double50 coth(const double50 &arg) {
        double50 tangh = tanh(arg);
        double50 coTh = 1 / tangh;
        return coTh;
    }

    inline double50 sech(const double50 &arg) {
        double50 COSh = cosh(arg);
        double50 SECh = 1 / COSh;
        return SECh;
    }

    inline double50 csch(const double50 &arg) {
        double50 SINh = sinh(arg);
        double50 CSCh = 1 / SINh;
        return CSCh;
    }

    inline double50 acoth(const double50 &arg) {
        double50 suitable_arg(1 / arg);
        double50 acotngth = atanh(suitable_arg);
        return acotngth;
    }

    inline double50 asech(const double50 &arg) {
        double50 suitable_arg(1 / arg);
        double50 asecnth = acosh(suitable_arg);
        return asecnth;
    }

    inline double50 acsch(const double50 &arg) {
        double50 suitable_arg(1 / arg);
        double50 cscnth = asinh(suitable_arg);
        return cscnth;
    }
}

namespace math::functions::complex::trig {
    inline complex50 cot(const complex50 &arg) {
        complex50 tang = std::tan(arg);
        complex50 coT = one / tang;
        return coT;
    }

    inline complex50 sec(const complex50 &arg) {
        complex50 COS = std::cos(arg);
        complex50 SEC = one / COS;
        return SEC;
    }

    inline complex50 csc(const complex50 &arg) {
        complex50 SIN = std::sin(arg);
        complex50 CSC = one / SIN;
        return CSC;
    }

    inline complex50 acot(const complex50 &arg) {
        complex50 suitable_arg(one / arg);
        complex50 acotngt = std::atan(suitable_arg);
        return acotngt;
    }

    inline complex50 asec(const complex50 &arg) {
        complex50 suitable_arg(one / arg);
        complex50 asecnt = std::acos(suitable_arg);
        return asecnt;
    }


    inline complex50 acsc(const complex50 &arg) {
        complex50 suitable_arg(one / arg);
        complex50 cscnt = std::asin(suitable_arg);
        return cscnt;
    }

    inline complex50 coth(const complex50 &arg) {
        complex50 tangh = std::tanh(arg);
        complex50 coTh = one / tangh;
        return coTh;
    }

    inline complex50 sech(const complex50 &arg) {
        complex50 COSh = std::cosh(arg);
        complex50 SECh = one / COSh;
        return SECh;
    }

    inline complex50 csch(const complex50 &arg) {
        complex50 SINh = std::sinh(arg);
        complex50 CSCh = one / SINh;
        return CSCh;
    }

    inline complex50 acoth(const complex50 &arg) {
        complex50 suitable_arg(one / arg);
        complex50 acotngth = std::atanh(suitable_arg);
        return acotngth;
    }

    inline complex50 asech(const complex50 &arg) {
        complex50 suitable_arg(one / arg);
        complex50 asecnth = std::acosh(suitable_arg);
        return asecnth;
    }

    inline complex50 acsch(const complex50 &arg) {
        complex50 suitable_arg(one / arg);
        complex50 cscnth = std::asinh(suitable_arg);
        return cscnth;
    }
}

#endif //MMQLC_FUNCTIONS_HPP
