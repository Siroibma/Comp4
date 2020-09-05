#include <iostream>
#include <SFML/Graphics>
#include <SFML/System>
#include <SFML/Window>

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000,1000), "Earth Test");
  sf::Texture p;
  if(!p.loadFromFile("earth.gif")){
      return EXIT_FAILURE;
    }
  sf::Sprite eart;

  eart.setTexture(p);

  eart.setPosition(749,500);
  while(window.isOpen())
    {
      sf::Event event;
      while(window.pollEvent(event)
	{
	  if(event.type == sf::Event::Closed){
	    window.close();
	  }
	}
      window.clear();
      window.draw(eart);
      window.display();
	
	
