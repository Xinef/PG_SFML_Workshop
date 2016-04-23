#include "GameObject.h"

void GameObject::runLogic(float deltaTime, Game& game) {
    position += velocity * deltaTime;
    velocity *= (1.0f - damping * deltaTime);
}

void GameObject::draw(sf::RenderWindow& app) {
    sprite->setPosition(position);
    app.draw(*sprite);
}
