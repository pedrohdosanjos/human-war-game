#include <iostream>
#include "FaseMedia.h"
#include "FaseContemp.h"

int main()
{
    int fase = 0;

    std::cout << "Selecione a fase desejada(1 ou 2): ";
    std::cin >> fase;
    std::cout << std::endl;

    if (fase == 1)
        FaseMedia fase1;

    else if (fase == 2)
        FaseContemp fase2;

    else
        std::cout << "INVÁLIDO";

    return 0;
}
