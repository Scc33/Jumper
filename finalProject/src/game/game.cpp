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
    ofSetColor(255,255,255);
    ofFill();
    
    for (int i = 0; i < obstacles.size(); i++) {
        ofDrawRectangle(obstacles.at(i), gameRows * cellSize - 360, cellSize * 2, cellSize * 6);
        obstacles.at(i) -= speed;
        
        //Detects if an obect is off the screen
        if (obstacles.at(i) + cellSize * 2 < 0) {
            obstacles.erase(obstacles.begin());
            score += 1 * difficultySetting;
            
            //This makes the game faster and increases the number of obstacles
            updateChanceOfNewObstacle += .04 * (difficultySetting / 1.5);
            speed += 0.02 * difficultySetting;
        }
    }
}

//Randomly adds a new obstacle
//Chance of new obstacle being creating increases as game goes on
void Game::obstacleGenerator() {
    chanceOfNewObstacle += ofRandom(0, updateChanceOfNewObstacle);
    if (ofRandom(0, chanceOfNewObstacle) > 18 / (difficultySetting / 1.5)) {
        obstacles.push_back(ofGetWidth());
        chanceOfNewObstacle = 0;
    }
}

//Detects if player has collided with an obstacle
bool Game::hasCollided() const {
    for (int obstacle : obstacles) {
        if (posX * cellSize >= obstacle && posX * cellSize <= obstacle + cellSize * 2 && posY > gameRows - 40) {
            return true;
        }
    }
    
    return false;
}

//Brings player back to the ground
int Game::gravityCalculation() {
    if (posY < gameRows - 34) {
        airtime += .024;
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
    //Controls
    if (keyIsDown[' ']) {
        posY -= .40;
    }
    
    if (keyIsDown['a']) {
        posX -= .60;
    }
    
    if (keyIsDown['w']) {
        posY -= .60;
    }
    
    if (keyIsDown['s']) {
        posY += .60;
    }
    
    if (keyIsDown['d']) {
        posX += .60;
    }
    
    //Keeps from walking out of the screeen
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
    
    obstacleGenerator();
    
    player.updatePlayerLocation(posX, posY);
}

void Game::drawGame() {
    ofSetColor(15,15,15);
    ofFill();
    ofDrawRectangle(0, gameRows * cellSize - 300, gameCols * cellSize, 300);
    
    drawObstacles();
    
    player.drawPlayer();
    
    ofSetColor(255,255,255);
    ofDrawBitmapString("Your score is " + ofToString(score), ofGetWidth() * 4 / 5, ofGetHeight() / 10);
}

//Called each time the game is started and sets up the initial variables
void Game::setupGame() {
    speed = 3 * difficultySetting;
    
    airtime = 0;
    score = 0;
    
    posX = 10;
    posY = 1;
    
    obstacles.clear();
    obstacles.push_back(ofGetWidth());
    chanceOfNewObstacle = 0;
    updateChanceOfNewObstacle = 0.3;
}

int Game::getScore() const {
    return score;
}
