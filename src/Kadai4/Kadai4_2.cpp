//
//  Kadai4_2.cpp
//  KUEEP_2015
//
//  Created by SakuragiYoshimasa on 2016/01/04.
//
//
#define xA 0.0
//#define xB 1.0
#define xB 1.0
#define R 40.0
#define MAXk 15

#include "Kadai4_2.h"

ofMesh Emesh; //誤差表示用のmesh
vector<ofMesh> TEMesh;

double Kadai4_2::f(double x){
    return pow(x, 19);
    
    //---------------------------------------------
    //課題4.3
    //---------------------------------------------
    //定義式1 xA = 0, xB = 1, I * 4.0
    //return 1.0 / (1.0 + x * x);
    //定義式2 xA = 0, xB = 1, I * 4.0
    //定義式3 xA = 0, xB = 0.5, (I - sqrt(3.0) / 8.0) * 12.0
    //定義式4 xA = 1, xB = 0.5, (I + sqrt(3.0) / 8.0) * 6.0
    //return sqrt(1.0 - x * x);
}

double Kadai4_2::I(){
    return 0.05; //積分の真値をreturn
}

void Kadai4_2::setup(){
    
    ofColor colorSet[2] = {
        ofColor(255,0,0), //台形
        ofColor(0,0,255)  //シンプソン
    };
    
    Emesh.clear();
    
    vector<double> T0; //l = 1
    for(int k = 1; k < MAXk; k++){
        int n = int(pow(2.0, k));
        double result = 0.0;
        double step = (xB - xA) / double(n);
        
        //複合台形公式
        result += f(xA);
        result += f(xB);
        for(int i = 1; i < n; i++){
            
            result += 2.0 * f(xA + step * i);
        }
        result *= (xB - xA) / (double(n) * 2.0) ;
        Emesh.addVertex(ofPoint(k * R, -log2(abs(I() - result)) * R / 10.0));
        Emesh.addColor(colorSet[0]);
        T0.push_back(result); // T0にstack
        cout << result << "  ";
        //複合シンプソン公式
        result = 0.0;
        result += f(xA);
        result += f(xB);
        for(int i = 1; i < n; i++){
            if(i % 2 == 1){
                result += 4.0 * f(xA + step * i);
            }else{
                result += 2.0 * f(xA + step * i);
            }
        }
        result *= (xB - xA) / (double(n) * 3.0) ;
        Emesh.addVertex(ofPoint(k * R, -log2(abs(I() - result)) * R / 10.0));
        Emesh.addColor(colorSet[1]);
    }
    cout << endl;
    vector<double> Tl = T0;
    for(int l = 1; l < MAXk; l++){
        ofMesh TlMesh = *new ofMesh();
        vector<double> TlPlusOne = vector<double>(0);
        TlPlusOne.clear();
        for(int k = l; k < MAXk - 1; k++){
            double result = (double(powf(4.0, l)) * Tl[k - l + 1] - Tl[k - l]) / (double(powf(4.0, l) - 1.0));
            cout << result << "  ";
            TlPlusOne.push_back(result);
            TlMesh.addVertex(ofPoint(k * R, -log2(abs(I() - result)) * R / 10.0));
            TlMesh.addColor(ofColor(255 - l * 15, l * 15,0));
        }
        cout << endl;
        TEMesh.push_back(TlMesh);
        Tl = TlPlusOne;
    }
    
    //---------------------------------------------
    //課題4.3 用出力
    //---------------------------------------------
    //定義式1 xA = 0, xB = 1, I * 4.0
    //定義式2 xA = 0, xB = 1, I * 4.0
    //cout << setprecision(30) <<"PI:" << Tl[0] * 4.0 << endl;
    //定義式3 xA = 0, xB = 0.5, (I - sqrt(3.0) / 8.0) * 12.0
    //cout << setprecision(30) <<"PI:" << (Tl[0] - sqrt(3.0) / 8.0) * 12.0 << endl;
    //定義式4 xA = 1, xB = 0.5, (I + sqrt(3.0) / 8.0) * 6.0
    //cout << setprecision(30) <<"PI:" << (Tl[0] + sqrt(3.0) / 8.0) * 6.0 << endl;
    
    
    ofBackground(255);
    glPointSize(5.0);
}

void Kadai4_2::update(){}

void Kadai4_2::draw(){
    
    ofPushMatrix();
    ofTranslate(50, ofGetHeight()/2);
    ofSetColor(0);
    glPointSize(5.0);
    Emesh.setMode(OF_PRIMITIVE_POINTS);
    Emesh.draw();
    
    for(int i = 0; i < TEMesh.size(); i++){
        glPointSize(i * 1.5);
        TEMesh[i].setMode(OF_PRIMITIVE_LINE_STRIP);
        TEMesh[i].draw();
        
        TEMesh[i].setMode(OF_PRIMITIVE_POINTS);
        TEMesh[i].draw();

    }
    
    ofSetColor(0);
    ofLine(0, - ofGetHeight()/2,0,ofGetHeight()/2);
    ofLine(-50, 0, ofGetWidth() - 50, 0);
    ofDrawBitmapString("k", ofPoint(220,20));
    for(float i = 0; i < MAXk; i+= 1){
        ofDrawBitmapString(ofToString(i), ofPoint(i * R,20));
        ofLine(i * R, - 5, i * R, 5);
    }
    
    ofDrawBitmapString("Log2(E)", ofPoint(30,220));
    for(float p = 0.0499; p <= 0.05; p+= 0.000099999){
        ofDrawBitmapString(ofToString(log2(abs(p - I()))), ofPoint(20, -log2(abs(p - I())) * R / 10.0));
        ofLine(-5, -log2(abs(p - I())) * R / 10.0, 5, -log2(abs(p - I())) * R / 10.0);
    }
    ofPopMatrix();
}