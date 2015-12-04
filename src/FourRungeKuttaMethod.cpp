//
//  FourRungeKuttaMethod.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/04.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "FourRungeKuttaMethod.h"

//--------------------------------------
//Yn+1 = Yn + h/6(k1 + 2*k2 + 2*k3 + k4)
//今回は微分にtがないのでfは実際tに関係なし
//k1 = f(tn,Yn)
//k2 = f(tn+h/2, Yn+h/2 * k1)
//k3 = f(tn+h/2, Yn+h/2 * k2)
//k4 = f(tn+h, Yn + h * k3)
//-------------------------------------
void FourRungeKuttaMethod::update(){
    
    double V_k1 = getDV_DT(); //-> (-K/M) * u
    double V_k2 = getDV_DT() + deltaT / 2.0 * (-K/M) * getDU_DT(); // -> (-K/M) * u + deltaT /2.0 * (-K/M) * v
    double V_k3 = getDV_DT() + deltaT / 2.0 * ((-K/M) * getDU_DT() + deltaT / 2.0 * (-K/M) * getDV_DT()); //-> (-K/M) * u + deltaT /2.0 * ((-K/M) * v + deltaT / 2.0 * (-K/M) * (-K/M) *u)
    double V_k4 = getDV_DT() + deltaT  * ((-K/M) * getDU_DT() + deltaT /2.0 * ((-K/M) * getDV_DT() + deltaT / 2.0 * (-K/M) * (-K/M) * getDU_DT()));
    double U_k1 = getDU_DT(); //->v
    double U_k2 = getDU_DT() + deltaT / 2.0 * getDV_DT(); //-> v + deltaT /2.0 * (-K/M)*u
    double U_k3 = getDU_DT() + deltaT / 2.0 * (getDV_DT() + deltaT / 2.0 * (-K/M) * getDU_DT()); //->v + deltaT /2.0 * ((-(K/M) * u + deltaT / 2.0 * (-K/M) * v) )
    double U_k4 = getDU_DT() + deltaT  * (getDV_DT() + deltaT /2.0 * ((-(K/M) * getDU_DT() + deltaT / 2.0 * (-K/M) * getDV_DT()) ));
    u = u + deltaT/6.0 * (U_k1 + 2.0 * U_k2 + 2.0 * U_k3 + U_k4);
    v = v + deltaT/6.0 * (V_k1 + 2.0 * V_k2 + 2.0 * V_k3 + V_k4);
    time += deltaT;
}

double FourRungeKuttaMethod::getDU_DT(){
    return this->v;
}

double FourRungeKuttaMethod::getDV_DT(){
    return - (K / M) * this->u;
}

double FourRungeKuttaMethod::SolutionU(double t){
    return cos(OMEGA * t);
}
double FourRungeKuttaMethod::SolutionV(double t){
    return - OMEGA * sin(OMEGA * t);
}

void FourRungeKuttaMethod::reset(){
    time = 0;
    v = 0;
    u = 1.0;
}