#pragma once

#include "ofxDatGui.h"
#include "ofxDatGuiGameTheme.h"
#include "globals.hpp"
#include "load.hpp"

class settingsMenu {
private:
    ofxDatGuiButton* confirmSettingsButton;
    ofxDatGuiDropdown* colorMenu;
    ofxDatGuiButton* settingsBackButton;
    
    bool fullScreen;
    double speed;
    
    vector<string> options;
    string getHex(int hex) const;
    
public:
    vector<ofColor> colors;
    
    settingsMenu();
    
    void runSettingsMenu();
    void drawSettingsMenu();
    
    void setupSettingsButtons();
    
    void onButtonEvent(ofxDatGuiButtonEvent e);
    void onDropdownEvent(ofxDatGuiDropdownEvent e);
};
