#ifndef _LFSR_H
#define _LFSR_H

#include <iostream>
#include <string>

class LFSR {
 private:
  std::string seed;
  int tap;
 public:
  LFSR(std::string _seed, int _tap);
  ~LFSR();
  std::string getSeed();
  int getTap();
  int step();
  int generate(int k);

  friend std::ostream& operator<<(std::ostream& os, LFSR &lfsr);
};

#endif
