#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Game");
    
    setSmallScreen();
    bFullscreen = false;
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofBackground(0,0,0);
    
    ballPositionX = 150;
    ballPositionY = 150;
    ballVelocityX = ofRandom(-5,5);
    ballVelocityY = ofRandom(-5,5);
    
    backgroundY = 0;
    
    setInitialBackground();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (keyIsDown['a']) {
        ballPositionX -= 10;
    }
    
    if (keyIsDown['w']) {
        ballPositionY -= 10;
    }
    
    if (keyIsDown['s']) {
        ballPositionY += 10;
    }
    
    if (keyIsDown['d']) {
        ballPositionX += 10;
    }
    
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
    
    //ofSetHexColor(0x999999);
    
    ofSetHexColor(0xFFFFFF);
    for (float x : backgroundX) {
        ofDrawRectangle(x, backgroundY, 10, screenH);
    }
    
    ofSetHexColor(0xAAAAAA);
    ofDrawCircle(ballPositionX, ballPositionY, 15);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    keyIsDown[key] = true;
    
    if (keyIsDown['f']) {
        bFullscreen = !bFullscreen;
        
        if (!bFullscreen) {
            //ofSetWindowShape(300,300);
            ofSetFullscreen(false);
            
            // figure out how to put the window in the center:
            setSmallScreen();
        } else if (bFullscreen == true) {
            ofSetFullscreen(true);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    keyIsDown[key] = false;
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

void ofApp::setSmallScreen() {
    screenW = ofGetScreenWidth();
    screenH = ofGetScreenHeight();
    ofSetWindowPosition(screenW / 4 - 150, screenH / 4 - 150);
}

void ofApp::setInitialBackground() {
    int setX = ofGetWidth();
    for (int i = 0; i < 10; ++i) {
        backgroundX[i] = setX;
        setX -= 500;
    }
}
