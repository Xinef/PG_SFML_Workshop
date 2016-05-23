#include "GameScene.h"
#include "Game.h"

float GameScene::difficulty = 0.0f;

GameScene::GameScene():
    Scene("assets/stars.png") {
    bgTexture->setRepeated(true);
    bgSprite->setTextureRect(sf::IntRect(0, 0, 800, 1200));

    scoreText.setString("Score: 0");
    scoreText.setPosition(10.0f, 570.0f);
    scoreText.setColor(sf::Color::Red);
    scoreText.setCharacterSize(20);

    scoreText2.setString("Score: 0");
    scoreText2.setPosition(10.0f, 550.0f);
    scoreText2.setColor(sf::Color::Cyan);
    scoreText2.setCharacterSize(20);

    escText.setString("ESC - powro't\nspacja - strzal\n<- -> - ruch");
    escText.setPosition(700.0f, 10.0f);
    escText.setColor(sf::Color::White);
    escText.setCharacterSize(12);
}

void GameScene::draw(sf::RenderWindow& app) {
    Scene::draw(app);
    for(PlasmaSeq::iterator it = plasma.begin(); it != plasma.end(); ++it) {
        it->draw(app);
    }
    for(EnemySeq::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        it->draw(app);
    }
    for(EnPlasmaSeq::iterator it = enPlasma.begin(); it != enPlasma.end(); ++it) {
        it->draw(app);
    }
    for(ExplosionSeq::iterator it = explosions.begin(); it != explosions.end(); ++it) {
        it->draw(app);
    }
    player.draw(app);
    player2.draw(app);
    app.draw(scoreText);
    app.draw(scoreText2);
    app.draw(escText);
}

void GameScene::runLogic(float deltaTime, Game& game) {
    if(game.server) {

        // SERVER

        cooldown -= deltaTime;
        enemySpawnCooldown -= deltaTime;
        enemyCooldown -= deltaTime;
        difficulty += deltaTime * 30.0f;

        bgMotion += deltaTime * bgSpeed;
        if(bgMotion > 256.0f)
            bgMotion -= 256.0f;
        bgSprite->setPosition(0.0f, -600.0f + bgMotion);

        shooting(deltaTime, game);
        spawningEnemies(deltaTime, game);
        flyEnemyPlasma(deltaTime, game);

        player.runLogic(deltaTime, game);

        std::string scoreString = std::to_string(score);
        scoreText.setString("Score: " + scoreString);
        scoreText.setFont(*game.font);
        escText.setFont(*game.font);

        std::string scoreString2 = std::to_string(score2);
        scoreText2.setString("Score: " + scoreString2);
        scoreText2.setFont(*game.font);

        sf::Packet packet;
        packet << player.position.x << player.position.y;
        sf::IpAddress clientAddress(game.clientAddress);
        game.socket->send(packet, clientAddress, game.udpPortClient);

    } else {

        // CLIENT

        sf::Packet packet;
        float x, y;
        sf::IpAddress serverAddress(game.serverAddress);
        game.socket->receive(packet, serverAddress, game.udpPortClient);
        if(packet >> x >> y) {
            player.position.x = x;
            player.position.y = y;
        }
    }
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
    if(cooldown < 0.0f && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.isAlive) {
        plasma.emplace_back(player.position);
        cooldown = rateOfFire;
    }
    for(PlasmaSeq::iterator it = plasma.begin(); it != plasma.end(); ++it) {
        it->runLogic(deltaTime, game);
        if(it->isAlive == false) {
            it = plasma.erase(it);
        }
    }
    for(ExplosionSeq::iterator it = explosions.begin(); it != explosions.end(); ++it) {
        it->runLogic(deltaTime, game);
        if(it->isAlive == false) {
            it = explosions.erase(it);
        }
    }
}

void GameScene::spawningEnemies(float deltaTime, Game& game) {
    if(enemies.size() < 30 && enemySpawnCooldown < 0.0f && player.isAlive) {
        enemySpawnCooldown = enemyRateOfSpawn * (1000.0f / (1000.0f + difficulty));
        sf::Vector2f pos(-100.0f, 50.0f);
        enemies.emplace_back(pos);
    }
    for(EnemySeq::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        it->runLogic(deltaTime, game);
        if(it->isAlive == false) {
            it = enemies.erase(it);
        }
    }
    for(EnemySeq::iterator it = enemies.begin(); it != enemies.end(); ++it) {
        for(PlasmaSeq::iterator yt = plasma.begin(); yt != plasma.end(); ++yt) {
            sf::Vector2f distance = ((*it).position - (*yt).position);
            float d = std::sqrt(distance.x * distance.x + distance.y * distance.y);
            if(d < (yt->radius + it->radius)) {
                it->isAlive = false;
                yt->isAlive = false;
                score += enemyScoreValue;
                explosions.emplace_back(it->position);
            }
        }
    }
}

void GameScene::flyEnemyPlasma(float deltaTime, Game& game) {
    if(enemyCooldown < 0.0f && enemies.size() > 0) {
        enemyCooldown = enemyRateOfFire * (300.0f / (300.0f + difficulty));
        int random = std::rand() % enemies.size();
        EnemySeq::iterator r = enemies.begin();
        std::advance(r, random);
        sf::Vector2f pos = r->position;
        if(pos.x > 20.0f && pos.x < 780.0f)
            enPlasma.emplace_back(pos);
    }

    for(EnPlasmaSeq::iterator it = enPlasma.begin(); it != enPlasma.end(); ++it) {
        it->runLogic(deltaTime, game);
        if(it->isAlive == false) {
            it = enPlasma.erase(it);
        }
    }

    for(EnPlasmaSeq::iterator it = enPlasma.begin(); it != enPlasma.end(); ++it) {
        sf::Vector2f distance = ((*it).position - player.position);
        float d = std::sqrt(distance.x * distance.x + distance.y * distance.y);
        if(d < (it->radius + player.radius)) {
            explosions.emplace_back(player.position);
            player.position.y += 200.0f;
            player.isAlive = false;
        }
    }
}

void GameScene::restart(Game& game) {
    score = 0;
    score2 = 0;
    difficulty = 0.0f;
    plasma.clear();
    enemies.clear();
    enPlasma.clear();
    explosions.clear();
    player.restart();
    player2.restart();

    // NETWORKING
    if(game.socket == NULL) {
        game.socket = new sf::UdpSocket();
        if (game.socket->bind(game.udpPort) != sf::Socket::Done) {
            sf::err() << "Failed to create UDP socket.";
        }
        game.socket->setBlocking(false);
    }
}

