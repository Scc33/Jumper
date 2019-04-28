#pragma once
#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"
#include "load.hpp"

class marketMenu {
private:
    ofxDatGuiButton* blueThemeButton;
    ofxDatGuiButton* greenThemeButton;
    ofxDatGuiButton* purpleThemeButton;
    ofxDatGuiButton* marketBackButton;
    
public:
    marketMenu();
    
    void runMarket();
    void drawMarket();
    
    void setupMarketButtons();
    
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
