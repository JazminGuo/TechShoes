#include "Almacen.h"


Almacen::Almacen()
{
	setIdAlmacen(0);
	setUbicaion("---");
}


Almacen::~Almacen()
{
}

Almacen::Almacen(int _id, char * _ubicacion)
{
	setIdAlmacen(_id);
	setUbicaion(_ubicacion);
}

int Almacen::getIdAlmacen()
{
	return this->idAlmacen;
}

void Almacen::setIdAlmacen(int _idAlmacen)
{
	this->idAlmacen = _idAlmacen;
}

char * Almacen::getUbicacion()
{
	return this->ubicacion;
}

void Almacen::setUbicaion(char * _ubicacion)
{
	strcpy_s(this->ubicacion, _ubicacion);
}
