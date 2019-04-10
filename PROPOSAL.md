# Project Proposal


## General Overview

For my final project I would like to create a platformer game. The game that I have in mind will be a classic platformer where the user controls a character that must jump over obstacles. When the user fails to dodge an obstacle that would be the end of a game and a score would be reported to the user. This would be a 2D game that has the user move across the screen and would take inspiration from the chrome dino game that you can play when there is no internet. It could start slow and slowly speed up to increase the difficulty like most games of this genre. For controls the player should be able to use the WASD keys or the arrow keys.

The game will obviously be created using openFrameworks and since it is a game it can leverage a windowed interface very nicelly. I have discovered a really cool outside library called ofxGameOfLife which perfectly fits with what I have in mind and I think it will greatly speed up the development process. In addition with speeding up the development process this library will contribute to the overall aesthetic of the game.
 
 **Desired Features**
 1. The actual platform game
 2. A menu that allows for the pausing of a game, seeing the high scores, and toggling settings
 3. A list of highest scores on that machine that is saved to a file
 4. Game settings can be saved to a file to maintain game state from game to game
 5. Difficulty settings which would change how points are scored 
 
 **Potential Bonus Features**
 1. Challenges to complete (e.g. jump over five objects in a row)
 2. Some sort of leveling up system
 
 **Stretch Features**
 1. Sound for each movement the character can take and the ability to toggle it on and off
 2. A marketplace which allows for the spending of points earned in game to skins and themes
 3. Varying obstacles which will make the game more interesting
 4. Different game modes to play


## Outside Library

Sound drastically adds to any game, but in this case I only have small plans for how to use sound, so I don't plan on using a sound library as my main outside library. I invision it as more of a stretch goal. Instead I have discovered an outside library called ofxGameOfLife. This library divides the screen up into a grid. Each cell in the grid can be individually acessed and changed. With the screen divided into a grid I can easily implement the pixelly old school game I have in mind.

This is a pretty well documented outside library and comes with some helpful examples. I have begun looking at the outside examples and thinking about how I could implement features of library into my game.


## Links

Link to outside library:\
https://github.com/bernardoaraujor/ofxGameOfLife

Link to openFramework:\
https://openframeworks.cc

Link to openFrameworks tutorials:\
https://openframeworks.cc/learning/
