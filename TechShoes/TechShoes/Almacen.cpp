#include "Almacen.h"


Almacen::Almacen()
{
	setId(0);
	setUbicaion("---");
}


Almacen::~Almacen()
{
}

Almacen::Almacen(int _id, char * _ubicacion)
{
	setId(_id);
	setUbicaion(_ubicacion);
}

int Almacen::getId()
{
	return this->id;
}

void Almacen::setId(int _id)
{
	this->id = _id;
}

char * Almacen::getUbicacion()
{
	return this->ubicacion;
}

void Almacen::setUbicaion(char * _ubicacion)
{
	strcpy_s(this->ubicacion, _ubicacion);
}
