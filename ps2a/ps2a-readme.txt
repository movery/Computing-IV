Michael Overy
February 9th, 2015
-------------------------------------

Project Representation
-------------------------------------
The representation of my LFSR simply uses a string to represent the bits. I had to keep in mind while implementing my functions that the string needed to be shifted towards the left, or towards the 0th index. When pulling characters from the string I needed to subtract the result by 48 to get the numerical representation s opposed to the ascii version.

Overall the biggest hurtle was finding a way to put bits back onto the end of the string. In the end I created a string-stream and used the assignment operator to make the seed equal to the string-stream I created in the step() function. After writing the step() function writing the generate() was trivial.

Test Cases
-------------------------------------
1.) The example-case testing 5 bits "00111" with the tap at 2.

2.) A test-case involving a string of all 0's with an arbitrary tap. It should product all 0's since there is nothing to successfully xor. 

3&4.) Tap and 0 and 4 is to test the boundaries of the string to make sure it is pulling elements propery and putting them back correctly and in the right order. Tap at 0 should perform a regular output, while tap at 4 should produce all 0's since it is Xoring the same bit with itself.
