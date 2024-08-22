#pragma once
#include <SFML/Graphics.hpp>

class GameOverState 
{
public:
    GameOverState(sf::RenderWindow& window);
    void handleEvents();
    void render();
    void reset();
    bool isRestartButtonClicked() const;
    bool isExitButtonClicked() const;
    void setScore(int score);

private:
    sf::RenderWindow& window;
    sf::Texture backgroundTexture;
    sf::Texture restartButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Sprite background;
    sf::Sprite restartButton;
    sf::Sprite exitButton;
    sf::Font font;
    sf::Text scoreText;
    bool restartButtonClicked;
    bool exitButtonClicked;
};
