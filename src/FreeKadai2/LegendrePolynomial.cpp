//
//  LegendrePolynomial.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2015/12/11.
//
//

#include "LegendrePolynomial.h"

double LegendrePolynomial::getValue(int n, double x){
    if(n == 0) return 1;
    if(n == 1) return x;
    return ((2 * n - 1) * x * LegendrePolynomial::getValue(n - 1, x) - (n - 1) * LegendrePolynomial::getValue(n - 2, x))/ double(n);
}

double LegendrePolynomial::getDifferentialValue(int n, double x){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return ((2 * n -1) * (x * LegendrePolynomial::getDifferentialValue(n - 1, x) + LegendrePolynomial::getValue(n - 1, x)) - (n - 1) * LegendrePolynomial::getDifferentialValue(n - 2, x)) / double(n);
    return 0;
}

vector<double> LegendrePolynomial::getZeroPoint(int n){
    vector<double> result = *new vector<double>(0);
    if(n == 0) return result;
    if(n == 1){
        result.push_back(0);
        return result;
    }
    
    vector<double> oneStepMinusResult = LegendrePolynomial::getZeroPoint(n - 1);
    oneStepMinusResult.insert(oneStepMinusResult.begin(), -1);
    oneStepMinusResult.insert(oneStepMinusResult.end(), 1);
    
    //---------------------------------------------
    //Q2
    //---------------------------------------------
    /*for(int i = 0; i < n; i++){
        double minRangeX = oneStepMinusResult.at(i);
        double maxRangeX = oneStepMinusResult.at(i+1);
        double a = minRangeX;
        double b = maxRangeX;
        double c;
        while (b - a > eps) {
            c = (a + b) / 2.0;
            if(LegendrePolynomial::getValue(n,a) * LegendrePolynomial::getValue(n,c) < 0){
                b = c;
            }else{
                a = c;
            }
        }
        result.push_back(c);
    }*/
    

    
    //---------------------------------------------
    //Q3
    //---------------------------------------------
    /*for(int i = 0; i < n; i++){
        double currentX = (oneStepMinusResult.at(i) + oneStepMinusResult.at(i + 1)) / 2.0;
        for(int t = 0; t < 10; t++){
            currentX = - LegendrePolynomial::getValue(n, currentX) / LegendrePolynomial::getDifferentialValue(n, currentX) + currentX;
        
        }
        result.push_back(currentX);
    }*/
    


    cout << "ZeroPoint:" << n << endl;
    for(int i = 0; i < result.size(); i++){
        cout <<  result.at(i) << endl;
    }
    return result;
}