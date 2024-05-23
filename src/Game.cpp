#include "Game.h"

Game::Game() :
    window(sf::VideoMode(800, 600), "Brick Breaker Game"),
    ball(10.f, 5.f),
    paddle(100.f, 20.f, 10.f),
    score(0) {

    if (!font.loadFromFile("assets/font/arial.ttf")) {
        // Handle error
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10.f, 10.f);

    resetBricks();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update() {
    paddle.update(window);
    ball.update(window, paddle.getShape(), bricks);

    // Update score
    scoreText.setString("Score: " + std::to_string(score));
}

void Game::render() {
    window.clear();
    paddle.draw(window);
    ball.draw(window);

    for (auto &brick : bricks)
        brick.draw(window);

    window.draw(scoreText);
    window.display();
}

void Game::resetBricks() {
    bricks.clear();
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            bricks.emplace_back(j * 70.f + 10.f, i * 30.f + 50.f, 60.f, 20.f);
        }
    }
}
