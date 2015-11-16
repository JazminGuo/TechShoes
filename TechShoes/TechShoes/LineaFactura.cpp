#include "LineaFactura.h"



LineaFactura::LineaFactura()
{
	setIdLineaFactura(0);
	setFecha("");
	setCliente("");
}


LineaFactura::~LineaFactura()
{
}


LineaFactura::LineaFactura(int _idFactura, char *_fecha, char *_cliente)
{
	setIdLineaFactura(_idFactura);
	setFecha(_fecha);
	setCliente(_cliente);
}

int LineaFactura::getIdLineaFactura()
{
	return this->idLineaFactura;
}
void LineaFactura::setIdLineaFactura(int _idFactura)
{
	this->idLineaFactura = _idFactura;
}

char *LineaFactura::getFecha()
{
	return this->fecha;
}
void LineaFactura::setFecha(char *_fecha)
{
	strcpy_s(this->fecha, _fecha);
}

char *LineaFactura::getCliente()
{
	return this->cliente;
}
void LineaFactura::setCliente(char *_cliente)
{
	strcpy_s(this->cliente, _cliente);
}