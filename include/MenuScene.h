#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <Scene.h>

class MenuScene : public Scene
{
    public:
        MenuScene();
        void draw(sf::RenderWindow &app);
        void runLogic(float deltaTime, Game &game);
        void handleEvent(sf::Event event, Game &game);
    protected:
    private:
        std::string ip;
};

#endif // MENUSCENE_H
