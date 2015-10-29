#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstring>
#include "Body.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace std;

int main(int argc, char* argv[]) {

  int windowSize = 500;
  double G = 6.67e-11;   // Gravitational Constant
  double universeSize;
  string input;
  int n;
  
  if(argc < 3) {
    cout << "Missing command line args" << endl;
    return 1;
  } else if(argc > 3) {
    cout << "Too many command line args" << endl;
    return 1;
  }

  // Prepare time variables
  double timeTotal = atof(argv[1]);
  double timeStep = atof(argv[2]);
  double timeElapsed = 0.0;

  // Prepare the time text
  sf::Font courier_new;
  courier_new.loadFromFile("cour.ttf");

  sf::Text timeText("0.0", courier_new);

  // Prepare the image background
  sf::Image backgroundI;
  backgroundI.loadFromFile("starfield.jpg");

  sf::Texture backgroundT;
  backgroundT.loadFromImage(backgroundI);
  
  sf::Sprite backgroundP(backgroundT);

  // Get number of planets to read
  getline(cin, input);
  n = (atoi(input.c_str()));

  // Get size of the universe
  getline(cin, input);
  universeSize = (atof(input.c_str()));

  // Create a template Body
  Body temp(windowSize, universeSize);

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
    
    // Vector of Force, initialized to 0
    vector<double> forceX;
    vector<double> forceY;
    
    for(int i = 0; i < n; i++) {
      forceX.push_back(0.0);
      forceY.push_back(0.0);
    }
    
    // Calculate Acceleration
    for(unsigned i = 0; i < universe.size(); i++)
      for(unsigned j = 0; j < universe.size(); j++) {
	if(i == j) {
	  forceX[i] += 0;
	  forceY[i] += 0;
	}
	else {
	  double deltaX = universe[j].getxPos() - universe[i].getxPos();
	  double deltaY = universe[j].getyPos() - universe[i].getyPos();
	  double r = sqrt(deltaX * deltaX + deltaY * deltaY);
	  double F = (G * universe[i].getMass() * universe[j].getMass()) / (r * r);
	  double Fx = F * (deltaX / r);
	  double Fy = F * (deltaY / r);
	  forceX[i] += Fx;
	  forceY[i] += Fy; 
	}
      }
    
    // Calculate New Velocity
    for(unsigned i = 0; i < universe.size(); i++) {
      double Ax = forceX[i] / universe[i].getMass();
      double Ay = forceY[i] / universe[i].getMass();
      
      universe[i].updateXVel(timeStep * Ax);
      universe[i].updateYVel(timeStep * Ay);
      
      // Update position
      universe[i].step(timeStep);
    }
    
    window.clear();
    
    window.draw(backgroundP);

    // Draw each body in the vector
    for(unsigned i = 0; i < universe.size(); i++)
      window.draw(universe[i]);

    // Update Time, close if max is reached
    timeElapsed += timeStep;
    if(timeElapsed > timeTotal) 
      window.close();

    // Update timeText
    stringstream ss;
    ss << timeElapsed;
    timeText.setString(ss.str());

    // Draw Current Time
    window.draw(timeText);
    
    window.display();
  } 

  for(unsigned i = 0; i < universe.size(); i++)
    cout << universe[i] << endl;
}
