#pragma once
#include "stdafx.h"

class Factura
{
private:
	int id;
	char fecha[30];
	char cliente[30];

public:
	Factura();
	~Factura();

	Factura(int, char *, char *);

	int getId();
	void setId(int);

	char * getFecha();
	void setFecha(char *);

	char * getCliente();
	void setCliente(char *);
};

