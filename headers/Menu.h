#pragma once

#include "GerenciadorGrafico.h"
#include <iostream>

class Menu {
    int pos;
    bool pressed, theselect;

    GerenciadorGrafico* graphicManager;

    sf::RectangleShape* winclose;
    sf::Font* font;
    sf::Texture* image;
    sf::Sprite* bg;

    sf::Vector2i pos_mouse;
    sf::Vector2f mouse_coord;

    std::vector<const char*> options;
    std::vector<sf::Vector2f> coords;
    std::vector<sf::Text> texts;
    std::vector<std::size_t> sizes;

protected:

public:
    Menu();
    ~Menu();

    int selectedFase = 0;

    void set_values();
    void loop_events();
    void draw_all();

    int getFase();

    void run_menu();
};