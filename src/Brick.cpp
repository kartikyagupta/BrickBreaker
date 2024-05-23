#include "Brick.h"

Brick::Brick(float x, float y, float width, float height) {
    brick.setSize(sf::Vector2f(width, height));
    brick.setFillColor(sf::Color::Green);
    brick.setPosition(x, y);
}

void Brick::draw(sf::RenderWindow &window) {
    window.draw(brick);
}

sf::RectangleShape& Brick::getShape() {
    return brick;
}
