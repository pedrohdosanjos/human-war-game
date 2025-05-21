#include "Soldado.h"

Soldado::Soldado(int pos) : Inimigo(id = soldier)
{
	this->initTexture();
	this->initSprite();
	this->setPosition(pos, 300);
}

Soldado::~Soldado()
{
}

void Soldado::initTexture()
{
	if (!this->textureSheet.loadFromFile("textures/player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n"
				  << std::endl;
	}
}

void Soldado::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); // 40 por 50

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
	this->sprite.setColor(sf::Color(255, 0, 0));
}
