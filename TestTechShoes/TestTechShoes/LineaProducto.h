#pragma once
#include "stdafx.h"
class LineaProducto
{
private:
	int idLineaProducto;
	char descripcion[30];

public:
	LineaProducto();
	~LineaProducto();

	LineaProducto(int , char *);

	int getIdLineaProducto();
	void setIdLineaProducto(int);

	char *getDescripcion();
	void setDescripcion(char *);
};

