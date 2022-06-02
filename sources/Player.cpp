#include "Player.h"

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}

Player::Player():Personagem()
{
	this->initTexture();
}

Player::~Player()
{
}

sf::Vector2f Player::updateMovement(sf::Vector2f pos)
{

	this->animState = IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->move(-1.f, 0.f);
		this->animState = MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//Right
	{
		this->move(1.f, 0.f);
		this->animState = MOVING_RIGHT;
	}	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canJump)//Right
	{
		this->canJump = false;
		this->move(0.f, 2.f);
		this->animState = JUMPING;
	}

	return this->getPosition();
}

