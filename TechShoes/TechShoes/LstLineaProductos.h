#pragma once
#include "NLineaProducto.h"
class LstLineaProductos
{
private:
	NLineaProducto *cab;
	int size;

	// Métodos Privados
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

	// Métodos Publicos

	bool vacia();
	bool agregar(LineaProducto *);
	bool modificar(int, LineaProducto *);
	bool eliminar(int);
	bool eliminarTodos();
	LineaProducto *buscar(int);
	void desplegar();

	// * Metodos de Listas de Listas *//
	int agregarSubLinea(int, SubLineaProducto *);
	int elimniarSubLinea(int, int);
	void subLineasDeLinea(int);
	void desplegarLineas_SubLineas();
};

