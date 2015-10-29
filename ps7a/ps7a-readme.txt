/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Michael Overy

Hours to complete assignment (optional): 3 hours


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
Completed 100% successfully.


/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
For ease of reading I first created these strings to construct the regex's with:

  string s_date("([0-9]{4})-([0-9]{1,2})-([0-9]{1,2}) ");
  string s_time("([0-9]{2}):([0-9]{2}):([0-9]{2})");
  string s_boot("(.*log.c.166.*)");
  string s_done("(.*oejs.AbstractConnector:Started SelectChannelConnector.*)");

I then made two regex's to use while parsing the file.

  regex r_boot(s_date + s_time + s_boot);
  regex r_done(s_date + s_time + s_done);

Both of these regex's first search for the date and time fields and groups
them into 6 pairs. The seventh pair is the only difference, as r_boot checks
for the boot-start  message and makes that the seventh pair, and r_done checks 
for the boot-finish message and makes that the seventh pair.

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
As we are reading from input, there are 5 things that could happen.

   1.) We aren't booting and we see a boot-start message
   2.) We aren't booting and we see a boot-finish message
   3.) We are booting and we see a boot-start message
   4.) We are booting and we see a boot-finish message
   5.) We don't see any boot message

All you need to do is keep track of when you are booting, and depending on 
what message you see it changes the output you want in the .rpt file.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
I took a function Victor Grinberg made that took a string and converted it
to an int. This is in place of using stoi as it is part of the C++11 standard.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
None.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Converting matches to dates/time was a bit of an issue. I'm not sure what I 
would have done if I hadn't found Victor's to_int function, but it definitely
helped a lot. This wouldn't be an issue if bottlenose supported C++11
