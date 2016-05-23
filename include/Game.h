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
        unsigned short udpPort = 0;
        unsigned short udpPortServer = 42042;
        unsigned short udpPortClient = 42043;
        std::string serverAddress = "172.20.1.49";
        std::string clientAddress = "172.20.1.49";
        sf::UdpSocket *socket = NULL;

        sf::RenderWindow *app;
        sf::Font *font;
    protected:
    private:
};

#endif // GAME_H
