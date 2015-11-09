#pragma once
#include "Almacen.h"

class NAlmacen
{
private:
	Almacen * almacen;
	NAlmacen * ante;
	NAlmacen * sgte;

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
};

