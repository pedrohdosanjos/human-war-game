#include "Player.h"

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("textures/player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n"
				  << std::endl;
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); // 40 por 50

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
}

void Player::initPhysics()
{
	this->velocityMax = 20.f;
	this->velocityMin = 1.f;
	this->acceleration = 3.3f;
	this->drag = 0.87f;
	this->gravity = 4.f;
	this->velocityMaxY = 80.f;
}

Player::Player() : Personagem(id = player)
{
	this->initTexture();
	this->initSprite();
	this->initPhysics();
}

Player::~Player()
{
}

sf::Vector2f Player::updateMovement(sf::Vector2f pos)
{

	this->animState = IDLE;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) // Left
	{
		this->move(-1.f, 0.f);
		this->animState = MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) // Right
	{
		this->move(1.f, 0.f);
		this->animState = MOVING_RIGHT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canJump) // Jump
	{
		this->canJump = false;
		this->move(0.f, 2.f);
		this->animState = JUMPING;
	}

	return this->getPosition();
}

void Player::collide(Entidade *otherEntity, sf::Vector2f collision)
{
	if (otherEntity->getID() == soldier || otherEntity->getID() == militar)
	{
		this->moveOnCollision(collision, otherEntity);

		// Funcao para receber dano
	}

	else

	{
		if (collision.x < 0.0f && collision.y < 0.0f)
		{

			this->moveOnCollision(collision, otherEntity);

			if (otherEntity->getID() == platform)
			{
				this->canJump = true;
			}

			else if (otherEntity->getID() == fire)
			{
				graphicManager->closeWindow();
				std::cout << "Voce morreu" << std::endl;
			}

			// Se tiver mais obstaculos colocar aqui
		}
	}
}