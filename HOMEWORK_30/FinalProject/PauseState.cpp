#include "PauseState.h"
#include <SFML/Graphics.hpp>

PauseState::PauseState(sf::RenderWindow& window)
    : window(window), resumeButtonClicked(false), exitButtonClicked(false) 
{
    if (!backgroundTexture.loadFromFile("pause_background.png") ||
        !resumeButtonTexture.loadFromFile("resume_button.png") ||
        !exitButtonTexture.loadFromFile("exit_button.png")) 
    {
        throw std::runtime_error("Error loading pause textures");
    }

    background.setTexture(backgroundTexture);
    resumeButton.setTexture(resumeButtonTexture);
    exitButton.setTexture(exitButtonTexture);

    background.setScale(window.getSize().x / static_cast<float>(backgroundTexture.getSize().x),
        window.getSize().y / static_cast<float>(backgroundTexture.getSize().y));

    resumeButton.setScale(window.getSize().x * 0.2f / resumeButtonTexture.getSize().x,
        window.getSize().y * 0.1f / resumeButtonTexture.getSize().y);
    resumeButton.setPosition(window.getSize().x / 2.0f - resumeButton.getGlobalBounds().width / 2.0f,
        window.getSize().y / 1.5f - resumeButton.getGlobalBounds().height / 2.0f - 50);

    exitButton.setScale(window.getSize().x * 0.2f / exitButtonTexture.getSize().x,
        window.getSize().y * 0.1f / exitButtonTexture.getSize().y);
    exitButton.setPosition(window.getSize().x / 2.0f - exitButton.getGlobalBounds().width / 2.0f,
        window.getSize().y / 1.5f + exitButton.getGlobalBounds().height / 2.0f + 10);
}

void PauseState::handleEvents() 
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

                if (resumeButton.getGlobalBounds().contains(mousePosF)) 
                {
                    resumeButtonClicked = true;
                }
                if (exitButton.getGlobalBounds().contains(mousePosF)) 
                {
                    exitButtonClicked = true;
                }
            }
        }
    }
}

void PauseState::render() 
{
    window.draw(background);
    window.draw(resumeButton);
    window.draw(exitButton);
}

void PauseState::reset() 
{
    resumeButtonClicked = false;
    exitButtonClicked = false;
}

bool PauseState::isResumeButtonClicked() const { return resumeButtonClicked; }
bool PauseState::isExitButtonClicked() const { return exitButtonClicked; }
