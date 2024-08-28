#include "Game.h"
#include <fstream>
#include <cstdlib>
#include <iostream>

int readHighScore() 
{
    int highScore = 0;
    std::ifstream file(RECORD_FILE);
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}

void writeHighScore(int highScore) 
{
    std::ofstream file(RECORD_FILE);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}

Game::Game()
    : window(sf::VideoMode(720, 920), "Doodle Jump", sf::Style::Default, sf::ContextSettings{ 8 }),
    state(GameState::Menu),
    menuState(window),
    pauseState(window),
    gameOverState(window),
    minHeightGap(window.getSize().y * 0.08f),
    maxHeightGap(window.getSize().y * 0.1f),
    dy(0),
    gravity(0.25f),
    jumpVelocity(-12),
    isJumping(false),
    maxHeight(window.getSize().y * 0.4f),
    hasBounced(false),
    score(0),
    movingPlatformSpawnProbability(0.1f),
    highScore(readHighScore()) 
{
    initialize();
}

void Game::initialize() 
{
    window.setFramerateLimit(60);

    if (!playerTexture.loadFromFile("doodle.png") ||
        !platformTexture.loadFromFile("platform.png") ||
        !brokenPlatformTexture.loadFromFile("broken_platform.png") ||
        !movingPlatformTexture.loadFromFile("moving_platform.png") ||
        !backgroundTexture.loadFromFile("background.png") ||
        !font.loadFromFile("arial.ttf") ||
        !buttonClickBuffer.loadFromFile("button_click.wav") ||
        !gameOverBuffer.loadFromFile("game_over.mp3") ||
        !collisionBuffer.loadFromFile("collision.mp3") ||
        !pauseBuffer.loadFromFile("pause.mp3") ||
        !platformBreakBuffer.loadFromFile("break.wav")) {
        std::cerr << "Error loading resources" << std::endl;
        exit(-1);
    }

    buttonClickSound.setBuffer(buttonClickBuffer);
    gameOverSound.setBuffer(gameOverBuffer);
    collisionSound.setBuffer(collisionBuffer);
    pauseSound.setBuffer(pauseBuffer);
    platformBreak.setBuffer(platformBreakBuffer);

    playerTexture.setSmooth(true);
    platformTexture.setSmooth(true);
    brokenPlatformTexture.setSmooth(true);
    movingPlatformTexture.setSmooth(true);
    backgroundTexture.setSmooth(true);

    player.setTexture(playerTexture);
    player.setScale(window.getSize().x * 0.1f / playerTexture.getSize().x,
        window.getSize().y * 0.1f / playerTexture.getSize().y);
    player.setPosition(window.getSize().x / 2.0f - player.getGlobalBounds().width / 2.0f,
        window.getSize().y - player.getGlobalBounds().height - 10);

    background.setTexture(backgroundTexture);
    background.setScale(window.getSize().x / static_cast<float>(backgroundTexture.getSize().x),
        window.getSize().y / static_cast<float>(backgroundTexture.getSize().y));

    score = 0;
    lastPlatformY = window.getSize().y;

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 40);

    highScoreText.setFont(font);
    highScoreText.setCharacterSize(24);
    highScoreText.setFillColor(sf::Color::Black);
    highScoreText.setPosition(10, 10);

    respawnPlatforms();
}

void Game::resetGame() 
{
    state = GameState::Menu;
    menuState.reset();
    pauseState.reset();
    gameOverState.reset();
    initialize();
}

void Game::updateHighScore() 
{
    if (score > highScore) 
    {
        highScore = score;
        writeHighScore(highScore);
    }
}

void Game::respawnPlatforms() 
{
    platforms.clear();

    float lastY = window.getSize().y - 50;
    while (lastY > 0) 
    {
        std::shared_ptr<Platform> platform = generatePlatform(lastY);
        platforms.push_back(platform);
        lastY -= rand() % static_cast<int>(maxHeightGap - minHeightGap + 1) + minHeightGap;
    }
}

std::shared_ptr<Platform> Game::generatePlatform(float yPos, bool isBroken, bool isMoving) 
{
    std::shared_ptr<Platform> platform;

    if (isBroken) 
    {
        platform = std::make_shared<BrokenPlatform>();
        platform->sprite.setTexture(brokenPlatformTexture);
    }
    else if (isMoving) 
    {
        platform = std::make_shared<MovingPlatform>(rand() % 4 + 2);
        platform->sprite.setTexture(movingPlatformTexture);
    }
    else 
    {
        platform = std::make_shared<RegularPlatform>();
        platform->sprite.setTexture(platformTexture);
    }

    platform->sprite.setScale(window.getSize().x * 0.25f / platform->sprite.getTexture()->getSize().x,
        window.getSize().y * 0.03f / platform->sprite.getTexture()->getSize().y);

    do 
    {
        platform->x = rand() % static_cast<int>(window.getSize().x - platform->sprite.getGlobalBounds().width);
        platform->y = yPos;
    } while (Platform::checkOverlap(platform, platforms));

    platform->sprite.setPosition(platform->x, platform->y);
    return platform;
}

