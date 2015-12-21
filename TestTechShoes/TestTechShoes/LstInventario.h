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
	bool agregar(Inventario *);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Inventario * obtenerInventario(int);
	bool modificarInventario(int, Inventario *);
	void desplegarLista();
	void buscar(int);

	/*------------------------------ MULTILISTA: Lista de Listas Salteada --------------------------------------------*/

	// Inventario hacer Un Salto Hacia Producto
	bool agregarUnProductoAlInventario(int, Producto *);

	bool actualizarInventarios(int, int);


	Inventario * buscarArticulo(int, int, int);

	bool aumentarExistencia(int, int, int, int);

};