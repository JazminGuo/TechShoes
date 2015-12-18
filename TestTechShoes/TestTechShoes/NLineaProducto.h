#pragma once
#include "LineaProducto.h"
#include "LstSubLineaProductos.h"
class NLineaProducto
{
private:
	LineaProducto * lineaProducto;    // Info
	LstSubLineaProductos * lstSubLineaProductos;
	NLineaProducto *sgte;
	NLineaProducto *ante;

public:
	NLineaProducto();
	~NLineaProducto();

	NLineaProducto(LineaProducto *);

	LineaProducto *getLineaProducto();
	void setLineaProducto(LineaProducto *);

	LstSubLineaProductos * getLstSubLineaProductos();
	void setLstSubLineaProductos(LstSubLineaProductos *);

	NLineaProducto *getSgte();
	void setSgte(NLineaProducto *);

	NLineaProducto *getAnte();
	void setAnte(NLineaProducto *);
};

