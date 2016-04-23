#include "MenuScene.h"
#include "Game.h"

MenuScene::MenuScene():
    Scene("assets/menu.png") {
}

void MenuScene::draw(sf::RenderWindow &app) {
    Scene::draw(app);
}

void MenuScene::runLogic(float deltaTime, Game &game) {
}

void MenuScene::handleEvent(sf::Event event, Game &game) {
    if (event.type == sf::Event::KeyPressed) {
        switch(event.key.code) {
        case sf::Keyboard::Num1:
            game.current = &game.gameScene;
            break;
        case sf::Keyboard::Num2:
            break;
        case sf::Keyboard::Num3:
            break;
        case sf::Keyboard::Num4:
            game.app->close();
            break;
        default:
            break;
        }
    }
}
