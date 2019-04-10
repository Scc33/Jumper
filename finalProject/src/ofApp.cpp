#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Game");
    
    setScreenSize();
    
    ofSetFrameRate(60);
    
    ofBackground(0,0,0);
    
    ballPositionX = 0;
    ballPositionY = 0;
    
    //setInitialBackground();
    
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
}

//--------------------------------------------------------------
void ofApp::update() {
    game.update();
    
    if (keyIsDown['a']) {
        ballPositionX -= 1;
        //game.getCell(ballPositionX, ballPositionY).currState = true;
    }
    
    if (keyIsDown['w']) {
        ballPositionY -= 1;
    }
    
    if (keyIsDown['s']) {
        ballPositionY += 1;
    }
    
    if (keyIsDown['d']) {
        ballPositionX += 1;
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
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetupScreen();
    
    for (int i = 0; i < game.getCols(); i++) {
        for (int j = 0; j < game.getRows(); j++) {
            ofSetColor(150, 150, 150);
            ofNoFill();
            ofDrawRectangle(i*cellSize, j*cellSize, cellSize, cellSize);
        }
    }
    
    drawPlayer();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    keyIsDown[key] = true;
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

void ofApp::setScreenSize() {
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

void ofApp::drawPlayer() {
    ofSetColor(0, 255, 0);
    ofFill();
    
    ofDrawRectangle(ballPositionX*cellSize, ballPositionY*cellSize, cellSize, cellSize);
    ofDrawRectangle((ballPositionX+1)*cellSize, ballPositionY*cellSize, cellSize, cellSize);
    ofDrawRectangle((ballPositionX-1)*cellSize, ballPositionY*cellSize, cellSize, cellSize);
    ofDrawRectangle(ballPositionX*cellSize, (ballPositionY-1)*cellSize, cellSize, cellSize);
    ofDrawRectangle(ballPositionX*cellSize, (ballPositionY+1)*cellSize, cellSize, cellSize);
    ofDrawRectangle(ballPositionX*cellSize, (ballPositionY+2)*cellSize, cellSize, cellSize);
    ofDrawRectangle((ballPositionX-1)*cellSize, (ballPositionY+2)*cellSize, cellSize, cellSize);
    ofDrawRectangle((ballPositionX+1)*cellSize, (ballPositionY+2)*cellSize, cellSize, cellSize);
    ofDrawRectangle((ballPositionX-1)*cellSize, (ballPositionY+3)*cellSize, cellSize, cellSize);
    ofDrawRectangle((ballPositionX+1)*cellSize, (ballPositionY+3)*cellSize, cellSize, cellSize);
}
