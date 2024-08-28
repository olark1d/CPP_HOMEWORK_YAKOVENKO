#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include "GameObject.h"

void updateBoundaries(sf::RenderWindow& window, Player& player)
{
    sf::FloatRect newBoundaries(0, 0, window.getSize().x, window.getSize().y);
    player.setBoundaries(newBoundaries);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Lecture25, SFML INTRO");

    sf::Font defaultGameFont;
    defaultGameFont.loadFromFile("arial.ttf");

    sf::Text myText;
    myText.setFont(defaultGameFont);
    myText.setString("HELLO WORLD");
    myText.setCharacterSize(48);
    myText.setFillColor(sf::Color::Blue);

    Player player("steve.png");

    updateBoundaries(window, player);

    sf::Clock worldClock;

    while (window.isOpen())
    {
        const float deltaTime = worldClock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                updateBoundaries(window, player);
                break;
            }
        }

        // UPDATE STEP
        player.update(deltaTime);

        // DRAW STEP
        window.clear(sf::Color{ 0, 255, 0 });
        player.draw(&window);
        window.draw(myText);
        window.display();
    }

    return 0;
}
