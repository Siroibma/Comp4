/**********************************************************************
 *  N-Body Simulation ps3b-readme.txt 
 **********************************************************************/

Name: Ambioris Lora
Hours to complete assignment: 8 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

We created an accurate physics system where planets/particles would affect each other. 

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
Vectors and pointers allowed us to finish this assignment and meet the requirements of allowing any type of universe to work in our function. 




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
We used smart pointers similarly to how we used smart pointers in the first assignment.
  std::unique_ptr<Universe>universe(new Universe());
  CelestialBody* planet;
  for(int i = 0; i < num_part;i++)
    {
      planet = new CelestialBody();
      cin >> *planet;
      (*universe).pushback(*planet);
      cout << *planet;
    }
  (*universe).draw(window1);
  window1.display();
as you can see we pushed back the object into a vector with in the universe class. which will delete the objects.



/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

My partner was Stephen J. Little

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

The planets rotating the opposite direction, the planet being off the screen and the planets not moving at all

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
Extra credit: sound file, clock
