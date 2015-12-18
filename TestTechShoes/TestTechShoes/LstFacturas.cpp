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
	return true;
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
	return true;
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

int LstFacturas::ultimaFactura() 
{
	if (vacia())
	{
		return 0;
	}
	else
	{
		NFactura * aux = dirUltimo();

		return aux->getFactura()->getIdFactura();
	}
}

// * Metodos de Listas de Listas  LineaFactura*//
int LstFacturas::agregarLineaFactura(int _idFactura, LineaFactura * _lineaFactura)
{
	/*Este metodo agrega a _lineaFactura en la Linea _idFactura.
	El metodo devuelve:
	1. Si el se inserto correctamente.
	2. No se inserto por que el curso no existe
	3.No se inserto por que el estudiante ya existe
	*/

	NFactura * aux = dirNodo(_idFactura);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getLstLineasF()->agregar(_lineaFactura))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

int LstFacturas::elimniarLineaFactura(int _idFactura, int _numLinea)
{
	NFactura * aux = dirNodo(_idFactura);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getLstLineasF()->eliminar(_numLinea))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

LineaFactura * LstFacturas::buscarLineaFactura(int _idFactura, int _numLinea)
{
	NFactura * aux = dirNodo(_idFactura);

	if (aux == NULL)
	{
		cout << "La linea que esta bucando no existe" << endl;
	}
	else
	{
		LineaFactura * _lineaFactura = aux->getLstLineasF()->buscar(_numLinea);

		if (_lineaFactura == NULL)
		{
			cout << "La sublinea que esta buscando no existe" << endl;
		}
		else
		{
			cout << "======================Linea Factura========================" << endl;
			cout << "No Linea: " << _lineaFactura->getNumFLinea() << endl;
			cout << "Codigo: " << _lineaFactura->getIdLinea() << "-" << _lineaFactura->getIdSublinea() << "-" << _lineaFactura->getIdProducto();
			cout << "Linea: " << _lineaFactura->getIdLinea() << endl;
			cout << "======================================================" << endl;
			return _lineaFactura;
		}
	}
}

void LstFacturas::desplegarLineasdeFactura(int _idFactura)
{
	NFactura * aux = dirNodo(_idFactura);

	cout << "=======================================================" << endl;
	cout << "No. Factura: " << aux->getFactura()->getIdFactura() << endl;
	cout << "Cliente: " << aux->getFactura()->getCliente() << endl;
	cout << "Fecha: " << aux->getFactura()->getFecha() << endl;

	aux->getLstLineasF()->desplegar();
}

void LstFacturas::desplegarFacturasConLinea()
{
	//Desplegar los datos de cada uno de los cursos y cada uno de sus estudiantes.
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NFactura * aux = getCab();
		int i = 1;
		cout << "============================================" << endl;

		do
		{
			cout << "Factura #" << i << ": " << endl;
			cout << "No. Factura: " << aux->getFactura()->getIdFactura() << endl;
			cout << "Cliente: " << aux->getFactura()->getCliente() << endl;
			cout << "Fecha: " << aux->getFactura()->getFecha() << endl;
			cout << "============================================" << endl;
			aux->getLstLineasF()->desplegar();

			aux = aux->getSgte();
			i++;
		} while (aux != getCab());
		cout << endl << "Fin de la Lista" << endl;
	}
	system("pause");
}

int LstFacturas::ultimaLinea(int _idFactura)
{
	NFactura * aux = dirNodo(_idFactura);

	return aux->getLstLineasF()->ultimaLinea();
}