#pragma once
#include "NLineaProducto.h"
class LstLineaProductos
{
private:
	NLineaProducto *cab;
	int size;

	// M�todos Privados
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
	NLineaProducto *dirNodo(int);
	NProducto *dirNodoLSP(int, int, int);
	bool vacia();
	bool agregar(LineaProducto *);
	bool modificar(int, LineaProducto *);
	bool eliminar(int);
	bool eliminarTodos();
	LineaProducto * buscar(int);
	void desplegar();

	bool dirNodoGlobal(int, int, int);

	// * Metodos de Listas de Listas  SubLinea*//
	int agregarSubLinea(int, SubLineaProducto *);
	int elimniarSubLinea(int, int);
	SubLineaProducto * buscarSublinea(int, int);
	void desplegarSubLineasDeLinea(int);
	void desplegarLineasConSubLineas();

	// * Metodos de Listas de Listas  Producto*//
	int agregarProducto(int, int, Producto *);
	int elimniarProducto(int, int, int);
	Producto * buscarProducto(int, int, int);
	void desplegarProductosDeSubLinea(int, int);
	void desplegarSubLineasConProductos(int);
};

