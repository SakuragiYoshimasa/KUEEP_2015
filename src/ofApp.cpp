#include "ofApp.h"

#include "LorenzAttractor.h"

//---------------------------
//Kadai3.3
//---------------------------
LorenzAttractor * lorenz;
ofMesh y1Points;
ofMesh y1y2Points;

//---------------------------
//For save file
//---------------------------
vector<ofPoint> saveData;


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);

    //-----------------------------------
    //kadai3.3
    //----------------------------------
    /*lorenz = new LorenzAttractor();
    y1Points.setMode(OF_PRIMITIVE_POINTS);
    y1y2Points.setMode(OF_PRIMITIVE_POINTS);
    lorenz->y.at(0) = 1 + 1.0 / 1000;
    while (lorenz->time <= 100) {
        
        y1Points.addVertex(ofPoint(lorenz->time * 100.0, lorenz->y[0] * 10.0,0));
        y1y2Points.addVertex(ofPoint(lorenz->y.at(0) * 10.0,lorenz->y.at(1) * 10.0));
        lorenz->update();
    }*/
}

//--------------------------------------------------------------
void ofApp::update(){
}


//--------------------------------------------------------------
void ofApp::draw(){



    //-----------------------------------
    //kadai3.3
    //----------------------------------
    /*ofPushMatrix();
    ofTranslate(0, ofGetHeight()/2);
    ofSetColor(0);
    y1Points.draw();
    ofTranslate(ofGetWidth()/2, 0);
    y1y2Points.draw();
    ofPopMatrix();*/
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}