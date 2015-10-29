#include <iostream>
#include <string>

#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

// Starter-case
BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {

  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}

// Testing arbitrary size and tap, all zeros.
BOOST_AUTO_TEST_CASE(twentyBitsAllZeros) {

  LFSR l("00000000000000000000", 2);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("00000000000000000000", 2);
  BOOST_REQUIRE(l2.generate(9) == 0);
}

// Testing to see if tap at zero works properly and in the right order
BOOST_AUTO_TEST_CASE(fiveBitsTapAtZero) {
  LFSR l("11001", 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("11001", 0);
  BOOST_REQUIRE(l2.generate(6) == 28);
}

// Arbitrary size, testing to see if tap at the first element in the string
// (the most significant bit) works properly.
BOOST_AUTO_TEST_CASE(thirtyBitsTapAt29) {
  LFSR l("110011001100110011001100110011", 29);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);

  LFSR l2("110011001100110011001100110011", 29);
  BOOST_REQUIRE(l2.generate(29) == 0);
}
