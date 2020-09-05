#include "particle.hpp"
//Need default constructor
particle::particle(){
  return;
}

//Particle class
particle::particle(double xpos, double ypos, double xvel, double yvel, double mass, std::string planet)
{
  sf::Sprite draw_plan;
  x_position = xpos;
  y_position = ypos;
  x_velocity = xvel;
  y_velocity = yvel;
  p_mass = mass;
  picture = planet;
  if(!pImage.loadFromFile(picture)){
    return;
  }
  pTexture.loadFromImage(pImage);
  pSprite.setTexture(pTexture);
  x_position = ((window.x/radius) * x_position/2) + (window.x / 2);
  y_position = ((window.y/radius) * y_position/2) + (window.y / 2);

  pSprite.setPosition(sf::Vector2f(x_position,y_position));

  std::cout << x_position << std::endl << y_position << std::endl;
}
 //Output operator                                       
std::ostream& operator <<(std::ostream &out, particle& c){
  out << "current x Position: " << c.x_position << std::endl;
  out << "current y Postion: " << c.y_position << std::endl;
  out << "current x Velocity: " << c.x_velocity << std::endl;
  out << "current y Velocity: " << c.y_velocity << std::endl;
  out << "Particle Mass: " << c.p_mass << std::endl;
  out << "Particle Name: " << c.picture << std::endl;
  return out;
}
//Overload of the draw of sf::Drawable
void particle::draw(sf::RenderTarget& obj, sf::RenderStates status) const
{
  obj.draw(pSprite);
}


