#pragma once
#include "Entidade.h"

class Obstaculo: public Entidade
{
protected:
	int freq;

public:
	Obstaculo();
	~Obstaculo();

	void setFreq(int fre);
	int getFreq();
};

