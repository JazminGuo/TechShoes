#pragma once
#include "NLineaFactura.h"
class LstLineaFacturas
{
	NLineaFactura * cab;
	int size;

	// M�todos Privados
	NLineaFactura * dirNodo(int);
	NLineaFactura * dirAnterior(int);
	NLineaFactura * dirUltimo();
	void agregarNodoAntesDe(NLineaFactura *, NLineaFactura *);
	void agregarNodoDespuesDe(NLineaFactura *, NLineaFactura *);

public:
	LstLineaFacturas();
	~LstLineaFacturas();

	NLineaFactura * getCab();
	void setCab(NLineaFactura *);

	int getSize();
	void setSize(int);

	// M�todos Publicos

	bool vacia();
	bool agregar(LineaFactura *);
	bool modificar(int, LineaFactura *);
	bool eliminar(int);
	bool eliminarTodos();
	LineaFactura * buscar(int);
	void desplegar();
	int ultimaLinea();

};

