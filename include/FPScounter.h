#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include <SFML/Graphics.hpp>

class FPScounter
{
    public:
        FPScounter();
        void draw(float deltaTime, sf::RenderWindow &app);
    protected:
    private:
        sf::Font font;
        sf::Text text;
        float dT = 0.0f;
        int n = 0;
};

#endif // FPSCOUNTER_H
