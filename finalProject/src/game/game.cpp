#include "game.hpp"
#include "ofApp.h"

Game::Game() {}

void Game::setGameGrid(int gridCols, int gridRows, int setCellSize) {
    gameCols = gridCols;
    gameRows = gridRows;
    cellSize = setCellSize;
}

void Game::setGamePlayer(Player &setPlayer) {
    player = setPlayer;
}

void Game::drawObstacles() {
    ofSetColor(200,50,50);
    ofFill();
    
    for (int i = 0; i < obstacles.size(); i++) {
        ofDrawRectangle(obstacles.at(i), gameRows * cellSize - 340, cellSize, cellSize * 4);
        obstacles.at(i) -= 2;
        
        if (obstacles.at(i) < 0) {
            obstacles.erase(obstacles.begin());
            score++;
        }
    }
}

//This doesn't seem to work from some angles (Or too fast?)
bool Game::hasCollided() const {
    for (int obstacle : obstacles) {
        if (posX * cellSize <= obstacle && posX * cellSize >= obstacle - cellSize && posY > gameRows - 36) {
            return true;
        }
    }
    
    return false;
}

//Needs tweaking to look better
int Game::gravityCalculation() {
    if (posY < gameRows - 34) {
        airtime += .02;
        posY += 1 * airtime * airtime;
    } else {
        airtime = 0;
    }
    
    //Keep player from going inside the ground
    if (posY > gameRows - 34) {
        posY = gameRows - 34;
        airtime = 0;
    }
}

void Game::runGame() {
    if (keyIsDown[' ']) {
        posY -= .8;
    }
    
    if (keyIsDown['a']) {
        posX -= .8;
    }
    
    if (keyIsDown['w']) {
        posY -= .8;
    }
    
    if (keyIsDown['s']) {
        posY += .8;
    }
    
    if (keyIsDown['d']) {
        posX += .8;
    }
    
    if (posX < 1) {
        posX = 1;
    } else if (posX > gameCols - 2) {
        posX = gameCols - 2;
    }
    
    if (posY < 1) {
        posY = 1;
    } else if (posY > gameRows - 4) {
        posY = gameRows - 4;
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

void Game::drawGame() {
    ofSetColor(255,0,0);
    ofFill();
    ofDrawRectangle(0, gameRows * cellSize - 300, gameCols * cellSize, 300);
    
    drawObstacles();
    
    player.drawPlayer();
    
    ofDrawBitmapString("Your score is " + ofToString(score), ofGetWidth() * 4 / 5, ofGetHeight() / 10);
}

void Game::setupGame() {
    airtime = 0;
    score = 0;
    
    posX = 10;
    posY = 1;
    
    obstacles.clear();
    obstacles.push_back(ofGetWidth());
    chanceOfNewObstacle = 0;
    updateChanceOfNewObstacle = .005;
}

int Game::getScore() const {
    return score;
}
