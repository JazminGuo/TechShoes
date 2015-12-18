#pragma once
#include"NFactura.h"

class LstFacturas
{
private:
	NFactura * cab;
	int size;

	//Miscelaneos Privados
	NFactura * dirNodo(int);
	NFactura * dirUltimo();
	NFactura * dirAnterior(int);
	void agregaNodoAntesDe(NFactura *, NFactura *);
	void agregaNFacturaDespuesDe(NFactura *, NFactura *);

public:
	LstFacturas();
	~LstFacturas();

	NFactura * getCab();
	void setCab(NFactura *);

	int getSize();
	void setSize(int);

	//Operraciones de Listas
	//Agregar
	bool agregaAsc(Factura *);

	//Eliminar
	bool eliminar(int);

	//Miscelaneos
	bool vacia();
	Factura * obtenerFactura(int);
	bool modificarFactura(int, Factura *);
	void desplegarLista();
	int ultimaFactura();

	// * Metodos de Listas de Listas  LineaFactura*//
	int agregarLineaFactura(int, LineaFactura *);
	int elimniarLineaFactura(int, int);
	LineaFactura * buscarLineaFactura(int, int);
	void imprimirFactura(int, LstLineaProductos *);
	void desplegarFacturasConLinea();
	int ultimaLinea(int);
};

