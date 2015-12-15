#include "LstSubLineaProductos.h"

// Lista Doble Lineal


LstSubLineaProductos::LstSubLineaProductos()
{
	setCab(NULL);
	setSize(0);
}


LstSubLineaProductos::~LstSubLineaProductos()
{
}

// Getter y Setter
NSubLineaProducto *LstSubLineaProductos::getCab()
{
	return this->cab;
}
void LstSubLineaProductos::setCab(NSubLineaProducto *_ptr)
{
	this->cab = _ptr;  //cab 
}
int LstSubLineaProductos::getSize()
{
	return this->size;
}
void LstSubLineaProductos::setSize(int _size)
{
	this->size = _size;
}

bool LstSubLineaProductos::vacia()
{
	return getCab() == NULL;
}

// Métodos Privados
NSubLineaProducto *LstSubLineaProductos::dirNodo(int _idSubLinea)
{
	NSubLineaProducto *aux = getCab();
	while (aux != NULL)
	{
		if (_idSubLinea == aux->getSubLineaProducto()->getIdSubLinea())
			return aux;
		else
			aux = aux->getSgte();
	}
	return NULL;
}
NSubLineaProducto *LstSubLineaProductos::dirAnterior(int _idSubLinea)
{
	NSubLineaProducto *aux = dirNodo(_idSubLinea);
	if (aux != NULL)
	{
		if (aux == getCab())
			return aux;
		else
			return aux->getAnte();
	}
	else
		return NULL;
}
NSubLineaProducto *LstSubLineaProductos::dirUltimo(int _idSubLinea)
{
	NSubLineaProducto *aux = getCab();
	while (aux != NULL)
	{
		if (aux->getSgte() == NULL)
			return aux;
		else
			aux = aux->getSgte();
	}
	return NULL;
}
void LstSubLineaProductos::agregarNodoAntesDe(NSubLineaProducto *_nuevo, NSubLineaProducto *_aux)
{
	_nuevo->setSgte(_aux);
	_nuevo->setAnte(_aux->getAnte());

	if (_aux == getCab())
		setCab(_nuevo);
	else
	_aux->getAnte()->setSgte(_nuevo);
	_aux->setAnte(_nuevo);
	setSize(getSize() + 1);
}
void LstSubLineaProductos::agregarNodoDespuesDe(NSubLineaProducto *_nuevo, NSubLineaProducto *_aux)
{
	_nuevo->setSgte(_aux->getSgte());
	_nuevo->setAnte(_aux);

	if (_aux->getSgte() == NULL)
		_aux->setSgte(_nuevo);
	else
	_aux->getSgte()->setAnte(_nuevo);
	_aux->setSgte(_nuevo);
	setSize(getSize() + 1);
}


// Métodos Publicos

bool LstSubLineaProductos::agregar(SubLineaProducto *_subLineaProducto)
{
	NSubLineaProducto *nuevo = new NSubLineaProducto(_subLineaProducto);
	if (vacia())
	{
		nuevo->setSgte(getCab());
		setCab(nuevo);
		setSize(getSize() + 1);
		return true;
	}
	else
	{
		NSubLineaProducto *aux = getCab();
		int idSubLinea = _subLineaProducto->getIdSubLinea();

		while ((aux != NULL) && (aux->getSgte() != NULL))
		{
			if (idSubLinea == aux->getSubLineaProducto()->getIdSubLinea())
				return false;

			if (idSubLinea < aux->getSubLineaProducto()->getIdSubLinea())
			{
				agregarNodoAntesDe(nuevo, aux);
				return true;
			}
			else
				aux = aux->getSgte();
		}
		if (aux->getSgte() == NULL)
		{
			if (idSubLinea == aux->getSubLineaProducto()->getIdSubLinea())
				return false;

			if (idSubLinea < aux->getSubLineaProducto()->getIdSubLinea())
			{
				agregarNodoAntesDe(nuevo, aux);
				return true;
			}
			else
			{
				agregarNodoDespuesDe(nuevo, aux);
				return true;
			}
				
		}
	}
	return true;
		
}
bool LstSubLineaProductos::modificar(int _idSubLinea, SubLineaProducto *_subLineaProducto)
{
	if (vacia())
		return false;
	else
	{
		NSubLineaProducto * aux = dirNodo(_idSubLinea);
		if (aux != NULL)
		{
			aux->setSubLineaProducto(_subLineaProducto);
			return true;
		}
		else
			return false;
	}
	return true;
}

