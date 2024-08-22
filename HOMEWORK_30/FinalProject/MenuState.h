#pragma once
#include <SFML/Graphics.hpp>

class MenuState 
{
public:
    MenuState(sf::RenderWindow& window);
    void handleEvents();
    void render();
    void reset();
    bool isStartButtonClicked() const;
    bool isExitButtonClicked() const;

private:
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Texture startButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Sprite background;
    sf::Sprite startButton;
    sf::Sprite exitButton;
    bool startButtonClicked;
    bool exitButtonClicked;
};

