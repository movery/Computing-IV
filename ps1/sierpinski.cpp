#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Triangle.hpp"

// Draws the initial triangle where the sub-triangles will be drawn
void drawInitTriangle(int depth, int height, sf::RenderWindow &window);

// Recursively calls itself to draw triangles until a certain depth is reached
void drawSubTriangles(int n, int depth, sf::Vector2f xy1, sf::Vector2f xy2, sf::Vector2f xy3, sf::RenderWindow &window);

int main(int argc, char *argv[]) {
  
  int depth = atoi(argv[1]);
  int height = atoi(argv[2]);

  // Create the window
  sf::RenderWindow window(sf::VideoMode(height, height), "Sierpinski's Triangle");
  
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window.close();
    }

    drawInitTriangle(depth, height, window);
    
    window.display();
  }

  return 0;
}

void drawInitTriangle(int depth, int height, sf::RenderWindow &window) {
  
  sf::Vector2f xy1(height / 2, 0);
  sf::Vector2f xy2(0, height);
  sf::Vector2f xy3(height, height);

  Triangle triangle(xy1, xy2, xy3);
  window.draw(triangle);

  drawSubTriangles(1, depth,
		   sf::Vector2f((xy1.x + xy2.x) / 2, (xy1.y + xy2.y) / 2),
		   sf::Vector2f((xy1.x + xy3.x) / 2, (xy1.y + xy3.y) / 2),
		   sf::Vector2f((xy2.x + xy3.x) / 2, (xy2.y + xy3.y) / 2),
		   window);
		   
}

void drawSubTriangles(int n, int depth, sf::Vector2f xy1, sf::Vector2f xy2, sf::Vector2f xy3, sf::RenderWindow &window) {

  Triangle triangle(xy1, xy2, xy3);
  triangle.setColorBlack();
  window.draw(triangle);

  if(n < depth) {
    drawSubTriangles(n + 1, depth, 
		     sf::Vector2f((xy1.x + xy2.x) / 2 + (xy2.x - xy3.x) / 2, 
		      (xy1.y + xy2.y) / 2 + (xy2.y - xy3.y) / 2),
		     sf::Vector2f((xy1.x + xy2.x) / 2 + (xy1.x - xy3.x) / 2,
		      (xy1.y + xy2.y) / 2 + (xy1.y - xy3.y) / 2),
		     sf::Vector2f((xy1.x + xy2.x) / 2, (xy1.y + xy2.y) / 2),
		     window);

    drawSubTriangles(n + 1, depth, 
		     sf::Vector2f((xy3.x + xy2.x) / 2 + (xy2.x - xy1.x) / 2,
		      (xy3.y + xy2.y) / 2 + (xy2.y - xy1.y) / 2),
		     sf::Vector2f((xy3.x + xy2.x) / 2 + (xy3.x - xy1.x) / 2,
		      (xy3.y + xy2.y) / 2 + (xy3.y - xy1.y) / 2),
		     sf::Vector2f((xy3.x + xy2.x) / 2, (xy3.y + xy2.y) / 2),
		     window);

    drawSubTriangles(n + 1, depth, 
		     sf::Vector2f((xy1.x + xy3.x) / 2 + (xy3.x - xy2.x) / 2,
		      (xy1.y + xy3.y) / 2 + (xy3.y - xy2.y) / 2),
		     sf::Vector2f((xy1.x + xy3.x) / 2 + (xy1.x - xy2.x) / 2,
		      (xy1.y + xy3.y) / 2 + (xy1.y - xy2.y) / 2),
		     sf::Vector2f((xy1.x + xy3.x) / 2, (xy1.y + xy3.y) / 2), 
		     window);
  }
}