void Game::handleEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }

        if (state == GameState::Menu) 
        {
            menuState.handleEvents();

            if (menuState.isStartButtonClicked()) 
            {
                buttonClickSound.play();
                state = GameState::Playing;
            }
            if (menuState.isExitButtonClicked()) 
            {
                buttonClickSound.play();
                window.close();
            }
        }
        else if (state == GameState::Playing) 
        {
            if (event.type == sf::Event::KeyPressed) 
            {
                if (event.key.code == sf::Keyboard::Escape) 
                {
                    pauseSound.play();
                    state = GameState::Paused;
                }
                else if (event.key.code == sf::Keyboard::Left) 
                {
                    moveLeft = true;
                }
                else if (event.key.code == sf::Keyboard::Right) 
                {
                    moveRight = true;
                }
            }

            if (event.type == sf::Event::KeyReleased) 
            {
                if (event.key.code == sf::Keyboard::Left) 
                {
                    moveLeft = false;
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    moveRight = false;
                }
            }
        }
        else if (state == GameState::Paused) 
        {
            pauseState.handleEvents();

            if (pauseState.isResumeButtonClicked()) 
            {
                buttonClickSound.play();
                state = GameState::Playing;
                pauseState.reset();
            }
            if (pauseState.isExitButtonClicked()) 
            {
                buttonClickSound.play();
                window.close();
            }
        }
        else if (state == GameState::GameOver) 
        {
            gameOverState.handleEvents();
            gameOverState.setScore(score);
            updateHighScore();

            if (gameOverState.isRestartButtonClicked()) 
            {
                buttonClickSound.play();
                resetGame();
                hasBouncedOffBottom = false;
                moveLeft = false;
                moveRight = false;
                state = GameState::Playing;
            }
            if (gameOverState.isExitButtonClicked()) 
            {
                buttonClickSound.play();
                window.close();
            }
        }
    }
}

void Game::update() 
{
    if (state == GameState::Playing) 
    {
        dy += gravity;
        player.move(0, dy);

        if (moveLeft) 
        {
            player.move(-5, 0);
        }
        if (moveRight) 
        {
            player.move(5, 0);
        }

        if (player.getPosition().x < -player.getGlobalBounds().width) 
        {
            player.setPosition(window.getSize().x, player.getPosition().y);
        }
        else if (player.getPosition().x > window.getSize().x) 
        {
            player.setPosition(-player.getGlobalBounds().width, player.getPosition().y);
        }

        if (!hasBouncedOffBottom && player.getPosition().y + player.getGlobalBounds().height >= window.getSize().y) 
        {
            dy = jumpVelocity;
            player.setPosition(player.getPosition().x, window.getSize().y - player.getGlobalBounds().height);
            hasBouncedOffBottom = true;
        }

        else if (hasBouncedOffBottom && player.getPosition().y >= window.getSize().y) {
            gameOverSound.play();
            state = GameState::GameOver;
        }

        bool onPlatform = false;
        sf::FloatRect playerBounds = player.getGlobalBounds();

        for (auto& platform : platforms) 
        {
            if (!platform) continue;

            sf::FloatRect platformBounds = platform->sprite.getGlobalBounds();

            if (playerBounds.intersects(platformBounds) &&
                dy > 0 &&
                playerBounds.top + playerBounds.height <= platformBounds.top + dy &&
                playerBounds.left + playerBounds.width > platformBounds.left &&
                playerBounds.left < platformBounds.left + platformBounds.width)
            {
                dy = jumpVelocity;
                player.setPosition(player.getPosition().x, platformBounds.top - playerBounds.height);
                onPlatform = true;

                if (platform->isBrokenPlatform() && !platform->isFalling()) 
                {
                    platform->startFalling();
                    platformBreak.play();
                }

                hasBounced = false;

                if (!platform->wasHit()) 
                {
                    score += 10;
                    platform->setWasHit(true);
                    collisionSound.play();
                }
            }

            if (auto movingPlatform = dynamic_cast<MovingPlatform*>(platform.get())) 
            {
                movingPlatform->update(window.getSize().x);
            }

            if (platform->isFalling()) 
            {
                platform->y += 5;
                platform->sprite.setPosition(platform->x, platform->y);
            }
        }

        if (!onPlatform) 
        {
            hasBounced = false;
        }

        if (player.getPosition().y < maxHeight) 
        {
            float diff = maxHeight - player.getPosition().y;
            player.setPosition(player.getPosition().x, maxHeight);

            for (auto& platform : platforms) 
            {
                platform->y += diff;
                platform->sprite.setPosition(platform->x, platform->y);

                if (platform->y > window.getSize().y) 
                {
                    platform = generatePlatform(-platform->sprite.getGlobalBounds().height,
                        static_cast<float>(rand()) / RAND_MAX < movingPlatformSpawnProbability,
                        static_cast<float>(rand()) / RAND_MAX < movingPlatformSpawnProbability);
                }
            }

            lastPlatformY = maxHeight;
        }

        for (auto& platform : platforms) 
        {
            if (platform->isFalling()) 
            {
                platform->sprite.move(0, 5);
            }
        }
    }
}

void Game::render() 
{
    window.clear(sf::Color::White);

    if (state == GameState::Playing)
    {
        window.draw(background);

        for (auto& platform : platforms) 
        {
            if (platform) 
            {
                window.draw(platform->sprite);
            }
        }
        window.draw(player);

        scoreText.setString("Score: " + std::to_string(score));
        window.draw(scoreText);

        highScoreText.setString("High Score: " + std::to_string(highScore));
        window.draw(highScoreText);
    }
    else if (state == GameState::Menu) 
    {
        menuState.render();
    }
    else if (state == GameState::Paused) 
    {
        pauseState.render();
    }
    else if (state == GameState::GameOver) 
    {
        gameOverState.render();
        gameOverState.setScore(score);

        highScoreText.setString("High Score: " + std::to_string(highScore));
        window.draw(highScoreText);
    }

    window.display();
}

void Game::run() 
{
    while (window.isOpen()) 
    {
        handleEvents();
        update();
        render();
    }
}
