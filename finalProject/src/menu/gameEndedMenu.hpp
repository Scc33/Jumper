#pragma once

#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "load.hpp"
#include "globals.hpp"

class gameEndedMenu {
private:
    double score;
    bool newHighScore;
    std::string newHighScoreName;
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
    ofxDatGuiTextInput* highScoreInput;
    ofxDatGuiButton* highScoreConfirm;
    
public:
    gameEndedMenu();
    
    void runGameEnded();
    void drawGameEnded();
    
    void setupEndgameButtons();
    void setHighScores(std::vector<int> setHighScores,
                       std::vector<std::string> setHighScoreNames);
    
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onTextInputEvent(ofxDatGuiTextInputEvent e);
};
