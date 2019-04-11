#pragma once

#include "ofMain.h"
#include "ofxGameOfLife.h"

class ofApp : public ofBaseApp {
private:
    const int cellSize = 10;
    
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
    
    float ballPositionX;
    float ballPositionY;
    float ballVelocityX;
    float ballVelocityY;
    
    bool keyIsDown[255];
    int start;
};
