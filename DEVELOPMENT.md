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

**Week Two**

**Week Three**

**Week Four**
