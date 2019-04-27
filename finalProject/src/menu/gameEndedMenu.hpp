#pragma once

#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "load.hpp"
#include "highScoreCalculator.hpp"
#include "globals.hpp"

class gameEndedMenu {
private:
    double score;
    std::string newHighScoreName;
    
    std::vector<int> highScores;
    std::vector<std::string> highScoreNames;
    
    ofxDatGuiButton* highScoreConfirm;
    
public:
    ofxDatGuiTextInput* highScoreInput;
    
    bool newHighScore;
    
    gameEndedMenu();
    
    void runGameEnded();
    void drawGameEnded();
    
    void setupEndgameButtons();
    void setNewScore(int setScore);
    void setHighScores(std::vector<int> setHighScores,
                       std::vector<std::string> setHighScoreNames);
    
    bool isHighScore();
    
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onTextInputEvent(ofxDatGuiTextInputEvent e);
};
