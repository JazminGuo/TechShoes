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
	bool agregaAsc(int idAlmacen, Almacen * _almacen, LstLineaProductos *_listaLineaProductos);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Almacen * obtenerAlmacen(int);
	bool modificarAlmacen(int, Almacen *);
	void desplegarLista();
	Almacen *buscar(int);

	/*------------------------------------ MULTILISTA: Lista de Listas ----------------------------------*/

	// Operaciones Almacen Con Inventarios
	int agregarUnInventarioEnUnAlmacen(int, Inventario *);
	void desplegarTodosInventariosDeUnAlmacen(int);
	void desplegarTodosInventariosDeTodosAlmacenes();
	void desplegarUnInventarioDeUnAlmacen(int, int);

	// Operaciones Almacen Con Entradas
	int agregarUnaEntradaEnUnAlmacen(int, int, Entrada *);
	int anularUnaEntradaDeUnAlmacen(int, int);
	void desplegarTodosEntradasDeUnAlmacen(int);
	void desplegarUnaEntradaDeUnAlmacen(int, int);

	// Operaciones Almacen Con Facturas
	int agregarUnaFacturaEnUnAlmacen(int, Factura *);
	int anularUnaFacturaDeUnAlmacen(int, int);
	void desplegarTodosFacturasDeUnAlmacen(int);


	/*-------------------------------------------------------------*/


	bool actualizarInventariosDeUnAlmacen(int, int, Entrada *);
};

