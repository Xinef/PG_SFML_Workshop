#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <list>
#include "Scene.h"
#include "Player.h"
#include "Plasma.h"

typedef std::list<Plasma> plasmaList;

class GameScene : public Scene
{
    public:
        GameScene();
        void draw(sf::RenderWindow &app);
        void runLogic(float deltaTime, Game &game);
        void handleEvent(sf::Event event, Game &game);
    protected:
    private:
        void shooting(float deltaTime, Game& game);

        float bgMotion = 0.0f;
        float bgSpeed = 200.0f;

        Player player;
        float cooldown = 0.0f;
        float rateOfFire = 0.2f;

        plasmaList plasma;
};

#endif // GAMESCENE_H
