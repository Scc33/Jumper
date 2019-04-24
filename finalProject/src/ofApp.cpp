#include "ofApp.h"
#include "ofxDatGuiGameTheme.h"

/*
 Functions to run openFrameworks
 */

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

    player.setPlayer(posX, posY, cellSize);
    
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    //Position the buttons in the middle of the screen and register to listen for events
    setupStartButtons();
    setupMarketButtons();
    setupSettingsButtons();
    setupHScoreButtons();
    
    startMenuRunning = true;
    gameRunning = false;
    gameEndedScreen = false;
    marketMenuRunning = false;
    settingsRunning = false;
    hScoreMenuRunning = false;
    
    loader::ReadScores("/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/highScores.txt", highScores);
}

//--------------------------------------------------------------
void ofApp::update() {
    if (keyIsDown[menuButton]) {
        startMenuRunning = true;
        gameRunning = false;
        gameEndedScreen = false;
        marketMenuRunning = false;
        settingsRunning = false;
        hScoreMenuRunning = false;
    }
    
    if (startMenuRunning) {
        runStartMenu();
    } else if (gameRunning) {
        if (hasCollided()) {
            gameRunning = false;
            gameEndedScreen = true;
            highScores = calcNewHighScores(score, highScores);
            loader::WriteScores("/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/highScores.txt", highScores);
        }
        runGame();
    } else if (marketMenuRunning) {
        runMarket();
    } else if (settingsRunning) {
        runSettingsMenu();
    } else if (hScoreMenuRunning) {
        runHighScores();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (startMenuRunning) {
        ofShowCursor();
        drawStartMenu();
    } else if (gameRunning) {
        ofHideCursor();
        drawGame();
    } else if (gameEndedScreen) {
        drawGameEnded();
    } else if (marketMenuRunning) {
        drawMarket();
    } else if (settingsRunning) {
        drawSettingsMenu();
    } else if (hScoreMenuRunning) {
        drawHighScores();
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
    ofSetColor(255,0,0);
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

std::vector<int> ofApp::calcNewHighScores(int score, std::vector<int> oldHighScores) {
    std::vector<int> newHighScores;
    bool newScore = false;
    
    for (int i = 0; i < oldHighScores.size(); i++) {
        if (score >= oldHighScores.at(i) && !newScore) {
            newHighScores.push_back(score);
            newScore = true;
        }
        newHighScores.push_back(oldHighScores.at(i));
    }
    
    if (newScore) {
        newHighScores.pop_back();
    }
    
    return newHighScores;
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == startGameButton) {
        std::cout << 0 << std::endl;
        startMenuRunning = false;
        gameRunning = true;
        setupGame();
    } else if (e.target == marketButton) {
        std::cout << 1 << std::endl;
        startMenuRunning = false;
        marketMenuRunning = true;
    } else if (e.target == settingsButton) {
        std::cout << 2 << std::endl;
        startMenuRunning = false;
        settingsRunning = true;
    } else if (e.target == highScoreButton) {
        std::cout << 3 << std::endl;
        startMenuRunning = false;
        hScoreMenuRunning = true;
    } else if (e.target == exitButton) {
        std::cout << 4 << std::endl;
        ofExit();
    } else if (e.target == marketBackButton) {
        std::cout << 5 << std::endl;
        startMenuRunning = true;
        marketMenuRunning = false;
    } else if (e.target == settingsBackButton) {
        std::cout << 6 << std::endl;
        startMenuRunning = true;
        settingsRunning = false;
    } else if (e.target == hScoresBackButton) {
        std::cout << 7 << std::endl;
        startMenuRunning = true;
        hScoreMenuRunning = false;
    } else if (e.target == blueThemeButton) {
        
    } else if (e.target == greenThemeButton) {
        
    } else if (e.target == purpleThemeButton) {
        
    } else if (e.target == confirmSettingsButton) {
        
    }
}

void ofApp::setupStartButtons() {
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
    
    startGameButton->setPosition(ofGetWidth()/2 - startGameButton->getWidth()/2, ofGetHeight()/2 - 90);
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

void ofApp::setupMarketButtons() {
    blueThemeButton = new ofxDatGuiButton("Blue theme");
    greenThemeButton = new ofxDatGuiButton("Green theme");
    purpleThemeButton = new ofxDatGuiButton("Purple theme");
    marketBackButton = new ofxDatGuiButton("Back");
    
    blueThemeButton->onButtonEvent(this, &ofApp::onButtonEvent);
    greenThemeButton->onButtonEvent(this, &ofApp::onButtonEvent);
    purpleThemeButton->onButtonEvent(this, &ofApp::onButtonEvent);
    marketBackButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    blueThemeButton->setPosition(ofGetWidth()/2 - blueThemeButton->getWidth()/2, ofGetHeight()/2 - 90);
    greenThemeButton->setPosition(startGameButton->getX(), blueThemeButton->getY() + 45);
    purpleThemeButton->setPosition(startGameButton->getX(), blueThemeButton->getY() + 90);
    marketBackButton->setPosition(startGameButton->getX(), blueThemeButton->getY() + 135);
    
    blueThemeButton->setTheme(new ofxDatGuiGameTheme(16));
    greenThemeButton->setTheme(new ofxDatGuiGameTheme(16));
    purpleThemeButton->setTheme(new ofxDatGuiGameTheme(16));
    marketBackButton->setTheme(new ofxDatGuiGameTheme(16));
}

void ofApp::setupSettingsButtons() {
    confirmSettingsButton = new ofxDatGuiButton("Confirm");
    settingsBackButton = new ofxDatGuiButton("Back");
    
    confirmSettingsButton->onButtonEvent(this, &ofApp::onButtonEvent);
    settingsBackButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    confirmSettingsButton->setPosition(ofGetWidth()/2 - confirmSettingsButton->getWidth()/2, ofGetHeight()/2 - 90);
    settingsBackButton->setPosition(startGameButton->getX(), confirmSettingsButton->getY() + 45);
    
    confirmSettingsButton->setTheme(new ofxDatGuiGameTheme(16));
    settingsBackButton->setTheme(new ofxDatGuiGameTheme(16));
}

void ofApp::setupHScoreButtons() {
    hScoresBackButton = new ofxDatGuiButton("Back");
    
    hScoresBackButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    hScoresBackButton->setPosition(ofGetWidth()/2 - hScoresBackButton->getWidth()/2, ofGetHeight()/2 + 90);
    
    hScoresBackButton->setTheme(new ofxDatGuiGameTheme(16));
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

void ofApp::drawGameEnded() {
    ofDrawBitmapString("Game over", 100, 100);
    ofDrawBitmapString("Your score was... " + ofToString(score), 150, 150);
    ofDrawBitmapString("Press 'm' to go to the main menu", 200, 200);
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
    
    player.updatePlayerLocation(posX, posY);
    
    startGameButton->update();
    marketButton->update();
    settingsButton->update();
    highScoreButton->update();
    exitButton->update();
}

void ofApp::drawStartMenu() {
    player.drawPlayer();
    
    startGameButton->draw();
    marketButton->draw();
    settingsButton->draw();
    highScoreButton->draw();
    exitButton->draw();
}

void ofApp::runMarket() {
    blueThemeButton->update();
    greenThemeButton->update();
    purpleThemeButton->update();
    marketBackButton->update();
}

void ofApp::drawMarket() {
    blueThemeButton->draw();
    greenThemeButton->draw();
    purpleThemeButton->draw();
    marketBackButton->draw();
}

void ofApp::runSettingsMenu() {
    confirmSettingsButton->update();
    settingsBackButton->update();
}

void ofApp::drawSettingsMenu() {
    confirmSettingsButton->draw();
    settingsBackButton->draw();
}

void ofApp::runHighScores() {
    hScoresBackButton->update();
}

void ofApp::drawHighScores() {
    int pos = ofGetHeight()/2 - 180;

    for (int score : highScores) {
        ofDrawBitmapString(ofToString(score), ofGetWidth()/2, pos);
        pos += 45;
    }
    
    hScoresBackButton->draw();
}
