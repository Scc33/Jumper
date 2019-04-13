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
    
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    setupPlatforms();
    
    // instantiate a basic button
    startGameButton = new ofxDatGuiButton("Start");
    settingsButton = new ofxDatGuiButton("Settings");
    highScoreButton = new ofxDatGuiButton("High Scores");
    
    // position the components in the middle of the screen
    setupButtons();
    
    // and register to listen for events
    startGameButton->onButtonEvent(this, &ofApp::onButtonEvent);
    settingsButton->onButtonEvent(this, &ofApp::onButtonEvent);
    highScoreButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    gameRunning = false;
}

//--------------------------------------------------------------
void ofApp::update() {
    startGameButton->update();
    settingsButton->update();
    highScoreButton->update();

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
        
        drawAllPlatforms();
        
        drawPlayer();
    } else {
        drawPlayer();
        
        startGameButton->draw();
        settingsButton->draw();
        highScoreButton->draw();
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

void ofApp::drawPlatform(int platform) {
    for (int i = platforms.at(platform).at(0); i >= platforms.at(platform).at(0) - platforms.at(platform).at(1); i--) {
        for (int j = game.getRows(); j > 70; j--) {
            int setX;
            if (i >= 0) {
                setX = i;
            } else {
                setX = game.getCols() + i;
            }
            
            //game.getCell(setX,j).currState = true;
            if (setX < game.getCols()) {
                ofSetColor(255,0,0);
                ofFill();
                ofDrawRectangle(setX*cellSize, j*cellSize, cellSize, cellSize);
            }
        }
    }
}

void ofApp::updatePlatformPositions() {
    for (int i = 0; i < platforms.size(); i++) {
        platforms.at(i).at(0)--;
        
        if (platforms.at(i).at(0) < 0) {
            platforms.at(i).at(0) = platforms.at(i).at(2);
            platforms.at(i).at(1) = ofRandom(10, 50);
        }
        
        //std::cout << platforms.at(i).at(0) << " " << platforms.at(i).at(1) << std::endl;
    }
}

void ofApp::drawAllPlatforms() {
    for (int i = 0; i < platforms.size(); i++) {
        drawPlatform(i);
    }
    updatePlatformPositions();
}

void ofApp::setupPlatforms() {
    int platformPos = 0;
    platforms.resize(10);
    
    for (auto curr = platforms.begin(); curr != platforms.end(); curr++) {
        curr->resize(3);
        curr->at(0) = platformPos;
        curr->at(1) = ofRandom(10, 50);
        curr->at(2) = curr->at(0);
        platformPos += 50;
    }
    
    for (int i = 0; i < platforms.size(); i++) {
        std::cout << platforms.at(i).at(0) << " " << platforms.at(i).at(1) << std::endl;
    }
    std::cout << std::endl;
}

int ofApp::gravityCalculation() {
    if (posY < game.getRows() + 10) {
        ++posY;
    }
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    // we have a couple ways to figure out which button was clicked //
    
    // we can compare our button pointer to the target of the event //
    if (e.target == startGameButton) {
        gameRunning = true;
        posX = 1;
        posY = 1;
    } else if (e.target == settingsButton) {

    }
}

void ofApp::setupButtons() {
    startGameButton->setPosition(ofGetWidth()/2 - settingsButton->getWidth()/2, ofGetHeight()/2 - 45);
    settingsButton->setPosition(startGameButton->getX(), startGameButton->getY() + 45);
    highScoreButton->setPosition(startGameButton->getX(), startGameButton->getY() + 90);
    
    startGameButton->setTheme(new ofxDatGuiGameTheme(16));
    settingsButton->setTheme(new ofxDatGuiGameTheme(16));
    highScoreButton->setTheme(new ofxDatGuiGameTheme(16));
}
