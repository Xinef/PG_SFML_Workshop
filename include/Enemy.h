#ifndef ENEMY_H
#define ENEMY_H

#include <GameObject.h>


class Enemy : public GameObject
{
    public:
        static sf::Texture *textureTemplate;

        Enemy(sf::Vector2f spawnPos);
        virtual ~Enemy();
        void runLogic(float deltaTime, Game &game);

        bool isAlive = true;
    protected:
    private:
        float speed = 1000.0f;
        bool movingRight = true;
        float desiredY;
};

#endif // ENEMY_H
