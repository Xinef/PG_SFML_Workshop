#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include <Scene.h>

class LoadingScene : public Scene
{
    public:
        LoadingScene();
        void draw(sf::RenderWindow &app);
        void runLogic(float deltaTime, Game &game);
        void handleEvent(sf::Event event, Game &game);
    protected:
    private:
        const float loadingTime = 3.0f;
        float timeElapsed = 3.0f;           //TODO Set to zero for release.
        sf::RectangleShape progressBar;
};

#endif // LOADINGSCENE_H
