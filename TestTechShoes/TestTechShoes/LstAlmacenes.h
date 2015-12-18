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
	bool agregaAsc(Almacen *, LstLineaProductos *);

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
	void autoAgregar(int, LstLineaProductos *);

	// Operaciones Almacen Con Entradas
	int agregarUnaEntradaEnUnAlmacen(int, int , int , int, Entrada *, LstLineaProductos *);
	int anularUnaEntradaDeUnAlmacen(int, int);
	void desplegarTodosEntradasDeUnAlmacen(int);
	void desplegarUnaEntradaDeUnAlmacen(int, int);

	// * Metodos de Listas de Listas Factura*//
	int agregarFactura(int, Factura *);
	int elimniarFactura(int, int);
	Factura * buscarFactura(int, int);
	void desplegarFacturasDeAlmacen(int);
	void desplegarAlamacenConFacturas();
	int ultimaFactura(int);

	// * Metodos de Listas de Listas de Listas Lineas de Factura*//
	int agregarLineaFactura(int, int, LineaFactura *);
	int elimniarLineaFactura(int, int, int);
	LineaFactura * buscarLineaFactura(int, int, int);
	void desplegarLineasDeFactura(int, int);
	void desplegarFacturasConLineas(int);
	int ultimaLinea(int, int);




	/*-------------------------------------------------------------*/


	int comprobarLineasySubs(int, int, int, Inventario *);

	void sustraerExistencia(int, int);

	bool actualizarInventariosDeUnAlmacen(int, int, Entrada *);
};

