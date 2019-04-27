# Development
**Week One**

*4/8/19*\
To start development I began thinking about ideas that I would like to create. After some thought I decided that I wanted to make an old school platformer game. I started development by pulling up one of the examples and using it as inspiration for how to start and for basic setup/boilerplate code.

*4/9/19*\
I continued development by first adding a little more setup code. I finished up the code that allows the window to jump from full screen to back again. I also created a very basic black and white background that moves across the screen to give the illusion of movement.

Additionally, today I began looking for an outside library that would augment my game and meet the outside library requirement. After some searching I discovered ofxGameOfLife (see link at end of this entry). This library splits a window into a bunch of tiny grids. The grids can be individually filled and accessed. While I dind't initially have this in mind I quickly realized that this library could be used to make an pixelled old school looking game. I began experimenting with the libary and figuring out how to implement it in my final project.

Finally, today I finished writing up my proposal.

Link to outside library: https://github.com/bernardoaraujor/ofxGameOfLife

*4/10/19*\
Today I began implementing ofGameOfLife into my project. I used its grid feature to divide the screen into a grid and display lines to help with the debug process. Once I had done that I created a basic model for a moveable character and I tried to work on collision detection. With collision detection I started running into errors. The grid system provided by ofxGameOfLife has a current state boolean as part of the class so I figured if an object was present in a grid spot I'd set that boolean to true and if another object tried to enter the already filled zone its movement would be rejected. However, when I tried to implement this method it caused this odd bug where it would reject four moves but on the fifth move it would allow it. After about an hour on this very odd and annoying bug I set it aside to look at later and began looking into creating a game menu.

I wasn't sure how to create a menu using the standard ofGui so I started looking at more addons and I discoverd one called ofxDatGui. This addon is specifically for creating menus and after running the example I think it is something I might be able to make use of. I'm not entirely sure how it all works so I will need to take a look at that later.

Link to outside library: https://github.com/braitsch/ofxDatGui

*4/11/19*\
Still struggling with my collision bug, today I decided to take a different route and work on other projects that need to be done. First I updated the game screen with platforms that move across the screen. This is import to the final version of the game and working on it now will help me understand how to improve it later on. Once I had created these platforms I began exmperimenting with ofxDatGui. I determined from this experimentation that this would be a good addon, so I added a dependency of it to my project. Finally, I added a simple button from ofxDatGui to the project just to test that the dependency was working properly.

*4/12/19*\
Today was all about creating a menu screen using ofxDatGui. From my experimentation yesterday I had pretty good idea of how the library worked, so I was able to easily add a few more buttons. I struggled with the font size being too small for awhile, but eventually I discovered the library supports creating and importing outside themes. So, I created my own theme with a larger font size and used that. Once I had my basic menu layout down I decided the screen looked too bare. Earlier when I was first experimenting with openFrameworks I had seen an example where a ball bounced randomly around the screen, so I took a little inspiration from this example. Instead of a ball randomly bouncing around the screen, I have my player randomly bounce around the screen and I am really satisfied with how it turned out.

*4/13/19*\
First, I tidied up my code base which had become kind of messy after all the exerimentation. Once I had tidied some stuff up I started to work on the platform system again. But after continuing to struggle with designing the platform system, I decided to scrap the whole thing. It was complicated and ugly looking and I though I could do better, so I started to replace it with a floor that had obstacles that poke out of it. This so far has been easier to design and easier to think about than my old approach.

Today, was also my first code review since starting the final project. I recieved final approval for my game under the condition that I move some of the stretch goals into the main goal category. I think I will make my marketplace idea a main goal because it is a significant extension and I am excited to implement it. I will need to update the proposal document to reflect this change.

**Week Two**

*4/14/19*\
My work so far on the final project has been extremely scattered. I'll work on one component for awhile only to get distracted by another and forget about my real goal. This has lead me to work on a thousand small tasks without ever getting main functionalities to work. Something I've already learned through this process is I need to set goals for myself before I sit down to code. For me to be my most productive I need to have a specific task in mind and I need to hammer away at that one task. From now on I am going to try and work on this because at the rate I am going I will never produce a playable game.

Apart from what I have learned today I did complete a few tasks. I worked a lot on the control flow of the game and now it is possible to move from one game screen to another with ease. Most of the screens don't do anything yet, but having a flow from screen to screen is making the game feel more real. Gravity was another thing I worked on today and I made it so the player will fall to the ground when they are supposed to now. However, I am still not quite statisfied with how the gravity makes the player look and I will definitely need to tweak it.

The last thing I did today was update the project proposal to reflect what was discussed in code review yesterday and to show that I was using two outside libraries to make my game.

*4/15/19*\
Work on the final project will probably be a little slower this week because I have a midterm so I only focused on two small tweaks today. First I tweaked gravity. Now gravity gets stronger the longer the player is off the ground so they will be pulled back to the ground in a more realistic looking manner. After this I split the logic for drawing a player into its own class which was a relatively simple code base improvement. Feeling confident after these two easy fixes I tried to split out drawing and handling of the menus into their own classes. This will make the code more readable and makes sense from a logic point, but I immediately ran into errors. It appears like the menu components from ofxDatGui require being in the main ofApp because they appear to take a reference of it to function. I am not sure how this functionality works and I will need to seriously look into it before I can make more progress in this direction.

