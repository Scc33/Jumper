#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"
#include "ofxDatGui.h"
#include "player.hpp"

class ofApp : public ofBaseApp {
private:
    const int cellSize = 10;
    const char menuButton = 'm';
    double airtime = 0;
    double chanceOfNewObstacle;
    double updateChanceOfNewObstacle;
    Player player;
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void runGame();
    void drawGame();
    
    void runStartMenu();
    void drawStartMenu();
    
    void runMarket();
    void drawMarket();
    
    void runSettingsMenu();
    void drawSettingsMenu();
    
    void drawHighScores();
    
    //Draw game
    void drawPlayer();
    void drawGridLines();
    void drawObstacles();
    
    //Game functionality
    ofxGameOfLife game;
    std::vector<int> obstacles;
    int gravityCalculation();
    double posX;
    double posY;
    double velX;
    double velY;
    bool hasCollided();
    
    //For controls
    bool keyIsDown[255];
    
    //Control flow variables
    bool startMenuRunning;
    bool gameRunning;
    bool gameEnded;
    bool marketMenuRunning;
    bool settingsRunning;
    bool hScoreMenuRunning;
    
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
    void updateButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
