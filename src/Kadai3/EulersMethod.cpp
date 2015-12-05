//
//  EulersMethod.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/03.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "EulersMethod.h"

void EulersMethod::update(){
    double U = u + deltaT * getDU_DT();
    double V = v + deltaT * getDV_DT();
    u = U;
    v = V;
    time += deltaT;
}

double EulersMethod::getDU_DT(){
    return this->v;
}

double EulersMethod::getDV_DT(){
    return - (K / M) * this->u;
}

double EulersMethod::SolutionU(double t){
    return cos(OMEGA * t);
}
double EulersMethod::SolutionV(double t){
    return - OMEGA * sin(OMEGA * t);
}

void EulersMethod::reset(){
    time = 0;
    v = 0;
    u = 1.0;
}