#include "load.hpp"

bool loader::WriteScores(std::string fileToWriteTo, std::vector<int> highScores, std::vector<std::string> highScoreNames) {
    std::ofstream myfile;
    myfile.open(fileToWriteTo, std::ios::in);
    
    for (int score : highScores) {
        myfile << score << std::endl;
    }
    for (std::string name : highScoreNames) {
        myfile << name << std::endl;
    }
    
    myfile.close();
    
    return true;
}

//Reads the model from a specified file and loads that data into a model object,
//if can't open the file "Unable to open file" is printed
bool loader::ReadScores(std::string fileToReadFrom, std::vector<int> &highScores, std::vector<std::string> &highScoreNames) {
    highScores.clear();
    highScoreNames.clear();
    
    std::ifstream myfile (fileToReadFrom);
    std::string line;
    
    if (!myfile.is_open()) {
        std::cout << "Unable to open file" << std::endl << std::endl;
        return false;
    }

    int count = 0;
    while (getline(myfile, line)) {
        if (count < 5) {
            int score = std::stoi(line);
            highScores.push_back(score);
        } else {
            highScoreNames.push_back(line);
        }
        count++;
    }
    
    myfile.close();
    
    return true;
}

bool loader::WriteSettings(std::string fileToWriteTo) {
    
}

bool loader::ReadSettings(std::string fileToReadFrom) {
    
}

bool loader::WriteMarket(std::string fileToWriteTo) {
    
}

bool loader::ReadMarket(std::string fileToReadFrom) {
    
}

bool loader::WriteMoney(std::string fileToWriteTo) {
    
}

bool loader::ReadMoney(std::string fileToReadFrom) {
    
}
