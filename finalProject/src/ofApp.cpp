#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Game");
    
    setSmallScreen();
    bFullscreen = false;
    
    ofSetFrameRate(60);
    
    ofBackground(0,0,0);
    
    ballPositionX = 150;
    ballPositionY = 150;
    ballVelocityX = ofRandom(-5,5);
    ballVelocityY = ofRandom(-5,5);
    
    backgroundY = 0;
    
    setInitialBackground();
    
    int cellSize = 6;
    
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    game.gliderGun(ofGetWidth()/3/cellSize, ofGetHeight()/2/cellSize);
}

//--------------------------------------------------------------
void ofApp::update() {
    game.update();
    
    if (keyIsDown['a']) {
        ballPositionX -= 3;
    }
    
    if (keyIsDown['w']) {
        ballPositionY -= 3;
    }
    
    if (keyIsDown['s']) {
        ballPositionY += 3;
    }
    
    if (keyIsDown['d']) {
        ballPositionX += 3;
    }
    
    if (bFullscreen) {
        ofHideCursor();
    } else {
        ofShowCursor();
    }
    
    if (ballPositionX < 0) {
        ballPositionX = 0;
    } else if (ballPositionX > ofGetWidth()) {
        ballPositionX = ofGetWidth();
    }
    
    if (ballPositionY < 0) {
        ballPositionY = 0;
    } else if (ballPositionY > ofGetHeight()) {
        ballPositionY = ofGetHeight();
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
    
    int cellWidth = 6;
    int cellHeight = 6;
    
    for (int i = 0; i < game.getCols(); i++) {
        for (int j = 0; j < game.getRows(); j++) {
            cell thisCell = game.getCell(i, j);
            ofSetColor(255, 150, 150);
            ofNoFill();
            ofDrawRectangle(i*cellWidth, j*cellHeight, cellWidth, cellHeight);
        }
    }
    
    cell thisCell = game.getCell(ballPositionX, ballPositionY);
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawRectangle(ballPositionX*cellWidth, ballPositionY*cellHeight, cellWidth, cellHeight);
    
    //ofSetHexColor(0x999999);
    
    /*ofSetHexColor(0xFFFFFF);
    for (float x : backgroundX) {
        ofDrawRectangle(x, backgroundY, 10, screenH);
    }
    
    ofSetHexColor(0xAAAAAA);
    ofDrawCircle(ballPositionX, ballPositionY, 15);*/
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    keyIsDown[key] = true;
    
    if (keyIsDown['f']) {
        bFullscreen = !bFullscreen;
        
        if (!bFullscreen) {
            ofSetFullscreen(false);
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
