#pragma once
#include "Entrada.h"
#include "LstProductos.h"
class NEntrada
{
private:
	Entrada *entrada;
	NEntrada *sgte;
	Producto *productoRef;

public:
	NEntrada();
	~NEntrada();

	NEntrada(Entrada *);

	Entrada *getEntrada();
	void setEntrada(Entrada *);

	NEntrada *getSgte();
	void setSgte(NEntrada *);
	Producto *getProductoRef();
	void setProductoRef(Producto *);
};

