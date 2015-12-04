//
//  HeunMethod.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/04.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "HeunMethod.h"

HeunMethod::HeunMethod(){
    this->uvt.v = 0.0;
    this->uvt.u = 1.0;
    this->uvt.t = 0.0;
}

//--------------------------------------
//Yn+1 = Yn + h/2(k1+k2)
//k1 = f(tn,Yn)
//k2 = f(tn+1,Yn+hk1)
//-------------------------------------
void HeunMethod::update(){
    
    UVT afterOneStepUVT;
    double V_k1 = getDV_DT();
    double U_k1 = getDU_DT();
    double V_k2 = getDV_DT() + deltaT * (-K/M) * getDU_DT();    //v_k2 = f(tn+1,Yn+h*k1) = f(tn+1,v + deltaT *  (-k/M)u)
    double U_k2 = getDU_DT() + deltaT * getDV_DT(); //u_k2 = f(tn+1,Yn+h*k1) = f(tn+1,v + deltaT * v)
    u = u + deltaT/2.0 * (U_k1 + U_k2);
    v = v + deltaT/2.0 * (V_k1 + V_k2);
    time += deltaT;
}

double HeunMethod::getDU_DT(){
    return this->v;
}

double HeunMethod::getDV_DT(){
    return - (K / M) * this->u;
}

double HeunMethod::SolutionU(double t){
    return cos(OMEGA * t);
}
double HeunMethod::SolutionV(double t){
    return - OMEGA * sin(OMEGA * t);
}

void HeunMethod::reset(){
    time = 0;
    v = 0;
    u = 1.0;
}