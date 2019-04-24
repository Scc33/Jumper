#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace loader {
    bool WriteScores(std::string fileToWriteTo, std::vector<int> highScores, std::vector<std::string> highScoreNames);
    bool ReadScores(std::string fileToReadFrom, std::vector<int> &highScores, std::vector<std::string> &highScoreNames);
    
    bool WriteSettings(std::string fileToWriteTo);
    bool ReadSettings(std::string fileToReadFrom);
}
