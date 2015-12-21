#include "LstInventario.h"



LstInventario::LstInventario()
{
	setCab(NULL);
	setSize(0);
}


LstInventario::~LstInventario()
{
}


NInventario * LstInventario::getCab()
{
	return this->cab;
}

void LstInventario::setCab(NInventario * _ptr)
{
	this->cab = _ptr;
}

int LstInventario::getSize()
{
	return this->size;
}

void LstInventario::setSize(int _size)
{
	this->size = _size;
}

//Miscelaneos Privados
NInventario * LstInventario::dirNodo(int _codArticulo)
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		NInventario * aux = getCab();

		do
		{
			if (aux->getInventario()->getCodArticulo() == _codArticulo)
			{
				return aux;
			}
			else
			{
				aux = aux->getSgte();
			}
		} while (aux != getCab());
		return NULL;
	}
}

NInventario * LstInventario::dirUltimo()
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		return getCab()->getAnte();
	}
}

NInventario * LstInventario::dirAnterior(int _codArticulo)
{
	NInventario * aux = dirNodo(_codArticulo);

	return aux->getAnte();
}

void LstInventario::agregaNodoAntesDe(NInventario * _ref, NInventario * _nuevo)
{
	_nuevo->setSgte(_ref);
	_nuevo->setAnte(_ref->getAnte());

	_ref->getAnte()->setSgte(_nuevo);
	_ref->setAnte(_nuevo);
}

void LstInventario::agregaNInventarioDespuesDe(NInventario * _ref, NInventario * _nuevo)
{
	_nuevo->setSgte(_ref->getSgte());
	_nuevo->setAnte(_ref);

	_ref->getSgte()->setAnte(_nuevo);
	_ref->setSgte(_nuevo);
}

//Operraciones de Listas
//Agregar

bool LstInventario::agregar(Inventario * _inventario)
{
	// Devuleve true si se puede insertar
	//Devuelve false si no se inserto el estudiante ya esta en la lista
	bool agregado = false;
	if (vacia())
	{
		setCab(new NInventario(_inventario));
		getCab()->setSgte(getCab());
		getCab()->setAnte(getCab());
		agregado = true;
	}
	else
	{
		int codArticulo = _inventario->getCodArticulo();
		NInventario * prim = getCab();
		NInventario * ult = getCab()->getAnte();

		if ((codArticulo < prim->getInventario()->getCodArticulo()) || (codArticulo > ult->getInventario()->getCodArticulo()))
		{
			agregaNInventarioDespuesDe(ult, new NInventario(_inventario));
			

			if (codArticulo < prim->getInventario()->getCodArticulo())
			{
				setCab(prim->getAnte());
			}
			agregado = true;
		}
		else
		{
			NInventario * aux = getCab();
			bool exist = false;
			do
			{

				if (codArticulo == aux->getInventario()->getCodArticulo())
				{
					exist = true;
				}

				if (codArticulo < aux->getSgte()->getInventario()->getCodArticulo())
				{
					agregaNInventarioDespuesDe(aux, new NInventario(_inventario));
					agregado = true;
				}
				else
				{
					aux = aux->getSgte();
				}
			} while ((aux != getCab()) && !exist);
		}
	}
	if (agregado)
	{
		setSize(getSize() + 1);
	}
	return agregado;
}

//Eliminar
bool LstInventario::eliminar(int _codArticulo)
{
	NInventario * aux = dirNodo(_codArticulo);

	if (aux != NULL)
	{
		if (getSize() == 1)
		{
			setCab(NULL);
		}
		else
		{
			aux->getAnte()->setSgte(aux->getSgte());
			aux->getSgte()->setAnte(aux->getAnte());

			if (aux == getCab())
			{
				setCab(aux->getSgte());
			}
		}
		delete aux;
		setSize(getSize() - 1);
		return true;
	}
	else
	{
		return false;
	}
}

//Miscelaneos
bool LstInventario::vacia()
{
	return getCab() == NULL;
}

Inventario * LstInventario::obtenerInventario(int _codArticulo)
{
	NInventario * aux = dirNodo(_codArticulo);

	if ((aux != NULL) && (aux->getInventario()->getCodArticulo() == _codArticulo))
	{
		return aux->getInventario();
	}
	return NULL;
}

//bool LstInventario::modificarInventario(int _codArticulo, Inventario * _inventario)
//{
//	if (!vacia())
//	{
//		NInventario * aux = dirNodo(_codArticulo);
//
//		if (aux != NULL)
//		{
//			aux->getInventario()->setCodArticulo(_inventario->getCodArticulo());
//			aux->getInventario()->setCodAlmacen(_inventario->getCodAlmacen());
//			aux->getInventario()->setExistencia(_inventario->getExistencia());
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	else
//	{
//		return false;
//	}
//}

