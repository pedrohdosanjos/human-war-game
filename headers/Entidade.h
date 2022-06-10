#pragma once
#include "Jogo.h"

enum ID { empty = 0, player, soldier, platform, militar, fire };

class Entidade
{
protected:

	//Protected Variables for Animation
	sf::Sprite sprite;
	sf::Texture textureSheet;
	sf::IntRect currentFrame;

	//ID 
	ID id;

public:
	//Gerenciador Grafico
	GerenciadorGrafico* graphicManager;

	//Constructor/Destructor
	Entidade(ID id = empty);
	~Entidade();

	//Public Functions
	virtual void initTexture() = 0;
	virtual void initSprite() = 0;

	//Sprite Functions
	void setPosition(const float x, const float y);
	const sf::Vector2f getPosition() const;
	const sf::Vector2f getSize() const;

	//Animation Functions
	void draw(sf::RenderTarget& target) { target.draw(this->sprite); }

	//Public Functions
	ID getID() const;
	virtual void collide(Entidade* otherEntity, sf::Vector2f collision) = 0;





};