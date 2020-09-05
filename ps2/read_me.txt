/**********************************************************************
 *  ps2-readme template                                                   
 *  Recursive Graphics (Pythagoras tree)                       
 **********************************************************************/

Your name: Ambioris Lora

Hours to complete assignment: 11 hours or so

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
This assignment was about teaching us how to manipulate shapes and recursively draw pictures. I was able to learn how to move shapes and use recursion on shapes. The goal of the assignment was to generate a pythagoras tree or another word for it is "fractal" through the sfml library. This isnt a difficult assignment in hindsight but it definitely took a long time to manipulate the shapes correctly. 


 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
The key part of this assignment was to picture things 10 steps ahead and it became alot easier. All I had to do was figure out how to get the corners


/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
I implemented the sf::RenderTarget& target, const int N, const sf::RectangleShape& parent). This allowed me to draw the tree using easy syntax. I also changed the color of tree using the setFill option for rectangular shapes. I used the setorigin function to set the the origins of the right and left rectangles to bottom left and right. I also used to transformpoint to transcribe the points from the parent rectangle to the global scale.



 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned how to manipluate origins and how to use transform point to transform cordinate systems from other systems. I learned to not use convex shapes for things like this. I also learned how to rotations more. 


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

None besides talks about how others got the corners. I ended up figuring out by myself eventually

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/

The makefile and the overloaded functions made it very difficult to work with. I also had issues with the recursion at first. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

The makefile and recursively getting the corners took me the longest
