#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800,800),"ps0");
  sf::Texture texture;
  if(!texture.loadFromFile("sprite.png"))
    {
      return EXIT_FAILURE;
    }
  sf::Sprite sprite(texture);
  while(window.isOpen())
    {
      sf::Event event;
      while(window.pollEvent(event))
	{
	  if(event.type == sf::Event::Closed)
	    {
	      window.close();
	    }
	  else if(event.type == sf::Event::KeyPressed)
	    {
	      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
		  sprite.move(0,-3);
		}
	      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
		  sprite.move(0,3);
		}
	      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
		  sprite.move(3,0);
		}
	      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
		  sprite.move(-3,0);
		}
	      else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
		  sprite.rotate(45);
		}
	    }
	}
	window.clear();
	window.draw(sprite);
	window.display();
    }
    return EXIT_SUCCESS;
}
