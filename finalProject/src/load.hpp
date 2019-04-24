#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace Loader {
    bool WriteScores(std::string fileToWriteTo);
    bool ReadScores(std::string fileToReadFrom);
    
    bool WriteSettings(std::string fileToWriteTo);
    bool ReadSettings(std::string fileToReadFrom);
}
