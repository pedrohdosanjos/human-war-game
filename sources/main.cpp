#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Soldado.h"
#include "Militar.h"

int main()
{
    int fase = 0;

    std::cout << "Selecione a fase desejada(1 ou 2): ";
    std::cin >> fase;
    std::cout << std::endl;

    if (fase == 1)
        Soldado Romano;

    else if (fase == 2)
        Militar Britanico;

    else
        std::cout << "INVÁLIDO";

    return 0;
}
