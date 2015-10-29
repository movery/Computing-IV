// Copyright Michael Overy 2015

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include "MarkovModel.hpp"

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cout << "Missing command line args" << std::endl;
    return 1;
  } else if (argc > 3) {
    std::cout << "Too many command line args" << std::endl;
    return 1;
  }

  // Gather User Input
  int k = atoi(argv[1]);
  int T = atoi(argv[2]);
  std::string input;
  std::string current;
  while (std::cin >> current) {
    input += " " + current;
    current = "";
  }

  // Create the MarkovModel
  MarkovModel model(input, k);

  // Generate a new string
  std::string temp;
  for (int i = 0; i < k; i++)
    temp.push_back(input[i]);

  std::cout << model.gen(temp, T) << std::endl;
}
