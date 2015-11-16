#pragma once
#include "NSubLineaProducto.h"
class LstSubLineaProductos
{
private:
	NSubLineaProducto *cab;
	int size;

	// M�todos Privados
	NSubLineaProducto *dirNodo(int);
	NSubLineaProducto *dirAnterior(int);
	NSubLineaProducto *dirUltimo(int);
	void agregarNodoAntesDe(NSubLineaProducto *, NSubLineaProducto *);
	void agregarNodoDespuesDe(NSubLineaProducto *, NSubLineaProducto *);

public:
	LstSubLineaProductos();
	~LstSubLineaProductos();

	NSubLineaProducto *getCab();
	void setCab(NSubLineaProducto *);

	int getSize();
	void setSize(int);

	// M�todos Publicos

	bool vacia();
	bool agregar(SubLineaProducto *);
	bool modificar(int, SubLineaProducto *);
	bool eliminar(int);
	bool eliminarTodos();
	SubLineaProducto *buscar(int);
	void desplegar();

};

