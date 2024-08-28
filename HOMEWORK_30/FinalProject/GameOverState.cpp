#include "GameOverState.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameOverState::GameOverState(sf::RenderWindow& window)
    : window(window), restartButtonClicked(false), exitButtonClicked(false) 
{
    if (!backgroundTexture.loadFromFile("game_over_background.png") ||
        !restartButtonTexture.loadFromFile("restart_button.png") ||
        !exitButtonTexture.loadFromFile("exit_button.png") ||
        !font.loadFromFile("arial.ttf")) {
        std::cerr << "Error loading textures or font" << std::endl;
        exit(-1);
    }

    background.setTexture(backgroundTexture);
    background.setScale(window.getSize().x / static_cast<float>(backgroundTexture.getSize().x),
        window.getSize().y / static_cast<float>(backgroundTexture.getSize().y));

    restartButton.setTexture(restartButtonTexture);
    restartButton.setScale(window.getSize().x * 0.2f / restartButtonTexture.getSize().x,
        window.getSize().y * 0.1f / restartButtonTexture.getSize().y);
    restartButton.setPosition(window.getSize().x / 2 - restartButton.getGlobalBounds().width / 2,
        window.getSize().y / 2 - restartButton.getGlobalBounds().height / 2);

    exitButton.setTexture(exitButtonTexture);
    exitButton.setScale(window.getSize().x * 0.2f / exitButtonTexture.getSize().x,
        window.getSize().y * 0.1f / exitButtonTexture.getSize().y);
    exitButton.setPosition(window.getSize().x / 2 - exitButton.getGlobalBounds().width / 2,
        window.getSize().y / 2 + restartButton.getGlobalBounds().height);

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 3);
}

void GameOverState::handleEvents() 
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

                if (restartButton.getGlobalBounds().contains(mousePosF)) 
                {
                    restartButtonClicked = true;
                }
                if (exitButton.getGlobalBounds().contains(mousePosF))
                {
                    exitButtonClicked = true;

                }
            }
        }
    }
}

void GameOverState::render() 
{
    window.draw(background);
    window.draw(restartButton);
    window.draw(exitButton);
    window.draw(scoreText);
}

void GameOverState::reset() 
{
    restartButtonClicked = false;
    exitButtonClicked = false;
}

bool GameOverState::isRestartButtonClicked() const { return restartButtonClicked; }
bool GameOverState::isExitButtonClicked() const { return exitButtonClicked; }

void GameOverState::setScore(int score) 
{
    scoreText.setString("Score: " + std::to_string(score));
}
