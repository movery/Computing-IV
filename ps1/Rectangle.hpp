#ifndef RECTANGLE_HPP
#define RECTANGE_HPP

#include <SFML/Graphics.hpp>

class Rectangle : public sf::Drawable {
private:
  sf::ConvexShape _vertices;
public:
  Rectangle(const sf::Vector2f& xy1, const sf::Vector2f& xy2, const sf::Vector2f& xy3, const sf::Vector2f& xy4);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
