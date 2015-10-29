#include "Rectangle.hpp"

using namespace sf;

Rectangle::Rectangle(const Vector2f& xy1, const Vector2f& xy2, const Vector2f& xy3, const Vector2f& xy4) {
  _vertices = ConvexShape(4);
  _vertices.setPoint(0, xy1);
  _vertices.setPoint(1, xy2);
  _vertices.setPoint(2, xy3);
  _vertices.setPoint(3, xy4);
}

void Rectangle::draw(RenderTarget& target, RenderStates states) const {
  target.draw(_vertices);
}
