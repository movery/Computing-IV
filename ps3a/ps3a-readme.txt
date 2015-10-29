Assignment: ps3a
Programmer: Michael Overy
Date Due  : 2/23/2015
-------------------------


Explanation: I created a class Body to respresent planets on an XY-plane. The following will walkthrough the programs steps (main.cpp code is also commented):

1.) First reads in 'n' from the file. This is the number of planets

2.) Next reads in the size of the universe from the file and stores it.

3.) Initializes a temporary Body that will be used as a template for all bodies pushed onto the vector. Tell it the window and universe sizes

4.) Create a Vector of Bodies (or Universe) and push the temporary Body on it 'n' times.

5.) Begin reading information from stdin line by line. getline is performed on cin, with the data stored in an input string, which is then converted back into an inputstringstream. Each element in the Universe will take a single line from cin to have all of its member variables set to the correct value. The stream insertion operator almost takes the roll of 'The True Constructor' for Body.

6.) Once the data is all inputted, draw each item in the Universe. The draw operator simply takes a ratio of the windowSize and universeSize and multiplies it to the planet size. It then adds half the windowSize to the result to shift the window origin to the center instead of the top-left.

Overall, reading the code should be pretty self-explanatory and easy to follow. Overall the most difficult part completing this project was getting the draw function to work. Not because the math was hard to work out, but it took me awhile to realize I should create a new sprite object inside of draw and set its position instead of the one in the class.

If something seems wrong, or anything is unclear, please let me know at mike.overy13@gmail.com, but I'm fairly certain I covered everything.
