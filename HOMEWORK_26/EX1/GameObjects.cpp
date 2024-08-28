#include "GameObjects.h"
#include "Component.h"
#include "Map.h"
#include "GameWorld.h"
#include "AIMoveBestRouteComponent.h"

//Enable if needed
//#define NPC_DEBUG_POSITION

GameObject::GameObject(const char* textureFileName)
{
	//#TODO, Bohdan: There must be as little texture loaded as possible
	//So GameObject should reuse the same texture but not load it 
	//several times

	m_texture.loadFromFile(textureFileName);
	m_sprite.setTexture(m_texture);
}

void GameObject::update(float deltaTime)
{
	for (Component* component : m_components)
	{
		component->update(deltaTime);
	}
}

void GameObject::draw(sf::RenderWindow* window)
{
	window->draw(m_sprite);

	for (Component* component : m_components)
	{
		component->draw(window);
	}
}

//Let's consider for now EVERY GameObject have Position and ONE Sprite
//It may change in future, for example we will need GameObject without physical/visual body represantation
//or with several sprites combined
void GameObject::setPosition(const sf::Vector2f& position)
{
	m_sprite.setPosition(position);
}

sf::Vector2f GameObject::getPosition() const
{
	return m_sprite.getPosition();
}

//#TODO, Bohdan: Make it a RestrictByMapComponent so there're objects that are restricted and not by Map Tiles
void GameObject::updatePosition(const sf::Vector2f& deltaPosition)
{
	sf::Vector2f position = getPosition();
	if (!Map::GetInstance().isTileBlocked({ position.x + deltaPosition.x, position.y }))
	{
		position.x += deltaPosition.x;
	}

	if (!Map::GetInstance().isTileBlocked({ position.x, position.y + deltaPosition.y }))
	{
		position.y += deltaPosition.y;
	}

	setPosition(position);
}

sf::Vector2f GameObject::getSize() const
{
	return m_sprite.getLocalBounds().getSize();
}

sf::Sprite* GameObject::getSprite()
{
	return &m_sprite;
}


NPC::NPC(const char* filename, NPC_Behavior behavior)
	: GameObject(filename), m_behavior(behavior)
{
	m_sprite.setOrigin(m_sprite.getGlobalBounds().getSize().x / 2,
		m_sprite.getGlobalBounds().getSize().y / 2);

	setPosition(Map::GetInstance().getRandomValidPosition());
}


void NPC::PostInit()
{
#ifdef NPC_DEBUG_POSITION
	m_components.push_back(new ShowObjectOriginComponent(this));
#endif 

	if (m_behavior == NPC_Behavior::AI_StraightLine)
	{
		m_components.push_back(new AIMoveStraightLineComponent(this, &GameWorld::Instance()->GetPlayer()));
	}
	else if (m_behavior == NPC_Behavior::AI_BestRoute)
	{
		m_components.push_back(new AIMoveBestRouteComponent(this, &GameWorld::Instance()->GetPlayer()));
	}
}

void NPC::update(float deltaTime)
{
	GameObject::update(deltaTime);

	if (m_behavior == NPC_Behavior::Floating)
	{
		if (m_floatClock.getElapsedTime().asSeconds() > 1)
		{
			m_floatDirection.x = std::rand() % 3 - 1;   //-1 0 1
			m_floatDirection.y = std::rand() % 3 - 1;   //-1 0 1

			m_floatClock.restart();
		}
		floatTo(m_floatDirection, deltaTime);

	}
	else if (m_behavior == NPC_Behavior::RandomSnap)
	{
		//update NPC position every second
		if (m_randomClock.getElapsedTime().asSeconds() > 1)
		{
			setRandomPosition({ static_cast<sf::Uint32>(WindowHelper::Instance().GetRenderWindow().getSize().x)
				, static_cast<sf::Uint32>(WindowHelper::Instance().GetRenderWindow().getSize().y) });

			setPosition(Map::GetInstance().getRandomValidPosition());

			m_randomClock.restart();
		}
	}
	else if (m_behavior == NPC_Behavior::Static) {}
}

void NPC::floatTo(const sf::Vector2f& direction, float deltaTime)
{
	const float MoveDelta = 200.0f * deltaTime;
	updatePosition({ MoveDelta * direction.x,  MoveDelta * direction.y });
}

void NPC::setRandomPosition(sf::Vector2u box)
{
	m_sprite.setPosition({ static_cast<float>(std::rand() % (box.x - static_cast<unsigned int>(m_sprite.getGlobalBounds().getSize().x))),
	static_cast<float>(std::rand() % (box.y - static_cast<unsigned int>(m_sprite.getGlobalBounds().getSize().y))) });
}