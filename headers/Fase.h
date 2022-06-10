#pragma once
#include <SFML/Graphics.hpp>
class Player;
class Soldado;
class Plataforma;
class ListaEntidades;

/*
	No futuro essa será uma das fases(em específico a Contemp) e não a classe fase pronta;
	A fase vai so chamar uma das duas e nelas serao instanciados os objetos da fase.
*/
class Fase
{
private:
	//Private Variables
	ListaEntidades* listaEntidades;
	Plataforma* platform;
	Soldado* soldier;
	Player* player;
	sf::RenderWindow* window;

	//Private Functions
	void initVariables();
	void initPosition();

public:
	//Constructor/Destructor
	Fase(Player* j1, sf::RenderWindow* window);
	~Fase();

	//Public Functions
	ListaEntidades* getListaEntidades() { return listaEntidades; };

	//Collision
	void updateCollision();
	void checkCollision();

	//Other Functions
	void updateCharacs();
	void resetAnimationTimer();
};
