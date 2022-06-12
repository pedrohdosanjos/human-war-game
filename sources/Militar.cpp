#include "Militar.h"
#define MILITAR_LIFE 20
#define MILITAR_DAMAGE 10
#define MILITAR_ATTACK_COOLDOWN 0.2f
#define MILITAR_DAMAGE_COOLDOWN 1
#define MILITAR_ATTACK_TIME 1.2f
#define MILITAR_ATTACK_DISTANCE 50.0f

Militar::Militar(int pos, Player* pP) :
	Inimigo(pP, MILITAR_LIFE, MILITAR_ATTACK_COOLDOWN, MILITAR_ATTACK_TIME, id = militar)
{
	this->setDamage(MILITAR_DAMAGE);
	this->initTexture();
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

void Militar::update(const float dt)
{
	this->incrementAttackingTimer(dt);

	if ((this->getPlayerPosition().x - this->getPosition().x) < MILITAR_ATTACK_DISTANCE && this->canAttack())
	{
		this->attack();
	}
}