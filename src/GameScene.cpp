#include "GameScene.h"
#include "Game.h"

GameScene::GameScene():
    Scene("assets/stars.png") {
    bgTexture->setRepeated(true);
    bgSprite->setTextureRect(sf::IntRect(0, 0, 800, 1200));
}

void GameScene::draw(sf::RenderWindow& app) {
    Scene::draw(app);
    for(plasmaList::iterator it = plasma.begin(); it != plasma.end(); ++it) {
        it->draw(app);
    }
    player.draw(app);
}

void GameScene::runLogic(float deltaTime, Game& game) {
    cooldown -= deltaTime;

    bgMotion += deltaTime * bgSpeed;
    if(bgMotion > 256.0f)
        bgMotion -= 256.0f;
    bgSprite->setPosition(0.0f, -600.0f + bgMotion);

    shooting(deltaTime, game);

    player.runLogic(deltaTime, game);
}

void GameScene::handleEvent(sf::Event event, Game& game) {
    if (event.type == sf::Event::KeyPressed) {
        switch(event.key.code) {
        case sf::Keyboard::Escape:
            game.current = &game.menuScene;
            break;
        default:
            break;
        }
    }
}

void GameScene::shooting(float deltaTime, Game& game) {
    if(cooldown < 0.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        plasma.emplace_back(player.position);
        cooldown = rateOfFire;
    }
    for(plasmaList::iterator it = plasma.begin(); it != plasma.end(); ++it) {
        it->runLogic(deltaTime, game);
        if(it->isAlive == false) {
            it = plasma.erase(it);
        }
    }
}
