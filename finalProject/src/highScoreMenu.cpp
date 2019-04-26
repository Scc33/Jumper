#include "highScoreMenu.hpp"

highScoreMenu::highScoreMenu() {

}

void highScoreMenu::setupHScoreButtons() {
    hScoresBackButton = new ofxDatGuiButton("Back");
    
    hScoresBackButton->onButtonEvent(this, &highScoreMenu::onButtonEvent);
    
    hScoresBackButton->setPosition(ofGetWidth()/2 - hScoresBackButton->getWidth()/2, ofGetHeight()/2 + 90);
    
    hScoresBackButton->setTheme(gameTheme);
}

void highScoreMenu::runHScoreMenu() {
    hScoresBackButton->update();
}

void highScoreMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == hScoresBackButton) {
        startMenuRunning = true;
        hScoreMenuRunning = false;
    }
}
