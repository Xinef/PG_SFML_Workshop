#include "EnemyPlasma.h"

sf::Texture* EnemyPlasma::textureTemplate = NULL;

EnemyPlasma::EnemyPlasma(sf::Vector2f spawnPos) {
    if(textureTemplate == NULL) {
        textureTemplate = new sf::Texture();
        if (!textureTemplate->loadFromFile("assets/plasma2.png")) {
            sf::err() << "Failed to load plasma2 image.";
            return;
        }
    }
    texture = textureTemplate;
    sprite = new sf::Sprite(*texture);

    position = spawnPos;
    velocity.x = 0.0f;
    velocity.y = 200.0f;
    damping = 0.0f;
    radius = 10.0f;

    sprite->setOrigin(4.5f, 18.5f);
    sprite->setRotation(180.0f);
}

EnemyPlasma::~EnemyPlasma() {
    delete sprite;
}

void EnemyPlasma::runLogic(float deltaTime, Game& game){
    GameObject::runLogic(deltaTime, game);
    if(position.y > 700.f) {
        isAlive = false;
    }
}
