#include "NInventario.h"


NInventario::NInventario()
{
	setInventario(new Inventario());
	setAnte(NULL);
	setSgte(NULL);
}


NInventario::~NInventario()
{
}

NInventario::NInventario(Inventario * _inventario)
{
	setInventario(_inventario);
	setAnte(NULL);
	setSgte(NULL);
}

Inventario * NInventario::getInventario()
{
	return this->inventario;
}

void NInventario::setInventario(Inventario * _inventario)
{
	this->inventario = _inventario;
}

NInventario * NInventario::getAnte()
{
	return this->ante;
}

void NInventario::setAnte(NInventario * _ante)
{
	this->ante = _ante;
}

NInventario * NInventario::getSgte()
{
	return this->sgte;
}

void NInventario::setSgte(NInventario * _sgte)
{
	this->sgte = _sgte;
}