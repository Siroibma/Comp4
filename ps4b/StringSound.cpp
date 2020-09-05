#include "StringSound.h"
#include "RingBuffer.h"

StringSound::StringSound(double frequency){
    int string_cap = ceil(44100/frequency); //44,100 divided by given frequency rounded to the highest whole number
    _rb = new RingBuffer(string_cap);
  _time = 0;
    while (!_rb->isFull()) {
      _rb->enqueue(0);
    }
}
StringSound::StringSound(std::vector<int16_t> init){
    _rb = new RingBuffer(init.size());
    int i = 0;
    while (!_rb->isFull()) {
      _rb->enqueue(init[i]);
      i++;
    }
// std::cout << (*_rb).capacity();
  _time = 0;
}

void StringSound::pluck(){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(-32768,32767); //maintaining int_16t
  if (_rb->isFull()) {
    for (int i = 0; i < _rb->size(); i++) {
      _rb->dequeue();
    }
  }
  while (!_rb->isFull()) {
    _rb->enqueue(distribution(generator));
  }
}

void StringSound::tic() {
  int16_t vHold=(_rb->dequeue() + _rb->peek())*0.5 * 0.996;
  _rb->enqueue(vHold);
  _time++;
}

int16_t StringSound::sample(){
  return _rb->peek();
}

int StringSound::time(){
  return _time;
}

StringSound::~StringSound() {
 
}
