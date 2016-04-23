#ifndef ENEMYPLASMA_H
#define ENEMYPLASMA_H

#include <GameObject.h>


class EnemyPlasma : public GameObject
{
    public:
        static sf::Texture *textureTemplate;

        EnemyPlasma(sf::Vector2f spawnPos);
        virtual ~EnemyPlasma();
        void runLogic(float deltaTime, Game &game);

        bool isAlive = true;
    protected:
    private:
        float speed = 5000.0f;
};

#endif // ENEMYPLASMA_H
