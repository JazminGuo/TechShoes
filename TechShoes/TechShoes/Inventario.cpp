#include "Inventario.h"



Inventario::Inventario()
{
	setCodArticulo(0);
	setCodAlmacen(0);
	setExistencia(0);
}


Inventario::~Inventario()
{
}

Inventario::Inventario(int _codArticulo, int _codAlmacen, int _existencia)
{
	setCodArticulo(_codArticulo);
	setCodAlmacen(_codAlmacen);
	setExistencia(_existencia);
}

int Inventario::getCodArticulo()
{
	return this->codArticulo;
}

void Inventario::setCodArticulo(int _codArticulo)
{
	this->codArticulo = _codArticulo;
}

int Inventario::getCodAlmacen()
{
	return this->codAlmacen;
}

void Inventario::setCodAlmacen(int _codAlmacen)
{
	this->codAlmacen = _codAlmacen;
}

int Inventario::getExistencia()
{
	return this->existencia;
}

void Inventario::setExistencia(int _existencia)
{
	this->existencia = _existencia;
}