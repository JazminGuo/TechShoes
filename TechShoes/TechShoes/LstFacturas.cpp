#include "LstFacturas.h"



LstFacturas::LstFacturas()
{
	setCab(NULL);
	setSize(0);
}


LstFacturas::~LstFacturas()
{
}


NFactura * LstFacturas::getCab()
{
	return this->cab;
}

void LstFacturas::setCab(NFactura * _ptr)
{
	this->cab = _ptr;
}

int LstFacturas::getSize()
{
	return this->size;
}

void LstFacturas::setSize(int _size)
{
	this->size = _size;
}

//Miscelaneos Privados
NFactura * LstFacturas::dirNodo(int _idFactura)
{
	NFactura * aux = getCab();

	while ((aux != NULL) && (aux->getFactura()->getIdFactura() != _idFactura))
	{
		aux = aux->getSgte();
	}
	return aux;
}

NFactura * LstFacturas::dirUltimo()
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		NFactura * aux = getCab();

		while (aux->getSgte() != NULL)
		{
			aux = aux->getSgte();
		}
		return aux;
	}
}

NFactura * LstFacturas::dirAnterior(int _idFactura)
{
	NFactura * aux = getCab();
	NFactura * ant = NULL;

	if (vacia())
	{
		return NULL;
	}
	else 
	{

		if (getCab()->getFactura()->getIdFactura() == _idFactura)
		{
			ant = NULL;
		}
		else
		{
			while ((aux->getSgte() != NULL) && (aux->getFactura()->getIdFactura() != _idFactura))
			{
				ant = aux;
				aux = aux->getSgte();
			}
		}
		return ant;
	}
}

void LstFacturas::agregaNodoAntesDe(NFactura * _ref, NFactura * _nuevo)
{
	NFactura * ant = dirAnterior(_ref->getFactura()->getIdFactura());
	ant->setSgte(_nuevo);
	_nuevo->setSgte(_ref);
}

void LstFacturas::agregaNFacturaDespuesDe(NFactura * _ref, NFactura * _nuevo)
{
	_nuevo->setSgte(_ref->getSgte());
	_ref->setSgte(_nuevo);
}

//Operraciones de Listas
//Agregar
bool LstFacturas::agregaAsc(Factura * _factura)
{
	int id = _factura->getIdFactura();

	if ((vacia()) || (id < getCab()->getFactura()->getIdFactura()))
	{
		NFactura * nuevo = new NFactura(_factura);
		nuevo->setSgte(getCab());
		setCab(nuevo);
		setSize(getSize() + 1);
		return true;
	}
	else
	{
		NFactura * aux = getCab();
		while (aux != NULL)
		{
			if (aux->getFactura()->getIdFactura() == id)
			{
				return false;
			}
			else
			{
				NFactura * nuevo = new NFactura(_factura);
				if (((aux->getSgte() != NULL) && (aux->getSgte()->getFactura()->getIdFactura() > id)) || (aux->getSgte() == NULL))
				{
					agregaNFacturaDespuesDe(aux, nuevo);
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
}

//Eliminar
bool LstFacturas::eliminar(int _idFactura)
{
	NFactura * aux;
	if (vacia())
	{
		return false;
	}
	else
	{
		if (getCab()->getFactura()->getIdFactura() == _idFactura)
		{
			aux = getCab();
			setCab(aux->getSgte());
			delete aux;
			size--;
			return true;
		}
		else
		{
			NFactura * ant = dirAnterior(_idFactura);
			if (ant != NULL)
			{
				aux = ant->getSgte();
				ant->setSgte(aux->getSgte());
				delete aux;
				size--;
			}
			else
			{
				return false;
			}
		}
	}
}

//Miscelaneos
bool LstFacturas::vacia()
{
	return getCab() == NULL;
}

Factura * LstFacturas::obtenerFactura(int _idFactura)
{
	NFactura * aux = dirNodo(_idFactura);

	if (aux != NULL)
	{
		return aux->getFactura();
	}
	else
	{
		return NULL;
	}
}

bool LstFacturas::modificarFactura(int _id, Factura * _factura)
{
	NFactura *  aux = dirNodo(_id);
	
	if (aux == NULL)
	{
		return false;
	}
	else
	{
		aux->getFactura()->setIdFactura(_factura->getIdFactura());
		aux->getFactura()->setFecha(_factura->getFecha());
		aux->getFactura()->setCliente(_factura->getCliente());
		return true;
	}
}

void LstFacturas::desplegarLista()
{
	//Desplegar los datos de cada uno de los cursos.
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NFactura * aux = getCab();
		int i = 1;
		cout << "============================================" << endl;
		while (aux != NULL)
		{
			cout << "Factura #" << i << ": " << endl;
			cout << "Id: " << aux->getFactura()->getIdFactura() << endl;
			cout << "Fecha: " << aux->getFactura()->getFecha() << endl;
			cout << "Cliente: " << aux->getFactura()->getCliente() << endl;
			cout << "============================================" << endl;

			aux = aux->getSgte();
			i++;
		}
		cout << endl << "Fin de la Lista" << endl;
	}
	system("pause");
	system("cls");
}