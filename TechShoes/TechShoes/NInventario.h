#pragma once
#include "Inventario.h"
#include "LstLineaProductos.h"

class NInventario
{
private:
	Inventario * inventario;
	NInventario * ante;
	NInventario * sgte;
public:
	NInventario();
	~NInventario();

	NInventario(Inventario *);

	Inventario * getInventario();
	void setInventario(Inventario *);

	NInventario * getAnte();
	void setAnte(NInventario *);

	NInventario * getSgte();
	void setSgte(NInventario *);
};

