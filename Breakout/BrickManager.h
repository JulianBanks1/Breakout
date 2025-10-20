#pragma once
#include <vector>
#include "Brick.h"
#include <SFML/Graphics.hpp>

class GameManager;

class BrickManager {
public:
    BrickManager(sf::RenderWindow* window, GameManager* gameManager, sf::RenderTexture* renderTex, Ball* ball);
    void createBricks(int rows, int cols, float brickWidth, float brickHeight, float spacing);
    void render();
    int checkCollision(sf::CircleShape& ball, sf::Vector2f& direction);

private:
    std::vector<Brick> _bricks;
    sf::RenderWindow* _window;
    sf::RenderTexture* _renderTex;
    Ball* _ball;

    GameManager* _gameManager;
    static constexpr float TOP_PADDING = 100.0f;
};
