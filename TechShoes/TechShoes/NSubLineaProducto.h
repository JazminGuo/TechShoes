#pragma once
#include "SubLineaProducto.h"
#include "LstProductos.h"
class NSubLineaProducto
{
private:
	SubLineaProducto *subLineaProducto;
	NSubLineaProducto *sgte;
	NSubLineaProducto *ante;
public:
	NSubLineaProducto();
	~NSubLineaProducto();

	NSubLineaProducto(SubLineaProducto *);
	
	SubLineaProducto *getSubLineaProducto();
	void setSubLineaProducto(SubLineaProducto *);

	NSubLineaProducto *getSgte();
	void setSgte(NSubLineaProducto *);

	NSubLineaProducto *getAnte();
	void setAnte(NSubLineaProducto *);
};

