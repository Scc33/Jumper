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
}

void marketMenu::setupMarketButtons() {
    blueThemeButton = new ofxDatGuiButton("Blue theme");
    greenThemeButton = new ofxDatGuiButton("Green theme");
    purpleThemeButton = new ofxDatGuiButton("Purple theme");
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
