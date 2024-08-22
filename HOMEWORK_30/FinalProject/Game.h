#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <memory>
#include "Platform.h"
#include "MenuState.h"
#include "PauseState.h"
#include "GameOverState.h"

const std::string RECORD_FILE = "highscore.txt";

int readHighScore();
void writeHighScore(int highScore);

enum class GameState 
{
    Menu,
    Playing,
    Paused,
    GameOver
};

class Game 
{
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    GameState state;
    MenuState menuState;
    PauseState pauseState;
    GameOverState gameOverState;
    sf::Texture playerTexture;
    sf::Texture platformTexture;
    sf::Texture brokenPlatformTexture;
    sf::Texture movingPlatformTexture;
    sf::Texture backgroundTexture;
    sf::Sprite player;
    sf::Sprite background;
    std::vector<std::shared_ptr<Platform>> platforms;
    sf::Font font;
    sf::Text scoreText;
    sf::Text highScoreText;
    sf::SoundBuffer buttonClickBuffer;
    sf::SoundBuffer gameOverBuffer;
    sf::SoundBuffer collisionBuffer;
    sf::SoundBuffer pauseBuffer;
    sf::SoundBuffer platformBreakBuffer;
    sf::Sound buttonClickSound;
    sf::Sound gameOverSound;
    sf::Sound collisionSound;
    sf::Sound pauseSound;
    sf::Sound platformBreak;

    float lastPlatformY;
    int score;
    int highScore;
    const float minHeightGap;
    const float maxHeightGap;
    float dy;
    const float gravity;
    const float jumpVelocity;
    bool isJumping;
    const float maxHeight;
    bool hasBounced;
    float movingPlatformSpawnProbability;
    bool moveLeft;
    bool moveRight;
    bool hasBouncedOffBottom;

    void initialize();
    void handleEvents();
    void update();
    void render();
    std::shared_ptr<Platform> generatePlatform(float yPos, bool isBroken = false, bool isMoving = false);
    void respawnPlatforms();
    void resetGame();
    void updateHighScore();
};

