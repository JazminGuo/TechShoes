#include "NEntrada.h"



NEntrada::NEntrada()
{
	setEntrada(new Entrada());
	setSgte(NULL);
}


NEntrada::~NEntrada()
{
}

NEntrada::NEntrada(Entrada *_entrada)
{
	setEntrada(_entrada);
	setSgte(NULL);
}

Entrada *NEntrada::getEntrada()
{
	return this->entrada;
}
void NEntrada::setEntrada(Entrada *_entrada)
{
	this->entrada = _entrada;
}

NEntrada *NEntrada::getSgte()
{
	return this->sgte;
}
void NEntrada::setSgte(NEntrada *_sgte)
{
	this->sgte = _sgte;
}

