#include "Soldado.h"

Soldado::Soldado() :
	Inimigo(id = soldier)
{
	this->initTexture();
}

Soldado::~Soldado()
{
}

void Soldado::initTexture()
{
	if (!this->textureSheet.loadFromFile("player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}
