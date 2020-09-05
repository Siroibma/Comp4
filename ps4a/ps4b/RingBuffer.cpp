/* Copyright 2020 Ambioris Lora */
#include "/home/osboxes/ps4b/RingBuffer.h"
#include <stdint.h>
#include <iostream>
#include <vector>

RingBuffer::RingBuffer(int capacity) {
  if (capacity == 0) {
    throw std::invalid_argument("RingBuffer constructor: capcity must be greater than zero");
  }
  ring.reserve(capacity);
  head = 0;
  tail = 0;
  ring_cap = capacity;
  for (int i = 0; i < capacity - 1; i++) {
      ring[i] = i;
  }
}

int RingBuffer::size() {
  return ring.size();
}

bool RingBuffer::isEmpty() {
  if (ring.size() == 0) {
      return true;
  } else {
      return false;
  }
}

bool RingBuffer::isFull() {
  if (ring.size() == ring_cap) {
      return true;
  } else {
      return false;
  }
}

void RingBuffer::enqueue(int16_t x) {
  if (isFull()) {
    throw std::runtime_error("enqueue: can't enqueue to a full ring!");
  } else {
    //  add by 1 to move but to make sure it stays within range
    ring.push_back(x);
    tail = (tail + 1) % ring_cap;
  }
}

int16_t RingBuffer::dequeue() {
  if (isEmpty()) {
    throw std::runtime_error("dequeue: can't dequeue from an empty ring");
  }
  if (ring.size() != 0) {
    // Here we hold the current value to return it
    v_hold = ring[head];
    ring.erase(ring.begin() + head);
    // if we go over the the cap we start at 0
    // elsewise we keep the head going in a circle
    // head = (head + 1) % ring_cap;
  }
  return v_hold;
}

int16_t RingBuffer::peek() {
  // simply return the head index
  return ring[head];
}

bool RingBuffer::empty() {
  ring.clear();
  if(ring.capacity() != 0 && ring.size() == 0) {
    return true;
  } else {
    return false;
  }
}
