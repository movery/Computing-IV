#ifndef _BODY_HPP
#define _BODY_HPP

#include <iostream>
#include <cstring>
#include <SFML/Graphics.hpp>

class Body : public sf::Drawable {
private:
  double xpos, ypos;
  double xvel, yvel;
  double mass;
  double universeSize;
  int windowSize;
  sf::Sprite sprite;
  sf::Texture texture;
public:
  Body();
  Body(double _universeSize, int _windowSize);
  Body(double _xpos, double _ypos, double _xvel, double _yvel, double _mass, std::string _fname);
  ~Body();
  void setWindowSize(int _size);
  void setUniverseSize(double _size);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  friend std::istream &operator>>(std::istream &input, Body &arg);
};

#endif
