#include "highScoreMenu.hpp"

highScoreMenu::highScoreMenu() {}

void highScoreMenu::setupHScoreButtons() {
    hScoresBackButton = new ofxDatGuiButton("Back");
    
    hScoresBackButton->onButtonEvent(this, &highScoreMenu::onButtonEvent);
    
    hScoresBackButton->setPosition(ofGetWidth()/2 - hScoresBackButton->getWidth()/2, ofGetHeight()/2 + 90);
    
    hScoresBackButton->setTheme(new ofxDatGuiGameTheme(16));
}

void highScoreMenu::updateHighScores() {
    loader::ReadScores(hScoreFileLoc, highScores, highScoreNames);
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
    updateHighScores();
    hScoresBackButton->update();
}

void highScoreMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == hScoresBackButton) {
        startMenuRunning = true;
        hScoreMenuRunning = false;
    }
}
