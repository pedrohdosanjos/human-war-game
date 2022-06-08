#pragma once
template <class TE> class Elemento
{
private:

	//Encadeamento Simples
	Elemento<TE>* pProximo;
	TE* pInfo;

public:

	//Constructor/Destructor
	Elemento();
	~Elemento();

	//Public Functions (set's)
	void setpProx(Elemento<TE>* prox) { this->pProximo = prox; }
	void setpInfo(TE* info) { this->pInfo = info; }

	//Public Functions (get's)
	Elemento<TE>* getpProx() { return pProximo; }
	TE* getpInfo() { return pInfo; }


};


template<class TE>
inline Elemento<TE>::Elemento()
{
	pProximo = nullptr;
	pInfo = nullptr;
}

template<class TE>
inline Elemento<TE>::~Elemento() {

}
