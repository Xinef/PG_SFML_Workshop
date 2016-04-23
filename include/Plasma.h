#ifndef PLASMA_H
#define PLASMA_H

#include <GameObject.h>


class Plasma : public GameObject
{
    public:
        static sf::Texture *textureTemplate;

        Plasma(sf::Vector2f spawnPos);
        virtual ~Plasma();
        void runLogic(float deltaTime, Game &game);

        bool isAlive = true;
    protected:
    private:
        float speed = 5000.0f;
};

#endif // PLASMA_H
