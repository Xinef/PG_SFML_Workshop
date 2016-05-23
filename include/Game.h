#ifndef GAME_H
#define GAME_H

#include "Scene.h"
#include "LoadingScene.h"
#include "MenuScene.h"
#include "GameScene.h"
#include "SFML/Network.hpp"

class Game
{
    public:
        Scene* current;
        LoadingScene loadingScene;
        MenuScene menuScene;
        GameScene gameScene;

        bool server;
        int udpPort = 42042;
        sf::UdpSocket socket;

        sf::RenderWindow *app;
        sf::Font *font;
    protected:
    private:
};

#endif // GAME_H
