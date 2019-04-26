#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"
#include "ofxDatGui.h"
#include "player.hpp"
#include "mainMenu.hpp"
#include "highScoreMenu.hpp"
#include "load.hpp"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"

class ofApp : public ofBaseApp {
private:
    const ofxDatGuiTheme *gameTheme = new ofxDatGuiGameTheme(16);
    const int cellSize = 10;
    const char menuButton = 'm';
    
    mainMenu mainM;
    highScoreMenu hScoreM;
    
    bool fullScreen;
    double speed;
    vector<ofColor> colors;
    vector<string> options;
    string getHex(int hex);
    
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
    bool isHighScore();
    std::vector<int> calcNewHighScores(int score, std::vector<int> oldHighScores, int &pos);
    std::vector<std::string> calcNewHighScoreNames(std::string name, std::vector<std::string> oldHighScoreName, int pos);
    
    //Endamge high score input
    ofxDatGuiTextInput* highScoreInput;
    ofxDatGuiButton* highScoreConfirm;
    void setupEndgame();
    
    //Market menu buttons
    ofxDatGuiButton* blueThemeButton;
    ofxDatGuiButton* greenThemeButton;
    ofxDatGuiButton* purpleThemeButton;
    ofxDatGuiButton* marketBackButton;
    void setupMarketButtons();
    
    //Settings menu buttons
    ofxDatGuiButton* confirmSettingsButton;
    ofxDatGuiDropdown* colorMenu;
    ofxDatGuiButton* settingsBackButton;
    void setupSettingsButtons();

    //Functions to handle all DatGui events
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onTextInputEvent(ofxDatGuiTextInputEvent e);
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
};
