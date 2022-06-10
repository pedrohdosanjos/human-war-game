#pragma once
#include "Elemento.h"

template <class TL> class Lista {
private:
	//List elements
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	int size;

public:
	//Constructor/Destructor
	Lista();
	~Lista();

	//List size
	int getSize() { return size; }

	//List Functions
	TL* getItem(int pos) {
		Elemento<TL>* pAux = pPrimeiro;
		if (pos == 0)
		{
			return pAux->getpInfo();
		}
		for (int i = 0; i < pos; i++)
		{
			pAux = pAux->getpProx();
		}
		return pAux->getpInfo();
	}

	void push(TL* info) {
		if (pPrimeiro == nullptr)
		{
			pPrimeiro = new Elemento<TL>;
			pPrimeiro->setpInfo(info);
			pUltimo = pPrimeiro; //quando so tem 1 elemento, ele eh o primeiro e o ultimo
		}
		else
		{
			Elemento<TL>* pAux = new Elemento<TL>;
			pAux->setpInfo(info);
			pUltimo->setpProx(pAux);
			pUltimo = pAux;
		}
		size++;
	}

	void pop(TL* info) {
		Elemento <TL>* pAux = pPrimeiro;
		Elemento <TL>* pAuxAnt = nullptr;

		while (pAux->getpInfo() != info)
		{
			pAuxAnt = pAux;
			pAux = pAux->getpProx();
		}
		//First position
		if (pAux == pPrimeiro)
		{
			pPrimeiro = pAux->getpProx;
		}
		//Last position
		else if (pAux == pUltimo)
		{
			pAuxAnt->setpProx(nullptr);
		}
		//Any other position
		else
		{
			pAux->setpProx(pAux->getpProx());
		}
		delete pAux;
		size--;
	}
};


template<class TL>
inline Lista <TL>::Lista()
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
	size = 0;
}

template<class TL>
inline Lista <TL>::~Lista()
{
}