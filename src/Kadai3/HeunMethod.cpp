//
//  HeunMethod.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/04.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "HeunMethod.h"

HeunMethod::HeunMethod(){
    this->uv.u = 1.0;
    this->uv.v = 0.0;
}

//--------------------------------------
//Yn+1 = Yn + h/2(k1+k2)
//k1 = f(tn,Yn)
//k2 = f(tn+1,Yn+hk1)
//-------------------------------------
void HeunMethod::update(){

    UV k1 = uv.getDY_DT();
    UV k2 = (uv + k1 * deltaT).getDY_DT();
    uv = uv + (k1 + k2) * (deltaT / 2.0);
    time += deltaT;
}

double HeunMethod::SolutionU(double t){
    return cos(OMEGA * t);
}
double HeunMethod::SolutionV(double t){
    return - OMEGA * sin(OMEGA * t);
}

void HeunMethod::reset(){
    time = 0;
//    v = 0;
//    u = 1.0;
    this->uv.u = 1.0;
    this->uv.v = 0.0;

}