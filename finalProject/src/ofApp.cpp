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
    velX = ofRandom(-0.5,0.5);
    velY = ofRandom(-0.5,0.5);
    
    obstacles.push_back(35);
    obstacles.push_back(105);
    obstacles.push_back(155);
    obstacles.push_back(175);
    obstacles.push_back(225);
    
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    //Position the buttons in the middle of the screen and register to listen for events
    setupButtons();
    
    startMenuRunning = true;
    gameRunning = false;
}

//--------------------------------------------------------------
void ofApp::update() {
    if (keyIsDown['m']) {
        startMenuRunning = true;
        gameRunning = false;
        marketMenuRunning = false;
        settingsRunning = false;
        hScoreMenuRunning = false;
    }
    
    updateButtons();
    
    if (gameRunning) {
        runGame();
    } else {
        runStartMenu();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (startMenuRunning) {
        drawStartMenu();
    }
    
    if (gameRunning) {
        drawGame();
    }
    
    if (marketMenuRunning) {
        
    }
    
    if (settingsRunning) {
        
    }
    
    if (hScoreMenuRunning) {
        
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
    
    for (int i = 0; i < obstacles.size(); i++) {
        ofDrawRectangle(obstacles.at(i), game.getRows() * cellSize - 240, cellSize, cellSize * 4);
        obstacles.at(i)--;
        
        if (obstacles.at(i) < 0) {
            obstacles.at(i) = game.getCols() * cellSize;
        }
    }
}

int ofApp::gravityCalculation() {
    if (posY < game.getRows() - 24 && !keyIsDown['w']) {
        airtime += .1;
        posY += 1 * airtime;
    } else {
        airtime = 0;
    }

    //Keep player from going inside the ground
    if (posY > game.getRows() - 24) {
        posY = game.getRows() - 24;
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == startGameButton) {
        startMenuRunning = false;
        gameRunning = true;
        posX = 10;
        posY = 1;
    } else if (e.target == marketButton) {
        startMenuRunning = false;
        marketMenuRunning = true;
    } else if (e.target == settingsButton) {
        startMenuRunning = false;
        settingsRunning = true;
    } else if (e.target == highScoreButton) {
        startMenuRunning = false;
        hScoreMenuRunning = true;
    } else if (e.target == exitButton) {
        ofExit();
    }
}

void ofApp::updateButtons() {
    startGameButton->update();
    marketButton->update();
    settingsButton->update();
    highScoreButton->update();
    exitButton->update();
}

void ofApp::setupButtons() {
    startGameButton = new ofxDatGuiButton("Start");
    marketButton = new ofxDatGuiButton("Market");
    settingsButton = new ofxDatGuiButton("Settings");
    highScoreButton = new ofxDatGuiButton("High Scores");
    exitButton = new ofxDatGuiButton("Exit");
    
    startGameButton->onButtonEvent(this, &ofApp::onButtonEvent);
    marketButton->onButtonEvent(this, &ofApp::onButtonEvent);
    settingsButton->onButtonEvent(this, &ofApp::onButtonEvent);
    highScoreButton->onButtonEvent(this, &ofApp::onButtonEvent);
    exitButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    startGameButton->setPosition(ofGetWidth()/2 - settingsButton->getWidth()/2, ofGetHeight()/2 - 90);
    marketButton->setPosition(startGameButton->getX(), startGameButton->getY() + 45);
    settingsButton->setPosition(startGameButton->getX(), startGameButton->getY() + 90);
    highScoreButton->setPosition(startGameButton->getX(), startGameButton->getY() + 135);
    exitButton->setPosition(startGameButton->getX(), startGameButton->getY() + 180);
    
    startGameButton->setTheme(new ofxDatGuiGameTheme(16));
    marketButton->setTheme(new ofxDatGuiGameTheme(16));
    settingsButton->setTheme(new ofxDatGuiGameTheme(16));
    highScoreButton->setTheme(new ofxDatGuiGameTheme(16));
    exitButton->setTheme(new ofxDatGuiGameTheme(16));
}

void ofApp::runGame() {
    game.update();
    
    int tempX = posX;
    int tempY = posY;
    
    if (keyIsDown['a']) {
        posX -= 1;
    }
    
    if (keyIsDown['w']) {
        posY -= 3;
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
    
    gravityCalculation();
}

void ofApp::drawGame() {
    drawGridLines();
    
    ofSetColor(255,0,0);
    ofFill();
    ofDrawRectangle(0, game.getRows() * cellSize - 200, game.getCols() * cellSize, 200);
    
    drawObstacles();
    
    drawPlayer();
}

void ofApp::runStartMenu() {
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

void ofApp::drawStartMenu() {
    drawPlayer();
    
    startGameButton->draw();
    marketButton->draw();
    settingsButton->draw();
    highScoreButton->draw();
    exitButton->draw();
}
