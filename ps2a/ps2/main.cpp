#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>

void drawptree(sf::RenderTarget& win, const float L, const int n);
void drawptree(sf::RenderTarget& win, sf::RectangleShape& rectangle, const int n);
/*
int main(){
  // int a = argv[1];
  //const float pyth = sqrt(2) / 2; 
  unsigned int L = 100;
  
  //sf::RectangleShape rectangle;
  //sf::VertexArray quad(sf::Quads, 4);

  //rectangle.setOrigin(rectangle.getSize().x, rectangle.getSize().y);
  //quad[0].position = sf::Vector2f(30.f, 30.f);
  //quad[1].position = sf::Vector2f(100.f, 30.f);
  //quad[2].position = sf::Vector2f(30.f, 100.f);
  //quad[3].position = sf::Vector2f(100.f, 100.f);
  
  //rectangle.setSize(sf::Vector2f(L,L));
  //rectangle.setPosition(quad[0].position);
  
  //auto right = rectangle;
  //right.setSize(sf::Vector2f(L,L));
  //rectangle.setFillColor(255,0,0);
  //right.setPosition(quad[1].position);
  //right.setRotation(45);
  //rectangle.setRotation(-45) 
  //sf::Vector2i vec2;
  //sf::Vector2u topleft = rectangle.getTransform().transformPoint(vec2(0,0));
  
  sf::RenderWindow window(sf::VideoMode(6 * L,4 * L), "Rectangle test");
  while(window.isOpen())
    {
      sf::Event event;
	while(window.pollEvent(event)){
	  if(event.type == sf::Event::Closed){
	    window.close();
	  }
	}
      window.clear();
      drawptree(window,L,10);
      window.display();
    }
  return EXIT_SUCCESS;
}
*/

void drawptree(sf::RenderTarget& win, const float L, const int n){
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(L,L));
  rectangle.setOrigin(rectangle.getSize().x/2.f, rectangle.getSize().y/2.f);
  rectangle.setPosition(win.getSize().x/2.f,win.getSize().y/2.f);
  drawptree(win,rectangle,n);
}



void drawptree(sf::RenderTarget& win, const sf::RectangleShape& rectangle, const int n){

  const float pyth = sqrt(2.f) / 2.f;
  auto right = rectangle;
  auto left = rectangle;
  auto tran = rectangle.getTransform();
  if(n < 1){
   win.draw(rectangle);
  }

  right.setSize(rectangle.getSize() * pyth);
  right.setOrigin(0,right.getSize().y);
  right.setRotation(45);
  right.setPosition(tran.transformPoint({rectangle.getSize().x,0}));


  left.setSize(rectangle.getSize() * pyth);
  left.setOrigin(0,0);
  left.setRotation(-45);
  left.setPosition(tran.transformPoint({0,0}));  
  
  drawptree(win,right,n-1);
  drawptree(win,left,n-1);
}

int main()
{
    const float L = 150;
    const int N = 14;

    const unsigned width = static_cast<unsigned>(6 * L);
    const unsigned height = static_cast<unsigned>(4 * L);
    sf::RenderWindow window{{width, height}, "Pythagorean Tree"};
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        for (sf::Event event; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        drawptree(window, L, N);
        window.display();
    }
}
