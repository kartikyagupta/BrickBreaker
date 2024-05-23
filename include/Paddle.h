#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(float width, float height, float speed);
    void update(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    sf::RectangleShape& getShape();

private:
    sf::RectangleShape paddle;
    float speed;
};

#endif // PADDLE_H
