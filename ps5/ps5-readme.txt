/**********************************************************************
 *  readme 
 *  DNA Sequence Alignment
 **********************************************************************/

Name: Ambioris Lora

Hours to complete assignment: 7 hours

/**********************************************************************
 * Explain which approach you decided to use when implementing
 * (either recursive with memoization, recursive without memoization,
 * dynamic programming or Hirschberg�s algorithm). Also describe why
 * you chose this approach and what its pros and cons are.
 **********************************************************************/
I used dynamic programming in which the matrix solved itself from the outside in. I choose this approach because it seemed the most compact. It was like pseudo recursion which meant it would be efficient. The pros were I didnt have to solve anything and It's like recursion but faster. The cons are it involves alot of testing to make sure its working correctly. Since its working under the hood you gotta make surer its doing what you want all the time not most of the time



/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: atattat
       tattata
Expected output: 4

What happened: It treated the string like a regular string. It gives me a seg fault but still works. If you run it using valgrind then it doesnt work.



/**********************************************************************
 * Look at your computer�s specs in the settings and find the total 
 * amount of RAM. Place it below. 
 **********************************************************************/
 8 gb


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
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 4
b = 2, for every character you get 2 spots of integers

8,000,000,000
largest N = 450000
425000^2 * 4 = ~800000000

for every character you include you add two integers to the matrix. So my thought process was to square and then multiply by 4 to get the accurate amount of bytes

/**********************************************************************
 * Run valgrind if you can and attach the output file to your submission. 
 * If you cannot run it, explain why, and list all errors you�re seeing. 
 * If you can run it successfully, does the memory usage nearly match that 
 * found in the question above? 
 * Explain why or why not. 
/**********************************************************************
Although I can not attach the output file. I can run it and no my answers were not corrrect. I think i misinterperted what the question was asking and I assumed that a and b were integers and characters. When in reality you can have a formula that does not relate to ints and chars


/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118			52.9048		25.193216
ecoli5000.txt	    160			200.0068	100.308578
ecoli7000.txt       194			391.801		196.388578
ecoli10000.txt      223			598.302		411.307581
ecoli20000.txt	    the last two bricked my computer(seg fault)	
ecoli28284.txt

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
The following is a guess
a = 3
b = 1

20000 = 7.73
40000 = 28~
80000 = 112
160000 = 448
640000 = 1792
1280000 = 7168
2560000 = 28672
by my estimation i can say 2560000 characters 
largest N =  2560000


**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where 
 * (describe a method or provide a lines numbers)
 **********************************************************************/
No

**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
No help whatsoever


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Had some trouble with seg faults but other than that not much trouble. The seg faults led to issues on the filling out the table and answering the question


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
