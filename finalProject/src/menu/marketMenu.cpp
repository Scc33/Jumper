#include "marketMenu.hpp"

marketMenu::marketMenu() {}

void marketMenu::runMarket() {
    blueThemeButton->update();
    greenThemeButton->update();
    purpleThemeButton->update();
    marketBackButton->update();
}

void marketMenu::drawMarket() {
    blueThemeButton->draw();
    greenThemeButton->draw();
    purpleThemeButton->draw();
    marketBackButton->draw();
    
    ofDrawBitmapString("Your total money is " + ofToString(totalMoney), ofGetWidth() * 4 / 5, ofGetHeight() / 10);
}

void marketMenu::setupMarketButtons() {
    blueThemeButton = new ofxDatGuiButton("Blue player");
    greenThemeButton = new ofxDatGuiButton("Green player");
    purpleThemeButton = new ofxDatGuiButton("Purple player");
    marketBackButton = new ofxDatGuiButton("Back");
    
    blueThemeButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    greenThemeButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    purpleThemeButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    marketBackButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    
    blueThemeButton->setPosition(ofGetWidth()/2 - blueThemeButton->getWidth()/2, ofGetHeight()/2 - 90);
    greenThemeButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 45);
    purpleThemeButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 90);
    marketBackButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 135);
    
    blueThemeButton->setTheme(new ofxDatGuiGameTheme(16));
    greenThemeButton->setTheme(new ofxDatGuiGameTheme(16));
    purpleThemeButton->setTheme(new ofxDatGuiGameTheme(16));
    marketBackButton->setTheme(new ofxDatGuiGameTheme(16));
}

void marketMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == marketBackButton) {
        startMenuRunning = true;
        marketMenuRunning = false;
    } else if (e.target == blueThemeButton) {
        
    } else if (e.target == greenThemeButton) {
        
    } else if (e.target == purpleThemeButton) {
        
    }
}
