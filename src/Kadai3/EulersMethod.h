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
#define K 3.0
#define M 5.0
#define OMEGA sqrt(K/M)

class EulersMethod {
public:
    double time = 0;
    double deltaT = 2* M_PI/ (64*OMEGA);
    double v = 0.0;
    double u = 1.0;
    
    void update();
    void reset();
    double SolutionV(double t);
    double SolutionU(double t);
private:
    double getDV_DT();
    double getDU_DT();
};
#endif
