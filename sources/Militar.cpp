#include "Militar.h"

Militar::Militar():Inimigo()
{
    this->initTexture();
}

Militar::~Militar()
{

}

void Militar::initTexture()
{
	if (!this->textureSheet.loadFromFile("player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}
