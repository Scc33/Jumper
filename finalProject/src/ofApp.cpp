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
    
    starts.push_back(47);
    starts.push_back(95);
    starts.push_back(143);
    
    numClicks = 0;
    
    // instantiate a basic button and a toggle button //
    button = new ofxDatGuiButton("CLICK ME");
    //toggle = new ofxDatGuiToggle("TOGGLE FULLSCREEN", false);
    
    // position the components in the middle of the screen //
    positionButtons();
    
    // and register to listen for events //
    button->onButtonEvent(this, &ofApp::onButtonEvent);
    //toggle->onButtonEvent(this, &ofApp::onButtonEvent);
}

//--------------------------------------------------------------
void ofApp::update() {
    game.update();
    
    button->update();
    //toggle->update();
    
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
    
    
    //gravityCalculation();
    //std::cout << game.getCell(ballPositionX, ballPositionY + 3).currState << std::endl;
}

//--------------------------------------------------------------
void ofApp::draw() {
    drawGridLines();
    
    drawPlatform(starts.at(0));
    drawPlatform(starts.at(1));
    drawPlatform(starts.at(2));
    updatePlatformPosition();
    
    drawPlayer();
    
    button->draw();
    //toggle->draw();
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

void ofApp::drawPlatform(int start) {
    for (int i = start; i >= start - 20; i--) {
        for (int j = game.getRows(); j > 70; j--) {
            int setX;
            if (i >= 0) {
                setX = i;
            } else {
                setX = game.getCols() + i;
            }
            
            //game.getCell(setX,j).currState = true;
            ofSetColor(255,0,0);
            ofFill();
            ofDrawRectangle(setX*cellSize, j*cellSize, cellSize, cellSize);
        }
    }
}

void ofApp::updatePlatformPosition() {
    for (int i = 0; i < starts.size(); i++) {
        starts.at(i)--;
        
        if (starts.at(i) < 0) {
            starts.at(i) = game.getCols() - 1;
        }
    }
}

int ofApp::gravityCalculation() {
    if (ballPositionY < game.getRows() + 10) {
        ++ballPositionY;
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
    // we have a couple ways to figure out which button was clicked //
    
    // we can compare our button pointer to the target of the event //
    if (e.target == button){
        numClicks++;
        if (numClicks == 1){
            button->setLabel("YOU CLICKED ME ONCE");
        }   else{
            button->setLabel("YOU CLICKED ME "+ofToString(numClicks)+" TIMES");
        }
        
        // or we can check against the label of the event target //
    }   else if(e.target->getLabel() == "TOGGLE FULLSCREEN"){
        isFullscreen =!isFullscreen;
        ofSetFullscreen(isFullscreen);
        if (!isFullscreen) {
            ofSetWindowShape(1920, 1080);
            ofSetWindowPosition((ofGetScreenWidth()/2)-(1920/2), 0);
        }
        positionButtons();
    }
}

void ofApp::positionButtons()
{
    button->setPosition(ofGetWidth()/2 - button->getWidth()/2, ofGetHeight()/2 - button->getHeight());
    //toggle->setPosition(button->getX(), button->getY() + button->getHeight() + 20);
}
