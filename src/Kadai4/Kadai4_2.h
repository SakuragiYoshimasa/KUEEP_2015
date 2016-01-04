//
//  Kadai4_2.hpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2016/01/04.
//
//

#pragma once

#include "ofMain.h"
#include "Includer.h"

class Kadai4_2 : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    double f(double x);
    double I();
};

