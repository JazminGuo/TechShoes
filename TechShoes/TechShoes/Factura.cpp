#include "Factura.h"



Factura::Factura()
{
	setId(0);
	setFecha("--/--/--");
	setCliente("----");
}


Factura::~Factura()
{
}

Factura::Factura(int _id, char * _fecha, char * _cliente)
{
	setId(_id);
	setFecha(_fecha);
	setCliente(_cliente);
}

int Factura::getId()
{
	return this->id;
}

void Factura::setId(int _id)
{
	this->id = _id;
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