#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Game");
    
    ofSetFullscreen(true);
    
    ofSetFrameRate(60);
    
    ofBackground(0,0,0);
    
    ballPositionX = 1;
    ballPositionY = 1;
    
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    start = 100;
}

//--------------------------------------------------------------
void ofApp::update() {
    game.update();
    
    int tempX = ballPositionX;
    int tempY = ballPositionY;
    
    if (keyIsDown['a']) {
        ballPositionX -= 1;
    }
    
    if (keyIsDown['w']) {
        ballPositionY -= 1;
    }
    
    if (keyIsDown['s'] && game.getCell(ballPositionX, ballPositionY + 3).currState != true) {
        ballPositionY += 1;
    }
    
    if (keyIsDown['d']) {
        ballPositionX += 1;
    }
    
    if (ballPositionX < 1) {
        ballPositionX = 1;
    } else if (ballPositionX > game.getCols() - 2) {
        ballPositionX = game.getCols() - 2;
    }
    
    if (ballPositionY < 1) {
        ballPositionY = 1;
    } else if (ballPositionY > game.getRows() - 4) {
        ballPositionY = game.getRows() - 4;
    }
    
    if (game.getCell(ballPositionX, ballPositionY + 3).currState == true) {
        ballPositionX = tempX;
        ballPositionY = tempY;
    }
    
    //std::cout << game.getCell(ballPositionX, ballPositionY + 3).currState << std::endl;
}

//--------------------------------------------------------------
void ofApp::draw() {
    drawGridLines();
    
    for (int i = start; i >= start - 50; i--) {
        for (int j = game.getRows(); j > 70; j--) {
            int setX;
            if (i >= 0) {
                setX = i;
            } else {
                setX = game.getCols() + i;
            }
            
            game.getCell(setX,j).currState = true;
            ofSetColor(255,0,0);
            ofFill();
            ofDrawRectangle(setX*cellSize, j*cellSize, cellSize, cellSize);
        }
    }
    
    drawPlayer();
    
    --start;
    if (start < 0) {
        start = game.getCols() - 1;
    }
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

void ofApp::drawGridLines() {
    for (int i = 0; i < game.getCols(); i++) {
        for (int j = 0; j < game.getRows(); j++) {
            ofSetColor(150, 150, 150);
            ofNoFill();
            ofDrawRectangle(i*cellSize, j*cellSize, cellSize, cellSize);
        }
    }
}
