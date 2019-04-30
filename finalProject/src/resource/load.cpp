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

bool loader::WriteSettings(std::string fileToWriteTo, int color, bool fullScreen) {
    std::ofstream myfile;
    myfile.open(fileToWriteTo, std::ios::in);
    
    myfile << color << std::endl << fullScreen;
    
    myfile.close();
    
    return true;
}

bool loader::ReadSettings(std::string fileToReadFrom, int &color, bool &fullScreen) {
    std::ifstream myfile (fileToReadFrom);
    std::string line;
    
    if (!myfile.is_open()) {
        std::cout << "Unable to open file" << std::endl << std::endl;
        return false;
    }
    
    int count = 0;
    while (getline(myfile, line)) {
        if (count == 0) {
            color = std::stoi(line);
        } else {
            fullScreen = std::stoi(line);
        }
        count++;
    }
    
    myfile.close();
    
    return true;
}

bool loader::WriteMarket(std::string fileToWriteTo, int color) {
    std::ofstream myfile;
    myfile.open(fileToWriteTo, std::ios::in);
    
    myfile << color;
    
    myfile.close();
    
    return true;
}

bool loader::ReadMarket(std::string fileToReadFrom, int &color) {
    std::ifstream myfile (fileToReadFrom);
    std::string line;
    
    if (!myfile.is_open()) {
        std::cout << "Unable to open file" << std::endl << std::endl;
        return false;
    }
    
    while(getline(myfile, line)) {
        color = std::stoi(line);
    }
    
    myfile.close();
    
    return true;
}

bool loader::WriteMoney(std::string fileToWriteTo, int money) {
    std::ofstream myfile;
    myfile.open(fileToWriteTo, std::ios::in);
    
    myfile << money;
    
    myfile.close();
    
    return true;
}

bool loader::ReadMoney(std::string fileToReadFrom, int &money) {
    std::ifstream myfile (fileToReadFrom);
    std::string line;
    
    if (!myfile.is_open()) {
        std::cout << "Unable to open file" << std::endl << std::endl;
        return false;
    }
    
    while (getline(myfile, line)) {
        money = std::stoi(line);
    }
    
    myfile.close();
    
    return true;
}
