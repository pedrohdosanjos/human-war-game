#include "Inimigo.h"
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <iostream>

Inimigo::Inimigo()
{
    vida = 100;
}

Inimigo::~Inimigo()
{
    vida = 0;
}

void Inimigo::setVida(int v)
{
    vida = v;
}

int Inimigo::getVida()
{
    return vida;
}
