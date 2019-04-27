#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetWindowTitle("Game");
    ofSetFullscreen(true);
    ofSetFrameRate(60);
    
    int backgroundColor = 0;
    loader::ReadSettings(settingsFileLoc, backgroundColor);
    ofBackgroundHex(backgroundColor);
    
    posX = 1;
    posY = 1;
    gameStarted = startMenuRunning;

    player.setPlayer(posX, posY, cellSize);
    grid.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    game.setGameGrid(grid.getCols(), grid.getRows(), cellSize);
    game.setGamePlayer(player);
    
    mainM.setMainMenu(grid.getCols(), grid.getRows(), cellSize);
    mainM.setMainMenuPlayer(player);
    mainM.setupButtons();
    
    hScoreM.setupHScoreButtons();
    hScoreM.updateHighScores();
    
    marketM.setupMarketButtons();
    
    settingsM.setupSettingsButtons();
    
    gameEndedM.setupEndgameButtons();
}

//--------------------------------------------------------------
void ofApp::update() {
    if (startMenuRunning != gameStarted) {
        game.setupGame();
        gameStarted = startMenuRunning;
    }
    
    if (game.keyIsDown[menuButton]) {
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
        if (game.hasCollided()) {
            gameRunning = false;
            gameEndedScreen = true;
            
            gameEndedM.setNewScore(game.getScore());
            gameEndedM.highScoreInput->setFocused(true);
        }
        game.runGame();
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
        game.drawGame();
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
    game.keyIsDown[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    game.keyIsDown[key] = false;
}
