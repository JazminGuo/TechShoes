#pragma once
#include "Inventario.h"
#include "LstProductos.h"

class NInventario
{
private:
	Inventario * inventario;
	NInventario * ante;
	NInventario * sgte;
	Producto *productoRef;

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

	Producto *getProductoRef();
	void setProdcutoRef(Producto *);
};

