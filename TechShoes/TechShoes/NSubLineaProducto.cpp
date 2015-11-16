#include "NSubLineaProducto.h"



NSubLineaProducto::NSubLineaProducto()
{
	setSubLineaProducto(new SubLineaProducto());
	setSgte(NULL);
	setAnte(NULL);
}


NSubLineaProducto::~NSubLineaProducto()
{
}

NSubLineaProducto::NSubLineaProducto(SubLineaProducto *_subLineaProducto)
{
	setSubLineaProducto(_subLineaProducto);
	setSgte(NULL);
	setAnte(NULL);
}

SubLineaProducto *NSubLineaProducto::getSubLineaProducto()
{
	return this->subLineaProducto;
}
void NSubLineaProducto::setSubLineaProducto(SubLineaProducto *_subLineaProducto)
{
	this->subLineaProducto = _subLineaProducto;
}

NSubLineaProducto *NSubLineaProducto::getSgte()
{
	return this->sgte;
}
void NSubLineaProducto::setSgte(NSubLineaProducto *_sgte)
{
	this->sgte = _sgte;
}

NSubLineaProducto *NSubLineaProducto::getAnte()
{
	return this->ante;
}
void NSubLineaProducto::setAnte(NSubLineaProducto *_ante)
{
	this->ante = _ante;
}