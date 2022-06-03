#include <iostream>
#include "Jogo.h"

int main()
{
    Jogo jogo;
    //Game loop
    while (jogo.running())
    {
        //Update
        jogo.update();

        //Render
        jogo.render();
    }


    return 0;
}