#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace loader {
    bool WriteScores(std::string fileToWriteTo, std::vector<int> highScores);
    bool ReadScores(std::string fileToReadFrom, std::vector<int> &highScores);
    
    bool WriteSettings(std::string fileToWriteTo);
    bool ReadSettings(std::string fileToReadFrom);
}
