#pragma once
#include "NLineaProducto.h"
class LstLineaProductos
{
private:
	NLineaProducto *cab;
	int size;

	// M�todos Privados
	NLineaProducto *dirNodo(int);
	NLineaProducto *dirAnterior(int);
	NLineaProducto *dirUltimo(int);
	void agregarNodoAntesDe(NLineaProducto *, NLineaProducto *);
	void agregarNodoDespuesDe(NLineaProducto *, NLineaProducto *);
public:
	LstLineaProductos();
	~LstLineaProductos();

	NLineaProducto *getCab();
	void setCab(NLineaProducto *);

	int getSize();
	void setSize(int);

	// M�todos Publicos

	bool vacia();
	bool agregar(LineaProducto *);
	bool modificar(int, LineaProducto *);
	bool eliminar(int);
	bool eliminarTodos();
	LineaProducto *buscar(int);
	void desplegar();
};

