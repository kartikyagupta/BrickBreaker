#include "Ball.h"

Ball::Ball(float radius, float speed) {
    ball.setRadius(radius);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(400.f, 300.f);
    velocity = sf::Vector2f(speed, speed);
}

void Ball::update(sf::RenderWindow &window, sf::RectangleShape &paddle, std::vector<sf::RectangleShape> &bricks) {
    sf::Vector2f position = ball.getPosition();

    // Check for window collisions
    if (position.x <= 0 || position.x >= window.getSize().x - ball.getRadius() * 2)
        velocity.x = -velocity.x;
    if (position.y <= 0)
        velocity.y = -velocity.y;
    if (position.y >= window.getSize().y - ball.getRadius() * 2) {
        ball.setPosition(400.f, 300.f); // Reset position
        velocity = sf::Vector2f(velocity.x, -velocity.y);
    }

    // Check for paddle collision
    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
        velocity.y = -velocity.y;

    // Check for brick collisions
    for (auto &brick : bricks) {
        if (ball.getGlobalBounds().intersects(brick.getGlobalBounds())) {
            velocity.y = -velocity.y;
            brick.setPosition(-100, -100); // Move the brick off-screen
        }
    }

    ball.move(velocity);
}

void Ball::draw(sf::RenderWindow &window) {
    window.draw(ball);
}
