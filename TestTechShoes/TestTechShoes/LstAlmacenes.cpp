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
	//if (agregado == true)
	//{
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
		
	//}

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
		cout << "=====================================================================" << endl;
		while (aux != NULL)
		{
			cout << "Almacen #" << i << ": " << endl;
			cout << "Id: " << aux->getAlmacen()->getIdAlmacen() << endl;
			cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
			cout << "=====================================================================" << endl;

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
		cout << "=====================================================================" << endl;
		cout << "ID Almacen : " << aux->getAlmacen()->getIdAlmacen() << endl;
		cout << "Ubicacion : " << aux->getAlmacen()->getUbicacion() << endl;
		cout << "=====================================================================" << endl;
	}
	else
		cout << "La Estructura de Almacen estan vacia! " << endl;
	return NULL;
}


/*------------------------------------ MULTILISTA: Lista de Listas ----------------------------------*/

bool LstAlmacenes::actualizarExistenciaInventariosDeUnAlmacen(int _idAlmacen, int _idProducto, Entrada *_entrada)
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
void LstAlmacenes::actualizarInventariosDeTodosAlmacenAuto(LstLineaProductos *_listaLineaProductos)
{

	// Sí NAlmacen no es NULL, entonces comparo

	NAlmacen *auxAlmacen = getCab();
	while (auxAlmacen != NULL)
	{
		int idAlmacen = auxAlmacen->getAlmacen()->getIdAlmacen();
		NLineaProducto *auxLineaProducto = _listaLineaProductos->getCab();
		do
		{
			NSubLineaProducto *auxSubLinea = auxLineaProducto->getLstSubLineaProductos()->getCab();
			while (auxSubLinea != NULL)
			{
				NProducto *auxProducto = auxSubLinea->getLstProductos()->getCab();
				do
				{
					
					Producto *producto = auxProducto->getProducto();
					Inventario *auxInventario = auxAlmacen->getListaInventarios()->buscarArticulo(producto->getLinea(), producto->getSubLinea(), producto->getIdProducto());
					if (auxInventario != NULL)
					{
						auxProducto = auxProducto->getSgte();
					}
					else
					{
						Inventario *inventario = new Inventario(producto->getLinea(), producto->getSubLinea(), producto->getIdProducto(),idAlmacen, 0);
						agregarUnInventarioEnUnAlmacen(idAlmacen, inventario);
						auxProducto = auxProducto->getSgte();
					} 
				} while ( (auxProducto!= NULL) && (auxProducto != auxSubLinea->getLstProductos()->getCab()) );  // end while de Producto
				auxSubLinea = auxSubLinea->getSgte();
			}  // end while de SubLinea Producto
			auxLineaProducto = auxLineaProducto->getSgte();
		} while ( (auxLineaProducto != NULL) && (auxLineaProducto != _listaLineaProductos->getCab()) );  // end while de Linea Producto
		auxAlmacen = auxAlmacen->getSgte();
	}  // end while de Almacen
}
void LstAlmacenes::actualizarInventariosEliminadoDeTodosAlmacenAuto(int _idLinea, int _idSubLinea, int _idProducto)
{
	NAlmacen *auxAlmacen = getCab();
	while (auxAlmacen != NULL)
	{
	
		bool eliminado = false;
		if (auxAlmacen->getListaInventarios()->actualizarInventariosEliminado(_idLinea, _idSubLinea, _idProducto))
		{
			auxAlmacen = auxAlmacen->getSgte();
		}
		else
			eliminado = false;
	}  // end while de Almacen
}
// Operaciones Almacen Con Inventarios

