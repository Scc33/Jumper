#pragma once
#include "ofApp.h"

class Player {
private:
    double posX;
    double posY;
    int cellSize;
    
public:
    Player(double setX, double setY, int setCellSize);
    
    void updatePlayerLocation(double updateX, double updateY);
    
    void drawPlayer();
};
