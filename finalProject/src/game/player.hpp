#pragma once

class Player {
private:
    double posX;
    double posY;
    int cellSize;
    
public:
    Player();
    
    void setPlayer(double setX, double setY, int setCellSize);
    
    void updatePlayerLocation(double updateX, double updateY);
    
    void drawPlayer();
    
    double getPosX() const;
    double getPosY() const;
};
