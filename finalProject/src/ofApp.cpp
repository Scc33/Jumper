#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    screenW = ofGetScreenWidth();
    screenH = ofGetScreenHeight();
    ofSetWindowPosition(screenW / 4 - 150, screenH / 4 - 150);
    
    bFullscreen = false;
    
    // lets set the initial window pos
    // and background color
    // ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofBackground(50,50,50);
    
    ballPositionX = 150;
    ballPositionY = 150;
    ballVelocityX = ofRandom(-5,5);
    ballVelocityY = ofRandom(-5,5);
    
    backgroundY = 0;
    
    int setX = ofGetWidth();
    for (int i = 0; i < 10; ++i) {
        backgroundX[i] = setX;
        setX -= 100;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle("Game");
    
    if (bFullscreen) {
        ofHideCursor();
    } else {
        ofShowCursor();
    }
    
    //ballPositionX += ballVelocityX;
    //ballPositionY += ballVelocityY;
    
    int posx = ofGetWindowPositionX();
    int posy = ofGetWindowPositionY();
    
    if (ballPositionX < 0) {
        ballPositionX = 0;
        ballVelocityX *= -1;
        if (!bFullscreen){
            ofSetWindowPosition(posx - 10, posy);
        }
    } else if (ballPositionX > ofGetWidth()) {
        ballPositionX = ofGetWidth();
        ballVelocityX *= -1;
        if (!bFullscreen) {
            ofSetWindowPosition(posx + 10, posy);
        }
    }
    
    if (ballPositionY < 0) {
        ballPositionY = 0;
        ballVelocityY *= -1;
        if (!bFullscreen) {
            ofSetWindowPosition(posx, posy - 10);
        }
    } else if (ballPositionY > ofGetHeight()) {
        ballPositionY = ofGetHeight();
        ballVelocityY *= -1;
        if (!bFullscreen) {
            ofSetWindowPosition(posx, posy + 10);
        }
    }
    
    for (int i = 0; i < 10; ++i) {
        --backgroundX[i];
        if (backgroundX[i] < 0) {
            backgroundX[i] = ofGetWidth();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetupScreen();
    
    ofSetHexColor(0x999999);
    
    ofSetHexColor(0xFFFFFF);
    for (float x : backgroundX) {
        ofDrawRectangle(x, backgroundY, 10, screenH);
    }
    
    ofSetHexColor(0xAAAAAA);
    ofDrawCircle(ballPositionX, ballPositionY, 15);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    if (key == 'a') {
        ballPositionX -= 10;
    }
    
    if (key == 'w') {
        ballPositionY -= 10;
    }
    
    if (key == 's') {
        ballPositionY += 10;
    }
    
    if (key == 'd') {
        ballPositionX += 10;
    }
    
    if (key == 'f') {
        bFullscreen = !bFullscreen;
        
        if (!bFullscreen) {
            ofSetWindowShape(300,300);
            ofSetFullscreen(false);
            
            // figure out how to put the window in the center:
            int screenW = ofGetScreenWidth();
            int screenH = ofGetScreenHeight();
            ofSetWindowPosition(screenW/2 - 150, screenH/2 - 150);
        } else if (bFullscreen == true) {
            ofSetFullscreen(true);
        }
    }
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
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
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
