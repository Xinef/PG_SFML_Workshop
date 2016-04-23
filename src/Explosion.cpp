#include "Explosion.h"

sf::Texture* Explosion::textureTemplate = NULL;

Explosion::Explosion(sf::Vector2f spawnPos) {
    if(textureTemplate == NULL) {
        textureTemplate = new sf::Texture();
        if (!textureTemplate->loadFromFile("assets/explosion.png")) {
            sf::err() << "Failed to load explosion image.";
            return;
        }
    }
    texture = textureTemplate;
    sprite = new sf::Sprite(*texture);

    position = spawnPos;
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    damping = 0.0f;
    radius = 0.0f;

    sprite->setOrigin(59.0f, 58.0f);
}

Explosion::~Explosion() {
    delete sprite;
}

void Explosion::runLogic(float deltaTime, Game& game) {
    lifeTime += deltaTime;
    sprite->rotate((std::rand() % 360) * 1.0f);

    if(lifeTime > endOfLife) {
        isAlive = false;
    }
}
