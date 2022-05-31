#include "Soldado.h"

Soldado::Soldado():Inimigo()
{
    setArquivo("SoldadoParado.png");
    setDano(100);
    setNum_vidas(5);
    setVelocidade(5);

}

Soldado::~Soldado()
{
}

