#include "ofApp.h"
#include "HeunMethod.h"
#include "FourRungeKuttaMethod.h"
#include "LorenzAttractor.h"
//-----------------------------------
//Draw pulse 3.1
//----------------------------------
PropagationOfPulse * p;
ofMesh mesh;
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

//---------------------------
//Kadai3.3
//---------------------------
LorenzAttractor * lorenz;
ofMesh y1Points;
ofMesh y1y2Points;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    //-----------------------------------
    //Set Pulse 3.1
    //----------------------------------
    /*p = new PropagationOfPulse(true);
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    */
    //-----------------------------------
    //kadai3.2
    //----------------------------------
    //method = new EulersMethod();
    //method = new HeunMethod();
    /*method = new FourRungeKuttaMethod();
   
    uvtMesh.clear();
    while (method->time < 10 * M_PI / OMEGA) {
        method->update();
        uvtMesh.addVertex(ofPoint(method->u * 100,method->v * 100));
        //--------
        //Euler
        //--------
        //gosaU.addVertex(ofPoint(method->time * 15.0, (method->u - method->SolutionU(method->time))* 100));
        //gosaV.addVertex(ofPoint(method->time * 15.0, (method->v - method->SolutionV(method->time))* 100));
        
        //--------
        //Heun
        //--------
        //gosaU.addVertex(ofPoint(method->time * 15.0, (method->u - method->SolutionU(method->time))* 10000));
        //gosaV.addVertex(ofPoint(method->time * 15.0, (method->v - method->SolutionV(method->time))* 10000));
  
        //--------
        //Runge
        //--------
        gosaU.addVertex(ofPoint(method->time * 15.0, (method->u - method->SolutionU(method->time))* 1000000));
        gosaV.addVertex(ofPoint(method->time * 15.0, (method->v - method->SolutionV(method->time))* 1000000));
        
    }
    uvtMesh.setMode(OF_PRIMITIVE_POINTS);
    gosaU.setMode(OF_PRIMITIVE_POINTS);
    gosaV.setMode(OF_PRIMITIVE_POINTS);
    method->reset();
    */
    //-----------------------------------
    //kadai3.2.2
    //----------------------------------
    /*euPoints.setMode(OF_PRIMITIVE_POINTS);
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
        euPoints.addVertex(ofPoint(p * 50, log2(Eu) * 10,0));
        evPoints.addVertex(ofPoint(p * 50, log2(Ev) * 10,0));
        method->reset();
    }
    double deltaT = 2* M_PI/ (64 * OMEGA);
    method->deltaT = deltaT;
    */
    
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
    //-----------------------------------
    //Update Pulse 3.1
    //----------------------------------
    /*mesh.clear();
    for(int i = 0; i < p->N; i++){
        mesh.addVertex(ofPoint(i * 4.0,p->uk.at(i) * 200.0));
    }
    p->update();*/
    
    //-----------------------------------
    //kadai3.2
    //----------------------------------
    //method->update(); //Test
}


//--------------------------------------------------------------
void ofApp::draw(){
    //ofCircle(ofGetWidth()/2, method->u * 100 + ofGetHeight()/2.0, 10); //Test
    //-----------------------------------
    //Draw pulse 3.1
    //----------------------------------
    /*ofPushMatrix();
    ofTranslate(50, ofGetHeight()/2);
    ofSetColor(0, 255, 255);
    mesh.draw();
    ofPopMatrix();
    */
    //-----------------------------------
    //kadai3.2.1
    //----------------------------------
    /*ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    glPointSize(5);
    ofSetColor(0, 255, 255);
    uvtMesh.draw();
    ofPopMatrix();
    ofPushMatrix();
    ofTranslate(50, ofGetHeight()/2);
    ofSetColor(0, 255, 255);
    gosaV.draw();
    ofSetColor(255, 255, 0);
    gosaU.draw();
    ofPopMatrix();
    */
    //-----------------------------------
    //kadai3.2.2
    //----------------------------------
    /*ofPushMatrix();
    glPointSize(5);
    ofTranslate(0, ofGetHeight()/2);
    ofSetColor(0, 255, 255);
    euPoints.draw();
    ofSetColor(255, 0, 255);
    evPoints.draw();
    ofPopMatrix();*/

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

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
