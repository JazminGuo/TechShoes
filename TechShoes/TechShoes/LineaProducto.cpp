#include "LineaProducto.h"



LineaProducto::LineaProducto()
{
	setIdProducto(0);
	setDescripcion("");
}


LineaProducto::~LineaProducto()
{
}

LineaProducto::LineaProducto(int _idProducto, char *_descripcion)
{
	setIdProducto(_idProducto);
	setDescripcion(_descripcion);
}

int LineaProducto ::getIdProducto()
{
	return this->idProducto;
}
void LineaProducto::setIdProducto(int _idProducto)
{
	this->idProducto = _idProducto;
}

char *LineaProducto::getDescripcion()
{
	return this->descripcion;
}

void LineaProducto::setDescripcion(char *_descripcion)
{
	strcpy_s(this->descripcion, _descripcion);
}
