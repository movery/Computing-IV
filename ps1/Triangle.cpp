#include "Triangle.hpp"

using namespace sf;

Triangle::Triangle(const Vector2f& xy1, const Vector2f& xy2, const Vector2f& xy3) {
  _vertices = VertexArray(sf::Triangles, 3);
  _vertices[0].position = xy1;
  _vertices[1].position = xy2;
  _vertices[2].position = xy3;
}

void Triangle::setColorBlack() {
  _vertices[0].color = Color::Black;
  _vertices[1].color = Color::Black;
  _vertices[2].color = Color::Black;
}

void Triangle::draw(RenderTarget& target, RenderStates states) const {
  target.draw(_vertices);
}

