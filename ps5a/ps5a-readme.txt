Program: RingBuffer ps5a
Programmer: Michael Overy
--------------------------------------------------------------------------------

Description: In this assignment I was able to implement a queue using a circular
vector. I wrote the code using the cpplint style to meet google's industry
standard for neat, easy to read code. I also was able to implement 3 minor
test-cases to briefly test my program using the boost framework.

I tested my implementation by checking to see if I would throw exceptions when
expected as well as checking to make sure my peek() and dequeue() functions
grabbed the correct data. During production I also tested often using a main()
file which I removed from this submission.

To implement the exceptions I simply had my functions throw the appropriate
exception in a try-block, had the exception caught in the catch-block, which
would then display an error message and throw the exception once more so it
could be caught by the boost tests and end the program.

The time and space performance is very simple. 

Time is a matter of how long the
buffer takes to run the different operations. If this were a regular vector,
time would be a matter of O(n) for enqueue() as I would have to insert an item
at the front of the vector, and dequeue() would be O(1) because I am just
peeling an item from the back of the vector. Peek() would also be O(1). But
seeing as I am using a circular vector, this allows even enqueue() to run at
O(1) time since I don't have to push the contents of my vector around whenever
an item is added.

Space I'm not 100% sure on. It is either O(n) because the vector needs to be
able to contain O(n) items, or it is O(1) because the vector never changes in
size. I suppose both of these could be true depending on what you're talking
about? I'm kind of leaning towards the latter case, but I'm not 100% on it.
