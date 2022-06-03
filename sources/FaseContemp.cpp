#include "FaseContemp.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <iostream>

FaseContemp::FaseContemp()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "The Human War: Fase 2");


    //Definindo Background
    sf::Texture img2;

    if (!img2.loadFromFile("Background2.png"))
    {
        std::cout << "ERROR loading Background." << std::endl;
    }

    sf::Sprite fundo(img2);
    fundo.setScale(0.6666, 0.6666);


    //Criando militar de forma gráfica
    sf::Texture enemy2;

    if (!enemy2.loadFromFile("MilitarParado.png"))
    {
        std::cout << "ERROR loading Militar." << std::endl;
    }

    sf::Sprite militar(enemy2);
    militar.setScale(0.6, 0.6);
    militar.setOrigin(sf::Vector2f(militar.getTexture()->getSize().x, militar.getTexture()->getSize().y));
    militar.setPosition(sf::Vector2f(window.getSize().x, window.getSize().y));
    

    //Criando arame farpado de forma gráfica
    sf::Texture obstcl2;

    if (!obstcl2.loadFromFile("ArameFarpado.png"))
    {
        std::cout << "ERROR loading Obstacle." << std::endl;
    }

    sf::Sprite arame(obstcl2);
    arame.setScale(0.6,0.6);
    arame.setOrigin(sf::Vector2f(0, arame.getTexture()->getSize().y));
    arame.setPosition(sf::Vector2f(640, window.getSize().y));
    arame.setColor(sf::Color(255,255,255));

    //Loop principal
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //movimentação
        if (militar.getPosition().x > 0)
        {
            militar.move(sf::Vector2f(-1, 0));
            Sleep(1);
        }

        //encerra quando inimigo termina de percorrer a tela;
        else
        {
            window.close();
        }

        window.clear();
        window.draw(fundo);
        window.draw(militar);
        window.draw(arame);
        window.display();
    }
}

FaseContemp::~FaseContemp()
{

}
