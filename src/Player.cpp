#include "Player.h"

Player::Player() {
    texture = new sf::Texture();
    if (!texture->loadFromFile("assets/player.png")) {
        sf::err() << "Failed to load player image.";
        return;
    }
    sprite = new sf::Sprite(*texture);

    position.x = 400.0f;
    position.y = 550.0f;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    radius = 40.0f;

    sprite->setOrigin(49.5f, 37.5f);

    GameObject::damping = damping;
}

void Player::runLogic(float deltaTime, Game& game) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= acceleration * deltaTime;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += acceleration * deltaTime;
    }

    if(position.x < 0.0f+radius && velocity.x < 0.0f)
        velocity.x = -velocity.x;
    if(position.x > 800.0f-radius && velocity.x > 0.0f)
        velocity.x = -velocity.x;

    GameObject::runLogic(deltaTime, game);
}

Player::~Player() {
    delete sprite;
    delete texture;
}

void Player::restart() {

    position.x = 400.0f;
    position.y = 550.0f;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    isAlive = true;
}
