#include "Soldado.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <iostream>

Soldado::Soldado():Inimigo()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "The Human War: Fase 1");

    sf::Texture enemy1;

    if (!enemy1.loadFromFile("SoldadoParado.png"))
    {
        std::cout << "ERROR loading Soldier." << std::endl;
    }

    sf::Sprite soldado(enemy1);
    soldado.setScale(0.35, 0.35);
    soldado.setOrigin(sf::Vector2f(soldado.getTexture()->getSize().x, soldado.getTexture()->getSize().y));
    soldado.setPosition(sf::Vector2f(window.getSize().x, window.getSize().y));

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(soldado);

        if (soldado.getPosition().x > 0)
        {
            soldado.move(sf::Vector2f(-1, 0));
            Sleep(1);
        }

        else
        {
            window.close();
        }

        window.display();
    }
}

Soldado::~Soldado()
{
	vida = 0;
}
