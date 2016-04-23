#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player: public GameObject
{
    public:
        Player();
        ~Player();
        void runLogic(float deltaTime, Game &game);
        void restart();

        float isAlive;
    protected:
    private:
        float acceleration = 5000.0f;
        float damping = 5.0f;
};

#endif // PLAYER_H