// Listas de Listas Inventarios
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
		if (aux->getListaInventarios()->agregar(_inventario))
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
		cout << "=====================================================================" << endl;
		cout << "ID Almacen: " << aux->getAlmacen()->getIdAlmacen() << endl;
		cout << "=====================================================================" << endl;
		cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
		cout << "=====================================================================" << endl;
		cout << "Inventarios en el Almacen: " << endl;
		cout << "=====================================================================" << endl;
		aux->getListaInventarios()->desplegarLista();
		cout << "=====================================================================" << endl;
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
			cout << "=====================================================================" << endl;
			cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
			cout << "=====================================================================" << endl;
			cout << "Inventarios en el Almacen: " << endl;
			cout << "=====================================================================" << endl;
			aux->getListaInventarios()->desplegarLista();
			cout << "=====================================================================" << endl;
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
		cout << "=====================================================================" << endl;
		cout << "=====================================================================" << endl;
		buscar(_idAlmacen);
		cout << "Entrada En el Almacen:" << endl;
		cout << "=====================================================================" << endl;
		aux->getListaInventarios()->buscar(_idProducto);
		cout << "=====================================================================" << endl;
		cout << "=====================================================================" << endl;
	}
}
void LstAlmacenes::desplegarTodosEntradasDeUnAlmacen(int _idAlmacen)
{
	NAlmacen *aux = dirNodo(_idAlmacen);
	if (aux != NULL)
	{
		cout << endl;
		cout << "=====================================================================" << endl;
		cout << "=====================================================================" << endl;
		desplegarLista();
		cout << "Entrada En el Almacen:" << endl;
		cout << "=====================================================================" << endl;
		aux->getListaEntradas()->desplegar();
		cout << "=====================================================================" << endl;
		cout << "=====================================================================" << endl;
	}
}
void LstAlmacenes::desplegarTodosEntradaDeTodosAlmacen()
{
	NAlmacen *aux = getCab();
	if (aux == NULL)
	{
		cout << endl; cout << "La Lista de Almacen Esta Vacia!" << endl;
	}
	else
	{
		cout << endl;
		cout << "=====================================================================" << endl;
		while (aux != NULL)
		{
			cout << endl;
			desplegarLista();
			aux->getListaEntradas()->desplegar();
			cout << endl;
			cout << "=====================================================================" << endl;
			aux = aux->getSgte();
		}
	}
}
//Auto agregar todos los articulos de Lineas //
void LstAlmacenes::autoAgregar(int idAlmacen, LstLineaProductos * lstLinea)
{
	NLineaProducto * auxL = lstLinea->getCab();

	if (auxL == NULL)
	{
		cout << "La Lista Linea esta Vacia !!" << endl;
	}
	else
	{
		do
		{
			NSubLineaProducto * auxS = auxL->getLstSubLineaProductos()->getCab();
			if (auxS == NULL)
				cout << "La Lista SubLinea esta vacio!!" << endl;
			else
			{

				while (auxS != NULL)
				{
					NProducto * auxP = auxS->getLstProductos()->getCab();

					if (auxP != NULL)
					{
						do
						{
							Producto * producto = auxP->getProducto();

							Inventario * inventario = new Inventario(producto->getLinea(), producto->getSubLinea(), producto->getIdProducto(), idAlmacen, 0);

							//comprobarLineasySubs(inventario->getCodLinea(), inventario->getCodSubLinea(), idAlmacen, inventario);

							agregarUnInventarioEnUnAlmacen(idAlmacen, inventario);

							auxP = auxP->getSgte();
						} while (auxP != auxS->getLstProductos()->getCab());

						
					}
					else
						auxS = auxS->getSgte();
				
				}

				auxL = auxL->getSgte();
			}
		} while (auxL != lstLinea->getCab());
	}
}

Inventario * LstAlmacenes::buscarArticulo(int _idAlmacen, int _idLinea, int _idSublinea, int _idProducto)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	return aux->getListaInventarios()->buscarArticulo(_idLinea, _idSublinea, _idProducto);
}

bool LstAlmacenes::sumarExistencia(int _idAlmacen, int _idLinea, int _idSublinea, int _idProducto, int _existencia)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	return aux->getListaInventarios()->sumarExistencia(_idLinea, _idSublinea, _idProducto, _existencia);
}

bool LstAlmacenes::restarExistencia(int _idAlmacen, int _idLinea, int _idSublinea, int _idProducto, int _existencia)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	return aux->getListaInventarios()->restarExistencia(_idLinea, _idSublinea, _idProducto, _existencia);
}





// Lista de listas Entradas

