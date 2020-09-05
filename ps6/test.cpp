/* Copyright 2020 Ambioris Lora */
#define BOOST_TEST_MODULE BigT
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include "/home/osboxes/ps6/MModel.h"
#include <iostream>
#include <string>

BOOST_AUTO_TEST_CASE(TEST_UNO) {
  BOOST_CHECK_NO_THROW(MModel a("abc", 1));
  MModel a("abc",2);
  BOOST_REQUIRE(a.kOrder() == 2);
}

BOOST_AUTO_TEST_CASE(TEST_DOS) {
  MModel b("abc",2);
  BOOST_CHECK_THROW(b.kRand(""), MModel);
}

BOOST_AUTO_TEST_CASE(TEST_TRES) {
  MModel c("abc",2);
  BOOST_REQUIRE(c.freq("bc") == 1);
  BOOST_CHECK_NO_THROW(c.kRand(""));
}

BOOST_AUTO_TEST_CASE(TEST_QUATRO) {
  MModel d("abc",2);
  BOOST_REQUIRE(d.freq("ab",'c') == 1);
}

BOOST_AUTO_TEST_CASE(TEST_CINCO) {
  MModel e("abcabc 123123",2);
  BOOST_REQUIRE(e.freq("ab") == 2);
}

BOOST_AUTO_TEST_CASE(TEST_FINALE) {
  MModel f("abc",2);
  BOOST_REQUIRE(f.kOrder() == 2);
}
