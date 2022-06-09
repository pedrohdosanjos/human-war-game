#include "GeradorDeMundo.h"
#include "Plataforma.h"

GeradorDeMundo::GeradorDeMundo(ListaEntidades* listaEntidades, const unsigned int distancia):
	listaEntidades(listaEntidades), distancia(distancia)
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

	ultimaPos.y = -(2.0f + rand() % 2) * 20 / 3 + limiteInf.y;

	Entidade* tmp;

	for (unsigned int i = 0; i < distancia; i++)
	{
		ultimaPos.x += 100;

		tmp = new Plataforma(ultimaPos);
		listaEntidades->LEs.push(static_cast<Entidade*>(tmp));
	}

	clean();
}

void GeradorDeMundo::clean()
{
	Entidade* pAux = nullptr;
	for (int i = 0; i < listaEntidades->LEs.getSize(); i++)
	{
		pAux = listaEntidades->LEs.getItem(i);
		if (pAux)
		{
			if (pAux->getPosition().x < (ultimaPos.x - 3 * distancia * 100))
			{
				listaEntidades->LEs.pop(pAux);
				i--;
				if (i < 0)
					i = -1;
			}
			else
				break;
		}
	}
}

void GeradorDeMundo::setDistancia()
{
	distancia = 20;
}


void GeradorDeMundo::resetToOrigin()
{
	ultimaPos = sf::Vector2f(0, 0);
}
