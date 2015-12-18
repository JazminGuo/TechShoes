#pragma once
#include "stdafx.h"
class Almacen
{
private:
	int idAlmacen;
	char ubicacion[30];
public:
	Almacen();
	~Almacen();

	Almacen(int, char *);

	int getIdAlmacen();
	void setIdAlmacen(int);

	char * getUbicacion();
	void setUbicaion(char *);
};

