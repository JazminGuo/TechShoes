#include "NProducto.h"


NProducto::NProducto()
{
	setProducto(new Producto());
	setAnte(NULL);
	setSgte(NULL);
}


NProducto::~NProducto()
{
}

NProducto::NProducto(Producto * _producto)
{
	setProducto(_producto);
	setAnte(NULL);
	setSgte(NULL);
}

Producto * NProducto::getProducto()
{
	return this->producto;
}

void NProducto::setProducto(Producto * _producto)
{
	this->producto = _producto;
}

NProducto * NProducto::getAnte()
{
	return this->ante;
}

void NProducto::setAnte(NProducto * _ante)
{
	this->ante = _ante;
}

NProducto * NProducto::getSgte()
{
	return this->sgte;
}

void NProducto::setSgte(NProducto * _sgte)
{
	this->sgte = _sgte;
}