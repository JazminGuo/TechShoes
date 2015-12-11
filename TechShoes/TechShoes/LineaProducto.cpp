#include "LineaProducto.h"



LineaProducto::LineaProducto()
{
	setIdLineaProducto(0);
	setDescripcion("");
}


LineaProducto::~LineaProducto()
{
}

LineaProducto::LineaProducto(int _idProducto, char *_descripcion)
{
	setIdLineaProducto(_idProducto);
	setDescripcion(_descripcion);
}

int LineaProducto ::getIdLineaProducto()
{
	return this->idLineaProducto;
}
void LineaProducto::setIdLineaProducto(int _idProducto)
{
	this->idLineaProducto = _idProducto;
}

char *LineaProducto::getDescripcion()
{
	return this->descripcion;
}

void LineaProducto::setDescripcion(char *_descripcion)
{
	strcpy_s(this->descripcion, _descripcion);
}
