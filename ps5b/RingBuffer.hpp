// Copyright 2015 Michael Overy

#ifndef _RING_BUFFER_HPP
#define _RING_BUFFER_HPP

#include <stdint.h>
#include <vector>

class RingBuffer {
 private:
  std::vector<int16_t> buffer;
  int _size;
  int _capacity;
  int first;
  int last;
 public:
  explicit RingBuffer(int capacity);
  int size() const;
  bool isEmpty() const;
  bool isFull() const;
  void enqueue(int16_t arg);
  int16_t dequeue();
  int16_t peek() const;
  void emptyBuffer();
};

#endif
