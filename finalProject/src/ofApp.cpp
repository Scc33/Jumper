#include "ofApp.h"

/*
 Functions to run openFrameworks
 */

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Game");
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    ofBackground(50, 50, 50);
    
    posX = 1;
    posY = 1;
    gameStarted = startMenuRunning;

    player.setPlayer(posX, posY, cellSize);
    grid.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    loader::ReadScores(hScoreFileLoc, highScores, highScoreNames);
    newHighScoreName = "";
    
    mainM.setMainMenu(grid.getCols(), grid.getRows(), cellSize);
    mainM.setMainMenuPlayer(player);
    mainM.setupButtons();
    
    hScoreM.setupHScoreButtons();
    hScoreM.updateHighScores();
    
    marketM.setupMarketButtons();
    
    settingsM.setupSettingsButtons();
    
    gameEndedM.setupEndgameButtons();
    
    //loader::ReadSettings();
}

//--------------------------------------------------------------
void ofApp::update() {
    if (startMenuRunning != gameStarted) {
        setupGame();
        gameStarted = startMenuRunning;
    }
    
    if (keyIsDown[menuButton]) {
        startMenuRunning = true;
        gameRunning = false;
        gameEndedScreen = false;
        marketMenuRunning = false;
        settingsRunning = false;
        hScoreMenuRunning = false;
    }
    
    if (startMenuRunning) {
        mainM.runStartMenu();
    } else if (gameRunning) {
        if (hasCollided()) {
            gameRunning = false;
            gameEndedScreen = true;
            
            gameEndedM.setNewScore(score);
            gameEndedM.highScoreInput->setFocused(true);
        }
        runGame();
    } else if (gameEndedScreen) {
        gameEndedM.runGameEnded();
    } else if (marketMenuRunning) {
        marketM.runMarket();
    } else if (settingsRunning) {
        settingsM.runSettingsMenu();
    } else if (hScoreMenuRunning) {
        hScoreM.runHScoreMenu();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (startMenuRunning) {
        ofShowCursor();
        mainM.drawStartMenu();
    } else if (gameRunning) {
        ofHideCursor();
        drawGame();
    } else if (gameEndedScreen) {
        ofShowCursor();
        gameEndedM.drawGameEnded();
    } else if (marketMenuRunning) {
        marketM.drawMarket();
    } else if (settingsRunning) {
        settingsM.drawSettingsMenu();
    } else if (hScoreMenuRunning) {
        hScoreM.drawHighScores();
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

/*
 Game functions
 */

void ofApp::drawObstacles() {
    ofSetColor(200,50,50);
    ofFill();
    
    for (int i = 0; i < obstacles.size(); i++) {
        ofDrawRectangle(obstacles.at(i), grid.getRows() * cellSize - 340, cellSize, cellSize * 4);
        obstacles.at(i) -= 2;
        
        if (obstacles.at(i) < 0) {
            obstacles.erase(obstacles.begin());
            score++;
        }
    }
}

//This doesn't seem to work from some angles (Or too fast?)
bool ofApp::hasCollided() {
    for (int obstacle : obstacles) {
        if (posX * cellSize <= obstacle && posX * cellSize >= obstacle - cellSize && posY > grid.getRows() - 36) {
            return true;
        }
    }
    
    return false;
}

//Needs tweaking to look better
int ofApp::gravityCalculation() {
    if (posY < grid.getRows() - 34) {
        airtime += .02;
        posY += 1 * airtime * airtime;
    } else {
        airtime = 0;
    }

    //Keep player from going inside the ground
    if (posY > grid.getRows() - 34) {
        posY = grid.getRows() - 34;
        airtime = 0;
    }
}

void ofApp::runGame() {
    grid.update();
    
    int tempX = posX;
    int tempY = posY;
    
    if (keyIsDown[' ']) {
        posY -= .8;
    }
    
    if (keyIsDown['a']) {
        posX -= .8;
    }
    
    if (keyIsDown['w']) {
        posY -= .8;
    }
    
    if (keyIsDown['s'] && grid.getCell(posX, posY + 3).currState != true) {
        posY += .8;
    }
    
    if (keyIsDown['d']) {
        posX += .8;
    }
    
    if (posX < 1) {
        posX = 1;
    } else if (posX > grid.getCols() - 2) {
        posX = grid.getCols() - 2;
    }
    
    if (posY < 1) {
        posY = 1;
    } else if (posY > grid.getRows() - 4) {
        posY = grid.getRows() - 4;
    }
    
    if (grid.getCell(posX, posY + 3).currState == true) {
        posX = tempX;
        posY = tempY;
    }
    
    gravityCalculation();
    
    //Randomly adds a new obstacle
    //Chance of new obstacle being creating increases as game goes on
    chanceOfNewObstacle += ofRandom(0, updateChanceOfNewObstacle);
    if (ofRandom(0, chanceOfNewObstacle) > 2) {
        obstacles.push_back(ofGetWidth());
        chanceOfNewObstacle = 0;
        updateChanceOfNewObstacle += .001;
    }
    
    player.updatePlayerLocation(posX, posY);
}

void ofApp::drawGame() {
    ofSetColor(255,0,0);
    ofFill();
    ofDrawRectangle(0, grid.getRows() * cellSize - 300, grid.getCols() * cellSize, 300);
    
    drawObstacles();
    
    player.drawPlayer();
    
    ofDrawBitmapString("Your score is " + ofToString(score), ofGetWidth() * 4 / 5, ofGetHeight() / 10);
}

void ofApp::setupGame() {
    airtime = 0;
    score = 0;
    
    posX = 10;
    posY = 1;
    
    obstacles.clear();
    obstacles.push_back(ofGetWidth());
    chanceOfNewObstacle = 0;
    updateChanceOfNewObstacle = .005;
}
