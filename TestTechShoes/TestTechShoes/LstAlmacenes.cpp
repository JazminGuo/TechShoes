#include "LstAlmacenes.h"

LstAlmacenes::LstAlmacenes()
{
	setCab(NULL);
	setSize(0);
}


LstAlmacenes::~LstAlmacenes()
{
}


NAlmacen * LstAlmacenes::getCab()
{
	return this->cab;
}

void LstAlmacenes::setCab(NAlmacen * _ptr)
{
	this->cab = _ptr;
}

int LstAlmacenes::getSize()
{
	return this->size;
}

void LstAlmacenes::setSize(int _size)
{
	this->size = _size;
}

//Miscelaneos Privados
NAlmacen * LstAlmacenes::dirNodo(int _id)
{
	NAlmacen * aux = getCab();

	while (aux != NULL)
	{
		if (_id == aux->getAlmacen()->getIdAlmacen())
			return aux;
		else
			aux = aux->getSgte();
	}
	return NULL;
}

NAlmacen * LstAlmacenes::dirUltimo()
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		NAlmacen * aux = getCab();
		while (aux->getSgte() == NULL)
		{
			aux = aux->getSgte();
		}
		return aux;
	}
}

NAlmacen * LstAlmacenes::dirAnterior(int _id)
{
	NAlmacen * aux = dirNodo(_id);
	if (aux != NULL)
	{
		return aux->getAnte();
	}
	else
	{
		return NULL;
	}
}

void LstAlmacenes::agregaNodoAntesDe(NAlmacen * _ref, NAlmacen * _nuevo)
{
	_nuevo->setSgte(_ref);
	_nuevo->setAnte(_ref->getAnte());

	//Paso 3
	if (_ref == getCab())
	{
		setCab(_nuevo);
	}
	else
	{
		_ref->getAnte()->setSgte(_nuevo);
	}
	_ref->setAnte(_nuevo);
	setSize(getSize() + 1);
}

void LstAlmacenes::agregaNAlmacenDespuesDe(NAlmacen * _ref, NAlmacen * _nuevo)
{
	if (_ref->getSgte() == NULL)
	{
		_nuevo->setAnte(_ref);
		_ref->setSgte(_nuevo);
	}
	else
	{
		_nuevo->setSgte(_ref->getSgte());
		_nuevo->setAnte(_ref);

		_ref->getSgte()->setAnte(_nuevo);
		_ref->setSgte(_nuevo);
	}
	setSize(getSize() + 1);
}

//Operraciones de Listas
//Agregar
bool LstAlmacenes::agregaAsc( Almacen * _almacen, LstLineaProductos *_listaLineaProductos)
{
	int id = _almacen->getIdAlmacen();

	bool agregado = false;
	//NProducto *auxProducto = _listaProductos->dirNodo(_idProducto);
	NAlmacen *nuevoAlmacen = new NAlmacen(_almacen);
	if (vacia())
	{
		nuevoAlmacen->setSgte(getCab());
		setCab(nuevoAlmacen);
		setSize(getSize() + 1);
		agregado = true;
	}
	else
	{
		NAlmacen *aux = getCab();
		int idAlmacen = _almacen->getIdAlmacen();

		while ((aux != NULL) && (aux->getSgte() != NULL))
		{
			if (idAlmacen == aux->getAlmacen()->getIdAlmacen())
				agregado = false;

			if (idAlmacen < aux->getAlmacen()->getIdAlmacen())
			{
				agregaNodoAntesDe(aux, nuevoAlmacen);
				agregado = true;
			}
			else
				aux = aux->getSgte();
		}
		if (aux->getSgte() == NULL)
		{
			if (idAlmacen == aux->getAlmacen()->getIdAlmacen())
				agregado = false;

			if (idAlmacen < aux->getAlmacen()->getIdAlmacen())
			{
				agregaNodoAntesDe(aux, nuevoAlmacen);
				agregado = true;
			}
			else
			{
				agregaNAlmacenDespuesDe(aux, nuevoAlmacen);
				agregado = true;
			}
		}	
	}
	if (agregado == true)
	{
		/*NLineaProducto *auxLineaProducto = _listaLineaProductos->getCab();
		if (auxLineaProducto != NULL)
		{
			do
			{
				NSubLineaProducto *auxSubLineaProducto = auxLineaProducto->getLstSubLineaProductos()->getCab();
				while (auxSubLineaProducto != NULL)
				{
					NProducto *auxProducto = auxSubLineaProducto->getLstProductos()->getCab();
					do
					{
						Producto *producto = auxProducto->getProducto();
						NAlmacen *auxAlmacen = dirNodo(_almacen->getIdAlmacen());
						if (auxAlmacen != NULL)
						{

							auxAlmacen->getListaInventarios()->agregarUnProductoAlInventario(idAlmacen, producto);


							auxProducto = auxProducto->getSgte();
						}
						else
							return false;
					} while (auxProducto != auxSubLineaProducto->getLstProductos()->getCab());

					auxSubLineaProducto = auxSubLineaProducto->getSgte();
				}
				auxLineaProducto = auxLineaProducto->getSgte();
			} while (auxLineaProducto != _listaLineaProductos->getCab());
		}
		else
			return false;*/
		
	}

	return true;
}

