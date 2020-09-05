#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include "RingBuffer.h"
#include <math.h>
#include <random>

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100

class StringSound{
public:
  explicit StringSound(double frequency);
  explicit StringSound(std::vector<sf::Int16> init);
  StringSound (const StringSound &obj) {
    _time = obj._time;
    _rb = obj._rb;
  }
  //~StringSound();
  void pluck();
  void tic();
  sf::Int16 sample();
  int time();
private:
  RingBuffer _rb;
  int _time;
};

std::vector<sf::Int16> makeSamplesFromString(StringSound gs) {
  std::vector<sf::Int16> samples;
  gs.pluck();
  int duration = 8;
  int i;
  for(i = 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }
  return samples;
}

StringSound::StringSound(double frequency){
  int string_cap = ceil(44100/frequency); //44,100 divided by given frequency rounded to the highest whole number
  _rb(string_cap);
  for(int i = 0; i < string_cap; i++){
    _rb.enqueue(0);
  }
  _time = 0;
  //std::cout << (*_rb).capacity() << std::endl;
}

StringSound::StringSound(std::vector<sf::Int16> init){
  int string_cap = init.size();
  
  for(auto i = init.begin(); i < init.end(); i++) {
    _rb.enqueue((std::int16_t)*i);
  }
  //std::cout << (*_rb).capacity();
  _time = 0;
  //std::cout << (*_rb).capacity() << std::endl;
}

void StringSound::pluck(){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(-32768,32767); //maintaining int_16t
  _rb.empty(); // Here we clear the vector while maintaining capctity

  //Fill the vector with random numbers
  for(int i = 0; i < _rb.capacity(); ++i) {
    _rb.enqueue(distribution(generator));
  }
  //std::cout << (*_rb).peek() << std::endl;
}

void StringSound::tic() {
  int16_t hold = _rb.dequeue(); //hold is equal to the first value
  hold = ((hold + _rb.peek())*.5) * .996; // (first value + second value *.5) * .996
  _rb.enqueue(hold);
  _time += 1; // This represents the amount of times we used tic
  //std::cout << (*_rb).size() << std::endl;
}

sf::Int16 StringSound::sample(){
  return _rb.peek();
}

int StringSound::time(){
  return _time;
}

/*StringSound::~StringSound() {
  std::cout << "Destructor called, deleting memory allocated" << std::endl;
  delete(_rb);
}
*/

int main() {
  /*
  sf::RenderWindow window(sf::VideoMode(300, 200), "SFML Guitar Hero Lite");
  sf::Event event;
  double freq;
  std::vector<sf::Int16> samples;

  // we're reusing the freq and samples vars, but
  // there are separate copies of GuitarString, SoundBuffer, and Sound
  //   for each note
  //
  // GuitarString is based on freq
  // samples are generated from GuitarString
  // SoundBuffer is loaded from samples
  // Sound is set to SoundBuffer

  freq = CONCERT_A;
  StringSound gs1 = StringSound(freq);
  sf::Sound sound1;
  sf::SoundBuffer buf1;
  samples = makeSamplesFromString(gs1);
  if (!buf1.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SEC))
    throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
  sound1.setBuffer(buf1);

  freq = CONCERT_A * pow(2, 3.0/12.0);
  StringSound gs2 = StringSound(freq);
  sf::Sound sound2;
  sf::SoundBuffer buf2;
  samples = makeSamplesFromString(gs2);
  if (!buf2.loadFromSamples(&samples[0], samples.size(), 2, SAMPLES_PER_SEC))
    throw std::runtime_error("sf::SoundBuffer: failed to load from samples.");
  
  sound2.setBuffer(buf2);

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::KeyPressed:
        switch (event.key.code) {
        case sf::Keyboard::A:
          sound1.play();
          break;
        case sf::Keyboard::C:
          sound2.play();
          break;
        default:
          break;
        }

      default:
        break;
      }

      window.clear();
      window.display();
    }
    }*/
  return 0;
}
