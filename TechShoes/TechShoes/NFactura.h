#pragma once
#include "Factura.h"

class NFactura
{
private:
	Factura * factura;
	NFactura * sgte;

public:
	NFactura();
	~NFactura();

	NFactura(Factura *);

	Factura * getFactura();
	void setFactura(Factura *);

	NFactura * getSgte();
	void setSgte(NFactura *);
};

