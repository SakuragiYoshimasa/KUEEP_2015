//
//  Kadai3_3.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2015/12/05.
//
//
#include "Kadai3_3.h"
#include "LorenzAttractor.h"

LorenzAttractor * lorenz;
ofMesh y1Points;
ofMesh y1y2Points;

//--------------------------------------------------------------
void Kadai3_3::setup(){
    ofBackground(255);
    lorenz = new LorenzAttractor();
    y1Points.setMode(OF_PRIMITIVE_POINTS);
    y1y2Points.setMode(OF_PRIMITIVE_POINTS);
    //lorenz->y.at(0) = 1 + 1.0 / 100;
    while (lorenz->time <= 100) {
        y1Points.addVertex(ofPoint(lorenz->time * 70.0, -lorenz->y[0] * 20.0,0));
        y1y2Points.addVertex(ofPoint(lorenz->y.at(0) * 15.0,-lorenz->y.at(1) * 15.0));
        y1y2Points.addColor(ofColor::fromHsb(int(lorenz->time) % 255, 255, 255));
        lorenz->update();
    }
}

//--------------------------------------------------------------
void Kadai3_3::update(){

}


//--------------------------------------------------------------
void Kadai3_3::draw(){
    
    ofPushMatrix();
    //---------------------
    //3.3.1-1
    //---------------------
    /*ofTranslate(50, ofGetHeight()/2);
    ofSetColor(0);
    y1Points.draw();
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-50, 0, ofGetWidth() - 50, 0);
    ofDrawBitmapString("Y1", ofPoint(30,-220));
    for(float i = -25.0; i <= 25; i+= 5){
        ofDrawBitmapString(ofToString(i), ofPoint(10,-i * 20.0));
        ofLine(-5, -i * 20.0, 5, -i * 20.0);
    }
    
    ofDrawBitmapString("Time", ofPoint(220,20));
    for(float p = 0; p <= 10; p++){
        ofDrawBitmapString(ofToString(p), ofPoint(p * 70.0,-10));
        ofLine(p * 70.0,-5, p * 70.0,5);
    }
    ofPopMatrix();
    */
    //---------------------
    //3.3.1-2
    //---------------------
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    y1y2Points.draw();
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-ofGetWidth()/2, 0, ofGetWidth()/2, 0);
    ofDrawBitmapString("Y2", ofPoint(30,-220));
    for(float i = -25.0; i <= 25; i+= 5){
        ofDrawBitmapString(ofToString(i), ofPoint(10,-i * 15.0));
        ofLine(-5, -i * 15.0, 5, -i * 15.0);
    }
    
    ofDrawBitmapString("Y1", ofPoint(220,20));
    for(float p = -25; p <= 25; p+=5){
        ofDrawBitmapString(ofToString(p), ofPoint(p * 15.0,-10));
        ofLine(p * 15.0,-5, p * 15.0,5);
    }
    ofPopMatrix();
}
