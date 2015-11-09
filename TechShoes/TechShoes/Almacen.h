#pragma once
#include "stdafx.h"
class Almacen
{
private:
	int id;
	char ubicacion[30];
public:
	Almacen();
	~Almacen();

	Almacen(int, char *);

	int getId();
	void setId(int);

	char * getUbicacion();
	void setUbicaion(char *);
};

