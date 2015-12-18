#include "NLineaFactura.h"



NLineaFactura::NLineaFactura()
{
	setLineaFactura(new LineaFactura());
	setSgte(NULL);
	setAnte(NULL);
}


NLineaFactura::~NLineaFactura()
{
}

NLineaFactura::NLineaFactura(LineaFactura *_factura)
{
	setLineaFactura(_factura);
	setSgte(NULL);
	setAnte(NULL);
}

LineaFactura *NLineaFactura::getLineaFactura()
{
	return this->lineaFactura;
}
void NLineaFactura::setLineaFactura(LineaFactura *_infoLineaFactura)
{
	this->lineaFactura = _infoLineaFactura;
}

NLineaFactura *NLineaFactura::getSgte()
{
	return this->sgte;
}
void NLineaFactura::setSgte(NLineaFactura *_sgte)
{
	this->sgte = _sgte;
}

NLineaFactura *NLineaFactura::getAnte()
{
	return this->ante;
}
void NLineaFactura::setAnte(NLineaFactura *_ante)
{
	this->ante = _ante;
}