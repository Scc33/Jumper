# Jumper

A classic platform side scroller game that takes inspiration from the famous no-internet game in the chrome browser. Avoid the obstacles at all costs and see if you can get a new high score! Please enjoy and have fun! :)

**Controls**\
WASD for movement across the screen and space bar to jump. When the 'W' key and space bar are pressed at the same time the player double jumps.

**High Scores and Settings**\
High scores and settings are accessible in game through menus. These are saved to files to maintain state from game to game, however due to time constraints their file locations are hard coded. To change the location of where you want these files to be saved go to globals.cpp and edit their file location values.

**Scaling Note**\
There are some unresolved issues with scaling so toggling fullscreen mode requires a game restart.

**Screenshots**\
Game screen\
![Alt text](/Screenshots/Game.png?raw=true "Game screen")
Main menu\
![Alt text](/Screenshots/MainMenu.png?raw=true "Main menu")
High score menu\
![Alt text](/Screenshots/HighScoreMenu.png?raw=true "High score menu")
Market\
![Alt text](/Screenshots/MarketMenu.png?raw=true "Market")
Settings\
![Alt text](/Screenshots/SettingsMenu.png?raw=true "Settings")

Built using C++ and openFrameworks.\
https://openframeworks.cc

Requires the following outside libraries.\
ofxGameOfLife:\
https://github.com/bernardoaraujor/ofxGameOfLife
ofxDatGui:\
https://github.com/braitsch/ofxDatGui
ofxGui:\
https://openframeworks.cc/documentation/ofxGui/
