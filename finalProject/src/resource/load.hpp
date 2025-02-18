#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Functions to load information from files
namespace loader {
    bool WriteScores(std::string fileToWriteTo, std::vector<int> highScores, std::vector<std::string> highScoreNames);
    bool ReadScores(std::string fileToReadFrom, std::vector<int> &highScores, std::vector<std::string> &highScoreNames);
    
    bool WriteSettings(std::string fileToWriteTo, int color, bool fullScreen);
    bool ReadSettings(std::string fileToReadFrom, int &color, bool &fullScreen);
    
    bool WriteMarket(std::string fileToWriteTo, int color);
    bool ReadMarket(std::string fileToReadFrom, int &color);
    
    bool WriteMoney(std::string fileToWriteTo, int money);
    bool ReadMoney(std::string fileToReadFrom, int &money);
}
