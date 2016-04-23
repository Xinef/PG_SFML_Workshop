#ifndef GAME_H
#define GAME_H

#include "Scene.h"
#include "LoadingScene.h"
#include "MenuScene.h"
#include "GameScene.h"

class Game
{
    public:
        Scene* current;
        LoadingScene loadingScene;
        MenuScene menuScene;
        GameScene gameScene;

        sf::RenderWindow *app;
    protected:
    private:
};

#endif // GAME_H
