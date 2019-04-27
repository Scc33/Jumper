#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"
#include "game.hpp"
#include "player.hpp"
#include "mainMenu.hpp"
#include "highScoreMenu.hpp"
#include "marketMenu.hpp"
#include "settingsMenu.hpp"
#include "gameEndedMenu.hpp"
#include "globals.hpp"

class ofApp : public ofBaseApp {
private:
    const char menuButton = 'm';
    const int cellSize = 10;
    
    Game game;
    mainMenu mainM;
    highScoreMenu hScoreM;
    marketMenu marketM;
    settingsMenu settingsM;
    gameEndedMenu gameEndedM;
    
    bool gameStarted;

    Player player;
    ofxGameOfLife grid;
    double posX;
    double posY;
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
};
