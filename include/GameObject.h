#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SFML/Graphics.hpp"

class Game;

class GameObject
{
    public:
        GameObject() {};
        virtual void draw(sf::RenderWindow &app);
        virtual void runLogic(float deltaTime, Game &game);

        sf::Vector2f position;
        sf::Vector2f velocity;
        float damping;
        float radius;
    protected:
        sf::Texture *texture;
        sf::Sprite *sprite;
    private:
};

#endif // GAMEOBJECT_H
