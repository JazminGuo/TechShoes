#pragma once
#include "stdafx.h"

class Factura
{
private:
	int idFactura;
	char fecha[30];
	char cliente[30];
	bool anular;

public:
	Factura();
	~Factura();

	Factura(int, char *, char *);

	int getIdFactura();
	void setIdFactura(int);

	char * getFecha();
	void setFecha(char *);

	char * getCliente();
	void setCliente(char *);

	bool getAnular();
	void setAnular(bool);
};

