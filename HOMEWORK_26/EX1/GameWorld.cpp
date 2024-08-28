#include "GameWorld.h"
#include "GameObjects.h"
#include "Map.h"

GameWorld* GameWorld::ms_gameWorld = nullptr;

GameWorld::GameWorld(sf::RenderWindow* window)
{
    //TODO, Bohdan: MAKE IT DATA-DRIVEN

    NPC* npc1 = new NPC("stone.png", NPC_Behavior::Floating); //center of the game window
    NPC* npc2 = new NPC("ball.png", NPC_Behavior::AI_StraightLine); //center of the game window
    NPC* npc3 = new NPC("banana.png", NPC_Behavior::AI_BestRoute); //center of the game window

    m_gameObjects.push_back(&player);
    m_gameObjects.push_back(npc1);
    m_gameObjects.push_back(npc2);
    m_gameObjects.push_back(npc3);

    m_collidableObjects.push_back(npc1);
    m_collidableObjects.push_back(npc2);
    m_collidableObjects.push_back(npc3);
}

void GameWorld::PostInit()
{
    for (auto gameObject : m_gameObjects)
    {
        gameObject->PostInit();
    }
}

GameWorld::~GameWorld()
{
    //TODO, Bohdan: Delete memory used
}

void GameWorld::blur()
{
    m_blurred = true;
}

void GameWorld::unblur()
{
    m_blurred = false;
}

bool checkCollision(const sf::Sprite* sprite1, const sf::Sprite* sprite2)
{
    if (sprite1 && sprite2)
    {
        return sprite1->getGlobalBounds().intersects(sprite2->getGlobalBounds());
    }

    assert(false && "Invalid sprites passed for the collision check");
    return false;
}


void GameWorld::update(float DeltaTime)
{
    //Update all game objects
    for (GameObject* object : m_gameObjects)
    {
        object->update(DeltaTime);
    }

    //Check Collisions
    bool isAnyOfCollided = false;

    for (GameObject* box : m_collidableObjects)
    {
        if (checkCollision(player.getSprite(), box->getSprite()))
        {
            isAnyOfCollided = true;
            box->getSprite()->setColor(sf::Color::Red);
        }
        else
        {
            // This color is modulated (multiplied) with the sprite's texture.
            box->getSprite()->setColor(sf::Color::White);
        }
    }
    m_collisionCounter.update(isAnyOfCollided);
}

void GameWorld::draw(sf::RenderWindow* window)
{
    Map::GetInstance().draw(window);

    for (GameObject* object : m_gameObjects)
    {
        object->draw(window);
    }

    m_collisionCounter.draw(window);

    if (m_blurred)
    {
        window->draw(m_rectangle);
    }
}