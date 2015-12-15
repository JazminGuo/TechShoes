#pragma once
#include "stdafx.h"
class Producto
{
private:
	int idProducto;
	char descripcion[30];
	double talla;
	double precio;
	int linea;
	int subLinea;

public:
	Producto();
	~Producto();

	Producto(int, char *, double, double, int, int);

	int getIdProducto();
	void setIdProducto(int);

	char * getDescripcion();
	void setDescripcion(char *);

	double getTalla();
	void setTalla(double);

	double getPrecio();
	void setPrecio(double);

	int getLinea();
	void setLinea(int);

	int getSubLinea();
	void setSubLinea(int);
};

