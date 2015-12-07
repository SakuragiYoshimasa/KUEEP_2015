//
//  EulersMethod.hpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/03.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

//------------------------------------
//課題3.2.1
//------------------------------------
#ifndef EulersMethod_h
#define EulersMethod_h

#include "Includer.h"
#include "UV.cpp"

class EulersMethod {
public:
    EulersMethod();
    
    double time = 0;
    double deltaT = 2* M_PI/ (64*OMEGA);
    UV uv;
    
    void update();
    void reset();
    double SolutionV(double t);
    double SolutionU(double t);
};
#endif