//Eliminar
bool LstAlmacenes::eliminar(int _id)
{
	NAlmacen * aux = dirNodo(_id);
	if (aux == NULL)
	{
		return false;
	}
	else
	{
		if (aux == getCab())
		{
			setCab(aux->getSgte());
		}
		else
		{
			aux->getAnte()->setSgte(aux->getSgte());
		}

		if (aux->getSgte() != NULL)
		{
			aux->getSgte()->setAnte(aux->getAnte());
		}

		delete aux;
		setSize(getSize() - 1);
		return true;
	}
}

//Miscelaneos
bool LstAlmacenes::vacia()
{
	return getCab() == NULL;
}

Almacen * LstAlmacenes::obtenerAlmacen(int _id)
{
	NAlmacen  * aux = dirNodo(_id);

	if (aux != NULL)
	{
		return aux->getAlmacen();
	}
	else
	{
		return NULL;
	}
}

bool LstAlmacenes::modificarAlmacen(int _id, Almacen * _almacen)
{
	NAlmacen * aux = dirNodo(_id);

	if (aux == NULL)
	{
		return false;
	}
	else
	{
		aux->getAlmacen()->setIdAlmacen(_almacen->getIdAlmacen());
		aux->getAlmacen()->setUbicaion(_almacen->getUbicacion());
		return true;
	}
}

void LstAlmacenes::desplegarLista()
{
	//Desplegar los datos de cada uno de los cursos.
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NAlmacen * aux = getCab();
		int i = 1;
		cout << "============================================" << endl;
		while (aux != NULL)
		{
			cout << "Almacen #" << i << ": " << endl;
			cout << "Id: " << aux->getAlmacen()->getIdAlmacen() << endl;
			cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
			cout << "============================================" << endl;

			aux = aux->getSgte();
			i++;
		}
		cout << endl << "Fin de la Lista" << endl;
	}
	//system("pause");
	//system("cls");
}

Almacen *LstAlmacenes::buscar(int _idAlmacen) 
{
	NAlmacen *aux = dirNodo(_idAlmacen);
	if (aux != NULL)
	{
		cout << endl;
		cout << "-----------------------------------" << endl;
		cout << "ID Almacen : " << aux->getAlmacen()->getIdAlmacen() << endl;
		cout << "Ubicacion : " << aux->getAlmacen()->getUbicacion() << endl;
		cout << "-----------------------------------" << endl;
	}
	else
		cout << "La Estructura de Almacen estan vacia! " << endl;
	return NULL;
}

/*------------------------------------ MULTILISTA: Lista de Listas ----------------------------------*/

bool LstAlmacenes::actualizarInventariosDeUnAlmacen(int _idAlmacen, int _idProducto, Entrada *_entrada)
{
	NAlmacen *auxAlmacen = dirNodo(_idAlmacen);
	if (auxAlmacen != NULL)
	{
		int cantidadEntrada = _entrada->getCantidadProducto();
		if (auxAlmacen->getListaInventarios()->actualizarInventarios(_idProducto, cantidadEntrada))
			return true;
		else
			return false;
	}
	else
		return false;
	return true;
}

// Operaciones Almacen Con Inventarios
int LstAlmacenes::agregarUnInventarioEnUnAlmacen(int _idAlmacen, Inventario *_inventario)
{
/*	    1. Se inserto exitosamente
	    2. No se inserto porque el Almacen no existe
	    3. No se insertó porque el Inventario ya existe, ya fue matriculado
*/
	NAlmacen *aux = dirNodo(_idAlmacen);

	if (aux == NULL)
		return 2;
	else
	{
		if (aux->getListaInventarios()->agregaAsc(_inventario))
			return 1;
		else
			return 3;

	}
	return 0;
}

