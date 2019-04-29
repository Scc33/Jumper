#include "player.hpp"

Player::Player() {
    colors.push_back(ofColor::fromHex(16764939));
    colors.push_back(ofColor::fromHex(3121622));
    colors.push_back(ofColor::fromHex(2020207));
    colors.push_back(ofColor::fromHex(12989014));
    colors.push_back(ofColor::fromHex(3289650));
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
    ofSetColor(colors[playerColor]);
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

double Player::getPosX() const {
    return posX;
}

double Player::getPosY() const {
    return posY;
}
