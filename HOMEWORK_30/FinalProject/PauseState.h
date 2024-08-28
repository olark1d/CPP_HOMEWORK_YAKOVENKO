#pragma once
#include <SFML/Graphics.hpp>

class PauseState 
{
public:
    PauseState(sf::RenderWindow& window);
    void handleEvents();
    void render();
    void reset();
    bool isResumeButtonClicked() const;
    bool isExitButtonClicked() const;

private:
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Texture resumeButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Sprite background;
    sf::Sprite resumeButton;
    sf::Sprite exitButton;
    bool resumeButtonClicked;
    bool exitButtonClicked;
};
