#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"

class ofApp : public ofBaseApp {
private:
    const int cellSize = 8;
    
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
    
    void setScreenSize();
    void setInitialBackground();
    
    void drawPlayer();
    
    int screenW;
    int screenH;
    
    float ballPositionX;
    float ballPositionY;
    float ballVelocityX;
    float ballVelocityY;
    
    float backgroundY;
    float backgroundX[10];
    
    bool keyIsDown[255];
};
