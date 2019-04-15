#pragma once
#include "ofApp.h"
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"

class mainMenu {
private:
    double posX;
    double posY;
    double velX;
    double velY;
    
    ofxDatGuiButton* startGameButton;
    ofxDatGuiButton* marketButton;
    ofxDatGuiButton* settingsButton;
    ofxDatGuiButton* highScoreButton;
    ofxDatGuiButton* exitButton;

public:
    mainMenu();
    
    void runStartMenu();
    void drawStartMenu();
    
    //Buttons
    void setupButtons();
    void updateButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
