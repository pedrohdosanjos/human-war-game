#include "Soldado.h"
#define SOLDIER_LIFE 20
#define SOLDIER_DAMAGE 5
#define SOLDIER_ATTACK_COOLDOWN 0.2f
#define SOLDIER_DAMAGE_COOLDOWN 0.3f
#define SOLDIER_ATTACK_TIME 0.6f
#define SOLDIER_ATTACK_DISTANCE 30.0f

Soldado::Soldado(int pos,Player* pP) :
	Inimigo(pP,SOLDIER_LIFE, SOLDIER_ATTACK_COOLDOWN, SOLDIER_ATTACK_TIME, id = soldier)
{
	this->setDamage(SOLDIER_DAMAGE);
	this->initTexture();
	this->setPosition(pos, 300);
}

Soldado::~Soldado()
{
}

void Soldado::update(const float dt)
{
	this->incrementAttackingTimer(dt);

	
	if ((this->getPlayerPosition().x - this->getPosition().x) < SOLDIER_ATTACK_DISTANCE && this->canAttack())
	{
		this->attack();
	}
}

void Soldado::initTexture()
{
	if (!this->textureSheet.loadFromFile("player.png"))
	{
		std::cout << "Erro ao carregar imagem" << "\n" << std::endl;
	}
}

void Soldado::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); //40 por 50 

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(3.f, 3.f);
	this->sprite.setColor(sf::Color(255, 0, 0));
}
