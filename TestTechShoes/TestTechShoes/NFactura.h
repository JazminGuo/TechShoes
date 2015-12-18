#pragma once
#include "Factura.h"
#include"LstLineaFacturas.h"

class NFactura
{
private:
	Factura * factura;
	LstLineaFacturas * lstLineasF;
	NFactura * sgte;

public:
	NFactura();
	~NFactura();

	NFactura(Factura *);

	Factura * getFactura();
	void setFactura(Factura *);

	NFactura * getSgte();
	void setSgte(NFactura *);

	LstLineaFacturas * getLstLineasF();
	void setLstLineasF(LstLineaFacturas *);
};

