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
    
    void drawPlayer();
    void drawGridLines();
    void drawPlatform(int start);
    void updatePlatformPosition();
    
    int gravityCalculation();
    
    float ballPositionX;
    float ballPositionY;
    float ballVelocityX;
    float ballVelocityY;
    
    bool keyIsDown[255];
    std::vector<int> starts;
    
    bool gameRunning;
    
    //Menu stuff
    int numClicks;
    bool isFullscreen;
    ofxDatGuiButton* button;
    ofxDatGuiButton* startGameButton;
    //ofxDatGuiButton* toggle;
    void positionButtons();
    void onButtonEvent(ofxDatGuiButtonEvent e);
};
