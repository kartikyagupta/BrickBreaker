#include "Paddle.h"

Paddle::Paddle(float width, float height, float speed) : speed(speed) {
    paddle.setSize(sf::Vector2f(width, height));
    paddle.setFillColor(sf::Color::Blue);
    paddle.setPosition(400.f - width / 2.f, 580.f);
}

void Paddle::update(sf::RenderWindow &window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.getPosition().x > 0) {
        paddle.move(-speed, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.getPosition().x < window.getSize().x - paddle.getSize().x) {
        paddle.move(speed, 0.f);
    }
}

void Paddle::draw(sf::RenderWindow &window) {
    window.draw(paddle);
}

sf::RectangleShape& Paddle::getShape() {
    return paddle;
}
