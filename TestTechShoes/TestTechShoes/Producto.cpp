#include "Producto.h"



Producto::Producto()
{
	setIdProducto(0);
	setDescripcion("-----");
	setTalla(0.0);
	setPrecio(0.0);
	setLinea(0);
	setSubLinea(0);
}

Producto::~Producto()
{
}

Producto::Producto(int _idProducto, char * _descripcion, double _talla, double _precio, int _linea, int _subLinea)
{
	setIdProducto(_idProducto);
	setDescripcion(_descripcion);
	setTalla(_talla);
	setPrecio(_precio);
	setLinea(_linea);
	setSubLinea(_subLinea);
}

int Producto::getIdProducto()
{
	return this->idProducto;
}

void Producto::setIdProducto(int _id)
{
	this->idProducto = _id;
}

char * Producto::getDescripcion()
{
	return this->descripcion;
}

void Producto::setDescripcion(char * _descripcion)
{
	strcpy_s(this->descripcion, _descripcion);
}

double Producto::getTalla()
{
	return this->talla;
}

void Producto::setTalla(double _talla)
{
	this->talla = _talla;
}

double Producto::getPrecio()
{
	return this->precio;
}

void Producto::setPrecio(double _precio)
{
	this->precio = _precio;
}


int Producto::getLinea()
{
	return this->linea;
}

void Producto::setLinea(int _linea)
{
	this->linea = _linea;
}

int Producto::getSubLinea()
{
	return this->subLinea;
}

void Producto::setSubLinea(int _subLinea)
{
	this->subLinea = _subLinea;
}
