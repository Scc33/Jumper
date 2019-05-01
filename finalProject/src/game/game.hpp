#pragma once
#include "player.hpp"
#include <vector>

class Game {
private:
    //Score += 1 or += 2 depending on the difficulty setting
    int score;
    
    //Game size
    int gameCols;
    int gameRows;
    int cellSize;
    
    //Player position
    double posX;
    double posY;
    
    //Used for gravity calculations
    double airtime;

    double chanceOfNewObstacle;
    double updateChanceOfNewObstacle;
    std::vector<int> obstacles;
    
    //Player that is drawn and moves around the map
    Player player;
    
    //Speed the obstacles move at
    double speed;
    
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
