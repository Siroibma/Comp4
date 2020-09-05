/* Copyright 2020 Ambioris Lora */
#ifndef _HOME_OSBOXES_PS4B_RINGBUFFER_H_
#define _HOME_OSBOXES_PS4B_RINGBUFFER_H_

#include <stdint.h>
#include <iostream>
#include <vector>
#include <memory>

class RingBuffer{
 public:
  explicit RingBuffer(int capacity);
  RingBuffer(const RingBuffer& obj) {
    ring_cap = obj.ring_cap;
    head = obj.head;
    tail = obj.tail;
    v_hold = obj.v_hold;
    ring = obj.ring;
  }
  int size();
  bool isEmpty();
  bool isFull();  // is the buffer full (size equals capacity)?
  void enqueue(int16_t x);  // add item x to the end
  int16_t dequeue();  // delete and return item from the front
  int capacity() {
    return ring.capacity();
  }
  int16_t peek();  // return (but do not delete) item from the front
  friend std::ostream& operator <<(std::ostream& out, const RingBuffer& a) {
    for (unsigned int i = 0; i < a.ring.size(); i++) {
      out << a.ring[i] << std::endl;
    }
    return out;
  }
  
  bool empty();
 private:
  unsigned int ring_cap;
  unsigned int head, tail, v_hold;
  std::vector<int> ring;
};

#endif  // _HOME_OSBOXES_PS4B_RINGBUFFER_H_
