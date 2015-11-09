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
};

