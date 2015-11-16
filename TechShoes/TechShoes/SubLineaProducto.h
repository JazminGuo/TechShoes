#pragma once
#include "stdafx.h"
class SubLineaProducto
{
private:
	int idSubLinea;
	char descripcion[30];
	int idLinea;
public:
	SubLineaProducto();
	~SubLineaProducto();

	SubLineaProducto(int , char *, int);

	int getIdSubLinea();
	void setIdSubLinea(int);

	char *getDescripcion();
	void setDescripcion(char *);

	int getIdLinea();
	void setIdLinea(int);
};

