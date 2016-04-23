#include "LoadingScene.h"
#include "Game.h"

LoadingScene::LoadingScene():
    Scene("assets/loading.png") {

    progressBar.setPosition(100, 500);
    progressBar.setFillColor(sf::Color::White);
}

void LoadingScene::draw(sf::RenderWindow &app)
{
    Scene::draw(app);

    app.draw(progressBar);
}

void LoadingScene::runLogic(float deltaTime, Game &game)
{
    timeElapsed += deltaTime;

    float progress = timeElapsed / loadingTime;
    progressBar.setSize(sf::Vector2f(600 * progress, 50));

    if(timeElapsed > loadingTime) {
        game.current = &game.menuScene;
    }
}

void LoadingScene::handleEvent(sf::Event event, Game &game)
{

}

