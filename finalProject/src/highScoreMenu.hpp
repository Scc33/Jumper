#pragma once
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"

class highScoreMenu {
private:
    const ofxDatGuiTheme *gameTheme = new ofxDatGuiGameTheme(16);
    ofxDatGuiButton* hScoresBackButton;
    
public:
    highScoreMenu();
    
    void setupHScoreButtons();
    
    void runHScoreMenu();

    void onButtonEvent(ofxDatGuiButtonEvent e);
};
