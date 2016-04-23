#include "Plasma.h"

sf::Texture* Plasma::textureTemplate = NULL;

Plasma::Plasma(sf::Vector2f spawnPos) {
    if(textureTemplate == NULL) {
        textureTemplate = new sf::Texture();
        if (!textureTemplate->loadFromFile("assets/plasma.png")) {
            sf::err() << "Failed to load plasma image.";
            return;
        }
    }
    texture = textureTemplate;
    sprite = new sf::Sprite(*texture);

    position = spawnPos;
    velocity.x = 0.0f;
    velocity.y = -1000.0f;
    damping = 0.0f;
    radius = 20.0f;

    sprite->setOrigin(4.5f, 28.5f);
}

Plasma::~Plasma() {
    delete sprite;
//    delete texture;
}

void Plasma::runLogic(float deltaTime, Game& game) {
    GameObject::runLogic(deltaTime, game);
    if(position.y < -100.f) {
        isAlive = false;
    }
}
