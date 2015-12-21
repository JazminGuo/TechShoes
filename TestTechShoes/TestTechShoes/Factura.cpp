#include "Factura.h"



Factura::Factura()
{
	setIdFactura(0);
	setFecha("--/--/--");
	setCliente("----");
	setAnular(false);
}


Factura::~Factura()
{
}

Factura::Factura(int _idFactura, char * _fecha, char * _cliente)
{
	setIdFactura(_idFactura);
	setFecha(_fecha);
	setCliente(_cliente);
	setAnular(false);
}

int Factura::getIdFactura()
{
	return this->idFactura;
}

void Factura::setIdFactura(int _idFactura)
{
	this->idFactura = _idFactura;
}

char * Factura::getFecha()
{
	return this->fecha;
}

void Factura::setFecha(char * _fecha)
{
	strcpy_s(this->fecha, _fecha);
}

char * Factura::getCliente()
{
	return this->cliente;
}

void Factura::setCliente(char * _cliente)
{
	strcpy_s(this->cliente, _cliente);
}

bool Factura::getAnular()
{
	return this->anular;
}

void Factura::setAnular(bool _anular)
{
	this->anular = _anular;
}