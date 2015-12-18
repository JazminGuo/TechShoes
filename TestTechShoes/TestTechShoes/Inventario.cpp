#include "Inventario.h"



Inventario::Inventario()
{
	setCodArticulo(0);
	setCodLinea(0);
	setCodSubLinea(0);
	setCodAlmacen(0);
	setExistencia(0);
}


Inventario::~Inventario()
{
}

Inventario::Inventario(int _codLinea, int _codSubLinea, int _codArticulo, int _codAlmacen, int _existencia)
{
	setCodLinea(_codLinea);
	setCodSubLinea(_codSubLinea);
	setCodArticulo(_codArticulo);
	setCodAlmacen(_codAlmacen);
	setExistencia(0);
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

int Inventario::getCodLinea()
{
	return this->codLinea;
}
void Inventario::setCodLinea(int _codLinea)
{
	this->codLinea = _codLinea;
}

int Inventario::getCodSubLinea()
{
	return this->codSublinea;
}
void Inventario::setCodSubLinea(int _codSubLinea)
{
	 this->codSublinea = _codSubLinea;
}