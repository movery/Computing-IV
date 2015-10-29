#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <SFML/Graphics.hpp>

class Triangle : public sf::Drawable {
private:
  sf::VertexArray _vertices;
public:
  Triangle(const sf::Vector2f& xy1, const sf::Vector2f& xy2, const sf::Vector2f& xy3);
  void setColorBlack();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
