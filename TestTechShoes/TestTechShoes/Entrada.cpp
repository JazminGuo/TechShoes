#include "Entrada.h"



Entrada::Entrada()
{
	setIdLinea(0);
	setIdSublinea(0);
	setIdProducto(0);
	setCantidadProducto(0);
}


Entrada::~Entrada()
{
}

Entrada::Entrada(int _idLinea, int _idSublinea, int _idProducto, int _cantidadProducto)
{
	setIdLinea(_idLinea);
	setIdSublinea(_idSublinea);
	setIdProducto(_idProducto);
	setCantidadProducto(_cantidadProducto);
}

int Entrada::getIdLinea()
{
	return this->idLinea;
}

void Entrada::setIdLinea(int _idLinea)
{
	this->idLinea = _idLinea;
}

int Entrada::getIdSublinea()
{
	return this->idSublinea;
}

void Entrada::setIdSublinea(int _idSublinea)
{
	this->idSublinea = _idSublinea;
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
