#include "NFactura.h"

NFactura::NFactura()
{
	setFactura(new Factura());
	setSgte(NULL);
}


NFactura::~NFactura()
{
}

NFactura::NFactura(Factura * _factura)
{
	setFactura(_factura);
	setSgte(NULL);
}

Factura * NFactura::getFactura()
{
	return this->factura;
}

void NFactura::setFactura(Factura * _factura)
{
	this->factura = _factura;
}

NFactura * NFactura::getSgte()
{
	return this->sgte;
}

void NFactura::setSgte(NFactura * _sgte)
{
	this->sgte = _sgte;
}

LstLineaFacturas * NFactura::getLstLineasF() 
{
	return this->lstLineasF;
}

void NFactura::setLstLineasF(LstLineaFacturas * lstLineasF) 
{
	this->lstLineasF = lstLineasF;
}