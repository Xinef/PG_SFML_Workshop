#include <SFML/Graphics.hpp>
#include <string>

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Clock clock;
    sf::Font font;
    if(!font.loadFromFile("CMR.ttf")) {
        return EXIT_FAILURE;
    }

    sf::Text text;
    text.setString("FPS: ---");
    text.setFont(font);
    text.setPosition(200.0f, 0.0f);
    text.setColor(sf::Color::Red);
    text.setCharacterSize(24);

    float dT = 0.0f;
    int n = 0;
    int nMax = 100;

    float x = 100.0f;
    float y = 100.0f;

    float r = 0.0f;

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

            if (event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Space) {
                    r += 100.0f;
                }
            }
        }

        sf::Time deltaTime = clock.restart();


        dT += deltaTime.asSeconds();
        n += 1;

        if(n >= nMax) {
            float fps = dT / nMax;
            std::string fpsString = std::to_string(1.0f/fps);
            text.setString("FPS: " + fpsString);
            n = 0;
            dT = 0.0f;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            y -= 100.0f * deltaTime.asSeconds();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            y += 100.0f * deltaTime.asSeconds();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            x -= 100.0f * deltaTime.asSeconds();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            x += 100.0f * deltaTime.asSeconds();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            r -= 100.0f * deltaTime.asSeconds();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            r += 100.0f * deltaTime.asSeconds();
        }

        sprite.setPosition(x, y);
        sprite.setOrigin(75.0f, 60.0f);
        sprite.setRotation(r);

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);
        app.draw(text);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
