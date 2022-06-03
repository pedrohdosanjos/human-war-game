#include "Obstaculo.h"

Obstaculo::Obstaculo() :Entidade()
{
	freq = 0;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::setFreq(int fre)
{
	freq = fre;
}

int Obstaculo::getFreq()
{
	return freq;
}