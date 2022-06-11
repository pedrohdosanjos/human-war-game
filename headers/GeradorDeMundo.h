#pragma once
#include "Player.h"
#include "ListaEntidades.h"

class GeradorDeMundo
{
private:
	sf::Vector2f viewPosition;
	sf::Vector2f limiteInf;
	sf::Vector2f ultimaPos;

	ListaEntidades* staticEntidades;
	ListaEntidades* movingEntidades;

	unsigned int distancia;

public:
	GeradorDeMundo(ListaEntidades* movingEntidades, ListaEntidades* staticEntidades, const unsigned int distancia = 20);

	~GeradorDeMundo();

	void generate(sf::Vector2f* viewPosition, Player* player, int fase);

	void clean();

	void setDistancia();

	void resetToOrigin();
};

