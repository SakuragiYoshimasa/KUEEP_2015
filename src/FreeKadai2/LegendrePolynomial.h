//
//  LegendrePolynomial.hpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2015/12/11.
//
//

#ifndef LegendrePolynomial_h
#define LegendrePolynomial_h

#include "Includer.h"
#define eps 1e-15

class LegendrePolynomial {
public:
    static double getValue(int n, double x);
    static double getDifferentialValue(int n ,double x);
    static vector<double> getZeroPoint(int n);
};
#endif
