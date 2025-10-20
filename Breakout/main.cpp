#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <iostream> 

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Breakout");
    sf::RenderTexture renderTex;
    renderTex.create(window.getSize().x, window.getSize().y);

    sf::Shader screenShader;
    if (!screenShader.loadFromFile("Shader.frag", sf::Shader::Fragment)) { return -1; }
    screenShader.setUniform("resolution", sf::Glsl::Vec2(window.getSize()));

    GameManager gameManager(&window, &renderTex);
    gameManager.initialize();


    sf::Clock clock;
    float deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();

        gameManager.update(deltaTime);

        renderTex.clear();
        gameManager.render();
        renderTex.display();

        window.clear();
        sf::Sprite screenSprite(renderTex.getTexture());
        window.draw(screenSprite, &screenShader);
        gameManager.renderUI();
        window.display();
    }

    return 0;
}
