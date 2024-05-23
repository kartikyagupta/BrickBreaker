#ifndef BRICK_H
#define BRICK_H

#include <SFML/Graphics.hpp>

class Brick {
public:
    Brick(float x, float y, float width, float height);
    void draw(sf::RenderWindow &window);
    sf::RectangleShape& getShape();

private:
    sf::RectangleShape brick;
};

#endif // BRICK_H
