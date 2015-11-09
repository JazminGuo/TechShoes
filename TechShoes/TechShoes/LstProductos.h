#pragma once
#include "NProducto.h"

class LstProductos
{
private:
	NProducto * cab;
	int size;

	//Miscelaneos Privados
	NProducto * dirNodo(int);
	NProducto * dirUltimo();
	NProducto * dirAnterior(int);
	void agregaNodoAntesDe(NProducto *, NProducto *);
	void agregaNProductoDespuesDe(NProducto *, NProducto *);

public:
	LstProductos();
	~LstProductos();

	NProducto * getCab();
	void setCab(NProducto *);

	int getSize();
	void setSize(int);

	//Operraciones de Listas
	//Agregar
	bool agregaAsc(Producto *);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Producto * obtenerProducto(int);
	bool modificarProducto(int, Producto *);
	void desplegarLista();
};