bool LstAlmacenes::agregarEntrada(int _idAlmacaen, Entrada * _entrada)
{
	NAlmacen * aux = dirNodo(_idAlmacaen);

	if (aux == NULL)
	{
		return false;
	}
	else
	{
		return aux->getListaEntradas()->agregar(_entrada);
	}
}


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

		NProducto *saltoLineaProducto = _listaLineaProductos->dirNodoLSP(_idLineaProducto, _idSubLinea, _idProducto);
		if (saltoLineaProducto != NULL)
		{
			if (auxAlmacen->getListaEntradas()->agregar(_entrada))
			{
				actualizarExistenciaInventariosDeUnAlmacen(_idAlmacen, _idProducto, _entrada);

				return 1;
			}

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

			//if (actualizarInventariosDeUnAlmacen(_idAlmacen, _idProducto, entrada))
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
		cout << "=====================================================================" << endl;
		cout << "=====================================================================" << endl;
		buscar(_idAlmacen);
		cout << "Entrada En el Almacen:" << endl;
		cout << "=====================================================================" << endl;
		aux->getListaEntradas()->buscar(_idProducto);
		cout << "=====================================================================" << endl;
		cout << "=====================================================================" << endl;
	}
}



////Auto agregar todos los articulos de Lineas //
//void LstAlmacenes::autoAgregar(int idAlmacen, LstLineaProductos * lstLinea)
//{
//	NLineaProducto * auxL = lstLinea->getCab();
//
//	if (auxL == NULL)
//	{
//		cout << "La Lista esta Vacia !!" << endl;
//	}
//	else
//	{
//		do
//		{
//			NSubLineaProducto * auxS = auxL->getLstSubLineaProductos()->getCab();
//			if (auxS == NULL)
//				cout << "La Lista esta vacio!!" << endl;
//			else
//			{
//
//				while (auxS != NULL)
//				{
//
//					if (vacia())
//					{
//						cout << "La lista Almacen esta vacia" << endl;
//					}
//					else
//					{
//						NProducto * auxP = auxS->getLstProductos()->getCab();
//
//						do
//						{
//							Producto * producto = auxP->getProducto();
//							NAlmacen *auxAlmacen = dirNodo(idAlmacen);
//							if (auxAlmacen->getListaInventarios()->dirNodoGlobal(producto->getLinea(), producto->getSubLinea(), producto->getIdProducto()))
//							{
//								auxP = auxP->getSgte();
//							}
//							else
//							{
//								Inventario *inventario = new Inventario(producto->getLinea(), producto->getSubLinea(), producto->getIdProducto(), idAlmacen, 0);
//								agregarUnInventarioEnUnAlmacen(idAlmacen, inventario);
//								auxP = auxP->getSgte();
//							}
//
//							//comprobarLineasySubs(inventario->getCodLinea(), inventario->getCodSubLinea(), idAlmacen, inventario);
//						} while ( (auxP != NULL) && (auxP != auxS->getLstProductos()->getCab()) );  // end while de auxP
//
//						auxS = auxS->getSgte();
//					}
//				} // end while de auxS
//
//				auxL = auxL->getSgte();
//			}
//		} while (auxL != lstLinea->getCab());
//	}
//}

// * Metodos de Listas de Listas Factura*//
int LstAlmacenes::agregarFactura(int _idAlmacen, Factura * _factura)
{
	/*Este metodo agrega a _subLineaProducto en la Linea _idAlmacen.
	El metodo devuelve:
	1. Si el se inserto correctamente.
	2. No se inserto por que el curso no existe
	3.No se inserto por que el estudiante ya existe
	*/

	NAlmacen * aux = dirNodo(_idAlmacen);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getListaFacturas()->agregaAsc(_factura))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

int LstAlmacenes::elimniarFactura(int _idAlmacen, int _idFactura)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getListaFacturas()->eliminar(_idFactura))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

Factura * LstAlmacenes::buscarFactura(int _idAlmacen, int _idFactura)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	if (aux == NULL)
	{
		cout << "La linea que esta bucando no existe" << endl;
	}
	else
	{
		Factura * _factura = aux->getListaFacturas()->buscar(_idFactura);

		if (_factura == NULL)
		{
			cout << "La sublinea que esta buscando no existe" << endl;
		}
		else
		{
			cout << "==============================Factura================================" << endl;
			cout << "ID: " << _factura->getIdFactura() << endl;
			cout << "Cliente: " << _factura->getCliente() << endl;
			cout << "Fecha: " << _factura->getFecha() << endl;
			cout << "=====================================================================" << endl;
			return _factura;
		}
	}
}

