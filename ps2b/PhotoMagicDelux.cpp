#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "LFSR.hpp"


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

typedef union character {
  char char_value;
  struct single_bits{
    unsigned b0 :1;
    unsigned b1 :1;
    unsigned b2 :1;
    unsigned b3 :1;
    unsigned b4 :1;
    unsigned b5 :1;
    unsigned b6 :1;
  } bit;
} character;

int main(int argc, char* argv[]) {

  if(argc < 5) {
    cout << "Not enough command-line arguments." << endl;
    return -1;
  }
  if(argc > 5) { 
    cout << "Too many command-line arguments." << endl;
    return -1;
  } 

  string seed(argv[3]);
  character bits;
  ostringstream oss;

  for(unsigned i = 0; i < seed.length(); i++) {
    bits.char_value = seed[i];
    
    oss << bits.bit.b5?'1':'0';
    oss << bits.bit.b4?'1':'0';
    oss << bits.bit.b3?'1':'0';
    oss << bits.bit.b2?'1':'0';
    oss << bits.bit.b1?'1':'0';
    oss << bits.bit.b0?'1':'0';
  }

  // Initialize LFSR with command-line arguments
  LFSR lfsr(oss.str(), atoi(argv[4]));

  // Initialize images
  sf::Image image_input;
  sf::Image image_output;

  // Load inputted image
  if(!image_input.loadFromFile(argv[1]))
    return -1;
  
  if(!image_output.loadFromFile(argv[1]))
    return -1;

  // Init helper variables
  sf::Color p;  
  sf::Vector2u size = image_output.getSize();

  // Encode the output image
  for(unsigned x = 0; x < size.x; x++)
    for(unsigned y = 0; y < size.y; y++) {
      p = image_output.getPixel(x, y);
      p.r = (p.r ^ lfsr.generate(8));
      p.g = (p.g ^ lfsr.generate(8));
      p.b = (p.b ^ lfsr.generate(8));
      image_output.setPixel(x, y, p);
    }
  
  sf::Texture texture_input;
  sf::Texture texture_output;
  texture_input.loadFromImage(image_input);
  texture_output.loadFromImage(image_output);

  sf::Sprite sprite_input;
  sf::Sprite sprite_output;
  sprite_input.setTexture(texture_input);
  sprite_output.setTexture(texture_output);

  sf::RenderWindow window_input(sf::VideoMode(size.x, size.y), "Input");
  sf::RenderWindow window_output(sf::VideoMode(size.x, size.y), "Output");

  while(window_input.isOpen() && window_output.isOpen()) {
    sf::Event event;
    while(window_input.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window_input.close();
    }
    while (window_output.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
	window_input.close();
    }
    
    window_input.clear(sf::Color::White);
    window_output.clear(sf::Color::White);

    window_input.draw(sprite_input);
    window_output.draw(sprite_output);

    window_input.display();
    window_output.display();
  }
  
  if(!image_output.saveToFile(argv[2]))
    return -1;
  
  return 0;
}
