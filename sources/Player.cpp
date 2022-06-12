#include "Player.h"
#define PLAYER_LIFE 100.0f
#define PLAYER_DAMAGE 10
#define PLAYER_ATTACK_COOLDOWN 0.2f
#define PLAYER_DAMAGE_COOLDOWN 1
#define PLAYER_ATTACK_TIME 1.2f
#define PLAYER_ATTACK_DISTANCE 15.0f


void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); //40 por 50 

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


Player::Player() :
	Personagem(PLAYER_LIFE, PLAYER_ATTACK_COOLDOWN, PLAYER_ATTACK_TIME, id = player),
	swordDistance(PLAYER_ATTACK_DISTANCE)
{
	this->setDamage(PLAYER_DAMAGE);
	this->damageCooldown = 0.0f;
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && canJump)//Jump
	{
		this->canJump = false;
		this->move(0.f, 2.f);
		this->animState = JUMPING;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && this->canAttack()) //Attack
	{
		this->attack();
		this->animState = ATTACKING;
		this->flagIsAttacking = true;
	}

	return this->getPosition();
}

void Player::collide(Entidade* otherEntity, sf::Vector2f collision)
{
	if (otherEntity->getID() == soldier || otherEntity->getID() == militar)
	{
		Personagem* pAux = dynamic_cast<Personagem*>(otherEntity);

		if (pAux != nullptr)
		{
			if (this->isAttacking())
			{
				pAux->receiveDamage(this->getDamage());
			}
		}

		this->moveOnCollision(collision, otherEntity);

	}
	else

	{
		if (collision.x < 0.0f && collision.y < 0.0f) {

			this->moveOnCollision(collision, otherEntity);

			if (otherEntity->getID() == platform)
			{
				this->canJump = true;
			}
			else if (otherEntity->getID() == fire)
			{
				//Funcao para receber dano
			}

			//Se tiver mais obstaculos colocar aqui
		}
	}

	if (this->life <= 0)
	{
		this->alive = false;
	}
}

void Player::update(const float dt)
{
	this->incrementAttackingTimer(dt);
	this->damageCooldown += dt;
}

const float Player::getSwordDistance()
{
	return this->swordDistance;
}

void Player::receiveDamage(const int damage)
{
	this->life -= damage;

	if (this->life <= 0)
	{
		this->alive = false;
	}
	this->damageCooldown = 0;
}
