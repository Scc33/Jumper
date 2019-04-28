#pragma once
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "player.hpp"
#include "globals.hpp"
#include "load.hpp"

class mainMenu {
private:
    double posX;
    double posY;
    double velX;
    double velY;
    
    int gameCols;
    int gameRows;
    int cellSize;
    
    //Start menu buttons
    ofxDatGuiButton* startGameButton;
    ofxDatGuiButton* marketButton;
    ofxDatGuiButton* settingsButton;
    ofxDatGuiButton* highScoreButton;
    ofxDatGuiButton* exitButton;
    
    //Settings menu buttons
    ofxDatGuiButton* confirmSettingsButton;
    ofxDatGuiButton* settingsBackButton;
    
    Player player;

public:
    mainMenu();
    
    void setMainMenu(int setGameCols, int setGameRows, int setCellSize);
    void setMainMenuPlayer(Player &setPlayer);
    
    void runStartMenu();
    void drawStartMenu();
    
    //Buttons
    void setupButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
    
    int getCols() const;
    int getRows() const;
    int getPosX() const;
    int getPosY() const;
};
