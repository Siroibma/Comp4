#include "FibLSFR.hpp"
#define BOOST_TEST_MODULE BigT
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <string>

BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps)
{
  LSFR a("1011011000110110");
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 1);

  LSFR b("1011011000110110");
  BOOST_REQUIRE(b.generate(9) == 51);
}

BOOST_AUTO_TEST_CASE(step20by3)
{
  LSFR a("11101111111111111100");
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 0);
}

BOOST_AUTO_TEST_CASE(yelena_example1){
  LSFR a("1011011000110110");
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 0);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 1);
  BOOST_REQUIRE(a.step() == 0);
}

BOOST_AUTO_TEST_CASE(yelenaexample1)
{
  LSFR a("1011011000110110");
  BOOST_REQUIRE(a.generate(5) == 3);
}
