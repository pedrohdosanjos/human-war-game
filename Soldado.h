#pragma once

class Soldado
{
private:
	int vida;

public:
	Soldado();
	~Soldado();
	int setvida(int v) { vida = v; }
	void getvida() { return vida; }
};