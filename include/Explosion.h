#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <GameObject.h>


class Explosion : public GameObject
{
    public:
        static sf::Texture *textureTemplate;

        Explosion(sf::Vector2f spawnPos);
        virtual ~Explosion();
        void runLogic(float deltaTime, Game &game);

        bool isAlive = true;
    protected:
    private:
        float lifeTime = 0.0f;
        float endOfLife = 0.3f;
};

#endif // EXPLOSION_H
