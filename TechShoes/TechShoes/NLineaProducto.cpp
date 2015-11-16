#include "NLineaProducto.h"



NLineaProducto::NLineaProducto()
{
	setLineaProducto(new LineaProducto());
	setSgte(NULL);
	setAnte(NULL);
}


NLineaProducto::~NLineaProducto()
{
}

NLineaProducto::NLineaProducto(LineaProducto *_lineaProducto)
{
	setLineaProducto(_lineaProducto);
	setSgte(NULL);
	setAnte(NULL);
}

LineaProducto *NLineaProducto::getLineaProducto()
{
	return this->lineaProducto;
}
void NLineaProducto::setLineaProducto(LineaProducto *_infoLineaProducto)
{
	this->lineaProducto = _infoLineaProducto;
}

NLineaProducto *NLineaProducto::getSgte()
{
	return this->sgte;
}

void NLineaProducto::setSgte(NLineaProducto *_sgte)
{
	this->sgte = _sgte;
}

NLineaProducto *NLineaProducto::getAnte()
{
	return this->ante;
}
void NLineaProducto::setAnte(NLineaProducto *_ante)
{
	this->ante = _ante;
}