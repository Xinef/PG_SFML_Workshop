#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"
#include "Icon.h"
#include "FPScounter.h"

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "Space Invaders");
    app.setIcon(icon.width, icon.height, icon.pixel_data);

    Game game;
    game.current = &game.loadingScene;
    game.app = &app;
    sf::Clock clock;
    FPScounter fps;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();

            else
                game.current->handleEvent(event, game);
        }

        sf::Time deltaTime = clock.restart();
        float timeSeconds = deltaTime.asSeconds();
        game.current->runLogic(timeSeconds, game);

        // Clear screen
        app.clear();

        // Draw the sprite
        game.current->draw(app);
        fps.draw(timeSeconds, app);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
