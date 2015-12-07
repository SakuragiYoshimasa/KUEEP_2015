//
//  FourRungeKuttaMethod.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/04.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "FourRungeKuttaMethod.h"

FourRungeKuttaMethod::FourRungeKuttaMethod(){
    this->uv.u = 1.0;
    this->uv.v = 0.0;
}

//--------------------------------------
//Yn+1 = Yn + h/6(k1 + 2*k2 + 2*k3 + k4)
//今回は微分にtがないのでfは実際tに関係なし
//k1 = f(tn,Yn)
//k2 = f(tn+h/2, Yn+h/2 * k1)
//k3 = f(tn+h/2, Yn+h/2 * k2)
//k4 = f(tn+h, Yn + h * k3)
//-------------------------------------
void FourRungeKuttaMethod::update(){
    UV k1 = uv.getDY_DT();
    UV k2 = (uv + k1 * (deltaT / 2.0)).getDY_DT();
    UV k3 = (uv + k2 * (deltaT / 2.0)).getDY_DT();
    UV k4 = (uv + k3 * deltaT).getDY_DT();
    uv = uv + (k1 + k2 * 2.0 + k3 * 2.0 + k4) * (deltaT / 6.0);
    time += deltaT;
}

double FourRungeKuttaMethod::SolutionU(double t){
    return cos(OMEGA * t);
}
double FourRungeKuttaMethod::SolutionV(double t){
    return - OMEGA * sin(OMEGA * t);
}

void FourRungeKuttaMethod::reset(){
    time = 0;
    this->uv.u = 1.0;
    this->uv.v = 0.0;
}