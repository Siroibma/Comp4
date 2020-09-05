/**********************************************************************
 *  readme.txt template                                                   
 *  Markov Model
 **********************************************************************/

Name: Ambioris Lora

Hours to complete assignment: 12
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The point of the assignmnet is to create a text generator using a markov model to generate text. The markov model using kgrams in the size of a variable to predict the future words. I used the map and string library to keep track of the kgrams and the frequency of said KGRAMs.


  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The string and the map library were key to this assignment. The map was required to recording the kgrams and the string library was for keeping the kgrams in k sized pieces.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
    for (auto const& pair : kascii) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    table = kascii;
    std::map<std::string, int>kgram2;
    position = 0;
    if (k != 0) {
	txt_hold += text.substr(0, k);
    }
    for (unsigned int i = 0; i < text.length(); i++) {
        string_hold = txt_hold.substr(position, k + 1);
        kgram2[string_hold] += 1;
        position = position + 1;
    }
    for (auto const& pair : kgram2) {
	std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
    table2 = kgram2;
The code above was used to keep track of the frequency of n sized Kgrams. This was the foundation of the program. I also used a ranged based for loop to display the map.




/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I completed roughly 80% of the assignment. I was able to get the generate function working. The only thing I dont know how to fix is the krand function. I know the other functions work because they trigger the test functions that I setup. They pass the test that I setup. 



/**********************************************************************
 *  Does your implementation pass the unit tests?
 *  Indicate yes or no, and explain how you know that it does or does not.
 **********************************************************************/

I used unit tests. I know they pass because it provides errors when it doesnt. I also made a seperate main.cpp to make sure that these work. 


 /**********************************************************************
 *  Describe where you used exceptions. 
 *  Provide files and lines of the code.
 ***********************************************************************/
    if (kgram.length() != (unsigned)order) {
    throw std::runtime_error("Error not Kgram length L.");
  }
Heres the exception when the kgram length does not match the order in the freq function.

    if (kgram.size() != (unsigned)order || table.end() == table.find(kgram)) {
        throw std::runtime_error("Error: randk kgram not valid");
    }
Heres the exception when the kgram length does not match the order and map cant find the kgram.



/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/

No help

I used the string library to guide me through this assignment. 

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

I couldnt get the rand function working for the generate function

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
N/A
