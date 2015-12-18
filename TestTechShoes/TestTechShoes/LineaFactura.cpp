#include "LineaFactura.h"



LineaFactura::LineaFactura()
{
	setIdFactura(0);
	setNumFLinea(0);
	setIdLinea(0);
	setIdSublinea(0);
	setIdProducto(0);
	setCantidad(0);
}


LineaFactura::~LineaFactura()
{
}


LineaFactura::LineaFactura(int _idFactura, int _numFlinea, int _idLinea, int _idSublinea, int _idProducto, int _cantidad)
{
	setIdFactura(_idFactura);
	setNumFLinea(_numFlinea);
	setIdLinea(_idLinea);
	setIdSublinea(_idSublinea);
	setIdProducto(_idProducto);
	setCantidad(_cantidad);
}

void LineaFactura::setIdFactura(int idFactura)
{
	this->idFactura = idFactura;
}

int LineaFactura::getIdFactura()
{
	return this->idFactura;
}

void LineaFactura::setNumFLinea(int numFLinea)
{
	this->numFLinea = numFLinea;
}

int LineaFactura::getNumFLinea()
{
	return this->numFLinea;
}

void LineaFactura::setIdLinea(int idLinea)
{
	this->idLinea = idLinea;
}

int LineaFactura::getIdLinea()
{
	return this->idLinea;
}

void LineaFactura::setIdSublinea(int idSublinea)
{
	this->idSublinea = idSublinea;
}

int LineaFactura::getIdSublinea()
{
	return this->idSublinea;
}

void LineaFactura::setIdProducto(int idProducto)
{
	this->idProducto = idProducto;
}

int LineaFactura::getIdProducto()
{
	return this->idProducto;
}

void LineaFactura::setCantidad(int cantidad)
{
	this->cantidad = cantidad;
}

int LineaFactura::getCantidad()
{
	return this->cantidad;
}