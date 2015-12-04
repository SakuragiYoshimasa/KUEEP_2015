//
//  PropagationOfPulse.hpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/03.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#ifndef PropagationOfPulse_h
#define PropagationOfPulse_h

#include "Includer.h"

#define C 2.0

class PropagationOfPulse {
public:
    PropagationOfPulse(bool bSaveData , double N = 200, double deltaT = 0.001, double deltaX = 0.005, double Td = 0.1);
    //---------------------------
    //Settings
    //---------------------------
    bool bSaveData;
    double N;
    double deltaT;
    double deltaX;
    double Td; //パルスの時間幅
    double myu;
    string fileName;
    
    //---------------------------
    //Variances
    //---------------------------
    int frameCounter; //k
    vector<double> uk;
    vector<double> ukMinusOneStep;
    vector<double> ukMinusTwoStep;
    
    //---------------------------
    //Functions
    //---------------------------
    void saveFileAsCsv();
    void update(); //next step
};
#endif
