# Project Proposal


## General Overview

For my final project I would like to create a platformer game. The game that I have in mind will be a classic platformer where the user controls a character that must jump over obstacles. When the user fails to dodge an obstacle that would be the end of a game and a score would be reported to the user. This would be a 2D game that has the user move across the screen and would take inspiration from the chrome dino game that you can play when there is no internet. It could start slow and slowly speed up to increase the difficulty like most games of this genre. For controls the player should be able to use the WASD keys or the arrow keys.

The game will obviously be created using openFrameworks and since it is a game it can leverage a windowed interface very nicelly. I have discovered a really cool outside library called ofxGameOfLife which perfectly fits with what I have in mind and I think it will greatly speed up the development process. In addition with speeding up the development process this library will contribute to the overall aesthetic of the game. I also have discovered ofxDatGui which allows for the creation of cool looking menus which I will use to make the main menu, marketplace, high scores, and setting screens.
 
 **Desired Features**
 1. The actual platform game (**Completed**)
 2. A menu that allows for the pausing of a game, seeing the high scores, and toggling settings (**Completed**)
 3. A list of highest scores on that machine that is saved to a file (**Completed**)
 4. Game settings can be saved to a file to maintain game state from game to game (**Completed**)
 5. Difficulty settings which would change how points are scored (**Completed**)
 6. A marketplace which allows for the spending of points earned in game to skins and themes (**Completed**)
 
 **Stretch Features**
 1. Sound for each movement the character can take and the ability to toggle it on and off
 2. Varying obstacles which will make the game more interesting
 3. ~Different game modes to play~ (This is basically the same as the difficulty setting)
 4. Challenges to complete (e.g. jump over five objects in a row)
 5. Some sort of leveling up system


## Outside Library

Sound drastically adds to any game, but in this case I only have small plans for how to use sound, so I don't plan on using a sound library as my main outside library. I invision it as more of a stretch goal. Instead I have discovered an outside library called ofxGameOfLife. This library divides the screen up into a grid. Each cell in the grid can be individually acessed and changed. With the screen divided into a grid I can easily implement the pixelly old school game I have in mind. This is a pretty well documented outside library and comes with some helpful examples. I have begun looking at the outside examples and thinking about how I could implement features of library into my game.

For this game I also want to create a nice looking menu. The menu will be important to display high scores, settings, the marketplace, and to start the game. Creating a working menu with basic openFrameworks would be really difficult, but I discovered an addon called ofxDatGui. This addon allows for the creation of really cool looking menus and it is super well documented. Within just a few minutes of firing up library I was able to get a lot of the features to work. I think this will be a really important addition to my project and my ability to complete the menus.


## Links

Link to ofxGameOfLife addon:\
https://github.com/bernardoaraujor/ofxGameOfLife

Link to ofxDatGui addon:\
https://github.com/braitsch/ofxDatGui

Link to openFramework:\
https://openframeworks.cc

Link to openFrameworks tutorials:\
https://openframeworks.cc/learning/
