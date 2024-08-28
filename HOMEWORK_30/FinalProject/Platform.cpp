#include "Platform.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

Platform::Platform() : x(0), y(0), hit(false) {}
Platform::~Platform() = default;

bool Platform::wasHit() const { return hit; }
void Platform::setWasHit(bool value) { hit = value; }

bool Platform::checkOverlap(const std::shared_ptr<Platform>& newPlatform, const std::vector<std::shared_ptr<Platform>>& existingPlatforms) 
{
    sf::FloatRect newBounds(newPlatform->x, newPlatform->y,
        newPlatform->sprite.getGlobalBounds().width,
        newPlatform->sprite.getGlobalBounds().height);

    for (const auto& platform : existingPlatforms) 
    {
        if (platform) 
        {
            sf::FloatRect existingBounds(platform->x, platform->y,
                platform->sprite.getGlobalBounds().width,
                platform->sprite.getGlobalBounds().height);

            if (newBounds.intersects(existingBounds)) 
            {
                return true;
            }
        }
    }
    return false;
}

bool RegularPlatform::isBrokenPlatform() const { return false; }
bool RegularPlatform::isFalling() const { return false; }
void RegularPlatform::startFalling() {}

BrokenPlatform::BrokenPlatform() : falling(false) {}
bool BrokenPlatform::isBrokenPlatform() const { return true; }
bool BrokenPlatform::isFalling() const { return falling; }
void BrokenPlatform::startFalling() { falling = true; }

MovingPlatform::MovingPlatform(float speed) : speed(speed), direction(1) {}

bool MovingPlatform::isBrokenPlatform() const 
{
    return false;
}

bool MovingPlatform::isFalling() const 
{
    return false;
}

void MovingPlatform::startFalling() {}

void MovingPlatform::update(float windowWidth) 
{
    x += speed * direction;
    if (x <= 0 || x >= windowWidth - sprite.getGlobalBounds().width)
    {
        direction *= -1;
    }
    sprite.setPosition(x, y);
}
