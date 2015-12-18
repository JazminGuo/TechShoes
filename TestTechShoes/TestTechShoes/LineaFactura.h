#pragma once
#include "stdafx.h"
class LineaFactura
{
private:
	int idLineaFactura;
	char fecha[10];
	char cliente[10];

public:
	LineaFactura();
	~LineaFactura();


	LineaFactura(int, char *, char *);

	int getIdLineaFactura();
	void setIdLineaFactura(int);

	char *getFecha();
	void setFecha(char *);

	char *getCliente();
	void setCliente(char *);
};

