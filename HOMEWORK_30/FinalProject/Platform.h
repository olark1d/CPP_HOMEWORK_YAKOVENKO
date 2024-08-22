#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Platform 
{
public:
    sf::Sprite sprite;
    float x, y;

    Platform();
    virtual ~Platform();

    virtual bool isBrokenPlatform() const = 0;
    virtual bool isFalling() const = 0;
    virtual void startFalling() = 0;

    bool wasHit() const;
    void setWasHit(bool value);

    static bool checkOverlap(const std::shared_ptr<Platform>& newPlatform, const std::vector<std::shared_ptr<Platform>>& existingPlatforms);

private:
    bool hit;
};

class RegularPlatform : public Platform 
{
public:
    bool isBrokenPlatform() const override;
    bool isFalling() const override;
    void startFalling() override;
};

class BrokenPlatform : public Platform 
{
public:
    BrokenPlatform();
    bool isBrokenPlatform() const override;
    bool isFalling() const override;
    void startFalling() override;

private:
    bool falling;
};

class MovingPlatform : public Platform 
{
public:
    MovingPlatform(float speed);
    bool isBrokenPlatform() const override;
    bool isFalling() const override;
    void startFalling() override;
    void update(float windowWidth);

private:
    float speed;
    int direction;
};
