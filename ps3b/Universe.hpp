#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP
#include <vector>
#include "particle.hpp"

class Universe{
public:
        //Do a loop and draw each particle
	void draw(sf::RenderWindow& window1,double Time)
	{
	for(unsigned int i = 0; i < uni.size();i++)
	 {
		window1.draw(uni[i]);
		uni[i].step(Time);
		uni[i].setPosition();
		//cout << "Called Loop " << i <<endl;
	 }
	} 
	void forceLoop(void)
	{
		double fX;
 		double fY;
	   for(unsigned int i = 0; i < uni.size();i++)
	    {
		 fX = 0;
 		 fY = 0;
 		for(unsigned int j = 0; j < uni.size();j++)
		{
			if(i!= j)
			{
			fX += calcX(uni[i],uni[j]);
			fY += calcY(uni[i],uni[j]);
			}
		}
		uni[i].setForce(fX,fY);
	    }
        }
	//puchback the particles
	void pushback(particle obj)
    	{
	uni.push_back(obj);
	}
   void out(void)
	{
	cout << "\nNew Simulation Results\n";
	for(unsigned int i = 0; i < uni.size();i++)
	    {
	    cout<<uni[i]<<endl;
	    }
	}
private:
 	std::vector<particle> uni;
};





#endif
