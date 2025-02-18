#pragma once

#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"
#include "load.hpp"

class settingsMenu {
private:
    ofxDatGuiDropdown* colorMenu;
    ofxDatGuiButton* fullScreenButton;
    ofxDatGuiButton* windowScreenButton;
    ofxDatGuiButton* hardDifficulty;
    ofxDatGuiButton* easyDifficulty;
    ofxDatGuiButton* settingsBackButton;
    
    bool fullScreen;
    
    vector<string> options;
    string getHex(int hex) const;
    
public:
    //Selected color will be written to file
    vector<ofColor> colors;
    
    settingsMenu();
    
    void runSettingsMenu();
    void drawSettingsMenu();
    
    void setupSettingsButtons();
    
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
};
