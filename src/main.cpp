#include "ofMain.h"
#include "ofApp.h"
#include "Kadai3_1_2.h"
#include "Kadai3_2.h"
//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
    //ofRunApp(new Kadai3_1_2());
    ofRunApp(new Kadai3_2());
}
