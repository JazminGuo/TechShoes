#pragma once
#include "stdafx.h"
class LineaFactura
{
private:
	int idFactura;
	int numFLinea;
	int idLinea;
	int idSublinea;
	int idProducto;
	int cantidad;

public:
	LineaFactura();
	~LineaFactura();

	LineaFactura(int, int, int, int, int, int);

	void setIdFactura(int);
	int getIdFactura();

	void setNumFLinea(int);
	int getNumFLinea();
	
	void setIdLinea(int);
	int getIdLinea();
	
	void setIdSublinea(int);
	int getIdSublinea();
	
	void setIdProducto(int);
	int getIdProducto();
	
	void setCantidad(int);
	int getCantidad();
};

