#pragma once
#include "Jogo.h"
class Entidade
{
protected:

	//Protected Variables for Animation
	sf::Sprite sprite;
	sf::Texture textureSheet;
	sf::IntRect currentFrame;
	sf::RenderWindow* window;



public:
	//Constructor/Destructor
	Entidade();
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
	void setWindow(sf::RenderWindow* window) { this->window = window; }
	sf::RenderWindow* getWindow() { return this->window; }

};


