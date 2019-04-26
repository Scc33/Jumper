#pragma once
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"

class highScoreMenu {
private:
    const ofxDatGuiTheme *gameTheme = new ofxDatGuiGameTheme(16);
    ofxDatGuiButton* hScoresBackButton;
    
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
public:
    highScoreMenu();
    
    void setupHScoreButtons();
    void setHighScores(std::vector<int> setHighScores, std::vector<std::string> setHighScoreNames);
    
    void runHScoreMenu();
    
    void drawHighScores();

    void onButtonEvent(ofxDatGuiButtonEvent e);
};
