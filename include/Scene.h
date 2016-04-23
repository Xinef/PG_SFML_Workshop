#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>
#include <string>

class Game;

class Scene
{
    public:
        Scene(std::string background);
        ~Scene();
        virtual void handleEvent(sf::Event event, Game &game) = 0;
        virtual void runLogic(float deltaTime, Game &game) = 0;
        virtual void draw(sf::RenderWindow &app);
    protected:
        sf::Texture* bgTexture;
        sf::Sprite* bgSprite;
    private:
};

#endif // SCENE_H
