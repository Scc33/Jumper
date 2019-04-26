#include "settingsMenu.hpp"

settingsMenu::settingsMenu() {}

void settingsMenu::runSettingsMenu() {
    confirmSettingsButton->update();
    settingsBackButton->update();
    colorMenu->update();
}

void settingsMenu::drawSettingsMenu() {
    confirmSettingsButton->draw();
    settingsBackButton->draw();
    colorMenu->draw();
}

void settingsMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == settingsBackButton) {
        startMenuRunning = true;
        settingsRunning = false;
    } else if (e.target == confirmSettingsButton) {
        
    }
}

void settingsMenu::onDropdownEvent(ofxDatGuiDropdownEvent e) {
    ofSetBackgroundColor(colors[e.child]);
    colorMenu->setStripeColor(ofColor::white);
}

void settingsMenu::setupSettingsButtons() {
    confirmSettingsButton = new ofxDatGuiButton("Confirm");
    settingsBackButton = new ofxDatGuiButton("Back");
    
    confirmSettingsButton->onButtonEvent(this, &settingsMenu::onButtonEvent);
    settingsBackButton->onButtonEvent(this, &settingsMenu::onButtonEvent);
    
    confirmSettingsButton->setPosition(ofGetWidth()/2 - confirmSettingsButton->getWidth()/2, ofGetHeight()/2 - 90);
    settingsBackButton->setPosition(ofGetWidth()/2 - settingsBackButton->getWidth()/2, confirmSettingsButton->getY() + 45);
    
    confirmSettingsButton->setTheme(new ofxDatGuiGameTheme(16));
    settingsBackButton->setTheme(new ofxDatGuiGameTheme(16));
    
    colors.push_back(ofColor::fromHex(0xFFD00B));
    colors.push_back(ofColor::fromHex(0x2FA1D6));
    colors.push_back(ofColor::fromHex(0x1ED36F));
    colors.push_back(ofColor::fromHex(0xC63256));
    colors.push_back(ofColor::fromHex(0x323232));
    
    vector<string> options;
    for (int i=0; i<colors.size(); i++) { options.push_back(getHex(colors[i].getHex()));
    }
    
    colorMenu = new ofxDatGuiDropdown("SELECT A COLOR", options);
    colorMenu->setTheme(new ofxDatGuiGameTheme(16));
    
    colorMenu->setPosition(ofGetWidth()/2 - colorMenu->getWidth()/2, confirmSettingsButton->getY() + 90);
    
    /*for (int i=0; i<colorMenu->size(); i++) { colorMenu->getChildAt(i)->setStripeColor(colors[i]);
     }*/
    
    colorMenu->onDropdownEvent(this, &settingsMenu::onDropdownEvent);
    
    colorMenu->expand();
}

string settingsMenu::getHex(int hex) {
    // convert decimal value to hex //
    std::stringstream ss;
    ss<< std::hex << hex;
    std::string res ( ss.str() );
    while(res.size() < 6) res+="0";
    return "#"+ofToUpper(res);
}
