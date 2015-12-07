//
//  EulersMethod.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/03.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "EulersMethod.h"

EulersMethod::EulersMethod(){
    this->uv.u = 1.0;
    this->uv.v = 0.0;
}

void EulersMethod::update(){
    uv = uv + uv.getDY_DT() * deltaT;
    time += deltaT;
}


double EulersMethod::SolutionU(double t){
    return cos(OMEGA * t);
}
double EulersMethod::SolutionV(double t){
    return - OMEGA * sin(OMEGA * t);
}

void EulersMethod::reset(){
    time = 0;
    this->uv.u = 1.0;
    this->uv.v = 0.0;
}