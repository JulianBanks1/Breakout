#pragma once
#include <SFML/Graphics.hpp>
#include "Ball.h"

#include "Eye.h"

class Brick {
public:
    Brick(float x, float y, float width, float height, Ball* ball, sf::RenderTexture* renderTex);
    void render(sf::RenderWindow& window, sf::RenderTexture* renderTex);
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape _shape;
    bool _isDestroyed;
    Ball* _ball;
    Eye* _eye;
};