/**********************************************************************
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Michael Overy
Login: mike.overy13@gmail.com
Hours to complete assignment (optional): ~2.5 Hours



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/

I used the dynamic programming method using a matrix. I filled in the
matrix using the algorithm provided on the princeton site. I found
the alignment itself by backtracking top-left to bottom right, moving 
from the current matrix index to the next-lowest matrix index. There was 
a special case where if the diagonal was 1 higher than the downwards or 
rightwards option, you still go diagonal. In any case, depending on which
direction I went, I either added a gap, or both letters, and incremented
i and j counters to traverse back to the bottom right of the matrix.


/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/

Input: ./ED < ./sequence/endgaps7.txt

Expected output: a - 2
	 	 t t 0
		 a a 0
		 t t 0
		 t t 0
		 a a 0
		 t t 0
		 - a 2

What happened: My program outputted the same value as the expected output
on the princeton site.


/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 4GB and 2GB. If your machine has 1 GB or less, use a cluster
 *  machine for this readme (see the checklist for instructions).
 **********************************************************************/

I am currently running this on a VM using Lubuntu and 2 gigabytes of ram.
Because of this I was unable to run the ecoli28284.txt file.

/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 1GB (billion bytes) of memory?
 **********************************************************************/

N^2 is the area of the matrix, the number of integer slots that need to be
filled in. 4 is the size of an integer in bytes.

a = 4
b = 2
largest N = ~ 15800

EXPLANATION: 4 * 15800^2 is 998,560,000, just under 1 gigabyte.

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
--------------------------------------------------------------------------------
  n        time(i)         total(B)   useful-heap(B) extra-heap(B)    stacks(B)
--------------------------------------------------------------------------------
 70    233,172,248      336,029,152      335,928,440       100,712            0
 71    235,479,480      345,272,848      345,169,364       103,484            0
 72    237,792,017      354,516,544      354,410,288       106,256            0
 73    240,099,249      363,760,240      363,651,212       109,028            0
 74    242,411,786      373,003,936      372,892,136       111,800            0
 75    244,719,018      382,247,632      382,133,060       114,572            0
 76    247,031,555      391,491,328      391,373,984       117,344            0
 77    249,512,926      400,504,952      400,384,897       120,055            0
 78  5,597,067,843      400,515,512      400,395,435       120,077            0
 79  5,600,293,584      400,564,112      400,444,030       120,082            0

 *  Explain if necessary.
/**********************************************************************

Running ecoli10000.txt. Before this it peaks out at aroung 650MB, not entirely
sure why, but it settles at 400MB pretty fast.

/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt		118		0.369814
ecoli5000.txt		160		1.349020
ecoli7000.txt		194		2.449720
ecoli10000.txt		223		5.501630
ecoli20000.txt 	       3135    	       60.065600
ecoli28284.txt	       Can't run, not enough memory

If you wish, please enter your data on a shared visualization for the 
whole class to view. Go to this URL:

http://isenseproject.org/projects/ xxx (TBD!)

and enter contributor key 204.

Then click on Contribute Data > Manual Entry, and enter your data.

For each row of data, enter the string length (e.g., 2500) and your run
time in seconds (e.g., 0.08).

Click "Add Row" to add enough rows for all of your entries.

Name your data set with your CS username and details about your computer
(processor, RAM, and OS).


/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730

/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/

We are still talking about total number of spaces we need to allocate for the 
matrix, so N^2 stays. Also, each time we double in size we seem to double in 
time (5000^2 * 2 = ~7000^2  and 7000^2 * 2 = ~10000^2), and each time we we 
quadruple in size the time quadruples. (10000^2 * 4 = ~20000^2) (Time shows 
the same-ish pattern).

So if everything is just doubling, I need to find a coefficient that works.
0.00000002 seems close enough for the cases here. It's a little too low for 
2500, but also a little to high for cases like 20000, but it's close.

a = 0.00000002
b = 2
largest N = 3.972253768 x 10*7

EXPLANATION: The steps are reversable. if I can find total time based on N by
.00000002 * N^2, I can solve for N by applying sqrt(t/0.00000002). The above 
calculation assumes 31557600 seconds in a day.

/**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/

None, Just the princeton page.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

I did not compile my EC Class File with -Wall or -Werror. The only warnings
or errors it was throwing were ones related to comparing unsigned integers
being returned from vector.size() to integers, but when I swapped my 
integers to unsigned I began to have underflow issues as I decremented. 
At that point, seeing as those are my only errors and I know I shouldn't
have a problem comparing integers or unsigned integers, compiling with 
-Wall or -Werror didn't seem necessary.

I also ran into most of the errors other people did where my sequence
did not match the one posted on bottlenose. I went as far as writing a 
python test script (test.py included in my submission) that takes an output
file from ED (with the 'Edit distance is: XXX' line removed, as well as 
the last two new lines in the file) that added up the distance found for
each step when putting together the alignment and found my total distance
was correct as expected.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

My class implementation does all of the work in the constructor and has 
all of the math stuff private. The user simply needs to access the getter
functions to examine what information ED has to offer. 

The upside to this is all of the information is readily available and will
only have to be computed once (which is done in the constructor), although 
this does cause the class to take up a lot of memory (between the alignment
string and the matrix). All of the functions available outside of the ED
class are very self-explanatory. 
