//
//  FourRungeKuttaMethod.hpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/04.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#ifndef FourRungeKuttaMethod_hpp
#define FourRungeKuttaMethod_hpp

#include "Includer.h"
#include "UV.cpp"

class FourRungeKuttaMethod {
public:
    FourRungeKuttaMethod();
    
    double time = 0;
    double deltaT = 2* M_PI/ (64*OMEGA);
    double v = 0.0;
    double u = 1.0;
    
    UV uv;
    
    void update();
    void reset();
    double SolutionV(double t);
    double SolutionU(double t);
private:
    double getDV_DT();
    double getDU_DT();
};
#endif