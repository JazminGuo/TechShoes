#pragma once
#include "NInventario.h"

class LstInventario
{
private:
	NInventario * cab;
	int size;

	//Miscelaneos Privados
	
	NInventario * dirUltimo();
	NInventario * dirAnterior(int);
	void agregaNodoAntesDe(NInventario *, NInventario *);
	void agregaNInventarioDespuesDe(NInventario *, NInventario *);

public:
	LstInventario();
	~LstInventario();

	NInventario * dirNodo(int);

	NInventario * getCab();
	void setCab(NInventario *);

	int getSize();
	void setSize(int);

	//Operraciones de Listas
	//Agregar
	bool agregar(Inventario *);
	bool agregar2(Inventario *);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Inventario * obtenerInventario(int);
	bool modificarInventario(int, Inventario *);
	void desplegarLista();
	void buscar(int);
	bool dirNodoGlobal(int, int, int);


	/*------------------------------ MULTILISTA: Lista de Listas Salteada --------------------------------------------*/

	// Inventario hacer Un Salto Hacia Producto
	bool agregarUnProductoAlInventario(int, Producto *);

	bool actualizarInventarios(int, int);


	Inventario * buscarArticulo(int, int, int);

	bool aumentarExistencia(int, int, int, int);

};