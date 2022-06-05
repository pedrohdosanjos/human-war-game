#pragma once
#include "Jogo.h"

class Entidade
{
protected:
	
	sf::Sprite sprite;
	sf::Texture textureSheet;

	sf::IntRect currentFrame;

public:
	Entidade();
	~Entidade();

	virtual void initTexture() = 0;
	virtual void initSprite() = 0;

	void setPosition(const float x, const float y);
	const sf::Vector2f getPosition() const;

	void render(sf::RenderTarget& target);

};



