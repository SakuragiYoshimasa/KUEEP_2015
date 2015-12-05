//
//  LorenzAttractor.hpp
//  KUEEP
//
//  Created by SakuragiYoshimasa on 2015/12/05.
//  Copyright © 2015年 SakuragiYoshimasa. All rights reserved.
//

#ifndef LorenzAttractor_h
#define LorenzAttractor_h
#include "Includer.h"

#define L_RO 10.0
#define L_B 8.0/3.0
#define L_R 28.0

class LorenzAttractor {
public:
    LorenzAttractor();
    double time = 0;
    double deltaT = 0.001;
    vector<double> y;
    
    void update();
    void reset();
    
    vector<double> getDY_DT(vector<double> yvec);
    vector<double> calcNextY(vector<double> k1,vector<double> k2,vector<double> k3,vector<double> k4);
    vector<double> ampVec(vector<double> v, double amp){
        vector<double> result = *new vector<double>;
        for(int i = 0; i < v.size(); i++){
            result.push_back(v[i] * amp);
        }
        return result;
    }
    
    vector<double> plusVec(vector<double> v0, vector<double> v1){
        vector<double> result = *new vector<double>;
        for(int i = 0; i < v0.size(); i++){
            result.push_back(v0[i] + v1[i]);
        }
        return result;
    }
};


#endif /* LorenzAttractor_hpp */
