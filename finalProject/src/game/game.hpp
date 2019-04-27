#pragma once
#include "ofxGameOfLife.h"
#include "player.hpp"
#include <vector>

class Game {
private:
    const int cellSize = 10;

    double airtime;
    double chanceOfNewObstacle;
    double updateChanceOfNewObstacle;
    double score;
    ofxGameOfLife grid;
    double posX;
    double posY;
    double velX;
    double velY;
    std::vector<int> obstacles;
    Player player;
    
    int gravityCalculation();
    void drawObstacles();
    
public:
    bool keyIsDown[255];
    
    Game();
    
    void runGame();
    void drawGame();
    void setupGame();
    
    bool hasCollided();
};
