//
//  FreeKadai2.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2015/12/11.
//
//

#include "FreeKadai2.h"

//----------------------------
//Q1
//----------------------------
ofMesh q1Mesh;

//--------------------------------------------------------------
void FreeKadai2::setup(){
    //----------------------------
    //Q1
    //----------------------------
    ofBackground(255);
    q1Mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    for(double x = -1.0; x <= 1.0; x += 0.001){
        q1Mesh.addVertex(ofPoint(x * 400, LegendrePolynomial::getValue(10, x) * 400));
    }
    glPointSize(6.0);
    
    //----------------------------
    //Q2
    //----------------------------
    LegendrePolynomial::getZeroPoint(10);
}

//--------------------------------------------------------------
void FreeKadai2::update(){
}


//--------------------------------------------------------------
void FreeKadai2::draw(){
    
    //----------------------------
    //Q1
    //----------------------------
    ofPushMatrix();
    ofSetColor(0);
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    q1Mesh.draw();
    
    
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-ofGetWidth()/2, 0, ofGetWidth()/2, 0);
    
    ofDrawBitmapString("Pn(x)", ofPoint(40,-220));
    for(float i = -1; i <= 1; i+= 0.1){
        ofDrawBitmapString(ofToString(i), ofPoint(10,-i * 400));
        ofLine(-5, -i * 400, 5, -i * 400);
    }
    ofDrawBitmapString("X", ofPoint(220,0));
    for(float i = -1; i <= 1; i+= 0.1){
        ofDrawBitmapString(ofToString(i), ofPoint(i * 400,-10));
        ofLine(i * 400,-5, i * 400,5);
    }
    
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void FreeKadai2::keyPressed(int key){
    
}