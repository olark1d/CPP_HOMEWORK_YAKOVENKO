#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(const char* textureFileName);

	virtual void update(float dt) {}
	virtual void draw(sf::RenderWindow* window) { window->draw(m_sprite); }

	void updateSpriteOrigin();
	void setTexture(const sf::Texture& texture);
	void setPosition(const sf::Vector2f& position) { m_sprite.setPosition(position); }
	sf::Vector2f getPosition() const { return m_sprite.getPosition(); }

	sf::FloatRect getBounds() const { return m_sprite.getGlobalBounds(); }

protected:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

class Player : public GameObject
{
public:
	using GameObject::GameObject;

	void update(float dt) override;
	void setBoundaries(const sf::FloatRect& boundaries) { m_boundaries = boundaries; }

private:
	void handleScale(float dt);
	void handleRotation(float dt);
	void handleMovement(float dt);

	void applyVelocity(float dt);

	void constrainToBoundaries();

private:
	sf::Vector2f m_velocity;
	sf::FloatRect m_boundaries;

	sf::Clock m_cooldownTimer;
	float m_cooldownSec = 1.0f;
};
