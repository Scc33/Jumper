#pragma once
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"
#include "load.hpp"

class highScoreMenu {
private:
    ofxDatGuiButton* hScoresBackButton;
    
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
public:
    highScoreMenu();
    
    void setupHScoreButtons();
    void updateHighScores();
    
    void runHScoreMenu();
    
    void drawHighScores();

    void onButtonEvent(ofxDatGuiButtonEvent e);
};
