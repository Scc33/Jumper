#pragma once
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "player.hpp"

class mainMenu {
private:
    double posX;
    double posY;
    double velX;
    double velY;
    
    int gameCols;
    int gameRows;
    int cellSize;
    
    ofxDatGuiButton* startGameButton;
    ofxDatGuiButton* marketButton;
    ofxDatGuiButton* settingsButton;
    ofxDatGuiButton* highScoreButton;
    ofxDatGuiButton* exitButton;
    
    Player player;

public:
    mainMenu();
    
    void setMainMenu(int setGameCols, int setGameRows, int setCellSize);
    void setMainMenuPlayer(double setX, double setY, double setVelX, double setVelY);
    
    void runStartMenu();
    void drawStartMenu();
    
    //Buttons
    void setupButtons();
    void updateButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
