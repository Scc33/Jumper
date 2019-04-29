#pragma once
#include "player.hpp"
#include <vector>

class Game {
private:
    double airtime;
    double chanceOfNewObstacle;
    double updateChanceOfNewObstacle;
    int score;
    int gameCols;
    int gameRows;
    int cellSize;
    double posX;
    double posY;
    double velX;
    double velY;
    std::vector<int> obstacles;
    Player player;
    int speed;
    
    int gravityCalculation();
    void drawObstacles();
    
public:
    bool keyIsDown[255];
    
    Game();
    void setGameGrid(int gridCols, int gridRows, int setCellSize);
    void setGamePlayer(Player &setPlayer);
    
    void runGame();
    void drawGame();
    void setupGame();
    
    bool hasCollided() const;
    
    int getScore() const;
};
