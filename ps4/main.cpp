#include <iostream>
#include <cstring>
#include "ED.hpp"

#include <SFML/System.hpp>

using namespace std;

int main() {

  // Get the clock running
  sf::Clock clock;
  sf::Time t;

  // Init string variables and get inpit
  string String1;
  string String2;

  cin >> String1;
  cin >> String2;
  
  // Initialize my class, all math done in constructor and sets relevant
  // member variables/
  ED test(String1, String2);


  // Get what we want from the class
  cout << "Edit distance = " << test.getEditDistance() << endl;
  cout << test.getEditString() << endl;

  t = clock.getElapsedTime();
  //  cout << "Execution time is " << t.asSeconds() << " seconds." << endl;

  return 0;
}
