#pragma once
#include "NSubLineaProducto.h"
class LstSubLineaProductos
{
private:
	NSubLineaProducto *cab;
	int size;

	// Métodos Privados
	
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

	// Métodos Publicos
	NSubLineaProducto *dirNodo(int);
	bool vacia();
	bool agregar(SubLineaProducto *);
	bool modificar(int, SubLineaProducto *);
	bool eliminar(int);
	bool eliminarTodos();
	SubLineaProducto * buscar(int);
	void desplegar();

	// * Metodos de Listas de Listas *//
	int agregarProducto(int, Producto *);
	int elimniarProducto(int, int);
	Producto * buscarProducto(int, int);
	void desplegarProductosDeSubLinea(int);
	void desplegarSubLineasConProductos();
};

