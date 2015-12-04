#include "ofApp.h"
#include "HeunMethod.h"
#include "FourRungeKuttaMethod.h"
//-----------------------------------
//Draw pulse
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
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    //-----------------------------------
    //Set Pulse
    //----------------------------------
    p = new PropagationOfPulse(true);
    mesh.setMode(OF_PRIMITIVE_LINE_STRIP);
    //method = new EulersMethod();
    //method = new HeunMethod();
    method = new FourRungeKuttaMethod();
    //-----------------------------------
    //euler method
    //----------------------------------
    uvtMesh.clear();
    while (method->time < 10 * M_PI / OMEGA) {
        method->update();
        uvtMesh.addVertex(ofPoint(method->u * 100,method->v * 100));
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
}

//--------------------------------------------------------------
void ofApp::update(){
    //-----------------------------------
    //Update Pulse
    //----------------------------------
    /*mesh.clear();
    for(int i = 0; i < p->N; i++){
        mesh.addVertex(ofPoint(i * 4.0,p->uk.at(i) * 200.0));
    }
    p->update();*/
}


//--------------------------------------------------------------
void ofApp::draw(){
    //-----------------------------------
    //Draw pulse
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
    ofPushMatrix();
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
