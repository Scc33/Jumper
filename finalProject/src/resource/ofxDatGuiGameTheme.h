#pragma once
#include "ofxDatGuiTheme.h"

//Theme used by all ofxDatGui buttons throughout the game
class ofxDatGuiGameTheme: public ofxDatGuiTheme {
public:
    ofxDatGuiGameTheme(int fontSize) {
        stripe.visible = false;
        color.label = hex(0xF8F3F0);
        color.guiBackground = hex(0x7d7066);
        color.background = hex(0x4C4743);
        color.inputAreaBackground = hex(0xB5BCB2);
        color.slider.fill = hex(0xFFB230);
        color.slider.text = hex(0xF8F3F0);
        color.textInput.text = hex(0xF8F3F0);
        color.textInput.highlight = hex(0x4C4743);
        color.textInput.backgroundOnActive = hex(0x7d7066);
        color.backgroundOnMouseOver = hex(0x7d7066);
        color.backgroundOnMouseDown = hex(0x333333);
        color.matrix.hover.button = hex(0xC3A279);
        color.matrix.selected.button = hex(0x7d7066);
        font.size = fontSize;
        init();
    }
};
