#include "Enemy.h"
#include "Game.h"

sf::Texture* Enemy::textureTemplate = NULL;

Enemy::Enemy(sf::Vector2f spawnPos) {
    if(textureTemplate == NULL) {
        textureTemplate = new sf::Texture();
        if (!textureTemplate->loadFromFile("assets/enemy1.png")) {
            sf::err() << "Failed to load enemy image.";
            return;
        }
    }
    texture = textureTemplate;
    sprite = new sf::Sprite(*texture);

    position = spawnPos;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    damping = 5.0f;
    radius = 45.0f;

    sprite->setOrigin(46.5f, 42.0f);

    desiredY = spawnPos.y;
}

Enemy::~Enemy(){
    delete sprite;
}

void Enemy::runLogic(float deltaTime, Game& game) {
    GameObject::runLogic(deltaTime, game);
    speed = 1000.0f + game.gameScene.difficulty;

    if(movingRight) {
        velocity.x += speed * deltaTime;
    }
    else {
        velocity.x -= speed * deltaTime;
    }
    if(position.x > 700.0f && movingRight) {
        movingRight = false;
        desiredY += 50.0f;
    } else if(position.x < 100.0f && !movingRight) {
        movingRight = true;
        desiredY += 50.0f;
    }
    if(position.y < desiredY) {
        velocity.y += speed * deltaTime;
    }
    if(position.y > desiredY) {
        velocity.y -= speed * deltaTime;
    }

    if(position.y > 700.0f) {
        isAlive = false;
    }
}
