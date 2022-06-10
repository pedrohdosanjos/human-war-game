#pragma once
#include "ListaEntidades.h"
class MovingEntidade;


class Collider
{
private:

	ListaEntidades* movEntities;
	ListaEntidades* statEntities;

public:
	//Constructor/Destructor
	Collider(ListaEntidades* movingEntities, ListaEntidades* staticEntities);
	~Collider();

	//Public Functions
	void collide();
	void clear();

};
