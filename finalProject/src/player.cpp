#include "player.hpp"
#include "ofMain.h"

Player::Player() {
    
}

void Player::setPlayer(double setX, double setY, int setCellSize) {
    posX = setX;
    posY = setY;
    cellSize = setCellSize;
}

void Player::updatePlayerLocation(double updateX, double updateY) {
    posX = updateX;
    posY = updateY;
}

void Player::drawPlayer() {
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
