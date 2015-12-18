#pragma once
#include "NProducto.h"

class LstProductos
{
private:
	NProducto * cab;
	int size;

	//Miscelaneos Privados
	
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

	NProducto * dirNodo(int);
	//Operraciones de Listas
	//Agregar
	bool agregar(Producto *);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Producto * buscar(int);
	bool modificarProducto(int, Producto *);
	void desplegarLista();
};

