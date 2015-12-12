#include "Producto.h"



Producto::Producto()
{
	setIdProducto(0);
	setDescripcion("-----");
	setTalla(0.0);
	setPrecio(0.0);
	//setLinea("-----");
	//setSublinea("-----");
}


Producto::~Producto()
{
}

Producto::Producto(int _idProducto, char * _descripcion, double _talla, double _precio)
{
	setIdProducto(_idProducto);
	setDescripcion(_descripcion);
	setTalla(_talla);
	setPrecio(_precio);
	//setLinea(_linea);
	//setSublinea(_subLinea);
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

/*
char * Producto::getLinea()
{
	return this->linea;
}

void Producto::setLinea(char * _linea)
{
	strcpy_s(this->linea, _linea);
}

char * Producto::getSubLinea()
{
	return this->subLinea;
}

void Producto::setSubLinea(char * _subLinea)
{
	strcpy_s(this->subLinea, _subLinea);
}
*/