int LstAlmacenes::comprobarLineasySubs(int _linea, int _subLinea, int _idAlmacen, Inventario * _inventario)
{
	if ((_linea != _inventario->getCodLinea()) && (_subLinea !=  _inventario->getCodSubLinea()))
	{
		return agregarUnInventarioEnUnAlmacen(_idAlmacen, _inventario);
	}
	else
	{
		if ((agregarUnInventarioEnUnAlmacen(_idAlmacen, _inventario) == 2) || (agregarUnInventarioEnUnAlmacen(_idAlmacen, _inventario) == 3))
		{
			return 5;
		}
		else
		{
			return 1;
		}
	}
}

void LstAlmacenes::desplegarTodosInventariosDeUnAlmacen(int _idAlmacen)
{
	NAlmacen *aux = dirNodo(_idAlmacen);
	bool existe = false;
	if (aux != NULL)
	{
		cout << endl;
		cout << "***********************************************" << endl;
		cout << "ID Almacen: " << aux->getAlmacen()->getIdAlmacen() << endl;
		cout << "====================================" << endl;
		cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
		cout << "====================================" << endl;
		cout << "Inventarios en el Almacen: " << endl;
		cout << "====================================" << endl;
		aux->getListaInventarios()->desplegarLista();
		cout << "*********************************************" << endl;
	}
	else
		existe;
}
void LstAlmacenes::desplegarTodosInventariosDeTodosAlmacenes()
{
	NAlmacen *aux = getCab();
	bool existe = false;
	if (aux == NULL)
		cout << "La Estructura de Almacen esta vacia!" << endl;
	else
	{

		while (aux != NULL)
		{
			cout << endl;
			//cout << "***********************************************" << endl;
			cout << "ID Almacen: " << aux->getAlmacen()->getIdAlmacen() << endl;
			cout << "====================================" << endl;
			cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
			cout << "====================================" << endl;
			cout << "Inventarios en el Almacen: " << endl;
			cout << "====================================" << endl;
			aux->getListaInventarios()->desplegarLista();
			cout << "***********************************************************************" << endl;
			aux = aux->getSgte();
		}
		//system("pause");
	}
}
void LstAlmacenes::desplegarUnInventarioDeUnAlmacen(int _idAlmacen, int _idProducto)
{
	NAlmacen *aux = getCab();
	if (aux != NULL)
	{
		cout << endl;
		cout << "*********************************************************" << endl;
		cout << "--------------------------------------" << endl;
		buscar(_idAlmacen);
		cout << "Entrada En el Almacen:" << endl;
		cout << "--------------------------------------" << endl;
		aux->getListaInventarios()->buscar(_idProducto);
		cout << "--------------------------------------" << endl;
		cout << "*********************************************************" << endl;
	}
}



// Operaciones Almacen Con Entradas
int LstAlmacenes::agregarUnaEntradaEnUnAlmacen(int _idAlmacen, int _idLineaProducto, int _idSubLinea ,int _idProducto, Entrada *_entrada, LstLineaProductos *_listaLineaProductos)
{
/*	   
		Agregar Una Entrada en Un Almacen Existente
		1. Sí se agregó exitosamente.
		2. No se agregó: El Entrada ya estaba registrada
		3. No se agregó: El idProducto no existe en la lista de Prodcutos
		4. No se agregó: El Almacen no existe
*/
	
	NAlmacen *auxAlmacen = dirNodo(_idAlmacen);

	if (auxAlmacen == NULL)
		return 4;
	else
	{
		
		NProducto *saltoLineaProducto = _listaLineaProductos->dirNodoLSP(_idLineaProducto,_idSubLinea,_idProducto);
		if (saltoLineaProducto != NULL)
		{
			if (auxAlmacen->getListaEntradas()->agregar(_entrada))
				return 1;
			else
				return 2;
		}
		else
			return 3;
		//if (auxAlmacen->getListaEntradas()->agregarUnCantidadProductoEnUnaEntrada(_idProducto, _entrada) == 1)
		//{
		//	if (actualizarInventariosDeUnAlmacen(_idAlmacen, _idProducto, _entrada))
		//		return 1;
		//}
		//else
		//	return aux->getListaEntradas()->agregarUnCantidadProductoEnUnaEntrada(_idProducto, _entrada);	
	}
	return 0;
}
int LstAlmacenes::anularUnaEntradaDeUnAlmacen(int _idAlmacen, int _idProducto)
{

/*
	Anular Una Entrada de Un Almacen
	1. Sí se elimino exitosamente.
	2. No se elimino: La Entrada no existe en la lista de Entrada
	3. No se elimino: El Almacen no existe
*/

	NAlmacen *auxAlmacen = dirNodo(_idAlmacen);

	if (auxAlmacen == NULL)
		return 3;
	else
	{
		if (auxAlmacen->getListaEntradas()->anularUnaEntrada(_idProducto) == 1)
		{
			Entrada *entrada = auxAlmacen->getListaEntradas()->obtenerEntrada(_idProducto);
			entrada->setCantidadProducto(0);

			if (actualizarInventariosDeUnAlmacen(_idAlmacen, _idProducto, entrada))
				return 1;
		}
		else
			return auxAlmacen->getListaEntradas()->anularUnaEntrada(_idProducto);
			
	}
	return 0;

}
void desplegarTodosEntradasDeUnAlmacen();
void LstAlmacenes::desplegarUnaEntradaDeUnAlmacen(int _idAlmacen, int _idProducto)
{
	NAlmacen *aux = getCab();
	if (aux != NULL)
	{
		cout << endl;
		cout << "*********************************************************" << endl;
		cout << "--------------------------------------" << endl;
		buscar(_idAlmacen);
		cout << "Entrada En el Almacen:" << endl;
		cout << "--------------------------------------" << endl;
		aux->getListaEntradas()->buscar(_idProducto);
		cout << "--------------------------------------" << endl;
		cout << "*********************************************************" << endl;
	}
}

