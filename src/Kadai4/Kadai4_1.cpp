//
//  Kadai4_1.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2016/01/04.
//
//

#define N 30
#define R 300.0 //描画倍率

#include "Kadai4_1.h"

ofMesh graphMesh; //補間点の描画用
vector<double> samplePoints; //標本点

ofMesh fMesh;

void Kadai4_1::setup(){

    //標本点の生成
    for(int i = 0; i <= N; i++){
        //4.1.1
        samplePoints.push_back(-1.0 + 2.0 * i / double(N));
        
        //4.1.2
        //samplePoints.push_back(cos((2.0 * (N - i) + 1.0) * PI / (2.0 * N + 2.0)));
    }
    
    //補間 4.1
    graphMesh.clear();
    graphMesh.setMode(OF_PRIMITIVE_POINTS);
    //fMesh.clear();
    //fMesh.setMode(OF_PRIMITIVE_POINTS);
    
    for(int j = 0; j <= 5000; j++){
        double Lx = 0;
        double x = - 1.0 + 2.0 * double(j) / 5000.0;
        for(int i = 0; i <= N; i++){
            Lx += f(samplePoints[i]) * l(i, x);
        }
        graphMesh.addVertex(ofPoint(x * R, -Lx * R)); //グラフ表示のためyを反転
        //fMesh.addVertex(ofPoint(x * R, f(x) * R));
    }
    
    ofBackground(255);
}

double Kadai4_1::f(double x){
    return 1.0 / (1.0 + 25.0 * x * x);
}

//標本点がすでに入ってることを前提。良くない。
double Kadai4_1::l(int i, double x){
    double result = 1.0;
    for(int k = 0; k <= N; k++){
        if(k == i) continue;
        result *= (x - samplePoints[k]);
        result /= (samplePoints[i] - samplePoints[k]);
    }
    return result;
}

void Kadai4_1::update(){}

void Kadai4_1::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(0);
    graphMesh.draw();
    //ofSetColor(255, 0, 0);
    //fMesh.draw();
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-ofGetWidth()/2, 0, ofGetWidth()/2, 0);
    ofDrawBitmapString("x", ofPoint(30,-220));
    for(float i = -1.0; i < 1.1; i+= 0.1){
        ofDrawBitmapString(ofToString(i), ofPoint(10,-i * R));
        ofLine(-5, -i * R, 5, -i * R);
    }
    
    ofDrawBitmapString("f or L", ofPoint(220,20));
    for(float p = - 1.0; p <= 1.0; p+= 0.1){
        ofDrawBitmapString(ofToString(p), ofPoint(p * R,-10));
        ofLine(p * R,-5, p * R,5);
    }
    
    
    ofPopMatrix();
}

