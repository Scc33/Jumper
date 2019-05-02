#include "marketMenu.hpp"

marketMenu::marketMenu() {
    littleMoney = false;
}

void marketMenu::runMarket() {
    redThemeButton->update();
    blueThemeButton->update();
    greenThemeButton->update();
    purpleThemeButton->update();
    marketBackButton->update();
    
    loader::ReadMoney(moneyFileLoc, totalMoney);
}

void marketMenu::drawMarket() {
    redThemeButton->draw();
    blueThemeButton->draw();
    greenThemeButton->draw();
    purpleThemeButton->draw();
    marketBackButton->draw();
    
    ofSetColor(255,255,255);
    ofDrawBitmapString("Your total money is " + ofToString(totalMoney), ofGetWidth() * 4 / 5, ofGetHeight() / 10);
    
    if (littleMoney) {
        ofDrawBitmapString("You need more money for that", ofGetWidth() * 2 / 3, ofGetHeight() / 2);
    }
}

void marketMenu::setupMarketButtons() {
    redThemeButton = new ofxDatGuiButton("Red Player: 50");
    blueThemeButton = new ofxDatGuiButton("Blue player: 10");
    greenThemeButton = new ofxDatGuiButton("Green player: 0");
    purpleThemeButton = new ofxDatGuiButton("Purple player: 100");
    marketBackButton = new ofxDatGuiButton("Back");
    
    redThemeButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    blueThemeButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    greenThemeButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    purpleThemeButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    marketBackButton->onButtonEvent(this, &marketMenu::onButtonEvent);
    
    redThemeButton->setPosition(ofGetWidth()/2 - redThemeButton->getWidth()/2, ofGetHeight()/2 - 135);
    blueThemeButton->setPosition(ofGetWidth()/2 - blueThemeButton->getWidth()/2, ofGetHeight()/2 - 90);
    greenThemeButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 45);
    purpleThemeButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 90);
    marketBackButton->setPosition(blueThemeButton->getX(), blueThemeButton->getY() + 135);
    
    const ofxDatGuiGameTheme *gameTheme = new ofxDatGuiGameTheme(16);
    redThemeButton->setTheme(gameTheme);
    blueThemeButton->setTheme(gameTheme);
    greenThemeButton->setTheme(gameTheme);
    purpleThemeButton->setTheme(gameTheme);
    marketBackButton->setTheme(gameTheme);
}

void marketMenu::onButtonEvent(ofxDatGuiButtonEvent e) {
    //Creates warning if you don't have enough money otherwise updates the player color
    
    if (e.target == marketBackButton) {
        startMenuRunning = true;
        marketMenuRunning = false;
        littleMoney = false;
    } else if (e.target == redThemeButton) {
        if (totalMoney < 50) {
            littleMoney = true;
        } else {
            littleMoney = false;
            playerColor = 0;
            std::cout << playerColor << std::endl;
        }
    } else if (e.target == blueThemeButton) {
        if (totalMoney < 10) {
            littleMoney = true;
        } else {
            littleMoney = false;
            playerColor = 1;
        }
    } else if (e.target == greenThemeButton) {
        playerColor = 2;
        littleMoney = false;
    } else if (e.target == purpleThemeButton) {
        if (totalMoney < 100) {
            littleMoney = true;
        } else {
            littleMoney = false;
            playerColor = 3;
        }
    }

    loader::WriteMarket(marketFileLoc, playerColor);
}
