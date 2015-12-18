#pragma once
#include "LineaFactura.h"
#include "LstLineaProductos.h"

class NLineaFactura
{
private:
	LineaFactura * lineaFactura;
	LstLineaProductos * lstLineasProducto;
	NLineaFactura * sgte;
	NLineaFactura * ante;

public:
	NLineaFactura();
	~NLineaFactura();

	NLineaFactura(LineaFactura *);

	LineaFactura * getLineaFactura();
	void setLineaFactura(LineaFactura *);

	NLineaFactura * getSgte();
	void setSgte(NLineaFactura *);

	NLineaFactura * getAnte();
	void setAnte(NLineaFactura *);
};

