#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "Body.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

int main(int argc, char* argv[]) {

  int windowSize = 500;
  double universeSize;
  string input;
  int n;

  // Get number of planets to read
  getline(cin, input);
  n = (atoi(input.c_str()));

  // Get size of the universe
  getline(cin, input);
  universeSize = (atof(input.c_str()));
  
  // Create a template Body
  Body temp;
  temp.setWindowSize(windowSize);
  temp.setUniverseSize(universeSize);

  // Fill the universe with 'n' bodies
  vector<Body> universe;
  for(int i = 0; i < n; i++)
    universe.push_back(temp);

  // Read in member variables to corresponding bodies
  for(int i = 0; i < n; i++) {
    getline(cin, input);
    istringstream iss(input);
    iss >> universe[i];
  }

  sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "Universe");
  
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window.close();
    }
    
    window.clear();

    // Draw each body in the vector
    for(unsigned i = 0; i < universe.size(); i++)
      window.draw(universe[i]);

    window.display();
  }
}
