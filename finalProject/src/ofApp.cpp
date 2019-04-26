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
    
    /*velX = ofRandom(-0.5,0.5);
    velY = ofRandom(-0.5,0.5);*/

    player.setPlayer(posX, posY, cellSize);
    game.setup(ofGetWidth(), ofGetHeight(), cellSize);
    
    mainM.setMainMenu(game.getCols(), game.getRows(), cellSize);
    mainM.setMainMenuPlayer(player);
    
    //Position the buttons in the middle of the screen and register to listen for events
    //setupStartButtons();
    setupEndgame();
    setupMarketButtons();
    setupSettingsButtons();
    setupHScoreButtons();
    /*
    startMenuRunning = true;
    gameRunning = false;
    gameEndedScreen = false;
    marketMenuRunning = false;
    settingsRunning = false;
    hScoreMenuRunning = false;*/
    
    mainM.setMainMenu(game.getCols(), game.getRows(), cellSize);
    mainM.setMainMenuPlayer(player);
    mainM.setupButtons();
    
    newHighScore = false;
    newHighScoreName = "";
    
    loader::ReadScores("/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/highScores.txt", highScores, highScoreNames);
    
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
        mainM.drawStartMenu();
    } else if (gameRunning) {
        ofHideCursor();
        drawGame();
    } else if (gameEndedScreen) {
        ofShowCursor();
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


string ofApp::getHex(int hex) {
    // convert decimal value to hex //
    std::stringstream ss;
    ss<< std::hex << hex;
    std::string res ( ss.str() );
    while(res.size() < 6) res+="0";
    return "#"+ofToUpper(res);
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
    if (e.target == startGameButton) {
        startMenuRunning = false;
        gameRunning = true;
        setupGame();
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
    } else if (e.target == marketBackButton) {
        startMenuRunning = true;
        marketMenuRunning = false;
    } else if (e.target == settingsBackButton) {
        startMenuRunning = true;
        settingsRunning = false;
    } else if (e.target == hScoresBackButton) {
        startMenuRunning = true;
        hScoreMenuRunning = false;
    } else if (e.target == blueThemeButton) {
        
    } else if (e.target == greenThemeButton) {
        
    } else if (e.target == purpleThemeButton) {
        
    } else if (e.target == confirmSettingsButton) {
        
    } else if (e.target == highScoreConfirm) {
        startMenuRunning = true;
        gameEndedScreen = false;
        
        int position = 0;
        highScores = calcNewHighScores(score, highScores, position);
        highScoreNames = calcNewHighScoreNames(newHighScoreName, highScoreNames, position);
        
        loader::WriteScores("/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/highScores.txt", highScores, highScoreNames);
        
        highScoreInput->setFocused(false);
    }
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e) {
    newHighScoreName = e.text;
}


void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e) {
    ofSetBackgroundColor(colors[e.child]);
    colorMenu->setStripeColor(ofColor::white);
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
    
    startGameButton->setTheme(gameTheme);
    marketButton->setTheme(gameTheme);
    settingsButton->setTheme(gameTheme);
    highScoreButton->setTheme(gameTheme);
    exitButton->setTheme(gameTheme);
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
    greenThemeButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 45);
    purpleThemeButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 90);
    marketBackButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 135);
    
    blueThemeButton->setTheme(gameTheme);
    greenThemeButton->setTheme(gameTheme);
    purpleThemeButton->setTheme(gameTheme);
    marketBackButton->setTheme(gameTheme);
}

void ofApp::setupSettingsButtons() {
    confirmSettingsButton = new ofxDatGuiButton("Confirm");
    settingsBackButton = new ofxDatGuiButton("Back");
    
    confirmSettingsButton->onButtonEvent(this, &ofApp::onButtonEvent);
    settingsBackButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    confirmSettingsButton->setPosition(ofGetWidth()/2 - confirmSettingsButton->getWidth()/2, ofGetHeight()/2 - 90);
    settingsBackButton->setPosition(ofGetWidth()/2 - settingsBackButton->getWidth()/2, confirmSettingsButton->getY() + 45);
    
    confirmSettingsButton->setTheme(gameTheme);
    settingsBackButton->setTheme(gameTheme);
    
    colors.push_back(ofColor::fromHex(0xFFD00B));
    colors.push_back(ofColor::fromHex(0x2FA1D6));
    colors.push_back(ofColor::fromHex(0x1ED36F));
    colors.push_back(ofColor::fromHex(0xC63256));
    
    vector<string> options;
    for (int i=0; i<colors.size(); i++) { options.push_back(getHex(colors[i].getHex()));
    }
    
    colorMenu = new ofxDatGuiDropdown("SELECT A COLOR", options);
    colorMenu->setTheme(gameTheme);
    
    colorMenu->setPosition(ofGetWidth()/2 - colorMenu->getWidth()/2, confirmSettingsButton->getY() + 90);
    
    /*for (int i=0; i<colorMenu->size(); i++) { colorMenu->getChildAt(i)->setStripeColor(colors[i]);
    }*/
    
    colorMenu->onDropdownEvent(this, &ofApp::onDropdownEvent);
    
    colorMenu->expand();
}

void ofApp::setupHScoreButtons() {
    hScoresBackButton = new ofxDatGuiButton("Back");
    
    hScoresBackButton->onButtonEvent(this, &ofApp::onButtonEvent);
    
    hScoresBackButton->setPosition(ofGetWidth()/2 - hScoresBackButton->getWidth()/2, ofGetHeight()/2 + 90);
    
    hScoresBackButton->setTheme(gameTheme);
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

/*void ofApp::runStartMenu() {
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
}*/

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
    colorMenu->update();
}

void ofApp::drawSettingsMenu() {
    confirmSettingsButton->draw();
    settingsBackButton->draw();
    colorMenu->draw();
}

void ofApp::runHighScores() {
    hScoresBackButton->update();
}

void ofApp::drawHighScores() {
    int pos = ofGetHeight()/2 - 180;

    for (int i = 0; i < highScores.size(); i++) {
        ofDrawBitmapString(highScoreNames.at(i) + " " + ofToString(highScores.at(i)), ofGetWidth()/2 - hScoresBackButton->getWidth()/2, pos);
        pos += 45;
    }
    
    hScoresBackButton->draw();
}
