#pragma once
#include "Almacen.h"
#include "LstInventario.h"
#include "LstEntradas.h"
#include "LstFacturas.h"

#include "LstLineaProductos.h"

class NAlmacen
{
private:
	Almacen * almacen;
	NAlmacen * ante;
	NAlmacen * sgte;
	LstInventario *listaInventarios;
	LstEntradas *listaEntradas;
	LstFacturas *listaFacturas;

public:
	NAlmacen();
	~NAlmacen();

	NAlmacen(Almacen *);

	Almacen * getAlmacen();
	void setAlmacen(Almacen *);

	NAlmacen * getAnte();
	void setAnte(NAlmacen *);

	NAlmacen * getSgte();
	void setSgte(NAlmacen *);

	LstInventario *getListaInventarios();
	void setListaInventarios(LstInventario *);

	LstEntradas *getListaEntradas();
	void setListaEntradas(LstEntradas *);

	LstFacturas *getListaFacturas();
	void setListaFacturas(LstFacturas *);
};

