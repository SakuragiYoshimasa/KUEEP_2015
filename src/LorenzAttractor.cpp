//
//  LorenzAttractor.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/05.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "LorenzAttractor.h"

LorenzAttractor::LorenzAttractor(){
    y = *new vector<double>(3);
    y[0] =1.0;
    y[1] = 0;
    y[2] =20.0;
}

//--------------------------------------
//Yn+1 = Yn + h/6(k1 + 2*k2 + 2*k3 + k4)
//k1 = f(tn,Yn)
//k2 = f(tn+h/2, Yn+h/2 * k1)
//k3 = f(tn+h/2, Yn+h/2 * k2)
//k4 = f(tn+h, Yn + h * k3)
//-------------------------------------
void LorenzAttractor::update(){
    vector<double> k1 = getDY_DT(this->y);
    vector<double> k2 = getDY_DT(plusVec(this->y, ampVec(k1, (deltaT / 2.0))));
    vector<double> k3 = getDY_DT(plusVec(this->y, ampVec(k2, (deltaT / 2.0))));
    vector<double> k4 = getDY_DT(plusVec(this->y, ampVec(k3, deltaT)));
    y = calcNextY(k1, k2, k3, k4);
    time += deltaT;
}

vector<double> LorenzAttractor::getDY_DT(vector<double> yvec){
    vector<double> v = *new vector<double>(3);
    v[0] = L_RO * (yvec[1] - yvec[0]);
    v[1] = L_R * yvec[0] - yvec[1] - yvec[0] * yvec[2];
    v[2] = yvec[0] * yvec[1] - L_B * yvec[2];
    return v;
}

void LorenzAttractor::reset(){
    time = 0;
    y = *new vector<double>(3);
    y[0] =1.0;
    y[1] = 0;
    y[2] =20.0;
}

vector<double> LorenzAttractor::calcNextY(vector<double> k1,vector<double> k2,vector<double> k3,vector<double> k4){
    vector<double> diff = ampVec(plusVec(plusVec(k1, ampVec(k2, 2.0)),plusVec(ampVec(k3, 2.0),k4)), deltaT/6.0);
    return plusVec(y, diff);
  //  y = y + (k1 +  +  + k4) * (deltaT / 6.0);
};