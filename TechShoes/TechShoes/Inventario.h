#pragma once
#include "stdafx.h"

class Inventario
{
private:
	int codArticulo;
	int codAlmacen;
	int existencia;

public:
	Inventario();
	~Inventario();

	Inventario(int, int);

	int getCodArticulo();
	void setCodArticulo(int);

	int getCodAlmacen();
	void setCodAlmacen(int);

	int getExistencia();
	void setExistencia(int);
};

