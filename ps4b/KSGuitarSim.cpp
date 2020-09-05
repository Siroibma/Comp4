#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "RingBuffer.h"
#include "StringSound.h"

#define CONCERT_A 220.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound gs) {
  std::vector<sf::Int16> samples;

  gs.pluck();
  int duration = 8;  // seconds
  int i;
  for (i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main() {
 sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Plucked String Sound Lite");
  sf::Event event;
  double freq;
  std::vector<sf::SoundBuffer> buffers(37);
  std::vector<sf::Sound> sounds(37);
  std::vector<std::vector<sf::Int16> > samples(37);
  int i = 0;
  while(i<37){
    freq = 200 + (i * 20);
    StringSound gs= StringSound(freq);
    samples[i] = makeSamples(gs);
    buffers[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, SAMPLES_PER_SEC);
    sounds[i].setBuffer(buffers[i]);
    i++;
  }
  unsigned int index;
  std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;

        case sf::Event::TextEntered:
          index = keyboard.find(event.text.unicode);
          if (index != std::string::npos){
	    if(index >= 0 && index < 38){
            sounds[index].play();
	    }
	  }
          break;
	  
        default:
          break;
      }
      window.clear();
      window.display();
    }
  }
  return 0;
}

