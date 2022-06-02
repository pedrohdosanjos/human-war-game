#include <iostream>
#include "Jogo.h"

int main()
{
    Jogo jogo;

    while (jogo.running())
    {
        jogo.update();
        jogo.render();
    }
    

    return 0;
}