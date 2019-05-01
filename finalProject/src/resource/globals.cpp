#include <stdio.h>
#include <string>

bool startMenuRunning = true;
bool gameRunning = false;
bool gameEndedScreen = false;
bool marketMenuRunning = false;
bool settingsRunning = false;
bool hScoreMenuRunning = false;

std::string hScoreFileLoc = "/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/highScores.txt";
std::string settingsFileLoc = "/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/settings.txt";
std::string moneyFileLoc = "/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/money.txt";
std::string marketFileLoc = "/Users/coughlin/Documents/School/CS 126 C++/of_v0.10.1_osx_release/apps/myApps/final-project-Scc33/finalProject/bin/data/market.txt";

int totalMoney = 0;

int difficultySetting = 1;

bool fullScreen = false;

int playerColor = 0;
