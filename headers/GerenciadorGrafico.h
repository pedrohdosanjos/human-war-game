#pragma once

#include <SFML/Graphics.hpp>

class GerenciadorGrafico
{
private:
    //Variables
    sf::RenderWindow* window;
    sf::View view;
 
    

    // Singleton design pattern
    static GerenciadorGrafico* instance;
    GerenciadorGrafico();

public:
    ~GerenciadorGrafico();

    static GerenciadorGrafico* getInstance();

    void render(sf::Sprite* body);

    void display();

    void clear();

    bool isWindowOpen() const;

    void closeWindow();

    void setWindowSize(sf::Vector2f tela);

    sf::Vector2f getWindowSize() const;

    sf::Vector2f getTopLeftPosition() const;

    void centerView(sf::Vector2f pos);

    sf::Texture* loadTexture(const char* arquivo);

    sf::RenderWindow* getWindow() const;

   

};

