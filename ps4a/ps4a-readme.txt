/**********************************************************************
 *  readme.txt                                                    
 *  Synthesizing a Plucked String Sound:
 *	RingBuffer implementation with unit tests and exceptions 
 **********************************************************************/

Name: Ambioris Lora


Hours to complete assignment: 10-12 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
I was able to use vectors to simulate a queue that can essientially keep going while maintaining order. A ring buffer is a queue in the form of an array but in this case I used a vector.




/**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I used a vector otherwise I wouldnt have been able to accomplish this assignment as easily as I did. I was trying to use a style array but I ran into a design confilct in which It needed to take a variable size which to my knowledge is not easily done with an array but Using a vector half way through development was the right idea




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
To enqueue I had to think ahead of the extreme case which was when it was full or when we at the last "spot." So I used the remainder operator to signify when it was time to start all over

head = (head+1) % capacity;
tail = (tail+1) % capacity;


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 *************************** ******************************************/
I completed the assignment and the only thing im suspicious about is the exceptions. I tested the functions 30-40 times to make sure they're working along with extreme cases




/**********************************************************************
 *  Does your RingBuffer implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/
Yes it took a while for me to understand what the boost library was even doing to my code. It failed the boost no throw test which means it indeed did throw an exception. This took me forever to understand




/**********************************************************************
 *  Explain the time and space performance of your RingBuffer
 *	implementation
 **********************************************************************/
I believe my ringbuffer time complexity for insertion is 1 and for deletion it is also 1 unless it is the worst case scenario and it has to go through the whole queue. Then that is n representing the number of objects in the buffer. As for space complexity it is slight worse than a regular array 




/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

I recieved no help 


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

I spent a good couple days trying to use an array and to no avail. Trying to have a variable size array is just trying to use a vector is what i learned at the end of all of this


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

Dont try and reinvent the wheel like i did
