#include "Militar.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <iostream>

Militar::Militar():Inimigo()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "The Human War: Fase 2");

    sf::Texture enemy2;

    if (!enemy2.loadFromFile("MilitarParado.png"))
    {
        std::cout << "ERROR loading Militar." << std::endl;
    }

    sf::Sprite militar(enemy2);
    militar.setScale(0.35, 0.35);
    militar.setOrigin(sf::Vector2f(militar.getTexture()->getSize().x, militar.getTexture()->getSize().y));
    militar.setPosition(sf::Vector2f(window.getSize().x, window.getSize().y));

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(militar);

        if (militar.getPosition().x > 0)
        {
            militar.move(sf::Vector2f(-1, 0));
            Sleep(1);
        }

        else
        {
            window.close();
        }

        window.display();
    }
}

Militar::~Militar()
{
	vida = 0;
}
