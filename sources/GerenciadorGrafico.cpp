#include "GerenciadorGrafico.h"

#include <cstring>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

    // Singleton design pattern - Only one instance will be created 
GerenciadorGrafico* GerenciadorGrafico::instance = nullptr;

    //Returns a pointer to the Graphics. 
GerenciadorGrafico* GerenciadorGrafico::getInstance() {
    if (instance == nullptr) {
        instance = new GerenciadorGrafico();
    }
    return instance;
}

GerenciadorGrafico::GerenciadorGrafico() :
    window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "The Human War", sf::Style::Titlebar | sf::Style::Close)),
    view(sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT))
{
    this->window->setFramerateLimit(60);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
    delete (window);
}

    // Give a pointer to a body and it will be drawn to the screen. 
void GerenciadorGrafico::render(sf::Sprite* body) {
    window->draw(*body);
}

    // Display everything that was drawn. 
void GerenciadorGrafico::display() {
    if (isWindowOpen())
        window->display();
}

    // Clear the window to re-display stuff. 
void GerenciadorGrafico::clear() {
    if (isWindowOpen())
        window->clear(sf::Color::Cyan);
}

    // Returns if the window is open. 
bool GerenciadorGrafico::isWindowOpen() const {
    return window->isOpen();
}

    // CAUTION: Call the close window function - SFML window will close. 
void GerenciadorGrafico::closeWindow()
{
    window->close();
}

    // Sets window size to its parameters 
void GerenciadorGrafico::setWindowSize(sf::Vector2f tela)
{
    window->setSize(sf::Vector2u(tela.x, tela.y));
    view.setSize(tela.x, tela.y);
    window->setView(view);
}

    // Returns the window size. 
sf::Vector2f GerenciadorGrafico::getWindowSize() const
{
    return sf::Vector2f(window->getSize().x, window->getSize().y);
}

    // Returns the top left position of screen. 
sf::Vector2f GerenciadorGrafico::getTopLeftPosition() const
{
    return sf::Vector2f(window->getView().getCenter().x - window->getSize().x / 2, window->getView().getCenter().y - window->getSize().y / 2);
}

    // Changes the view position. 
void GerenciadorGrafico::centerView(sf::Vector2f pos)
{
    view.setCenter(sf::Vector2f(pos.x, pos.y));
    window->setView(view);
}

    // Returns a texture to be used by an entity. 
sf::Texture* GerenciadorGrafico::loadTexture(const char* arquivo)
{

    sf::Texture* tex = new sf::Texture();

    if (!tex->loadFromFile(arquivo))
    {
        std::cout << "ERROR loading file " << arquivo << std::endl;
        exit(1);
    }

    return tex;
}

float GerenciadorGrafico::updateDeltaTime()
{
    return 0.0f;
}

sf::RenderWindow* GerenciadorGrafico::getWindow() const
{
    return window;
}
  