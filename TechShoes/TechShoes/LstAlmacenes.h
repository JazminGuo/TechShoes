#pragma once
#include "NAlamacen.h"

class LstAlmacenes
{
private:
	NAlmacen * cab;
	int size;

	//Miscelaneos Privados
	NAlmacen * dirNodo(int);
	NAlmacen * dirUltimo();
	NAlmacen * dirAnterior(int);
	void agregaNodoAntesDe(NAlmacen *, NAlmacen *);
	void agregaNAlmacenDespuesDe(NAlmacen *, NAlmacen *);

public:
	LstAlmacenes();
	~LstAlmacenes();

	NAlmacen * getCab();
	void setCab(NAlmacen *);

	int getSize();
	void setSize(int);

	//Operraciones de Listas
	//Agregar
	bool agregaAsc(Almacen *);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Almacen * obtenerAlmacen(int);
	bool modificarAlmacen(int, Almacen *);
	void desplegarLista();

	/*------------------------------------ MULTILISTA: Lista de Listas ----------------------------------*/

	// Operaciones Almacen Con Inventarios
	int agregarUnInventarioEnUnAlmacen(int, Inventario *);
	void desplegarTodosInventariosDeUnAlmacen(int);
	void desplegarTodosInventariosDeTodosAlmacenes();

	// Operaciones Almacen Con Entradas
	int agregarUnaEntradaEnUnAlmacen(int, Entrada *);
	int anularUnaEntradaDeUnAlmacen(int, int);
	void desplegarTodosEntradasDeUnAlmacen(int);

	// Operaciones Almacen Con Facturas
	int agregarUnaFacturaEnUnAlmacen(int, Factura *);
	int anularUnaFacturaDeUnAlmacen(int, int);
	void desplegarTodosFacturasDeUnAlmacen(int);
};

