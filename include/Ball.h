#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius, float speed);
    void update(sf::RenderWindow &window, sf::RectangleShape &paddle, std::vector<sf::RectangleShape> &bricks);
    void draw(sf::RenderWindow &window);

private:
    sf::CircleShape ball;
    sf::Vector2f velocity;
};

#endif // BALL_H
