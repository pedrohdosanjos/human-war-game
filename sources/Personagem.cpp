#include "Personagem.h"

Personagem::Personagem():Entidade()
{
	velocidade = 0;
	num_vidas = 0;
}

Personagem::~Personagem()
{
}

void Personagem::setVelocidade(int vel)
{
	velocidade = vel;
}

int Personagem::getVelocidade()
{
	return velocidade;
}

void Personagem::setNum_vidas(int vidas)
{
	num_vidas = vidas;
}

int Personagem::getNum_vidas()
{
	return num_vidas;
}
