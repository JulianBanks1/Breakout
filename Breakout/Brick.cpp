#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, Ball* ball, sf::RenderTexture* renderTex)
    : _isDestroyed(false)
{
    _shape.setPosition(x, y);
    _shape.setSize(sf::Vector2f(width, height));
    _shape.setFillColor(sf::Color::Red);
    _ball = ball;
    _eye = new Eye(8, renderTex, ball);
    int maxX = 25;
    int offsetX = std::rand() % (maxX * 2 + 1);
    offsetX -= maxX;

    int maxY = 5;
    int offsetY = std::rand() % (maxY * 2 + 1);
    offsetY -= maxY;
    _eye->setPos(sf::Vector2f(x - 8 + width * 0.5f + offsetX, y + 8 + offsetY));
}

void Brick::render(sf::RenderWindow& window, sf::RenderTexture* renderTex)
{
    if (!_isDestroyed) {
        //window.draw(_shape);
        renderTex->draw(_shape);
        _eye->render();
    }
}

sf::FloatRect Brick::getBounds() const
{
    return _shape.getGlobalBounds();
}