bool LstSubLineaProductos::eliminar(int _idSubLinea)
{
	NSubLineaProducto *aux1 = dirAnterior(_idSubLinea);
	

	if (aux1 != NULL)
	{
		if (getSize() == 1)
		{
			delete aux1;
			setCab(NULL);
			setSize(getSize() - 1);
			return true;
		}
		else
		{
			NSubLineaProducto *aux2 = aux1->getSgte();
			if (aux2->getSgte() == NULL)
			{
				aux1->setSgte(NULL);
				delete aux2;
				setSize(getSize() - 1);
				return true;
			}
			else
			{
				if (aux1 == getCab())
				{
					setCab(aux2);
					delete aux1;
					setSize(getSize() - 1);
					return true;
				}
				else
				{
					aux2->getSgte()->setAnte(aux1);
					aux1->setSgte(aux2->getSgte());
					delete aux2;
					setSize(getSize() - 1);
					return true;
				}
				
				
			}
			
		}
		
	}
	else
		return false;
	return true;
}
bool LstSubLineaProductos::eliminarTodos()
{
	NSubLineaProducto *aux = getCab();

	while (aux != NULL)
	{
		setCab(aux->getSgte());
		delete aux;
		setSize(getSize() - 1);
		aux = getCab();
	}
	return true;
}
SubLineaProducto *LstSubLineaProductos::buscar(int _idSubLinea)
{
	NSubLineaProducto *aux = dirNodo(_idSubLinea);
	if (aux != NULL)
		return aux->getSubLineaProducto();
	else
		return NULL;
	return NULL;
}



void LstSubLineaProductos::desplegar()
{
	NSubLineaProducto *aux = getCab();
	if (aux == NULL)
		cout << "La Lista esta vacio!!" << endl;
	else
	{
		cout << endl;
		cout << "-----------------------------------" << endl;

		while (aux != NULL)
		{
			cout << "ID SubLinea: " << aux->getSubLineaProducto()->getIdSubLinea() << endl;
			cout << "ID Linea: " << aux->getSubLineaProducto()->getIdLinea() << endl;
			cout << "Descripcion: " << aux->getSubLineaProducto()->getDescripcion() << endl;
			cout << "-----------------------------------" << endl;

			aux = aux->getSgte();
	    }
    }	
}

// * Metodos de Listas de Listas *//
int LstSubLineaProductos::agregarProducto(int _idSubLinea, Producto * _Producto)
{
	/*Este metodo agrega a _subLineaProducto en la Linea _idLineaProducto.
	El metodo devuelve:
	1. Si el se inserto correctamente.
	2. No se inserto por que el curso no existe
	3.No se inserto por que el estudiante ya existe
	*/

	NSubLineaProducto * aux = dirNodo(_idSubLinea);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getLstProductos()->agregar(_Producto))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

int LstSubLineaProductos::elimniarProducto(int _idSubLinea, int _idProducto)
{
	NSubLineaProducto * aux = dirNodo(_idSubLinea);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getLstProductos()->eliminar(_idProducto))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

Producto * LstSubLineaProductos::buscarProducto(int _idSubLinea, int _idProducto)
{
	NSubLineaProducto * aux = dirNodo(_idSubLinea);

	if (aux == NULL)
	{
		cout << "La Sublinea que esta bucando no existe" << endl;
	}
	else
	{
		Producto * _producto = aux->getLstProductos()->buscar(_idProducto);

		if (_producto == NULL)
		{
			cout << "El Producto que esta buscando no existe" << endl;
		}
		else
		{
			cout << "======================Producto========================" << endl;
			cout << "Id: " << _producto->getIdProducto() << endl;
			cout << "Descripcion: " << _producto->getDescripcion() << endl;
			cout << "Talla: " << _producto->getTalla() << endl;
			cout << "Id: " << _producto->getPrecio() << endl;
			cout << "Linea: " << _producto->getLinea() << endl;
			cout << "Sublinea: " << _producto->getSubLinea() << endl;
			cout << "======================================================" << endl;

			return _producto;
		}
	}
}

void LstSubLineaProductos::desplegarProductosDeSubLinea(int _idSubLineaProducto)
{
	NSubLineaProducto * aux = dirNodo(_idSubLineaProducto);

	cout << "=======================================================" << endl;
	cout << "ID: " << aux->getSubLineaProducto()->getIdSubLinea() << endl;
	cout << "Descripcion: " << aux->getSubLineaProducto()->getDescripcion() << endl;

	aux->getLstProductos()->desplegarLista();
}

void LstSubLineaProductos::desplegarSubLineasConProductos()
{
	//Desplegar los datos de cada uno de los cursos y cada uno de sus estudiantes.
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NSubLineaProducto * aux = getCab();
		int i = 1;
		cout << "============================================" << endl;
		while (aux != NULL)
		{
			cout << "Sublinea #" << i << ": " << endl;
			cout << "ID: " << aux->getSubLineaProducto()->getIdSubLinea() << endl;
			cout << "Descripcion: " << aux->getSubLineaProducto()->getDescripcion() << endl;
			cout << "Linea: " << aux->getSubLineaProducto()->getIdLinea() << endl;
			cout << "============================================" << endl;
			aux->getLstProductos()->desplegarLista();

			aux = aux->getSgte();
			i++;
		}
		cout << endl << "Fin de la Lista" << endl;
	}
	system("pause");
}