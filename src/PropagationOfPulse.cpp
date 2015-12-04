//
//  PropagationOfPulse.cpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/03.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#include "PropagationOfPulse.h"

PropagationOfPulse::PropagationOfPulse(bool bSaveData, double N, double deltaT, double deltaX, double Td){
    this->bSaveData = bSaveData;
    this->N = N;
    this->deltaT = deltaT;
    this->deltaX = deltaX;
    this->Td = Td;
    this->myu = C * C * deltaT * deltaT / ( deltaX * deltaX );
    this->uk = *new vector<double>(N);
    this->ukMinusOneStep = *new vector<double>(N);;
    this->ukMinusTwoStep = *new vector<double>(N);;
    this->frameCounter = 0;
}

void PropagationOfPulse::update(){
    //------------------------
    //遷移処理
    //------------------------
    ukMinusTwoStep = ukMinusOneStep;
    ukMinusOneStep = uk;
    uk = *new vector<double>(N);
   
    //------------------------
    // i = 0 パルスの発生
    //------------------------
    if(float(frameCounter * deltaT) < Td){
        uk.at(0) = 1.0;
    }else{
        uk.at(0) = 0;
    }
    frameCounter+=1;
    if(frameCounter == 1) return;
    //------------------------
    // i = N - 1 固定端
    //------------------------
    uk.at(N-1) = - ukMinusTwoStep.at(N-1) + myu * ukMinusOneStep.at(N-2) + 2.0 * (1.0 - myu) * ukMinusOneStep.at(N-1);
    
    //------------------------
    // i = N - 1 自由端
    //------------------------
    //uk.at(N-1) = - ukMinusTwoStep.at(N-1) + myu * ukMinusOneStep.at(N-2) + (2.0 - myu) * ukMinusOneStep.at(N-1);
    
    
    //------------------------
    //1 ~ N -2
    //------------------------
    for(int i = 1; i < N - 1; i++){
        uk.at(i) = - ukMinusTwoStep.at(i) + myu * ukMinusOneStep.at(i - 1) + 2.0 * (1.0 - myu) * ukMinusOneStep.at(i) + myu * ukMinusOneStep.at(i + 1);
    }
    
}