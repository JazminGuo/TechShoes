#pragma once
#include "Entrada.h"
class NEntrada
{
private:
	Entrada *entrada;
	NEntrada *sgte;

public:
	NEntrada();
	~NEntrada();

	NEntrada(Entrada *);

	Entrada *getEntrada();
	void setEntrada(Entrada *);

	NEntrada *getSgte();
	void setSgte(NEntrada *);

};

