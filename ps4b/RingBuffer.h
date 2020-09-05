/* Copyright 2020 Ambioris Lora */
#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdint.h>
#include <iostream>
#include <vector>
#include <memory>

class RingBuffer {
 public:
    explicit RingBuffer(int capacity);
    RingBuffer(const RingBuffer& obj) {
    bufferCapacity = obj.bufferCapacity;
   bufferSize = obj.bufferSize;
    head = obj.head;
    ring = obj.ring;
  }
    int size();  
    bool isEmpty();  
    bool isFull();  // is the buffer full (size equals capacity)?
  void enqueue(int16_t x);  // add item x to the end
  int16_t dequeue();  // delete and return item from the front
  int capacity() {
    return bufferCapacity;
  }
  int16_t peek();  // return (but do not delete) item from the front
 private:
    int bufferSize, bufferCapacity;
    int16_t *ring, head;
};
#endif
