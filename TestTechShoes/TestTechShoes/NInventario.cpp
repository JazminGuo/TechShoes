#include "NInventario.h"


NInventario::NInventario()
{
	setInventario(new Inventario());
	setAnte(NULL);
	setSgte(NULL);
	setProdcutoRef(new Producto());
}


NInventario::~NInventario()
{
}

NInventario::NInventario(Inventario * _inventario)
{
	setInventario(_inventario);
	setAnte(NULL);
	setSgte(NULL);
	setProdcutoRef(new Producto());
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

Producto *NInventario::getProductoRef()
{
	return this->productoRef;
}
void NInventario::setProdcutoRef(Producto *_producto)
{
	this->productoRef = _producto;
}