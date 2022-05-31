#include "Militar.h"

Militar::Militar():Inimigo()
{
    setArquivo("MilitarParado.png");
    setDano(100);
    setNum_vidas(5);
    setVelocidade(5);

}

Militar::~Militar()
{

}
