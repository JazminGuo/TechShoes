#include "LstProductos.h"


LstProductos::LstProductos()
{
	setCab(NULL);
	setSize(0);
}


LstProductos::~LstProductos()
{
}

NProducto * LstProductos::getCab()
{
	return this->cab;
}

void LstProductos::setCab(NProducto * _ptr)
{
	this->cab = _ptr;
}

int LstProductos::getSize()
{
	return this->size;
}

void LstProductos::setSize(int _size)
{
	this->size = _size;
}

//Miscelaneos Privados
NProducto * LstProductos::dirNodo(int _idProducto)
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		NProducto * aux = getCab();

		do
		{
			if (aux->getProducto()->getIdProducto() == _idProducto)
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

NProducto * LstProductos::dirUltimo()
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

NProducto * LstProductos::dirAnterior(int _idProducto)
{
	NProducto * aux = dirNodo(_idProducto);
	
	return aux->getAnte();
}

void LstProductos::agregaNodoAntesDe(NProducto * _ref, NProducto * _nuevo)
{
	_nuevo->setSgte(_ref);
	_nuevo->setAnte(_ref->getAnte());

	_ref->getAnte()->setSgte(_nuevo);
	_ref->setAnte(_nuevo);
}

void LstProductos::agregaNProductoDespuesDe(NProducto * _ref, NProducto * _nuevo)
{
	_nuevo->setSgte(_ref->getSgte());
	_nuevo->setAnte(_ref);

	_ref->getSgte()->setAnte(_nuevo);
	_ref->setSgte(_nuevo);
}

//Operraciones de Listas
//Agregar
bool LstProductos::agregaAsc(Producto * _producto)
{
	// Devuleve true si se puede insertar
	//Devuelve false si no se inserto el estudiante ya esta en la lista
	bool agregado = false;
	if (vacia())
	{
		setCab(new NProducto(_producto));
		getCab()->setSgte(getCab());
		getCab()->setAnte(getCab());
		
		agregado = true;
	}
	else
	{
		int id = _producto->getIdProducto();
		NProducto * prim = getCab();
		NProducto * ult = getCab()->getAnte();

		if ((id < prim->getProducto()->getIdProducto()) || (id > ult->getProducto()->getIdProducto()))
		{
			agregaNProductoDespuesDe(ult, new NProducto(_producto));
			
			if (id < prim->getProducto()->getIdProducto())
			{
				setCab(prim->getAnte());
			}
			agregado = true;
		}
		else
		{
			NProducto * aux = getCab();
			bool exist = false;
			do
			{

				if (id == aux->getProducto()->getIdProducto())
				{
					exist = true;
				}

				if (id < aux->getSgte()->getProducto()->getIdProducto())
				{
					agregaNProductoDespuesDe(aux, new NProducto(_producto));
					
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
bool LstProductos::eliminar(int _idProducto)
{
	NProducto * aux = dirNodo(_idProducto);

	if ( aux != NULL)
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
bool LstProductos::vacia()
{
	return getCab() == NULL;
}

Producto * LstProductos::obtenerProducto(int _idProducto)
{
	NProducto * aux = dirNodo(_idProducto);

	if ((aux != NULL) && (aux->getProducto()->getIdProducto() == _idProducto))
	{
		return aux->getProducto();
	}		
}

bool LstProductos::modificarProducto(int _idProducto, Producto * _producto)
{
	if (vacia())
	{
		return false;
	}
	else
	{
		NProducto * aux = dirNodo(_idProducto);

		if (aux != NULL)
		{
			aux->getProducto()->setIdProducto(_producto->getIdProducto());
			aux->getProducto()->setDescripcion(_producto->getDescripcion());
			aux->getProducto()->setTalla(_producto->getTalla());
			aux->getProducto()->setPrecio(_producto->getPrecio());
			return true;
		}
		else
		{
			return false;
		}
	}
}

void LstProductos::desplegarLista()
{
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NProducto * aux = getCab();
		int i = 1;
		cout << "============================================" << endl;
		do
		{
			cout << "Producto #" << i << ": " << endl;
			cout << "Id: " << aux->getProducto()->getIdProducto() << endl;
			cout << "Descripcion: " << aux->getProducto()->getDescripcion() << endl;
			cout << "Talla: " << aux->getProducto()->getTalla() << endl;
			cout << "Precio: " << aux->getProducto()->getPrecio() << endl;
			cout << "============================================" << endl;
			aux = aux->getSgte();
			i++;
		} while (aux != getCab());
		cout << endl << "Fin de la Lista" << endl;
	}
	system("pause");
	system("cls");
}

