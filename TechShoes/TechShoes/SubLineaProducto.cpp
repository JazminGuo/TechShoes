#include "SubLineaProducto.h"



SubLineaProducto::SubLineaProducto()
{
	setIdSubLinea(0);
	setDescripcion("");
	setIdLinea(0);
}


SubLineaProducto::~SubLineaProducto()
{
}


SubLineaProducto::SubLineaProducto(int _idSubLinea, char *_descripcion, int _idLinea)
{
	setIdSubLinea(_idSubLinea);
	setDescripcion(_descripcion);
	setIdLinea(_idLinea);
}

int SubLineaProducto::getIdSubLinea()
{
	return this->idSubLinea;
}
void SubLineaProducto::setIdSubLinea(int _idSubLiena)
{
	this->idSubLinea = _idSubLiena;
}

char *SubLineaProducto::getDescripcion()
{
	return this->descripcion;
}
void SubLineaProducto::setDescripcion(char *_descripcion)
{
	strcpy_s(this->descripcion, _descripcion);
}

int SubLineaProducto::getIdLinea()
{
	return this->idLinea;
}
void SubLineaProducto::setIdLinea(int _idLinea)
{
	this->idLinea = _idLinea;
}