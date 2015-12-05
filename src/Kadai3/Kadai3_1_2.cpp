//
//  Kadai3_1_2.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2015/12/05.
//
//
#include "Kadai3_1_2.h"
#include "PropagationOfPulse.h"
#include "csvOperator.h"
//-----------------------------------
//Draw pulse 3.1
//----------------------------------
PropagationOfPulse * p;
ofMesh mesh;

//---------------------------
//For save file
//---------------------------
vector<ofPoint> saveData;


//--------------------------------------------------------------
void Kadai3_1_2::setup(){
    ofBackground(255);
    p = new PropagationOfPulse(true);
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    p->free = true; //jiyuutan
}

//--------------------------------------------------------------
void Kadai3_1_2::update(){
    mesh.clear();
    for(int i = 0; i < p->N; i++){
        mesh.addVertex(ofPoint(i * 4.0,-p->uk.at(i) * 200.0));
        if(p->frameCounter == 100){
            saveData.push_back(ofPoint(i,p->uk.at(i)));
        }
    }
    if(p->frameCounter == 100) csvOperator::saveSplinePoints("3_1_2out", saveData);
    p->update();
    
}


//--------------------------------------------------------------
void Kadai3_1_2::draw(){
    ofPushMatrix();
    ofTranslate(50, ofGetHeight()/2);
    ofSetColor(0, 255, 0);
    mesh.draw();
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(800, - ofGetHeight()/2,800,ofGetHeight()/2);
    ofLine(-50, 0, ofGetWidth() - 50, 0);
    for(float i = -1.5; i <= 1.5; i+= 0.5){
        ofDrawBitmapString(ofToString(i), ofPoint(0,-i * 200));
    }
    
    for(int i = 20; i <= p->N; i+= 20){
        ofDrawBitmapString(ofToString(i), ofPoint(i * 4.0,10));
    }
    
    ofDrawBitmapString("k=" + ofToString(p->frameCounter), ofPoint(200,-200));
    
    ofPopMatrix();
}
