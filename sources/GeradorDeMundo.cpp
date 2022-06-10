#include "GeradorDeMundo.h"
#include "Plataforma.h"
#include <Windows.h>

GeradorDeMundo::GeradorDeMundo(ListaEntidades* movingEntidades, ListaEntidades* staticEntidades, const unsigned int distancia):
	staticEntidades(staticEntidades),
	movingEntidades(movingEntidades),
	distancia(distancia)
{
	srand(time(NULL));

	sf::Vector2f telaTam = GerenciadorGrafico::getInstance()->getWindowSize();

	limiteInf.y = telaTam.y;

	resetToOrigin();
	setDistancia();
}

GeradorDeMundo::~GeradorDeMundo()
{
}

void GeradorDeMundo::generate(sf::Vector2f* viewPosition, Player* player)
{
	*viewPosition = ultimaPos;

	Entidade* tmp;

	for (unsigned int i = 0; i < distancia; i++)
	{
		ultimaPos.y = limiteInf.y -(rand() % 2)* 75.f;
		//ultimaPos.y = limiteInf.y;

		ultimaPos.x += 300.f;

		tmp = new Plataforma(ultimaPos);
		staticEntidades->LEs.push(static_cast<Entidade*>(tmp));
	}

	clean();
}

void GeradorDeMundo::clean()
{
	Entidade* pAux = nullptr;
	for (int i = 0; i < staticEntidades->LEs.getSize(); i++)
	{
		pAux = staticEntidades->LEs.getItem(i);
		if (pAux)
		{
			if (pAux->getPosition().x < ultimaPos.x - 3 * distancia * 300)
			{
				staticEntidades->LEs.pop(pAux);

				i--;
				if (i < 0)
					i = -1;
			}
			else 
			{
				printf("%d \n", staticEntidades->LEs.getSize());
				break;
			}
		}
	}
}

void GeradorDeMundo::setDistancia()
{
	distancia = 10;
}


void GeradorDeMundo::resetToOrigin()
{
	ultimaPos = sf::Vector2f(0.0f, 0.0f);
}
