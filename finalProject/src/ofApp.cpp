#include "ofApp.h"
#include "ofxDatGuiGameTheme.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Game");
    
    ofSetFullscreen(true);
    
    ofSetFrameRate(60);
    
    ofBackground(0,0,0);
    
    posX = 1;
    posY = 1;
    velX = ofRandom(-1,1);
    velY = ofRandom(-1,1);
    
    obstacles.push_back(35);
    
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    // instantiate a basic button
    startGameButton = new ofxDatGuiButton("Start");
    settingsButton = new ofxDatGuiButton("Settings");
    highScoreButton = new ofxDatGuiButton("High Scores");
    exitButton = new ofxDatGuiButton("Exit");
    
    // position the components in the middle of the screen
    setupButtons();
    
    // and register to listen for events
    startGameButton->onButtonEvent(this, &ofApp::onButtonEvent);
    settingsButton->onButtonEvent(this, &ofApp::onButtonEvent);
    highScoreButton->onButtonEvent(this, &ofApp::onButtonEvent);
    exitButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    
    gameRunning = false;
}

//--------------------------------------------------------------
void ofApp::update() {
    startGameButton->update();
    settingsButton->update();
    highScoreButton->update();
    exitButton->update();

    if (gameRunning) {
        game.update();
        
        int tempX = posX;
        int tempY = posY;
        
        if (keyIsDown['a']) {
            posX -= 1;
        }
        
        if (keyIsDown['w']) {
            posY -= 1;
        }
        
        if (keyIsDown['s'] && game.getCell(posX, posY + 3).currState != true) {
            posY += 1;
        }
        
        if (keyIsDown['d']) {
            posX += 1;
        }
        
        if (posX < 1) {
            posX = 1;
        } else if (posX > game.getCols() - 2) {
            posX = game.getCols() - 2;
        }
        
        if (posY < 1) {
            posY = 1;
        } else if (posY > game.getRows() - 4) {
            posY = game.getRows() - 4;
        }
        
        if (game.getCell(posX, posY + 3).currState == true) {
            posX = tempX;
            posY = tempY;
        }
        
        //gravityCalculation();
    } else {
        posX += velX;
        posY += velY;
        
        if (posX < 1) {
            posX = 1;
            velX *= -1;
        } else if (posX > game.getCols() - 2) {
            posX = game.getCols() - 2;
            velX *= -1;
        }
        
        if (posY < 1) {
            posY = 1;
            velY *= -1;
        } else if (posY > game.getRows() - 4){
            posY = game.getRows() - 4;
            velY *= -1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (gameRunning) {
        drawGridLines();
        
        ofSetColor(255,0,0);
        ofFill();
        ofDrawRectangle(0, game.getRows() * cellSize - 150, game.getCols() * cellSize, 150);
        
        drawObstacles();
        
        drawPlayer();
    } else {
        drawPlayer();
        
        startGameButton->draw();
        settingsButton->draw();
        highScoreButton->draw();
        exitButton->draw();
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
    
    ofDrawRectangle(posX*cellSize, posY*cellSize, cellSize, cellSize);
    ofDrawRectangle((posX+1)*cellSize, posY*cellSize, cellSize, cellSize);
    ofDrawRectangle((posX-1)*cellSize, posY*cellSize, cellSize, cellSize);
    ofDrawRectangle(posX*cellSize, (posY-1)*cellSize, cellSize, cellSize);
    ofDrawRectangle(posX*cellSize, (posY+1)*cellSize, cellSize, cellSize);
    ofDrawRectangle(posX*cellSize, (posY+2)*cellSize, cellSize, cellSize);
    ofDrawRectangle((posX-1)*cellSize, (posY+2)*cellSize, cellSize, cellSize);
    ofDrawRectangle((posX+1)*cellSize, (posY+2)*cellSize, cellSize, cellSize);
    ofDrawRectangle((posX-1)*cellSize, (posY+3)*cellSize, cellSize, cellSize);
    ofDrawRectangle((posX+1)*cellSize, (posY+3)*cellSize, cellSize, cellSize);
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

void ofApp::drawObstacles() {
    ofSetColor(255,0,0);
    ofFill();
    
    ofDrawRectangle(obstacles.at(0), game.getRows() * cellSize - 170, cellSize, cellSize * 4);
    obstacles.at(0)--;
    
    if (obstacles.at(0) < 0) {
        obstacles.at(0) = game.getCols() * cellSize;
    }
}

int ofApp::gravityCalculation() {
    if (posY < game.getRows() + 10) {
        ++posY;
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == startGameButton) {
        gameRunning = true;
        posX = 1;
        posY = 1;
    } else if (e.target == settingsButton) {

    }
}

void ofApp::setupButtons() {
    startGameButton->setPosition(ofGetWidth()/2 - settingsButton->getWidth()/2, ofGetHeight()/2 - 90);
    settingsButton->setPosition(startGameButton->getX(), startGameButton->getY() + 45);
    highScoreButton->setPosition(startGameButton->getX(), startGameButton->getY() + 90);
    exitButton->setPosition(startGameButton->getX(), startGameButton->getY() + 135);
    
    startGameButton->setTheme(new ofxDatGuiGameTheme(16));
    settingsButton->setTheme(new ofxDatGuiGameTheme(16));
    highScoreButton->setTheme(new ofxDatGuiGameTheme(16));
    exitButton->setTheme(new ofxDatGuiGameTheme(16));
}
