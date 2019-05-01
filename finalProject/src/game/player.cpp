#include "player.hpp"

Player::Player() {
    //Possible players colors
    //Selected using the marketplace
    colors.push_back(ofColor::fromHex(0xff0012)); //Red
    colors.push_back(ofColor::fromHex(0x526eff)); //Blue
    colors.push_back(ofColor::fromHex(0x00ff3e)); //Green
    colors.push_back(ofColor::fromHex(0x7f4fca)); //Purple
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
    loader::ReadMarket(marketFileLoc, playerColor);
    ofSetColor(colors[playerColor]);
    ofFill();
    
    //Center
    ofDrawRectangle(posX*cellSize, posY*cellSize, cellSize, cellSize);
    
    //Arms
    ofDrawRectangle((posX+1)*cellSize, posY*cellSize, cellSize, cellSize);
    ofDrawRectangle((posX-1)*cellSize, posY*cellSize, cellSize, cellSize);
    
    //Torso
    ofDrawRectangle(posX*cellSize, (posY-1)*cellSize, cellSize, cellSize);
    ofDrawRectangle(posX*cellSize, (posY+1)*cellSize, cellSize, cellSize);
    ofDrawRectangle(posX*cellSize, (posY+2)*cellSize, cellSize, cellSize);
    
    //Legs
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
