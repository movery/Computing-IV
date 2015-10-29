#include <iostream>
#include <sstream>
#include <iomanip>
#include "Body.hpp"

using namespace std;

Body::Body() {
  xpos = 0;
  ypos = 0;
  xvel = 0;
  yvel = 0;
  mass = 0;
}

Body::Body(int _windowSize, double _universeSize) {
  xpos = 0;
  ypos = 0;
  xvel = 0;
  yvel = 0;
  mass = 0;
  windowSize = _windowSize;
  universeSize = _universeSize;
}

Body::~Body() { }

void Body::setWindowSize(int _size) {
  windowSize = _size;
}

void Body::setUniverseSize(double _size) {
  universeSize = _size;
}

double Body::getxPos() {
  return xpos;
}

double Body::getyPos() {
  return ypos;
}

double Body::getMass() {
  return mass;
}

void Body::updateXVel(double AxT) {
  xvel -= AxT;
}

void Body::updateYVel(double AxT) {
  yvel -= AxT;
}

void Body::step(double time) {
  xpos = xpos - time * xvel;
  ypos = ypos - time * yvel;

}

void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  sf::Sprite sprite_temp = sprite;  
  double ratio = (windowSize / 2) / universeSize;
  double rxpos = xpos * ratio + (windowSize / 2);
  double rypos = ypos * ratio + (windowSize / 2);
  
  sprite_temp.setPosition(rxpos, rypos);
  
  target.draw(sprite_temp);
}

istream &operator>>(istream &input, Body &arg) {
  input >> arg.xpos;
  input >> arg.ypos;
  input >> arg.xvel;
  input >> arg.yvel;
  input >> arg.mass;
  input >> arg.fname;

  arg.texture.loadFromFile(arg.fname);
  arg.sprite.setTexture(arg.texture);

  return input;
}

ostream &operator<<(ostream &output, Body &arg) {
  output << setw(14) << arg.xpos;
  output << setw(14) << arg.ypos;
  output << setw(14) << arg.xvel;
  output << setw(14) << arg.yvel;
  output << setw(14) << arg.mass;
  output << setw(14) << arg.fname;

  return output;
}
