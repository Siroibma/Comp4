#include "StringSound.h"

StringSound::StringSound(double frequency){
  int string_cap = ceil(44100/frequency); //44,100 divided by given frequency rounded to the highest whole number
  _rb = new RingBuffer(string_cap);
  _time = 0;
  std::cout << (*_rb).capacity() << std::endl;
}

StringSound::StringSound(std::vector<int16_t> init){
  _rb = new RingBuffer(init.capacity());
  for(int i = 0; i < init.capacity(); i++) {
    (*_rb).enqueue(init.at(i));
  }
  // std::cout << (*_rb).capacity();
  _time = 0;
}

void StringSound::pluck(){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(-32768,32767); //maintaining int_16t
  (*_rb).empty(); // Here we clear the vector while maintaining capctity

  //Fill the vector with random numbers
  for(int i = 0; i < (*_rb).capacity(); ++i) {
    (*_rb).enqueue(distribution(generator));
  }
    
}

void StringSound::tic() {
  int16_t hold = (*_rb).dequeue(); //hold is equal to the first value
  hold = ((hold + (*_rb).peek())*.5) * .996; // (first value + second value *.5) * .996
  (*_rb).enqueue(hold);
  _time += 1; // This represents the amount of times we used tic
}

int16_t StringSound::sample(){
  return (*_rb).peek();
}

int StringSound::time(){
  return _time;
}

StringSound::~StringSound() {
  std::cout << "Destructor called, deleting memory allocated" << std::endl;
  delete(_rb);
}
