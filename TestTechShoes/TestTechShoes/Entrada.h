#pragma once
#include "stdafx.h"

class Entrada
{
private:
	int idProducto;
	int cantidadProducto;
public:
	Entrada();
	~Entrada();

	Entrada(int, int);

	int getIdProducto();
	void setIdProducto(int);

	int getCantidadProducto();
	void setCantidadProducto(int);
};

