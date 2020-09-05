#include "particle.hpp"
#include "Universe.hpp"
#include <string>
#include <iostream>
#include <memory>
#include <iterator>

int main(int argc,char *argv[]){

  int num_part;
  double radius;
  double current_time = 0;
  double tStemp = stod(argv[2]);
  double simulationT = stod(argv[1]);
  
  //Set up render window and the background
  sf::RenderWindow window1(sf::VideoMode(500, 500), "Immersion 101");

  std::string hold;
  
  sf::Image backgroundi;
  backgroundi.loadFromFile("background_image.jpg");

  sf::Texture backgroundt;
  backgroundt.loadFromImage(backgroundi);

  sf::Time duration = sf::seconds(10000);

  sf::Font font;
  if(!font.loadFromFile("arial.ttf")){
    std::cerr << "didnt load chief" << std::endl;
  }

  
  sf::Text timer;
  timer.setFont(font);
  timer.setCharacterSize(20);


  sf::Sprite backgrounds;
  backgrounds.setTexture(backgroundt);

  window1.setFramerateLimit(60);

  std::cout << std::scientific;
  //Play sound

  sf::Music buffer;
  buffer.openFromFile("2001.wav");
 // buffer.setVolume(100.f);
  buffer.setLoop(true);
  buffer.play();
 //smart pointer
  std::unique_ptr<Universe>universe(new Universe());
 // Universe universe = Universe();
  particle* planet;
  //std::ifstream infile;
 //Get number of particles and radius
  std::cin >> num_part >> radius;
  window1.draw(backgrounds);
  window1.display();

  cout << "Input: " << num_part << " Radius: " << radius << endl;
  //Interate through and add the particles into the Universe
  for(int i = 0; i < num_part;i++)
	{
	
		planet = new particle();
		cin >> *planet;
		(*universe).pushback(*planet);
		cout << *planet;
	}
    //(*universe).draw(window1);
    // window1.display();
    sf::Clock clock;
  while (window1.isOpen())
  {
    window1.clear();
    sf::Event event;
    while(window1.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window1.close();
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        window1.close();
      }
    }
    duration = clock.getElapsedTime();
    hold = std::to_string(duration.asSeconds() * tStemp);
    timer.setString(hold + "s");
    (*universe).forceLoop();
    window1.draw(backgrounds);
    (*universe).draw(window1,tStemp);
    window1.draw(timer);
    window1.display();
    current_time += tStemp;
    if(current_time >= simulationT)
      {
	break;
      }
   }
  (*universe).out();
  return 0;
}
