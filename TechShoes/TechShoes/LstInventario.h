#pragma once
#include "NInventario.h"

class LstInventario
{
private:
	NInventario * cab;
	int size;

	//Miscelaneos Privados
	NInventario * dirNodo(int);
	NInventario * dirUltimo();
	NInventario * dirAnterior(int);
	void agregaNodoAntesDe(NInventario *, NInventario *);
	void agregaNInventarioDespuesDe(NInventario *, NInventario *);

public:
	LstInventario();
	~LstInventario();

	NInventario * getCab();
	void setCab(NInventario *);

	int getSize();
	void setSize(int);

	//Operraciones de Listas
	//Agregar
	bool agregaAsc(Inventario *);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Inventario * obtenerInventario(int);
	bool modificarInventario(int, Inventario *);
	void desplegarLista();

	void agregarProductos(LstLineaProductos *, int);
};

