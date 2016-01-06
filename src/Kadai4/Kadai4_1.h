//
//  Kadai4_1.h
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2016/01/04.
//
//

#pragma once

#include "ofMain.h"
#include "Includer.h"


//ラグランジュ補間
//Ln(x) = Sigma(fili(x))
//lii(x) = (8.5)

class Kadai4_1 : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    double f(double x); // -1 <= x <= 1
    double l(int i, double x, int N); //補間用の関数
    
};
