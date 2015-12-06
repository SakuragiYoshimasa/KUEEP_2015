//
//  HeunMethod.hpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/04.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#ifndef HeunMethod_h
#define HeunMethod_h

#include "Includer.h"
#include "UV.cpp"

class HeunMethod {
public:
    HeunMethod();
    
    double time = 0;
    double deltaT = 2* M_PI/ (64*OMEGA);
    UV uv;
    
    void update();
    void reset();
    double SolutionV(double t);
    double SolutionU(double t);
};
#endif
