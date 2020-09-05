#include "FibLSFR.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <algorithm>

sf::Image photomag(sf::Image& in, LSFR b);

int main(int argc,char* argv[]){
  string a = argv[3];
  LSFR test(a);
  
  sf::Vector2u v1;
  sf::Texture scram,prescram;

  //sf::Color pix;

  //unsigned int i,j
  //I noticed too late that the for loop has to be and x and y as the ints. You can't use i and j
  //unsigned int x,y;
  
  //create two copies of the image
  sf::Image before;
  if(!before.loadFromFile(argv[1])){
    return EXIT_FAILURE;
  }

  sf::Image after;
  if(!after.loadFromFile(argv[1])){
    return EXIT_FAILURE;
  }

  //Get image size
  v1 = before.getSize();


  //two sprites. one for the before the scramble and one for after
  sf::Sprite sprite1,sprite2;    
  
  
  //prescramble
  prescram.loadFromImage(before);
  sprite2.setTexture(prescram);

  after = photomag(before, test);
  
  //postscram
  scram.loadFromImage(after);
  sprite1.setTexture(scram);
  

  //save result to a png, you can run it twice to get the original picture
  after.saveToFile(argv[2]);

  //two windows
  sf::RenderWindow window(sf::VideoMode(v1.x,v1.y), "Base Picture");
  sf::RenderWindow scramble(sf::VideoMode(v1.x,v1.y), "Scrambled");
  
  //Code we were given on the pdf
  while(scramble.isOpen() && window.isOpen())
    {
      sf::Event event;
      while(scramble.pollEvent(event))
	{
	  if(event.type == sf::Event::Closed)
	    {
	    scramble.close();
	    }
	}
      while(window.pollEvent(event))
	{
	if(event.type == sf::Event::Closed)
	  {
	    window.close();
	  }
	}
      window.clear();
      window.draw(sprite2);
      window.display();
      scramble.clear();
      scramble.draw(sprite1);
      scramble.display();
    }
  return 0;
}

sf::Image photomag(sf::Image& in, LSFR b){
  unsigned x,y;
  sf::Vector2u u1;
  sf::Color p;
  u1 = in.getSize();
  for(x = 0; x < u1.x; x++){
    for(y = 0; y < u1.y; y++){
      p = in.getPixel(x,y);
      p.r = p.r ^ b.generate(8);
	//pix.r = pix.r ^ test.generate(5);

      p.b = p.b ^ b.generate(8);
	//pix.b = pix.b ^ test.generate(5);

      p.g = p.g ^ b.generate(8);
	//pix.g = pix.g ^ test.generate(5);
      in.setPixel(x,y,p);
      // a whole lot of trial and error, garbage code below
      /*r = pix.r;
      b = pix.b;
      g = pix.g;
      pix.r = to_int(to_bin(r) ^ test.toString());
      test.step();
      pix.b = to_int(to_bin(b) ^ test.toString());
      test.step();
      pix.g = to_int(to_bin(g) ^ test.toString());
      */
      }
    }
  return in;
}
      
