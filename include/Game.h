#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void resetBricks();

    sf::RenderWindow window;
    Ball ball;
    Paddle paddle;
    std::vector<Brick> bricks;
    sf::Font font;
    sf::Text scoreText;
    int score;
};

#endif // GAME_H
