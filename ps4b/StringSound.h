#ifndef STRINGSOUND_H
#define STRINGSOUND_H

#include "RingBuffer.h"
#include <math.h>
#include <random>
#include <vector>
class StringSound{
 public:
   explicit StringSound(double frequency);
  explicit StringSound(std::vector<int16_t> init);
  StringSound (const StringSound &obj) {
    _time = obj._time;
    *_rb = *obj._rb;
  };
    ~StringSound();
    void pluck();
    void tic();
   int16_t sample();
    int time();
 private:
    RingBuffer* _rb;
    int _time;
};
#endif