void LstAlmacenes::desplegarFacturasDeAlmacen(int _idAlmacen)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	cout << "=====================================================================" << endl;
	cout << "ID: " << aux->getAlmacen()->getIdAlmacen() << endl;
	cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;

	aux->getListaFacturas()->desplegarLista();
}

void LstAlmacenes::desplegarAlamacenConFacturas()
{
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NAlmacen * aux = getCab();
		int i = 1;
		cout << "=====================================================================" << endl;

		do
		{
			cout << "Almacen #" << i << ": " << endl;
			cout << "ID: " << aux->getAlmacen()->getIdAlmacen() << endl;
			cout << "Ubicacion: " << aux->getAlmacen()->getUbicacion() << endl;
			cout << "=====================================================================" << endl;
			aux->getListaFacturas()->desplegarLista();

			aux = aux->getSgte();
			i++;
		} while (aux != getCab());
		cout << endl << "Fin de la Lista" << endl;
	}
	system("pause");
}

int LstAlmacenes::ultimaFactura(int _idAlmacen)
{
	NAlmacen * aux = dirNodo(_idAlmacen);
	if (aux != NULL)
		return aux->getListaFacturas()->ultimaFactura();
	else
		return 0;
}

bool LstAlmacenes::anularFactura(int _idAlmacen, int _idFactura)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	if (aux == NULL)
	{
		return false;
	}
	else
	{
		NFactura * nfactura = aux->getListaFacturas()->anularFactura(_idFactura);

		if (nfactura != NULL)
		{
			int i = 1;
			int tamano = nfactura->getLstLineasF()->getSize();
			LineaFactura * lfactura;

			while (i <= tamano)
			{
				lfactura = nfactura->getLstLineasF()->buscar(i);

				if (lfactura != NULL)
				{
					sumarExistencia(_idAlmacen, lfactura->getIdLinea(), lfactura->getIdSublinea(), lfactura->getIdProducto(), lfactura->getCantidad());
				}
				i++;
			}
			return true;
		}
		else
		{
			return NULL;
		}
	}
}


// * Metodos de Listas de Listas de Listas Lineas de Factura*//
int LstAlmacenes::agregarLineaFactura(int _idAlmacen, int _idFactura, LineaFactura * _lineaFactura)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	if (aux == NULL)
	{
		return 4;
	}
	else
	{
		return aux->getListaFacturas()->agregarLineaFactura(_idFactura, _lineaFactura);
	}
}

int LstAlmacenes::elimniarLineaFactura(int _idAlmacen, int _idFactura, int _numLinea)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	if (aux == NULL)
	{
		return 4;
	}
	else
	{
		return aux->getListaFacturas()->elimniarLineaFactura(_idFactura, _numLinea);
	}
}

LineaFactura * LstAlmacenes::buscarLineaFactura(int _idAlmacen, int _idFactura, int _numLinea)
{
	NAlmacen * aux = dirNodo(_idAlmacen);

	if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		return aux->getListaFacturas()->buscarLineaFactura(_idFactura, _numLinea);
	}
}

void LstAlmacenes::imprimirFactura(int _idAlmacen, int _idFactura, LstLineaProductos * lstLineaProducto)
{
	NAlmacen * aux = dirNodo(_idAlmacen);
	aux->getListaFacturas()->imprimirFactura(_idFactura, lstLineaProducto);
}

void LstAlmacenes::desplegarFacturasConLineas(int _idAlmacen, LstLineaProductos * _lstLineas)
{
	NAlmacen * aux = dirNodo(_idAlmacen);
	aux->getListaFacturas()->desplegarFacturasConLinea(_lstLineas);
}

int LstAlmacenes::ultimaLinea(int _idAlamacen, int _idFactura)
{
	NAlmacen * aux = dirNodo(_idAlamacen);

	return aux->getListaFacturas()->ultimaLinea(_idFactura);
}


void LstAlmacenes::sustraerExistencia(int _idAlmacen, int _exitencia)
{
	NAlmacen * aux = dirNodo(_idAlmacen);
}