#include <cstdlib>
#include <sstream>
#include "LFSR.hpp"

LFSR::LFSR(std::string _seed, int _tap) {
  seed = _seed;
  tap = _tap;
}

LFSR::~LFSR() { }

std::string LFSR::getSeed() {
  return seed;
}

int LFSR::getTap() {
  return tap;
}

int LFSR::step() {
  std::ostringstream oss;
  int bit = (seed[0] - 48) ^ (seed[seed.length() - (tap + 1)] - 48);

  for(unsigned i = 1; i < seed.length(); i++)
    oss << seed[i];
  oss << bit;

  seed = oss.str();

  return bit;
}

int LFSR::generate(int k) {
  int result = 0;
  for(int i = 0; i < k; i++) {
    result = result * 2 + step();
  }
  
  return result;
}

std::ostream& operator<<(std::ostream& os, LFSR &lfsr) {
  os << lfsr.getSeed();
  return os;
}
