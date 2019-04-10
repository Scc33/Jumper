# Development
**Week One**\

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

**Week Two**

**Week Three**

**Week Four**
