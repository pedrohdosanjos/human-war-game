#include "Entidade.h"
#include <string.h>

Entidade::Entidade():Ente()
{
	x = 0;
	y = 0;

	dano = 0;
	*arquivo_png = NULL;
}

Entidade::~Entidade()
{
}

void Entidade::setX(int posx)
{
	x = posx;
}

int Entidade::getX()
{
	return x;
}

void Entidade::setY(int posy)
{
	y = posy;
}

int Entidade::getY()
{
	return y;
}

void Entidade::setDano(int dn)
{
	dano = dn;
}

int Entidade::getDano()
{
	return dano;
}

void Entidade::setArquivo(const char* arq)
{
	strcpy_s(arquivo_png, arq);
}

char* Entidade::getArquivo()
{
	return arquivo_png;
}
