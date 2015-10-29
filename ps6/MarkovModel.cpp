// Copyright Michael Overy 2015

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "MarkovModel.hpp"

using std::string;

MarkovModel::MarkovModel(string text, int k) {
  srand(time(NULL));
  _order = k;
  initial = text;

  // Collect characters for a list of the alphabet
  for (unsigned i = 0; i < text.size(); i++)
    if (string::npos == alphabet.find(text[i]))
      alphabet.push_back(text[i]);

  // Create a map of all the kgrams
  for (unsigned i = 0; i < text.size(); i++) {
    string temp;
    string temp2;

    // Build up a string of k consecutive characters
    for (unsigned j = i; j < i + k; j++)
      if (j >= text.size())
        temp.push_back(text[j - text.size()]);
      else
        temp.push_back(text[j]);

    // Put the occurance of the string into the kgram map
    if (kgrams.end() == kgrams.find(temp))
      kgrams[temp] = 1;
    else
      kgrams[temp] += 1;

    // Put in all possible k+1 strings (regardless of existence)
    for (unsigned j = 0; j < alphabet.size(); j++)
      if (kgrams.end() == kgrams.find(temp + alphabet[j]))
        kgrams[temp + alphabet[j]] = 0;

    // Build up a string of k+1 consecutive characters
    for (unsigned j = i; j < i + k + 1; j++)
      if (j >= text.size())
        temp2.push_back(text[j - text.size()]);
      else
        temp2.push_back(text[j]);

    // Put the occurance of the string into the kgram map
    kgrams[temp2] += 1;
  }
}

int MarkovModel::order() const {
  return _order;
}

int MarkovModel::freq(string kgram) {
  if (kgram.size() != (unsigned)_order)
    throw std::runtime_error("kgram is not size k");

  if (_order == 0)
    return initial.size();
  else
    return kgrams[kgram];
}

int MarkovModel::freq(string kgram, char c) {
  if (kgram.size() != (unsigned)_order)
    throw std::runtime_error("kgram is not size k");

  if (_order == 0) {
    int count = 0;
    for (unsigned i = 0; i < initial.size(); i++)
      if (initial[i] == c)
        count++;
    return count;
  } else {
    return kgrams[kgram + c];
  }

  return 0;
}

char MarkovModel::randk(string kgram) {
  if (kgram.size() != (unsigned)_order || kgrams.end() == kgrams.find(kgram))
    throw std::runtime_error("Error: randk kgram not valid");

  string temp;
  for (unsigned i = 0; i < alphabet.size(); i++)
    for (int j = 0; j < kgrams[kgram + alphabet[i]]; j++)
      temp.push_back(alphabet[i]);

  return temp[rand() % temp.size()];
}

string MarkovModel::gen(string kgram, int T) {
  string temp = kgram;
  string ret = kgram;
  char rc;

  for (int i = 0; i < T - _order; i++) {
    rc = randk(temp);
    ret.push_back(rc);
    temp.erase(temp.begin());
    temp.push_back(rc);
  }

  return ret;
}

std::ostream& operator<<(std::ostream& os, MarkovModel& mm) {
  os << "\n" << "Original string is \"" << mm.initial << "\"" << std::endl;
  os << "Order is " << mm._order << std::endl;
  os << "Alphabet is \"" << mm.alphabet << "\"" << "\n" << std::endl;

  os << "MarkovModel Map" << std::endl;
  std::map <string, int> temp = mm.kgrams;
  for (std::map<string, int>::iterator it = temp.begin();
       it != temp.end(); ++it) {
    os << it->first << " " << it->second << " => ";
    for (unsigned i = 0; i < mm.alphabet.size(); i++) {
      it++;
      os << it->first << " " << it->second << " ";
    }

    os << std::endl;
  }

  return os;
}
