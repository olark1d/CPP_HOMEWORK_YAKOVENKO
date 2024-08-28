#include "GameObject.h"

GameObject::GameObject(const char* textureFileName)
{
    m_texture.loadFromFile(textureFileName);
    m_sprite.setTexture(m_texture);

    updateSpriteOrigin();
}

void GameObject::updateSpriteOrigin()
{
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    m_sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void GameObject::setTexture(const sf::Texture& texture)
{
    m_texture = texture;
    m_sprite.setTexture(m_texture);
    updateSpriteOrigin();
}

void Player::update(float dt)
{
    handleMovement(dt);
    handleScale(dt);
    handleRotation(dt);

    applyVelocity(dt);
    constrainToBoundaries();
}

void Player::handleScale(float dt)
{
    const float ScaleSpeed = 0.02f;

    float Scale = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        Scale = ScaleSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        Scale = -ScaleSpeed;
    }

    sf::Vector2f scale = m_sprite.getScale();
    scale.x += Scale;
    scale.y += Scale;
    m_sprite.setScale(scale);

    updateSpriteOrigin();
}

void Player::handleRotation(float dt)
{
    const float RotationSpeed = 1;  //0 - 360

    float DeltaRotation = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        DeltaRotation = RotationSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        DeltaRotation = -RotationSpeed;
    }

    m_sprite.setRotation(m_sprite.getRotation() + DeltaRotation);
}

void Player::handleMovement(float dt)
{
    const float Speed = 500.0f * dt;
    float DeltaX = 0.0f;
    float DeltaY = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        DeltaY = -Speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        DeltaY = Speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        DeltaX = Speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        DeltaX = -Speed;
    }

    sf::Vector2f position = m_sprite.getPosition();
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    sf::Vector2f newPosition = position + sf::Vector2f(DeltaX, DeltaY);

    if (newPosition.x - bounds.width / 2.0f < m_boundaries.left)
    {
        newPosition.x = m_boundaries.left + bounds.width / 2.0f;
    }
    else if (newPosition.x + bounds.width / 2.0f > m_boundaries.left + m_boundaries.width)
    {
        newPosition.x = m_boundaries.left + m_boundaries.width - bounds.width / 2.0f;
    }

    if (newPosition.y - bounds.height / 2.0f < m_boundaries.top)
    {
        newPosition.y = m_boundaries.top + bounds.height / 2.0f;
    }
    else if (newPosition.y + bounds.height / 2.0f > m_boundaries.top + m_boundaries.height)
    {
        newPosition.y = m_boundaries.top + m_boundaries.height - bounds.height / 2.0f;
    }


    m_sprite.setPosition(newPosition);
}

void Player::applyVelocity(float dt)
{
    const sf::Vector2f displacement{ m_velocity.x * dt, m_velocity.y * dt };
    m_sprite.setPosition(m_sprite.getPosition() + displacement);
}

void Player::constrainToBoundaries()
{
    sf::FloatRect playerBounds = m_sprite.getGlobalBounds();

    sf::Vector2f position = m_sprite.getPosition();

    if (playerBounds.left < m_boundaries.left)
    {
        position.x = m_boundaries.left + playerBounds.width / 2;
    }
    else if (playerBounds.left + playerBounds.width > m_boundaries.left + m_boundaries.width)
    {
        position.x = m_boundaries.left + m_boundaries.width - playerBounds.width / 2;
    }

    if (playerBounds.top < m_boundaries.top)
    {
        position.y = m_boundaries.top + playerBounds.height / 2;
    }
    else if (playerBounds.top + playerBounds.height > m_boundaries.top + m_boundaries.height)
    {
        position.y = m_boundaries.top + m_boundaries.height - playerBounds.height / 2;
    }

    m_sprite.setPosition(position);
}


