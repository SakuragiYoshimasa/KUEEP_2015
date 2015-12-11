//
//  csvOperator.hpp
//  ofSplineSample
//
//  Created by SakuragiYoshimasa on 2015/11/01.
//
//

#ifndef csvOperator_h
#define csvOperator_h

#include "ofMain.h"

class csvOperator {
public:
    static void savePoints(string fileName, vector<ofVec3f> points);
    static vector<ofVec3f> loadPoints(string fileName);
};
#endif
