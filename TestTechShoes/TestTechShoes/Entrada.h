#pragma once
#include "stdafx.h"

class Entrada
{
private:
	int idLinea;
	int idSublinea;
	int idProducto;
	int cantidadProducto;

public:
	Entrada();
	~Entrada();

	Entrada(int, int, int, int);

	int getIdLinea();
	void setIdLinea(int);

	int getIdSublinea();
	void setIdSublinea(int);

	int getIdProducto();
	void setIdProducto(int);

	int getCantidadProducto();
	void setCantidadProducto(int);
};

