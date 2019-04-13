#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp {
private:
    const int cellSize = 5;
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofxGameOfLife game;
    
    //New stuff
    
    void drawPlayer();
    void drawGridLines();
    
    int gravityCalculation();
    
    float posX;
    float posY;
    float velX;
    float velY;
    
    bool keyIsDown[255];
    std::vector<std::vector<int>> platforms;
    
    bool gameRunning;
    
    //Menu stuff
    ofxDatGuiButton* startGameButton;
    ofxDatGuiButton* settingsButton;
    ofxDatGuiButton* highScoreButton;

    void setupButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
