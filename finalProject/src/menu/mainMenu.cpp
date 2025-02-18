#include "mainMenu.hpp"

mainMenu::mainMenu() {
    posX = 1;
    posY = 1;
    velX = ofRandom(0.1,0.5);
    velY = ofRandom(0.1,0.5);
    
    player.setPlayer(posX, posY, cellSize);
}

void mainMenu::setMainMenu(int setGameCols, int setGameRows, int setCellSize) {
    gameCols = setGameCols;
    gameRows = setGameRows;
    cellSize = setCellSize;
}

void mainMenu::setMainMenuPlayer(Player &setPlayer) {
    player = setPlayer;
}

void mainMenu::runStartMenu() {
    posX += velX;
    posY += velY;
    
    //Bounces the player around the screen
    if (posX < 1) {
        posX = 1;
        velX *= -1;
    } else if (posX > gameCols - 2) {
        posX = gameCols - 2;
        velX *= -1;
    }
    
    if (posY < 1) {
        posY = 1;
        velY *= -1;
    } else if (posY > gameRows - 4){
        posY = gameRows - 4;
        velY *= -1;
    }
    
    player.updatePlayerLocation(posX, posY);
    
    startGameButton->update();
    marketButton->update();
    settingsButton->update();
    highScoreButton->update();
    exitButton->update();
    
    loader::ReadMoney(moneyFileLoc, totalMoney);
}

void mainMenu::drawStartMenu() {
    player.drawPlayer();
    
    startGameButton->draw();
    marketButton->draw();
    settingsButton->draw();
    highScoreButton->draw();
    exitButton->draw();
    
    ofSetColor(255,255,255);
    ofDrawBitmapString("Your total money is " + ofToString(totalMoney), ofGetWidth() * 4 / 5, ofGetHeight() / 10);
}

void mainMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == startGameButton) {
        startMenuRunning = false;
        gameRunning = true;
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

//Position the buttons in the middle of the screen and register to listen for events
void mainMenu::setupButtons() {
    startGameButton = new ofxDatGuiButton("Start");
    marketButton = new ofxDatGuiButton("Market");
    settingsButton = new ofxDatGuiButton("Settings");
    highScoreButton = new ofxDatGuiButton("High Scores");
    exitButton = new ofxDatGuiButton("Exit");
    
    startGameButton->onButtonEvent(this, &mainMenu::onButtonEvent);
    marketButton->onButtonEvent(this, &mainMenu::onButtonEvent);
    settingsButton->onButtonEvent(this, &mainMenu::onButtonEvent);
    highScoreButton->onButtonEvent(this, &mainMenu::onButtonEvent);
    exitButton->onButtonEvent(this, &mainMenu::onButtonEvent);
    
    startGameButton->setPosition(ofGetWidth()/2 - settingsButton->getWidth()/2, ofGetHeight()/2 - 90);
    marketButton->setPosition(startGameButton->getX(), startGameButton->getY() + 45);
    settingsButton->setPosition(startGameButton->getX(), startGameButton->getY() + 90);
    highScoreButton->setPosition(startGameButton->getX(), startGameButton->getY() + 135);
    exitButton->setPosition(startGameButton->getX(), startGameButton->getY() + 180);
    
    const ofxDatGuiGameTheme *gameTheme = new ofxDatGuiGameTheme(16);
    startGameButton->setTheme(gameTheme);
    marketButton->setTheme(gameTheme);
    settingsButton->setTheme(gameTheme);
    highScoreButton->setTheme(gameTheme);
    exitButton->setTheme(gameTheme);
}

int mainMenu::getCols() const {
    return gameCols;
}

int mainMenu::getRows() const {
    return gameRows;
}

int mainMenu::getPosX() const {
    return posX;
}

int mainMenu::getPosY() const {
    return posY;
}
