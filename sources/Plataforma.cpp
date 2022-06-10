#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos) :
	Obstaculo(id = platform)
{
	this->initSprite();
	this->initTexture();

	this->setPosition(pos.x, pos.y);
}

Plataforma::~Plataforma()
{

}

void Plataforma::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 100, 22);

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 100, 22));
}

void Plataforma::initTexture()
{
	if (!this->textureSheet.loadFromFile("plataforma.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}