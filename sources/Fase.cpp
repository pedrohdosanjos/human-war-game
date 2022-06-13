#include "Fase.h"
#include "Player.h"
#include "Soldado.h"
#include "Plataforma.h"
#include "ListaEntidades.h"

Fase::Fase() :
	movingEntities(new ListaEntidades()),
	staticEntities(new ListaEntidades()),
	worldGen(movingEntities, staticEntities)
{
}

Fase::~Fase()
{
	delete this->player;
	delete this->collider;
	delete this->staticEntities;
	delete this->movingEntities;
}

void Fase::checkCollision()
{
	this->collider->collide();
}