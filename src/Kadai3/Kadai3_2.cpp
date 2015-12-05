//
//  Kadai3_2.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2015/12/05.
//
//

#include "Kadai3_2.h"
#include "HeunMethod.h"
#include "FourRungeKuttaMethod.h"
#include "EulersMethod.h"
#include "csvOperator.h"
//-----------------------------------
//kadai3.2.1
//----------------------------------
//EulersMethod * method;
//HeunMethod * method;
FourRungeKuttaMethod * method;
ofMesh uvtMesh;
ofMesh gosaU;
ofMesh gosaV;
//-----------------------------------
//kadai3.2.2
//----------------------------------
double Eu;
double Ev;
ofMesh euPoints;
ofMesh evPoints;

//---------------------------
//For save file
//---------------------------
vector<ofPoint> saveData;


//--------------------------------------------------------------
void Kadai3_2::setup(){
    ofBackground(255);
    //method = new EulersMethod();
    //method = new HeunMethod();
    method = new FourRungeKuttaMethod();
    //-----------------------------------
    //kadai3.2
    //----------------------------------
    
    /*uvtMesh.clear();
    while (method->time < 10 * M_PI / OMEGA) {
        method->update();
        uvtMesh.addVertex(ofPoint(-method->u * 100,-method->v * 100));
        //--------
        //Euler
        //--------
        gosaU.addVertex(ofPoint(method->time * 15.0, (method->u - method->SolutionU(method->time))* 100));
        gosaV.addVertex(ofPoint(method->time * 15.0, (method->v - method->SolutionV(method->time))* 100));
        
        //--------
        //Heun
        //--------
        //gosaU.addVertex(ofPoint(method->time * 15.0, (method->u - method->SolutionU(method->time))* 10000));
        //gosaV.addVertex(ofPoint(method->time * 15.0, (method->v - method->SolutionV(method->time))* 10000));
        
        //--------
        //Runge
        //--------
        //gosaU.addVertex(ofPoint(method->time * 15.0, (method->u - method->SolutionU(method->time))* 10000000));
        //gosaV.addVertex(ofPoint(method->time * 15.0, (method->v - method->SolutionV(method->time))* 10000000));
        
    }
    uvtMesh.setMode(OF_PRIMITIVE_POINTS);
    gosaU.setMode(OF_PRIMITIVE_POINTS);
    gosaV.setMode(OF_PRIMITIVE_POINTS);
    method->reset();
    */
    //-----------------------------------
    //kadai3.2.2
    //----------------------------------
    euPoints.setMode(OF_PRIMITIVE_POINTS);
    evPoints.setMode(OF_PRIMITIVE_POINTS);
    for(int p = 3; p <= 18; p++){
        double deltaT = 2* M_PI/ (pow(2.0, p) * OMEGA);
        method->deltaT = deltaT;
        Eu = 0;
        Ev = 0;
        while (method->time < 10 * M_PI / OMEGA) {
            method->update();
            double eu = method->u - method->SolutionU(method->time);
            double ev = method->v - method->SolutionV(method->time);
            
            if(Eu < abs(eu)) Eu = abs(eu);
            if(Ev < abs(ev)) Ev = abs(ev);
        }
        euPoints.addVertex(ofPoint(p * 50, -log2(Eu) * 10,0));
        evPoints.addVertex(ofPoint(p * 50, -log2(Ev) * 10,0));
        method->reset();
    }
    double deltaT = 2* M_PI/ (64 * OMEGA);
    method->deltaT = deltaT;
}

//--------------------------------------------------------------
void Kadai3_2::update(){
    
    //-----------------------------------
    //kadai3.2
    //----------------------------------
    //method->update(); //Test
}


//--------------------------------------------------------------
void Kadai3_2::draw(){
    
    ofSetColor(0);
    glPointSize(5);
    //-----------------------------------
    //kadai3.2.1 UVPlot
    //----------------------------------
    /*ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    uvtMesh.draw();
    
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-ofGetWidth()/2, 0, ofGetWidth()/2, 0);
    
    ofDrawBitmapString("V", ofPoint(0,-220));
    for(float i = -5; i <= 5; i+= 0.5){
        ofDrawBitmapString(ofToString(i), ofPoint(10,-i * 100));
        ofLine(-5, -i * 100, 5, -i * 100);
    }
    ofDrawBitmapString("U", ofPoint(220,0));
    for(float i = -5; i <= 5; i+= 0.5){
        ofDrawBitmapString(ofToString(i), ofPoint(i * 100,-10));
        ofLine(i * 100,-5, i * 100,5);
    }
    ofPopMatrix();
    */
    
    //-------------------
    //kadai3.2.1 Gosa
    //------------------
    /*ofPushMatrix();
    ofTranslate(50, ofGetHeight()/2);
    ofSetColor(255, 0, 0);
    ofDrawBitmapString("GosaV", ofPoint(300,-300));
    gosaV.draw();
    ofSetColor(0, 0, 255);
    ofDrawBitmapString("GosaU", ofPoint(300,-320));
    gosaU.draw();
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-50, 0, ofGetWidth() - 50, 0);
    
    ofDrawBitmapString("GOSA", ofPoint(0,-220));
    for(float i = -5; i <= 5; i+= 0.5){
        ofDrawBitmapString(ofToString(i), ofPoint(10,-i * 100));//Euler
        //ofDrawBitmapString(ofToString(i / 100.0), ofPoint(10,-i * 100)); //Heun
        //ofDrawBitmapString(ofToString(i / 100000.0), ofPoint(10,-i * 100)); //Runge
        ofLine(-5, -i * 100, 5, -i * 100);
    }
    
    ofDrawBitmapString("T", ofPoint(220,20));
    for(float i = 0; i <= 40; i+= 5){
        ofDrawBitmapString(ofToString(i), ofPoint(i * 15.0,-10));
        ofLine(i * 15.0,-5, i * 15.0,5);
    }
    ofPopMatrix();
    */
    
    //----------------------------------
    //kadai3.2.2
    //----------------------------------
    ofPushMatrix();
    glPointSize(5);
    ofTranslate(50, ofGetHeight()/4);
    ofSetColor(0, 255, 255);
    ofDrawBitmapString("Eu", ofPoint(300,-320));
    euPoints.draw();
    ofSetColor(255, 0, 255);
    ofDrawBitmapString("Ev", ofPoint(300,-320));
    evPoints.draw();
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/4,0,ofGetHeight());
    ofLine(-50, 0, ofGetWidth() - 50, 0);
    
    ofDrawBitmapString("Log2(max(Gosa))", ofPoint(0,-220));
    for(float i = -50; i <= 50; i+= 5){
        ofDrawBitmapString(ofToString(i), ofPoint(10,-i * 10));
        ofLine(-5, -i * 10, 5, -i * 10);
    }
    
    ofDrawBitmapString("p", ofPoint(220,20));
    for(float p = 3; p <= 18; p++){
        ofDrawBitmapString(ofToString(p), ofPoint(p * 50.0,-10));
        ofLine(p * 50.0,-5, p * 50.0,5);
    }
    ofPopMatrix();
}
