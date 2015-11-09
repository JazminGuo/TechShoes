#pragma once
#include "stdafx.h"
class Producto
{
private:
	int id;
	char descripcion[30];
	double talla;
	double precio;
	//char linea[30];
	//char subLinea[30];

public:
	Producto();
	~Producto();

	Producto(int, char *, double, double);

	int getId();
	void setId(int);

	char * getDescripcion();
	void setDescripcion(char *);

	double getTalla();
	void setTalla(double);

	double getPrecio();
	void setPrecio(double);


	/*
	char * getLinea();
	void setLinea(char *);

	char * getSubLinea();
	void setSubLinea(char *);
	*/
};

