#include "load.hpp"

bool loader::WriteScores(std::string fileToWriteTo, std::vector<int> highScores) {
    std::ofstream myfile;
    myfile.open(fileToWriteTo, std::ios::in);
    
    for (int score : highScores) {
        myfile << score << std::endl;
    }
    
    myfile.close();
    
    return true;
}

//Reads the model from a specified file and loads that data into a model object,
//if can't open the file "Unable to open file" is printed
bool loader::ReadScores(std::string fileToReadFrom, std::vector<int> &highScores) {
    highScores.clear();
    
    std::ifstream myfile (fileToReadFrom);
    std::string line;
    
    if (!myfile.is_open()) {
        std::cout << "Unable to open file" << std::endl << std::endl;
        return false;
    }

    while (getline(myfile, line)) {
        int score = std::stoi(line);
        highScores.push_back(score);
    }
    
    myfile.close();
    
    return true;
}

bool loader::WriteSettings(std::string fileToWriteTo) {
    
}

bool loader::ReadSettings(std::string fileToReadFrom) {
    
}