// Operaciones Almacen Con Facturas
int LstAlmacenes::agregarUnaFacturaEnUnAlmacen(int _idAlmacen, Factura *_factura)
{
	/*	    1. Se inserto exitosamente
	2. No se inserto porque el Almacen no existe
	3. No se insertó porque el Inventario ya existe, ya fue matriculado
	*/
	NAlmacen *aux = dirNodo(_idAlmacen);

	if (aux == NULL)
		return 2;
	else
	{
		if (aux->getListaFacturas()->agregaAsc(_factura))
			return 1;
		else
			return 3;

	}
	return 0;
}
int LstAlmacenes::anularUnaFacturaDeUnAlmacen(int _idAlmacen, int _idFactura)
{
/*	    1. Se eliminó exitosamente
	    2. No se eliminó porque el Almacen no existe
	    3. No se eliminó porque el Inventario NO existe
*/
	NAlmacen *aux = dirNodo(_idAlmacen); // Buscando Alamacen

	if (aux == NULL)
		return 2;
	else
	{
		if (aux->getListaFacturas()->eliminar(_idFactura))
			return 1;

		else
			return 3;
	}
}
void LstAlmacenes::desplegarTodosFacturasDeUnAlmacen(int _idAlmacen)
{
	NAlmacen *aux = dirNodo(_idAlmacen);
	bool existe = false;
	if (aux != NULL)
	{
		cout << endl;
		cout << "***********************************************" << endl;
		cout << "ID Almacen: " << aux->getAlmacen()->getIdAlmacen() << endl;
		cout << "====================================" << endl;
		cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
		cout << "====================================" << endl;
		cout << "Facturas en el Almacen: " << endl;
		cout << "====================================" << endl;
		aux->getListaFacturas()->desplegarLista();
		cout << "*********************************************" << endl;
	}
	else
		existe;
}



//Auto agregar todos los articulos de Lineas //
void LstAlmacenes::autoAgregar(int idAlmacen, LstLineaProductos * lstLinea)
{
	NLineaProducto * auxL = lstLinea->getCab();

	if (auxL == NULL)
	{
		cout << "La Lista esta Vacia !!" << endl;
	}
	else
	{
		do
		{
			NSubLineaProducto * auxS = auxL->getLstSubLineaProductos()->getCab();
			if (auxS == NULL)
				cout << "La Lista esta vacio!!" << endl;
			else
			{

				while (auxS != NULL)
				{

					if (vacia())
					{
						cout << "La lista esta vacia" << endl;
					}
					else
					{
						NProducto * auxP = auxS->getLstProductos()->getCab();

						do
						{
							Producto * producto = auxP->getProducto();

							Inventario * inventario = new Inventario(producto->getLinea(), producto->getSubLinea(), producto->getIdProducto(), idAlmacen, 0);

							comprobarLineasySubs(inventario->getCodLinea(), inventario->getCodSubLinea(), idAlmacen, inventario);

							//agregarUnInventarioEnUnAlmacen(idAlmacen, inventario);

							auxP = auxP->getSgte();
						} while (auxP != auxS->getLstProductos()->getCab());

						auxS = auxS->getSgte();
					}
				}

				auxL = auxL->getSgte();
			}
		} while (auxL != lstLinea->getCab());
	}
}