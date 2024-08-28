#include "MenuState.h"
#include <SFML/Graphics.hpp>

MenuState::MenuState(sf::RenderWindow& window)
    : window(window), startButtonClicked(false), exitButtonClicked(false) 
{
    if (!backgroundTexture.loadFromFile("menu_background.png") ||
        !startButtonTexture.loadFromFile("start_button.png") ||
        !exitButtonTexture.loadFromFile("exit_button.png")) {
        throw std::runtime_error("Error loading menu textures");
    }

    background.setTexture(backgroundTexture);
    startButton.setTexture(startButtonTexture);
    exitButton.setTexture(exitButtonTexture);

    background.setScale(window.getSize().x / static_cast<float>(backgroundTexture.getSize().x),
        window.getSize().y / static_cast<float>(backgroundTexture.getSize().y));

    startButton.setScale(window.getSize().x * 0.2f / startButtonTexture.getSize().x,
        window.getSize().y * 0.1f / startButtonTexture.getSize().y);
    startButton.setPosition(window.getSize().x / 2.0f - startButton.getGlobalBounds().width / 2.0f,
        window.getSize().y / 2.0f - startButton.getGlobalBounds().height / 2.0f - 50);

    exitButton.setScale(window.getSize().x * 0.2f / exitButtonTexture.getSize().x,
        window.getSize().y * 0.1f / exitButtonTexture.getSize().y);
    exitButton.setPosition(window.getSize().x / 2.0f - exitButton.getGlobalBounds().width / 2.0f,
        window.getSize().y / 2.0f + exitButton.getGlobalBounds().height / 2.0f + 10);
}

void MenuState::handleEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) 
        {
            if (event.mouseButton.button == sf::Mouse::Left) 
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);

                if (startButton.getGlobalBounds().contains(mousePosF)) 
                {
                    startButtonClicked = true;
                }
                if (exitButton.getGlobalBounds().contains(mousePosF)) 
                {
                    exitButtonClicked = true;
                }
            }
        }
    }
}

void MenuState::render() 
{
    window.draw(background);
    window.draw(startButton);
    window.draw(exitButton);
}

void MenuState::reset() 
{
    startButtonClicked = false;
    exitButtonClicked = false;
}

bool MenuState::isStartButtonClicked() const { return startButtonClicked; }
bool MenuState::isExitButtonClicked() const { return exitButtonClicked; }
