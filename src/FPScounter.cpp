#include "FPScounter.h"

FPScounter::FPScounter() {

    if(!font.loadFromFile("assets/CMR.ttf")) {
        sf::err() << "Failed to load font.";
    }

    text.setString("FPS: ---");
    text.setFont(font);
    text.setPosition(10.0f, 10.0f);
    text.setColor(sf::Color::Red);
    text.setCharacterSize(16);
}

void FPScounter::draw(float deltaTime, sf::RenderWindow &app) {
        dT += deltaTime;
        n += 1;

        if(dT >= 1.0f) {
            float fps = n / dT;
            std::string fpsString = std::to_string(fps);
            text.setString("FPS: " + fpsString);
            n = 0;
            dT = 0.0f;
        }
        app.draw(text);
}
