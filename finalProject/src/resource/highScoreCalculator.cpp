#include "highScoreCalculator.hpp"

std::vector<int> highScoreCalculator::calcNewHighScores(int score, std::vector<int> oldHighScores, int &pos) {
    std::vector<int> newHighScores;
    bool newScore = false;
    
    for (int i = 0; i < oldHighScores.size(); i++) {
        if (score >= oldHighScores.at(i) && !newScore) {
            newHighScores.push_back(score);
            pos = i;
            newScore = true;
        }
        newHighScores.push_back(oldHighScores.at(i));
    }
    newHighScores.pop_back();
    
    return newHighScores;
}

std::vector<std::string> highScoreCalculator::calcNewHighScoreNames(std::string name, std::vector<std::string> oldHighScoreNames, int pos) {
    std::vector<std::string> newHighScoreNames;
    
    int count = 0;
    std::cout << pos << std::endl;
    for (int i = 0; i < oldHighScoreNames.size(); i++) {
        if (count == pos) {
            newHighScoreNames.push_back(name);
        }
        newHighScoreNames.push_back(oldHighScoreNames.at(i));
        count++;
    }
    
    newHighScoreNames.pop_back();
    
    return newHighScoreNames;
}
