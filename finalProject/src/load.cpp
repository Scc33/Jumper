#include "load.hpp"

bool Loader::WriteScores(std::string fileToWriteTo) {
    std::ofstream myfile;
    myfile.open(fileToWriteTo, std::ios::in);
    

    
    myfile.close();
    
    return true;
}

//Reads the model from a specified file and loads that data into a model object,
//if can't open the file "Unable to open file" is printed
bool Loader::ReadScores(std::string fileToReadFrom) {
    std::ifstream myfile (fileToReadFrom);
    std::string line;
    
    if (!myfile.is_open()) {
        std::cout << "Unable to open file" << std::endl << std::endl;
        
        return false;
    }

    
    myfile.close();
    
    return true;
}

bool Loader::WriteScores(std::string fileToWriteTo) {
    
}

bool Loader::ReadSettings(std::string fileToReadFrom) {
    
}
