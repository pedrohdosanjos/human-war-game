#include "Militar.h"

Militar::Militar(int pos) :
	Inimigo(id = militar)
{
	this->initTexture();
	this->initSprite();
	this->setPosition(pos, 300);
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

void Militar::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); //40 por 50 

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
	this->sprite.setColor(sf::Color(0, 255, 0));
}