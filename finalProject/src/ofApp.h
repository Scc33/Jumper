#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"
#include "ofxDatGui.h"
#include "player.hpp"
#include "load.hpp"

class ofApp : public ofBaseApp {
private:
    const int cellSize = 10;
    const char menuButton = 'm';
    double airtime;
    double chanceOfNewObstacle;
    double updateChanceOfNewObstacle;
    Player player;
    double score;
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
    //For controls
    bool keyIsDown[255];
    
    //Control flow variables
    bool startMenuRunning;
    bool gameRunning;
    bool gameEndedScreen;
    bool marketMenuRunning;
    bool settingsRunning;
    bool hScoreMenuRunning;
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    
    void runGame();
    void drawGame();
    void setupGame();
    
    void drawGameEnded();
    
    void runStartMenu();
    void drawStartMenu();
    
    void runMarket();
    void drawMarket();
    
    void runSettingsMenu();
    void drawSettingsMenu();
    
    void runHighScores();
    void drawHighScores();
    
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
    std::vector<int> calcNewHighScores(int score, std::vector<int> oldHighScores);
    
    //Start menu buttons
    ofxDatGuiButton* startGameButton;
    ofxDatGuiButton* marketButton;
    ofxDatGuiButton* settingsButton;
    ofxDatGuiButton* highScoreButton;
    ofxDatGuiButton* exitButton;
    void setupStartButtons();
    
    //Market menu buttons
    ofxDatGuiButton* blueThemeButton;
    ofxDatGuiButton* greenThemeButton;
    ofxDatGuiButton* purpleThemeButton;
    ofxDatGuiButton* marketBackButton;
    void setupMarketButtons();
    
    //Settings menu buttons
    ofxDatGuiButton* confirmSettingsButton;
    ofxDatGuiButton* settingsBackButton;
    void setupSettingsButtons();
    
    //High score buttons
    ofxDatGuiButton* hScoresBackButton;
    void setupHScoreButtons();

    //Functions for all buttons
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
