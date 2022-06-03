#pragma once
#include "Entidade.h"

class Obstaculo : public Entidade
{
protected:
	//Variables
	int freq;

public:
	//Constructor/Destructor
	Obstaculo();
	~Obstaculo();

	//Public Functions
	void setFreq(int fre);
	int getFreq();
};
