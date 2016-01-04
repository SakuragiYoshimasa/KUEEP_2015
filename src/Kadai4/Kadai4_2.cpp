//
//  Kadai4_2.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2016/01/04.
//
//
#define xA 0.0
#define xB 1.0
#define R 40.0
#define MAXk 15

#include "Kadai4_2.h"

ofMesh Emesh; //誤差表示用のmesh

double Kadai4_2::f(double x){
    return pow(x, 19);
}

double Kadai4_2::I(){
    return 1.0 / 20.0; //積分の真値をreturn
}

void Kadai4_2::setup(){
    Emesh.clear();
    Emesh.setMode(OF_PRIMITIVE_POINTS);
    
    for(int k = 1; k < MAXk; k++){
        int n = int(pow(2.0, k));
        double result = 0.0;
        double step = (xB - xA) / double(n);
        
        //複合台形公式
        /*result += f(xA);
        result += f(xB);
        for(int i = 1; i < n; i++){
            
            result += 2.0 * f(xA + step * i);
        }
        result *= (xB - xA) / (double(n) * 2.0) ;
        */
        
        //複合シンプソン公式
        /*result += f(xA);
        result += f(xB);
        for(int i = 1; i < n; i++){
            if(i % 2 == 1){
                result += 4.0 * f(xA + step * i);
            }else{
                result += 2.0 * f(xA + step * i);
            }
        }
        result *= (xB - xA) / (double(n) * 3.0) ;
        */
        cout << "k" << k << " :" << result << endl;
        Emesh.addVertex(ofPoint(k * R, (I() - result) * R * 10));
    }
    
    ofBackground(255);
    glPointSize(5.0);
}

void Kadai4_2::update(){}

void Kadai4_2::draw(){
    
    ofPushMatrix();
    ofTranslate(50, ofGetHeight()/2);
    ofSetColor(0);
    Emesh.draw();
    
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-50, 0, ofGetWidth() - 50, 0);
    ofDrawBitmapString("k", ofPoint(220,20));
    for(float i = 0; i < MAXk; i+= 1){
        ofDrawBitmapString(ofToString(i), ofPoint(i * R,20));
        ofLine(-i * R, - 5, -i * R, 5);
    }
    
    ofDrawBitmapString("E", ofPoint(30,-220));
    for(float p = 0; p <= 0.5; p+= 0.05){
        ofDrawBitmapString(ofToString(p), ofPoint(-10, -p * R * 10));
        ofLine(-5, -p * R * 10, 5, -p * R * 10);
    }
    
    
    ofPopMatrix();
}