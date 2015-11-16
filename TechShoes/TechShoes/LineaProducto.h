#pragma once
#include "stdafx.h"
class LineaProducto
{
private:
	int idProducto;
	char descripcion[30];

public:
	LineaProducto();
	~LineaProducto();

	LineaProducto(int , char *);

	int getIdProducto();
	void setIdProducto(int);

	char *getDescripcion();
	void setDescripcion(char *);
};

