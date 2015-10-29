// Copyright Michael Overy 2015

#ifndef _MARKOVMODEL_HPP
#define _MARKOVMODEL_HPP

#include <string>
#include <vector>
#include <map>

using std::string;

class MarkovModel {
 private:
  std::map <string, int> kgrams;
  int _order;
  string alphabet;
  string initial;
 public:
  MarkovModel(string text, int k);
  int order() const;
  int freq(string kgram);
  int freq(string kgram, char c);
  char randk(string kgram);
  string gen(string kgram, int T);

  friend std::ostream& operator<<(std::ostream& os, MarkovModel& mm);
};

#endif