*4/16/19*\
Before today obstacles were only created for testing purposes and to see how it all looked. Today, I switched that so obstacles generate automatically and move across the screen as they did before. As the game goes on the chance of obstacle creation increases which will cause the obstacles to be created closer and closer together as the game progresses. This is one way the game will get harder as it goes on. The other way the game will get harder is by increasing in speed and I intend on implementing that within the next few days.

*4/17/19*\
The second code review of the final project was today. I had been fearing that I was falling behind on my project. It turns out I'm right on track. I didn't have anytime to code today, but I did get some important feedback at code review today and I have some big plans I want to implement within the next few days.

*4/18/19*\
No work done today.

*4/19/19*\
No work done today.

*4/20/19*\
No work done today.

**Week Three**

*4/21/19*\
Just minor work done today mostly on tidying up, adding catch for testing, and shifted some visuals around to look a little better.

*4/22/19*\
No work done today.

*4/23/19*\
Today I took a big step forward for the game, I implemented collision dection. Now the game will end when a player collides with one of the obstacles. Obviously a big component of the game, I had been putting this task off because I thought it would be tough to implement but I was pleasantly suprised. I still need to do some more thorough testing on it, but I am pretty happy with the collision detection system now. I also added more buttons to the game that will be used for the settings, market, and high score screens. This has been routine work in the past but I was running across strange bugs messing up the control flow. I don't know if these bugs are from errors in my logic or because of something I don't know about ofxDatGui yet. I will be exploring this issue more tomorrow.

*4/24/19*\
First up today was fixing all button bugs. There were quite a few and this took me awhile. The first problem was the logic was set up such that multiple screens could be drawn over each other. Switching this was just a little tweak to the logic. The second problem was that the buttons were all being updated at once even if they weren't currently onscreen. I changed this so that a button is only updated if it is currently onscreen and being drawn. The final issue was because buttons are drawn in relation to each other and some were being drawn in relation to the wrong other button. This caused buttons to pile up on each other which looked fine, but when clicked might trigger the wrong event listener.

Once all the buttons bugs were squashed. I tided up the code base which had begun to look messy. I dug up an old project which I had already done reading and writing to files in and took that code which will be used to write high scores and settings to file. And I added a score counter which counts how many obstacles have been avoided.

With this housekeeping done I was ready to start the next big feature which is tracking high scores. First up was using the file reader to read in high scores from a file and then display them on the high score page. After this came the process of updating the high scores when one is beat. The final part of this puzzle that I haven't worked out yet is allowing the user to input the name that corresponds with their high score. This is causing me some trouble because it requires incorporating a new ofxDatGui feature, the textbox. Adding in this new interface requires a lot more code that I haven't got completely working yet. It needs new event listeners, new setup, and setting the focus to the textbox when on that screen. These are a lot of moving parts and I will need to look more into this tomorrow.

*4/25/19*\
Today was the toughest day for me by far. The number of errors I encountered was astronomical and completely discouraging. The day started off well enough with changing of the high score interface. The screen to allow a user to know they set a high score and enter their name will now only display if they have set a high score like it should. Next, I wrote the code that would pull the name the user input and write it to the high score file. Now when the user goes to see the high scores they will see their name next to it.

Next, I wanted to work on my decomposition. So I tried to split the main menu code out into its own class. I had worked on this earlier without success so this was my second attempt. Things were going well until I couldn't get the classes to share the set of control variables. Nothing I tried worked. I tried global variables which seemed promising but failed with weird errors. I tried passing the control variables into the menu class by reference which failed. Then I tried global variables one more time and it failed again. At this point I had wasted hours of time and I was so flustered I needed to stop. So I took the work that I had currently and split it out into its own branch for looking at later.

Finally, completely upset by my failure to improve my decomposition, I decided to work on a smaller project. I updated the settings menu with a new dropdown bar which allows the user to select a background color. Tomorrow I will save this to a file so that their choice is preserved from launch to launch. I also tried to reconfigure my environment to setup testing. Sadly, this did't go very well and at this point I still don't have testing using catch working properly.

*4/26/19*\
First up today was getting catch working. My solution, while not particularly elegant, works pretty well. I now select which main I want to compile, the test main or the app main. After I got testing working, I tested my reading and writing scores functions and my player drawing creations. After this I sought out help to understand global variables. It turns out I had my declarations correct, but I wasn't initializing them properlly or I would initialize them twice. Still confuses me, but the good news is they work properly which allows for different classes to change them. Since different classes can now alter the global control variables I could start improving my decomposition.

First, I pulled all the code for creating and running the main menu into its own class. This was a pretty long process because the code was rather spaghetti like. After pulling main menu into its own class I repeated the process with the high score menu then with the market menu and finally with the settings menu. Along the way I tested the functionality of the main menu with my now working tester.

Next up on my list of things to-do is create two more classes one for the game ended screen and one for the game screen. Once all the classes are made I can go through and easily write automated tests for them all. Today was an extremely productive day and I think my code readability and style really improved along the way.

*4/27/19*\
With all the new classes I had made yesterday the project was starting to get really cluttered wtih files, so I decided to organize them into separate files all nice and neat. Next I pulled the high score calculator into its own namespace because it is used by multiple classes. Then I migrated the game ended menu into its own class. Finally I pulled the game code into its own class. With this I had completed the long task of decomposing my code. 

Today I also took care of two smaller tasks. One was adding const to all my functions that are const which is an important semantics improvement. The other task was saving the settings color to file so that it is maintained from gameplay to gameplay. Lastly today was another code review and I appear to be on track to finish things up well.

**Week Four**

*4/28/19*\
