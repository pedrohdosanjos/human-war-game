#pragma once

class Inimigo
{
protected:
	int vida;

public:
	Inimigo();
	~Inimigo();

	void setVida(int v);

	int getVida();
};