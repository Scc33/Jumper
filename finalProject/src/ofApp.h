#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"
#include "ofxDatGui.h"
#include "player.hpp"
#include "mainMenu.hpp"
#include "highScoreMenu.hpp"
#include "marketMenu.hpp"
#include "settingsMenu.hpp"
#include "gameEndedMenu.hpp"
#include "load.hpp"
#include "highScoreCalculator.hpp"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"

class ofApp : public ofBaseApp {
private:
    const ofxDatGuiTheme *gameTheme = new ofxDatGuiGameTheme(16);
    const int cellSize = 10;
    const char menuButton = 'm';
    
    mainMenu mainM;
    highScoreMenu hScoreM;
    marketMenu marketM;
    settingsMenu settingsM;
    gameEndedMenu gameEndedM;
    
    bool gameStarted;
    double airtime;
    double chanceOfNewObstacle;
    double updateChanceOfNewObstacle;
    Player player;
    double score;
    bool newHighScore;
    std::string newHighScoreName;
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
    //For controls
    bool keyIsDown[255];
    
public:
    //openFrameworks functions
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    
    void runGame();
    void drawGame();
    void setupGame();
    
    void runGameEnded();
    void drawGameEnded();
    
    //Game functionality
    ofxGameOfLife game;
    double posX;
    double posY;
    double velX;
    double velY;
    std::vector<int> obstacles;
    
    void drawObstacles();
    int gravityCalculation();
    bool hasCollided();
    bool isHighScore();
};
