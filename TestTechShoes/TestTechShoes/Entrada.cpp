#include "Entrada.h"



Entrada::Entrada()
{
	setIdProducto(0);
	setCantidadProducto(0);
}


Entrada::~Entrada()
{
}

Entrada::Entrada(int _idProducto, int _cantidadProducto)
{
	setIdProducto(_idProducto);
	setCantidadProducto(_cantidadProducto);
}

int Entrada::getIdProducto()
{
	return this->idProducto;
}
void Entrada::setIdProducto(int _idProducto)
{
	this->idProducto = _idProducto;
}

int Entrada::getCantidadProducto()
{
	return this->cantidadProducto;
}
void Entrada::setCantidadProducto(int _cantidadProducto)
{
	this->cantidadProducto = _cantidadProducto;
}
