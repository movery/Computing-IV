#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Rectangle.hpp"

void drawSubRectangle(int n, int depth, sf::Vector2f xy1, sf::Vector2f xy2, sf::Vector2f xy3, sf::Vector2f xy4, sf::RenderWindow& window);

void drawInitRectangle(int depth, int height, sf::RenderWindow& window);

int main(int argc, char *argv[]) {
  
  int depth = atoi(argv[1]);
  int height = atoi(argv[2]);

  // Create the window
  sf::RenderWindow window(sf::VideoMode(height, height), "Staircase");
  
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window.close();
    }

    drawInitRectangle(depth, height, window);
    
    window.display();
  }

  return 0;
}

void drawInitRectangle(int depth, int height, sf::RenderWindow& window) {
  
  sf::Vector2f xy1(0, height * 0.5);
  sf::Vector2f xy2(height * 0.5, height * 0.5);
  sf::Vector2f xy3(height * 0.5, height);
  sf::Vector2f xy4(0, height);

  Rectangle rectangle(xy1, xy2, xy3, xy4);
  window.draw(rectangle);

  drawSubRectangle(1, depth,
		   sf::Vector2f(0, height * .25),
		   sf::Vector2f(height * .25, height * .25),
		   sf::Vector2f(height * .25, height * .5),
		   sf::Vector2f(0, height * .5),
		   window);

  drawSubRectangle(1, depth, 			
		   sf::Vector2f(height * .5, height * .75),
		   sf::Vector2f(height * .75, height * .75),
		   sf::Vector2f(height * .75, height),
		   sf::Vector2f(height * .5, height),
		   window);
}

void drawSubRectangle(int n, int depth, sf::Vector2f xy1, sf::Vector2f xy2, sf::Vector2f xy3, sf::Vector2f xy4, sf::RenderWindow& window) {

  Rectangle rectangle(xy1, xy2, xy3, xy4);
  window.draw(rectangle);

  double sidelength = (xy2.x - xy1.x) / 2;

  if(n < depth) {
    
    drawSubRectangle(n + 1, depth, 
		     sf::Vector2f(xy1.x, xy1.y - sidelength),
		     sf::Vector2f(xy1.x + sidelength, xy1.y - sidelength),
		     sf::Vector2f(xy1.x + sidelength, xy1.y),
		     sf::Vector2f(xy1.x, xy1.y),
		     window);

    drawSubRectangle(n + 1, depth,
		     sf::Vector2f(xy2.x, xy2.y + sidelength),
		     sf::Vector2f(xy2.x + sidelength, xy2.y + sidelength),
		     sf::Vector2f(xy2.x + sidelength, xy3.y),
		     sf::Vector2f(xy2.x, xy3.y),
		     window);
  }

}
