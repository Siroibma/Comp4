#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
const sf::Vector2f window(500,500);
const double radius = 2.50e11;
const double g_constant = 6.67408e-11;
using namespace std;

class particle: public sf::Drawable
{
public:
  particle();
  particle(double xpos, double ypos, double xvel, double yvel, double mass, std::string planet);
 //NEW STUFF
 void setForce(double x, double y)
 {
  x_force = x;
  y_force = y;
 }
  //calc x force
  friend double calcX(particle &a1,particle &b2)
 {
  double tx= b2.x_position - a1.x_position;
  double ty= b2.y_position - a1.y_position;
  double distance= pow(ty,2)+pow(tx,2);
  double force= (g_constant*a1.p_mass*b2.p_mass)/distance;
  return (force*(tx/sqrt(distance)));
 }
 //Calc y force
 friend double calcY(particle &a1,particle &b2)
{
  double tx= b2.x_position - a1.x_position;
  double ty= b2.y_position - a1.y_position;
  double distance= pow(tx,2)+pow(ty,2);
  double force= (g_constant*a1.p_mass*b2.p_mass)/distance;
  return (force*(ty/sqrt(distance)));
 }
  //simulate a step
 void step(double time)
 {
 x_acc = x_force/p_mass;
 y_acc = y_force/p_mass;
 x_velocity += x_acc*time;
 y_velocity += y_acc*time;
 x_position += x_velocity*time;
 y_position += y_velocity*time;
 }
  //set position
 void setPosition(void)
 {
  double newX= ((x_position/radius)*(window.x/2))+(window.x/2);
  double newY= ((y_position/radius)*(window.y/2))+(window.y/2);
 // double x = ((window.x/radius)* x_position/2)+(window.x/2);
 //double y = ((window.y/radius)* y_position/2)+(window.y/2);
  pSprite.setPosition(sf::Vector2f(newY,newX));

 }


  friend ostream& operator <<(std::ostream &out, particle& c);
  //Insertion overload
  friend istream& operator >>(std::istream &in, particle& d)
 {
 in >> d.x_position >> d.y_position >> d.x_velocity >> d.y_velocity >> d.p_mass >> d.picture;

  if(!d.pImage.loadFromFile(d.picture)){
    throw "Picture did not load";
  }
  d.pTexture.loadFromImage(d.pImage);
  d.pSprite.setTexture(d.pTexture);

  
  //d.x_position = ((window.x/radius) * d.x_position/2) + (window.x / 2);
  //d.y_position = ((window.y/radius) * d.y_position/2) + (window.y / 2);
  
  d.pSprite.setPosition(sf::Vector2f(d.x_position, d.y_position));
  d.x_force = 0;
  d.y_force = 0;
  d.x_acc = 0;
  d.y_acc = 0;
  return in;
 }
  void draw(sf::RenderTarget& obj, sf::RenderStates status) const;
private:
  //Pheraps make a strucutre akin to Vector2f to hold x,f more effcient
  // - SL
  double x_force;
  double y_force;
  double x_acc;
  double y_acc;
  double x_position;
  double y_position;
  double x_velocity;
  double y_velocity;
  double p_mass;
  std::string picture;

  sf::Image pImage;
  sf::Sprite pSprite;
 //PTexture may no be needed -SL
  sf::Texture pTexture;
};

#endif 
