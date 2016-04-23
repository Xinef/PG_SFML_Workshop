#include "Scene.h"

Scene::Scene(std::string background) {
    bgTexture = new sf::Texture();
    if (!bgTexture->loadFromFile(background)) {
        sf::err() << "Failed to load background image.";
        return;
    }
    bgSprite = new sf::Sprite(*bgTexture);
}

Scene::~Scene() {
    delete bgSprite;
    delete bgTexture;
}

void Scene::draw(sf::RenderWindow &app) {
    app.draw(*bgSprite);
}
