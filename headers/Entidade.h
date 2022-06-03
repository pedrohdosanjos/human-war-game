#pragma once
#include "Ente.h"

class Entidade : public Ente
{
protected:
	//Protected variables
	int x;
	int y;
	int dano;
	char arquivo_png[30];

public:
	//Constructor/Destructor
	Entidade();
	~Entidade();

	//Public Functions
	void setX(int posx);
	int getX();

	void setY(int posy);
	int getY();

	void setDano(int dn);
	int getDano();

	void setArquivo(const char* arq);
	char* getArquivo();
};


