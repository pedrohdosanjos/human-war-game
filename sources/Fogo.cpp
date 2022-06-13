#include "Fogo.h"

void Fogo::initTexture()
{
	if (!this->textureSheet.loadFromFile("FogoObstaculo.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}

void Fogo::initSprite()
{
	this->sprite.setTexture(this->textureSheet);

	this->currentFrame = sf::IntRect(0, 0, 68, 60);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(2.f, 2.f);
}

Fogo::Fogo(sf::Vector2f pos):Obstaculo(id = fire)
{
	this->initTexture();

	this->initSprite();

	this->setPosition(pos.x, pos.y);

}

Fogo::~Fogo()
{
}
