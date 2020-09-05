/* Copyright 2020 Ambioris Lora */
#define BOOST_TEST_MODULE BigT
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include "/home/osboxes/ps4a/RingBuffer.h"
#include <iostream>
#include <string>

BOOST_AUTO_TEST_CASE(EMPTY_LADS_TEST) {
  BOOST_CHECK_NO_THROW(RingBuffer a(0));
  RingBuffer a(1);
  a.enqueue(1);
  // BOOST_REQUIRE(a.dequeue() == 1);
}

BOOST_AUTO_TEST_CASE(FULL_LADS_TEST) {
  RingBuffer b(2);
  b.enqueue(1);
  b.enqueue(2);
  BOOST_CHECK_THROW(b.enqueue(1), RingBuffer);
}

BOOST_AUTO_TEST_CASE(DEQUEUE_EMPTY_LADS_TEST) {
  RingBuffer c(1);
  c.enqueue(1);
  BOOST_REQUIRE(c.dequeue() == 1);
  BOOST_CHECK_NO_THROW(c.dequeue());
}

BOOST_AUTO_TEST_CASE(TEST) {
  RingBuffer d(1);
  d.enqueue(1);
  BOOST_REQUIRE(d.dequeue() == 1);
}

BOOST_AUTO_TEST_CASE(PEEK_TEST) {
  RingBuffer e(1);
  e.enqueue(1);
  BOOST_REQUIRE(e.peek() == 1);
}

BOOST_AUTO_TEST_CASE(DEQUEUE_TEST) {
  RingBuffer f(1);
  f.enqueue(2);
  BOOST_REQUIRE(f.dequeue() == 2);
}
