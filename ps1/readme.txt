ReadMe for PS1

Programmer: Michael Overy
Date Due  : 2/4/2015

Description: I simply made a triangle and rectangle class that allowed me to quickly and cleanly create shapes in my programs and did all of the math and drawing inside of the event loop. As a result my program is likely slower than if I had implemented a class Sierpinski and Staircase which made the entire object beforehand and just drew it. Specficially, the math to find the locations of each triangle is done every time in the event loop which is the main flaw in my implementation.

Put simply, my program draws the initial shape, and then passes the locations of a new shape to draw to 'drawSub<Shape>'. drawSub<Shape> then recurses by calling itself each time the depth has not been reached, passing the verticies of where to draw the next set of shapes.

Each time a function is called, a stack frame is added. So if I am running depth 3, The event loop creates a second stack frame with drawInit<Shape>, a third with drawSub<Shape>, a fourth with another drawSub<Shape>, a fifth with ANOTHER drawSub<Shape>, at which point it falls back to the fourth stack frame to continue with the second call of drawSub<Shape>. So depth 3 has a max of 5 stack frames during the recursive process.



Overall I spent about 4 hours on this assignment. The majority of it was spent trying to figure out the math on how to find the vertices of where each triangle/rectangle will be drawn. I did some research, and the site lodev.org gave a great explanation of how the Sierpinski's  triangle is created in a recursive fashion as well as gave several other fractal examples.

I'm a little worried that since I didn't make a sierpinsi class I didn't do it the way you wanted me to, but I completed the assignment before you began to show us example code (like during the online meeting), and since I had already found a solution that worked, I wasn't too worried about porting my implementation. Hopefully it won't bite me in the butt.

### ALSO ### In the last assignment I never answered the questions on Academic Integrity, so I will answer that here.

Honestly, (b) is probably the most revelant outside of (a). Trying to cheat or make a solution look like it works (even though it doesn't) is something you can pull off pretty easily (to an extent) in a CS course. Combined with the fact that a lot of information is so readily available with a quick google search, it's hard to imagine 'unauthorized materials' are in light use. It's a problem that I know exists, especially during computer-lab tests as well as on difficult assignments in an attempt to gain credit based on the expected output. 
