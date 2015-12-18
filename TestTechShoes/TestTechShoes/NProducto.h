#pragma once
#include "Producto.h"
class NProducto
{
private:
	Producto * producto;
	NProducto * ante;
	NProducto * sgte;

public:
	NProducto();
	~NProducto();

	NProducto(Producto *);

	Producto * getProducto();
	void setProducto(Producto *);

	NProducto * getAnte();
	void setAnte(NProducto *);

	NProducto * getSgte();
	void setSgte(NProducto *);
};

