#pragma once
#include "globals.hpp"
#include "ofMain.h"
#include <vector>
#include "load.hpp"

class Player {
private:
    double posX;
    double posY;
    int cellSize;
    std::vector<ofColor> colors;
    
public:
    Player();
    
    void setPlayer(double setX, double setY, int setCellSize);
    
    void updatePlayerLocation(double updateX, double updateY);
    
    void drawPlayer();
    
    double getPosX() const;
    double getPosY() const;
};
