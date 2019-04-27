#include "gameEndedMenu.hpp"

gameEndedMenu::gameEndedMenu() {}

void gameEndedMenu::setupEndgameButtons() {
    highScoreInput = new ofxDatGuiTextInput("TEXT INPUT", "Type Something Here");
    highScoreConfirm = new ofxDatGuiButton("Confirm name");
    
    highScoreInput->onTextInputEvent(this, &gameEndedMenu::onTextInputEvent);
    highScoreConfirm->onButtonEvent(this, &gameEndedMenu::onButtonEvent);
    
    highScoreInput->setWidth(800, .2);
    highScoreInput->setPosition(ofGetWidth()/2 - highScoreInput->getWidth()/2, 240);
    highScoreConfirm->setPosition(ofGetWidth()/2 - highScoreConfirm->getWidth()/2, ofGetHeight()/2 + 80);
    
    highScoreConfirm->setTheme(new ofxDatGuiGameTheme(16));
}

void gameEndedMenu::setNewScore(int setScore) {
    score = setScore;
}

void gameEndedMenu::runGameEnded() {
    highScoreInput->update();
    highScoreConfirm->update();
}

void gameEndedMenu::drawGameEnded() {
    if (newHighScore) {
        ofDrawBitmapString("Congrats on the new High Score", 100, 100);
        ofDrawBitmapString("Your score was... " + ofToString(score), 150, 150);
        ofDrawBitmapString("Please enter in your name", 200, 200);
        highScoreInput->draw();
        highScoreConfirm->draw();
    } else {
        ofDrawBitmapString("Game over", 100, 100);
        ofDrawBitmapString("Your score was... " + ofToString(score), 150, 150);
        ofDrawBitmapString("Press 'm' to go to the main colorMenu", 200, 200);
    }
}

bool gameEndedMenu::isHighScore() {
    for (int oldhighScore : highScores) {
        if (score >= oldhighScore) {
            return true;
        }
    }
    
    return false;
}

void gameEndedMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    if (e.target == highScoreConfirm) {
        startMenuRunning = true;
        gameEndedScreen = false;
        
        int position = 0;
        highScores = highScoreCalculator::calcNewHighScores(score, highScores, position);
        highScoreNames = highScoreCalculator::calcNewHighScoreNames(newHighScoreName, highScoreNames, position);
        
        loader::WriteScores(hScoreFileLoc, highScores, highScoreNames);
        
        highScoreInput->setFocused(false);
    }
}

void gameEndedMenu::onTextInputEvent(ofxDatGuiTextInputEvent e) {
    newHighScoreName = e.text;
}
