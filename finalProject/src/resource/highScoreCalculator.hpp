#pragma once
#include <fstream>
#include <iostream>
#include <vector>

namespace highScoreCalculator {
    std::vector<int> calcNewHighScores(int score, std::vector<int> oldHighScores, int &pos);
    
    std::vector<std::string> calcNewHighScoreNames(std::string name, std::vector<std::string> oldHighScoreName, int pos);
}
