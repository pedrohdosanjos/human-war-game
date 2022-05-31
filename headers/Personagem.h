#pragma once
#include "Entidade.h"

class Personagem: public Entidade
{
protected:
	int velocidade;
	int num_vidas;

public:
	Personagem();
	~Personagem();

	void setVelocidade(int vel);
	int getVelocidade();

	void setNum_vidas(int vidas);
	int getNum_vidas();
};

