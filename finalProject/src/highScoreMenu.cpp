#include "highScoreMenu.hpp"
#include "ofApp.h"

highScoreMenu::highScoreMenu() {

}

void highScoreMenu::setupHScoreButtons() {
    hScoresBackButton = new ofxDatGuiButton("Back");
    
    hScoresBackButton->onButtonEvent(this, &highScoreMenu::onButtonEvent);
    
    hScoresBackButton->setPosition(ofGetWidth()/2 - hScoresBackButton->getWidth()/2, ofGetHeight()/2 + 90);
    
    hScoresBackButton->setTheme(gameTheme);
}

void highScoreMenu::setHighScores(std::vector<int> setHighScores, std::vector<std::string> setHighScoreNames) {
    highScores = setHighScores;
    highScoreNames = setHighScoreNames;
}

void highScoreMenu::drawHighScores() {
    int pos = ofGetHeight()/2 - 180;
    
    for (int i = 0; i < highScores.size(); i++) {
        ofDrawBitmapString(highScoreNames.at(i) + " " + ofToString(highScores.at(i)), ofGetWidth()/2 - hScoresBackButton->getWidth()/2, pos);
        pos += 45;
    }
    
    hScoresBackButton->draw();
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
