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
NAlmacen * LstAlmacenes::dirNodo(int _idAlmacen)
{
	NAlmacen * aux = getCab();

	while ((aux != NULL) && (aux->getAlmacen()->getIdAlmacen() != _idAlmacen))
	{
		aux = aux->getSgte();
	}
	return aux;
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

NAlmacen * LstAlmacenes::dirAnterior(int _idAlmacen)
{
	NAlmacen * aux = dirNodo(_idAlmacen);
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
bool LstAlmacenes::agregaAsc(Almacen * _almacen)
{
	int id = _almacen->getIdAlmacen();
	if (vacia())
	{
		NAlmacen * nuevo = new NAlmacen(_almacen);
		setCab(nuevo);
		setSize(getSize() + 1);
		return true;
	}
	else
	{
		NAlmacen * aux = getCab();
		while (aux != NULL)
		{
			if (aux->getAlmacen()->getIdAlmacen() == id)
			{
				return false;
			}
			else
			{
				NAlmacen * nuevo = new NAlmacen(_almacen);
				if (((aux->getSgte() != NULL) && (aux->getSgte()->getAlmacen()->getIdAlmacen() > id)) || (aux->getSgte() == NULL))
				{
					agregaNAlmacenDespuesDe(aux, nuevo);
					setSize(getSize() + 1);
					return true;
				}
				else
				{
					aux = aux->getSgte();
				}
			}
		}
	}
	return true;
}

//Eliminar
bool LstAlmacenes::eliminar(int _idAlmacen)
{
	NAlmacen * aux = dirNodo(_idAlmacen);
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
	system("pause");
	system("cls");
}