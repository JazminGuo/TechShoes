#include "NAlamacen.h"

NAlmacen::NAlmacen()
{
	setAlmacen(new Almacen());
	setAnte(NULL);
	setSgte(NULL);
	setListaInventarios(new LstInventario());
	setListaEntradas(new LstEntradas());
	setListaFacturas(new LstFacturas());
}


NAlmacen::~NAlmacen()
{
}

NAlmacen::NAlmacen(Almacen * _almacen)
{
	setAlmacen(_almacen);
	setAnte(NULL);
	setSgte(NULL);
	setListaInventarios(new LstInventario());
	setListaEntradas(new LstEntradas());
	setListaFacturas(new LstFacturas());
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
LstInventario *NAlmacen::getListaInventarios()
{
	return this->listaInventarios;
}
void NAlmacen::setListaInventarios(LstInventario *_listaInventarios)
{
	this->listaInventarios = _listaInventarios;
}

LstEntradas *NAlmacen::getListaEntradas()
{
	return this->listaEntradas;
}
void NAlmacen::setListaEntradas(LstEntradas *_listaEntradas)
{
	this->listaEntradas = _listaEntradas;
}

LstFacturas *NAlmacen::getListaFacturas()
{
	return this->listaFacturas;
}
void NAlmacen::setListaFacturas(LstFacturas *_listaFacturas)
{
	this->listaFacturas = _listaFacturas;
}