void LstInventario::desplegarLista()
{
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NInventario * aux = getCab();
		int i = 1;
		cout << "============================================" << endl;
		do
		{
			cout << "Inventario #" << i << ": " << endl;
			cout << "Codigo del Articulo: " <<aux->getInventario()->getCodLinea() << "-" << aux->getInventario()->getCodSubLinea() << "-" << aux->getInventario()->getCodArticulo() << endl;
			cout << "Codigo del Almacen: " << aux->getInventario()->getCodAlmacen() << endl;
			cout << "Existencia: " << aux->getInventario()->getExistencia() << endl;
			cout << "============================================" << endl;
			aux = aux->getSgte();
			i++;
		} while (aux != getCab());
		cout << endl << "Fin de la Lista" << endl;
	}
	//system("pause");
	//system("cls");
}
void LstInventario::buscar(int _idProducto)
{
	NInventario *aux = dirNodo(_idProducto);
	if (aux != NULL)
	{
		cout << endl;
		cout << "-----------------------------------" << endl;
		cout << "ID Almacen : " << aux->getInventario()->getCodAlmacen() << endl;
		//cout << "ID Producto : " << aux->getInventario()->getCodArticulo() << endl;
		cout << "Cantidad de Prodcuto : " << aux->getInventario()->getExistencia() << endl;
		cout << "-----------------------------------" << endl;
	}
	else
		cout << "La Estructura de Inventarios estan vacia!" << endl;
}


/*------------------------------ MULTILISTA: Lista de Listas Salteada --------------------------------------------*/

// Inventario hacer Un Salto Hacia Producto
bool LstInventario::actualizarInventarios(int _idProducto, int _cantidadEntrada)
{
	NInventario *auxInventario = dirNodo(_idProducto);
	if (auxInventario != NULL)
	{
		int totalCantidad = 0;
		totalCantidad += _cantidadEntrada;
		auxInventario->getInventario()->setExistencia(totalCantidad);
		return true;
	}
	else
		return false;
	return true;
}
bool LstInventario::agregarUnProductoAlInventario(int _idAlmacen, Producto *_producto)
{
	// Agregando Un Producto en la Lista de Inventario

	/*
	Devuelve:
	1. Sí se agregó exitosamente
	2. No se agregó: El Producto porque ya estaba registrado
	3. No se agregó: El Producto no existe en la lista de Producto
	*/
	// Devuleve true si se puede insertar
	// Devuelve false si no se inserto el estudiante ya esta en la lista


	Inventario * _inventario = new Inventario(_producto->getLinea(), _producto->getSubLinea(), _producto->getIdProducto(), _idAlmacen, 0);

	bool agregado = false;
	if (vacia())
	{
		setCab(new NInventario(_inventario));
		getCab()->setSgte(getCab());
		getCab()->setAnte(getCab());
		agregado = true;
	}
	else
	{
		int codArticulo = _inventario->getCodArticulo();
		NInventario * prim = getCab();
		NInventario * ult = getCab()->getAnte();

		if ((codArticulo < prim->getInventario()->getCodArticulo()) || (codArticulo > ult->getInventario()->getCodArticulo()))
		{
			agregaNInventarioDespuesDe(ult, new NInventario(_inventario));


			if (codArticulo < prim->getInventario()->getCodArticulo())
			{
				setCab(prim->getAnte());
			}
			agregado = true;
		}
		else
		{
			NInventario * aux = getCab();
			bool exist = false;
			do
			{

				if (codArticulo == aux->getInventario()->getCodArticulo())
				{
					exist = true;
				}

				if (codArticulo < aux->getSgte()->getInventario()->getCodArticulo())
				{
					agregaNInventarioDespuesDe(aux, new NInventario(_inventario));
					agregado = true;
				}
				else
				{
					aux = aux->getSgte();
				}
			} while ((aux != getCab()) && !exist);
		}
	}
	if (agregado)
	{
		setSize(getSize() + 1);

	}
	return agregado;
}

Inventario * LstInventario::buscarArticulo(int _idLinea, int _idSublinea, int _idProducto)
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		NInventario * aux = getCab();

		do
		{
			if ((aux->getInventario()->getCodLinea() == _idLinea) && (aux->getInventario()->getCodSubLinea() == _idSublinea) && (aux->getInventario()->getCodArticulo() == _idProducto))
			{
				return aux->getInventario();
			}
			else
			{
				aux = aux->getSgte();
			}
		} while (aux != getCab());
		return NULL;
	}
}

bool LstInventario::aumentarExistencia(int _idLinea, int _idSublinea, int _idProducto, int _existencia)
{
	Inventario * articulo = buscarArticulo(_idLinea, _idSublinea, _idProducto);
	if(articulo == NULL)
	{
		return false;
	}
	else
	{
		articulo->setExistencia(articulo->getExistencia() + _existencia);
		return true;
	}
}
