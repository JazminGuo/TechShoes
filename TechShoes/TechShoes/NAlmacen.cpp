#include "NAlamacen.h"

NAlmacen::NAlmacen()
{
	setAlmacen(new Almacen());
	setAnte(NULL);
	setSgte(NULL);
}


NAlmacen::~NAlmacen()
{
}

NAlmacen::NAlmacen(Almacen * _almacen)
{
	setAlmacen(_almacen);
	setAnte(NULL);
	setSgte(NULL);
}

Almacen * NAlmacen::getAlmacen()
{
	return this->almacen;
}

void NAlmacen::setAlmacen(Almacen * _almacen)
{
	this->almacen = _almacen;
}

NAlmacen * NAlmacen::getAnte()
{
	return this->ante;
}

void NAlmacen::setAnte(NAlmacen * _ante)
{
	this->ante = _ante;
}

NAlmacen * NAlmacen::getSgte()
{
	return this->sgte;
}

void NAlmacen::setSgte(NAlmacen * _sgte)
{
	this->sgte = _sgte;
}