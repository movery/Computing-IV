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
  std::string fname;
  sf::Sprite sprite;
  sf::Texture texture;
public:
  Body();
  Body(int _windowSize, double _universeSize);
  ~Body();
  void setWindowSize(int _size);
  void setUniverseSize(double _size);
  double getxPos();
  double getyPos();
  double getMass();
  void updateXVel(double AxT);
  void updateYVel(double AxT);
  void step(double time);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  friend std::istream &operator>>(std::istream &input, Body &arg);
  friend std::ostream &operator<<(std::ostream &output, Body &arg);
};

#endif
