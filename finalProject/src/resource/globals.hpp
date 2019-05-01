#pragma once
#include <string>

//Control flow variables
//Global in scope so every menu can change and access them
extern bool startMenuRunning;
extern bool gameRunning;
extern bool gameEndedScreen;
extern bool marketMenuRunning;
extern bool settingsRunning;
extern bool hScoreMenuRunning;

//File locations
extern std::string hScoreFileLoc;
extern std::string settingsFileLoc;
extern std::string moneyFileLoc;
extern std::string marketFileLoc;

//Total obstacles avoid by the player through all games
extern int totalMoney;

//Controlled by the chosen setting
extern int difficultySetting;
extern bool fullScreen;

//Controlled by the market place
extern int playerColor;
