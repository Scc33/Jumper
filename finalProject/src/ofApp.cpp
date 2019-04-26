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
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    //Position the buttons in the middle of the screen and register to listen for events
    //setupStartButtons();
    setupEndgame();
    
    loader::ReadScores(hScoreFileLoc, highScores, highScoreNames);
    newHighScore = false;
    newHighScoreName = "";
    
    mainM.setMainMenu(game.getCols(), game.getRows(), cellSize);
    mainM.setMainMenuPlayer(player);
    mainM.setupButtons();
    
    hScoreM.setupHScoreButtons();
    hScoreM.setHighScores(highScores, highScoreNames);
    
    marketM.setupMarketButtons();
    
    settingsM.setupSettingsButtons();
    
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
            newHighScore = isHighScore();
            highScoreInput->setFocused(true);
        }
        runGame();
    } else if (gameEndedScreen) {
        runGameEnded();
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
        drawGameEnded();
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
        ofDrawRectangle(obstacles.at(i), game.getRows() * cellSize - 340, cellSize, cellSize * 4);
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
        if (posX * cellSize <= obstacle && posX * cellSize >= obstacle - cellSize && posY > game.getRows() - 36) {
            return true;
        }
    }
    
    return false;
}

int ofApp::gravityCalculation() {
    if (posY < game.getRows() - 34) {
        airtime += .02;
        posY += 1 * airtime * airtime;
    } else {
        airtime = 0;
    }

    //Keep player from going inside the ground
    if (posY > game.getRows() - 34) {
        posY = game.getRows() - 34;
        airtime = 0;
    }
}

bool ofApp::isHighScore() {
    for (int oldhighScore : highScores) {
        if (score >= oldhighScore) {
            return true;
        }
    }
    
    return false;
}

std::vector<int> ofApp::calcNewHighScores(int score, std::vector<int> oldHighScores, int &pos) {
    std::vector<int> newHighScores;
    bool newScore = false;
    
    for (int i = 0; i < oldHighScores.size(); i++) {
        if (score >= oldHighScores.at(i) && !newScore) {
            newHighScores.push_back(score);
            pos = i;
            newScore = true;
        }
        newHighScores.push_back(oldHighScores.at(i));
    }
    newHighScores.pop_back();
    
    return newHighScores;
}

std::vector<std::string> ofApp::calcNewHighScoreNames(std::string name, std::vector<std::string> oldHighScoreNames, int pos) {
    std::vector<std::string> newHighScoreNames;
    
    int count = 0;
    std::cout << pos << std::endl;
    for (int i = 0; i < oldHighScoreNames.size(); i++) {
        if (count == pos) {
            newHighScoreNames.push_back(name);
        }
        newHighScoreNames.push_back(oldHighScoreNames.at(i));
        count++;
    }
    
    newHighScoreNames.pop_back();

    return newHighScoreNames;
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == highScoreConfirm) {
        startMenuRunning = true;
        gameEndedScreen = false;
        
        int position = 0;
        highScores = calcNewHighScores(score, highScores, position);
        highScoreNames = calcNewHighScoreNames(newHighScoreName, highScoreNames, position);
        
        loader::WriteScores(hScoreFileLoc, highScores, highScoreNames);
        hScoreM.setHighScores(highScores, highScoreNames);
        
        highScoreInput->setFocused(false);
    }
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e) {
    newHighScoreName = e.text;
}

void ofApp::setupEndgame() {
    highScoreInput = new ofxDatGuiTextInput("TEXT INPUT", "Type Something Here");
    highScoreConfirm = new ofxDatGuiButton("Confirm name");
    
    highScoreInput->onTextInputEvent(this, &ofApp::onTextInputEvent);
    highScoreConfirm->onButtonEvent(this, &ofApp::onButtonEvent);
    
    highScoreInput->setWidth(800, .2);
    highScoreInput->setPosition(ofGetWidth()/2 - highScoreInput->getWidth()/2, 240);
    highScoreConfirm->setPosition(ofGetWidth()/2 - highScoreConfirm->getWidth()/2, ofGetHeight()/2 + 80);
    
    highScoreConfirm->setTheme(gameTheme);
}

void ofApp::runGame() {
    game.update();
    
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
    
    if (keyIsDown['s'] && game.getCell(posX, posY + 3).currState != true) {
        posY += .8;
    }
    
    if (keyIsDown['d']) {
        posX += .8;
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
    ofDrawRectangle(0, game.getRows() * cellSize - 300, game.getCols() * cellSize, 300);
    
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

void ofApp::runGameEnded() {
    highScoreInput->update();
    highScoreConfirm->update();
}

void ofApp::drawGameEnded() {
    if (newHighScore) {
        ofDrawBitmapString("Congrats on the new High Score", 100, 100);
        ofDrawBitmapString("Your score was... " + ofToString(score), 150, 150);
        ofDrawBitmapString("Please enter in your name", 200, 200);
        highScoreInput->draw();
        highScoreConfirm->draw();
    } else {
        ofDrawBitmapString("Game over", 100, 100);
        ofDrawBitmapString("Your score was... " + ofToString(score), 150, 150);
        ofDrawBitmapString("Press 'm' to go to the main colorMenu", 200, 200);
    }
}
