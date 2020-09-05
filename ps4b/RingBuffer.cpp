//* Copyright 2020 Ambioris Lora */
#include "RingBuffer.h"
#include <stdint.h>
#include <iostream>
#include <vector>

RingBuffer::RingBuffer(int capacity) {
  if (capacity == 0) {
    throw std::invalid_argument("RingBuffer constructor: capcity must be greater than zero");
  }
  bufferSize = 0;
  head = 0;
  bufferCapacity = capacity;
  ring = new int16_t[bufferCapacity];
}

int RingBuffer::size() {
  return bufferSize;
}

bool RingBuffer::isEmpty() {
  if (bufferSize == 0) {
      return true;
  } else {
      return false;
  }
}
///////////////
bool RingBuffer::isFull() {
  if (bufferSize == bufferCapacity) {
      return true;
  } else {
      return false;
  }
}
//////
void RingBuffer::enqueue(int16_t x) {
  if (isFull()) {
    throw std::runtime_error("enqueue: can't enqueue to a full ring!");
  } else {
  ring[(head + bufferSize) % bufferCapacity] = x;
  bufferSize++;
  }
}

int16_t RingBuffer::dequeue() {
  if (isEmpty()) {
    throw std::runtime_error("dequeue: can't dequeue from an empty ring");
  }
  bufferSize--;
  int dequeued = head;
  head = (head + 1) % bufferCapacity;
  return ring[dequeued];
}

int16_t RingBuffer::peek() {
  return ring[head];
}
