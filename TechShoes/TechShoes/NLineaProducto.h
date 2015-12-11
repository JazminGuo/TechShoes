#pragma once
#include "LineaProducto.h"
#include "LstSubLineaProductos.h"
class NLineaProducto
{
private:
	LineaProducto *lineaProducto;    // Info
	NLineaProducto *sgte;
	NLineaProducto *ante;

public:
	NLineaProducto();
	~NLineaProducto();

	NLineaProducto(LineaProducto *);

	LineaProducto *getLineaProducto();
	void setLineaProducto(LineaProducto *);

	NLineaProducto *getSgte();
	void setSgte(NLineaProducto *);

	NLineaProducto *getAnte();
	void setAnte(NLineaProducto *);
};

