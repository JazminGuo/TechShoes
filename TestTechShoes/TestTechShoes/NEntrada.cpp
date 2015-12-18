#include "NEntrada.h"



NEntrada::NEntrada()
{
	setEntrada(new Entrada());
	setSgte(NULL);
	setProductoRef(new Producto());
}


NEntrada::~NEntrada()
{
}

NEntrada::NEntrada(Entrada *_entrada)
{
	setEntrada(_entrada);
	setSgte(NULL);
	setProductoRef(new Producto());
}

Entrada *NEntrada::getEntrada()
{
	return this->entrada;
}
void NEntrada::setEntrada(Entrada *_entrada)
{
	this->entrada = _entrada;
}

NEntrada *NEntrada::getSgte()
{
	return this->sgte;
}
void NEntrada::setSgte(NEntrada *_sgte)
{
	this->sgte = _sgte;
}
Producto *NEntrada::getProductoRef()
{
	return this->productoRef;
}
void NEntrada::setProductoRef(Producto *_productoRef)
{
	this->productoRef = _productoRef;
}
