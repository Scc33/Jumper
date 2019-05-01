#pragma once
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"
#include "load.hpp"

class marketMenu {
private:
    ofxDatGuiButton* redThemeButton;
    ofxDatGuiButton* blueThemeButton;
    ofxDatGuiButton* greenThemeButton;
    ofxDatGuiButton* purpleThemeButton;
    ofxDatGuiButton* marketBackButton;
    
    //Flag to determine if not enough money warning should be drawn
    bool littleMoney;
    
public:
    marketMenu();
    
    void runMarket();
    void drawMarket();
    
    void setupMarketButtons();
    
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
