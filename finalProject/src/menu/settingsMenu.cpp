#include "settingsMenu.hpp"

settingsMenu::settingsMenu() {}

void settingsMenu::runSettingsMenu() {
    settingsBackButton->update();
    colorMenu->update();
    fullScreenButton->update();
    windowScreenButton->update();
    hardDifficulty->update();
    easyDifficulty->update();
}

void settingsMenu::drawSettingsMenu() {
    ofSetColor(255,255,255);
    
    settingsBackButton->draw();
    colorMenu->draw();
    fullScreenButton->draw();
    windowScreenButton->draw();
    hardDifficulty->draw();
    easyDifficulty->draw();
    
    ofDrawBitmapString("Changing window status requires restart", ofGetWidth() * 2 / 3, ofGetHeight() / 2);
}

void settingsMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == settingsBackButton) {
        startMenuRunning = true;
        settingsRunning = false;
    } else if (e.target == fullScreenButton) {
        int color = 0;
        loader::ReadSettings(settingsFileLoc, color, fullScreen);
        
        fullScreen = true;
        ofSetFullscreen(fullScreen);
        
        loader::WriteSettings(settingsFileLoc, color, fullScreen);
    } else if (e.target == windowScreenButton) {
        int color = 0;
        loader::ReadSettings(settingsFileLoc, color, fullScreen);
        
        fullScreen = false;
        ofSetFullscreen(fullScreen);
        
        loader::WriteSettings(settingsFileLoc, color, fullScreen);
    } else if (e.target == hardDifficulty) {
        difficutlySetting = 2;
    } else if (e.target == easyDifficulty) {
        difficutlySetting = 1;
    }
}

void settingsMenu::onDropdownEvent(ofxDatGuiDropdownEvent e) {
    ofSetBackgroundColor(colors[e.child]);
    colorMenu->setStripeColor(ofColor::white);
    loader::WriteSettings(settingsFileLoc, e.child, fullScreen);
}

void settingsMenu::setupSettingsButtons() {
    settingsBackButton = new ofxDatGuiButton("Back");
    windowScreenButton = new ofxDatGuiButton("Window screen");
    fullScreenButton = new ofxDatGuiButton("Full screen");
    easyDifficulty = new ofxDatGuiButton("Easy difficulty");
    hardDifficulty = new ofxDatGuiButton("Hard difficulty");
    
    settingsBackButton->onButtonEvent(this, &settingsMenu::onButtonEvent);
    windowScreenButton->onButtonEvent(this, &settingsMenu::onButtonEvent);
    fullScreenButton->onButtonEvent(this, &settingsMenu::onButtonEvent);
    easyDifficulty->onButtonEvent(this, &settingsMenu::onButtonEvent);
    hardDifficulty->onButtonEvent(this, &settingsMenu::onButtonEvent);
    
    settingsBackButton->setPosition(ofGetWindowWidth()/2 - settingsBackButton->getWidth()/2, ofGetHeight()/2 - 135);
    windowScreenButton->setPosition(ofGetWidth()/2 - settingsBackButton->getWidth()/2, settingsBackButton->getY() + 45);
    fullScreenButton->setPosition(ofGetWidth()/2 - settingsBackButton->getWidth()/2, settingsBackButton->getY() + 90);
    easyDifficulty->setPosition(ofGetWidth()/2 - settingsBackButton->getWidth()/2, settingsBackButton->getY() + 135);
    hardDifficulty->setPosition(ofGetWidth()/2 - settingsBackButton->getWidth()/2, settingsBackButton->getY() + 180);
    
    settingsBackButton->setTheme(new ofxDatGuiGameTheme(16));
    windowScreenButton->setTheme(new ofxDatGuiGameTheme(16));
    fullScreenButton->setTheme(new ofxDatGuiGameTheme(16));
    easyDifficulty->setTheme(new ofxDatGuiGameTheme(16));
    hardDifficulty->setTheme(new ofxDatGuiGameTheme(16));
    
    colors.push_back(ofColor::fromHex(16764939));
    colors.push_back(ofColor::fromHex(3121622));
    colors.push_back(ofColor::fromHex(2020207));
    colors.push_back(ofColor::fromHex(12989014));
    colors.push_back(ofColor::fromHex(3289650));
    
    vector<string> options;
    for (int i=0; i<colors.size(); i++) {
        options.push_back(getHex(colors[i].getHex()));
    }
    
    colorMenu = new ofxDatGuiDropdown("SELECT A COLOR", options);
    colorMenu->setTheme(new ofxDatGuiGameTheme(16));
    
    colorMenu->setPosition(ofGetWidth()/2 - colorMenu->getWidth()/2, settingsBackButton->getY() + 225);
    
    colorMenu->onDropdownEvent(this, &settingsMenu::onDropdownEvent);
    
    colorMenu->expand();
}

string settingsMenu::getHex(int hex) const {
    // convert decimal value to hex //
    std::stringstream ss;
    ss<< std::hex << hex;
    std::string res(ss.str());
    while(res.size() < 6) {
        res += "0";
    }
    return "#" + ofToUpper(res);
}
