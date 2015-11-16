#include "LstLineaProductos.h"

// LineaProducto es Circular

LstLineaProductos::LstLineaProductos()
{
	setSize(0);
	setCab(NULL);
}


LstLineaProductos::~LstLineaProductos()
{
}

// Getter y Setter
NLineaProducto *LstLineaProductos::getCab()
{
	return this->cab;
}
void LstLineaProductos::setCab(NLineaProducto *_ptr)
{
	this->cab = _ptr;  //cab 
}
int LstLineaProductos::getSize()
{
	return this->size;
}
void LstLineaProductos::setSize(int _size)
{
	this->size = _size;
}

bool LstLineaProductos::vacia()
{
	return getCab() == NULL;
}

// Métodos Privados
NLineaProducto *LstLineaProductos::dirNodo(int _idProducto)
{
	NLineaProducto *aux = getCab();

	if (vacia())
		return false;
	else
	{
		do
		{
			if (_idProducto == aux->getLineaProducto()->getIdProducto())
			{
				return aux;
			}
			else
				aux = aux->getSgte();
		} while (aux != getCab());
	}
	return NULL;
}
NLineaProducto *LstLineaProductos::dirAnterior(int _idProducto)
{
	return NULL;
}
NLineaProducto *LstLineaProductos::dirUltimo(int _idProducto)
{
	NLineaProducto *aux = getCab();
	do
	{
		aux = aux->getSgte();
	} while (aux != getCab());
	return aux;
}
void LstLineaProductos::agregarNodoAntesDe(NLineaProducto *_nuevo, NLineaProducto *_aux)
{
	_nuevo->setSgte(_aux);
	_nuevo->setAnte(_aux->getAnte());

	_aux->getAnte()->setSgte(_nuevo);
	_aux->setAnte(_nuevo);

	if (_aux == getCab())
		setCab(_nuevo);
	setSize(getSize() + 1);
}
void LstLineaProductos::agregarNodoDespuesDe(NLineaProducto *_nuevo, NLineaProducto *_aux)
{
	_nuevo->setSgte(_aux->getSgte());
	_nuevo->setAnte(_aux);

	_aux->getSgte()->setAnte(_nuevo);
	_aux->setSgte(_nuevo);

	setSize(getSize() + 1);
}

// Métodos CRUD
bool LstLineaProductos::agregar(LineaProducto *_lineaProducto)
{
	NLineaProducto *nuevo = new NLineaProducto(_lineaProducto);
	if (vacia())
	{
		setCab(nuevo);
		getCab()->setSgte(getCab());
		getCab()->setAnte(getCab());
		setSize(getSize() + 1);
	}
	else
	{
		int id = _lineaProducto->getIdProducto();
		NLineaProducto *primero = getCab();
		NLineaProducto *ultimo = getCab()->getAnte();

		if (id < primero->getLineaProducto()->getIdProducto() || id > ultimo->getLineaProducto()->getIdProducto())
		{
			if (id < primero->getLineaProducto()->getIdProducto())
				agregarNodoAntesDe(nuevo, primero);
			if (id > ultimo->getLineaProducto()->getIdProducto())
				agregarNodoDespuesDe(nuevo, ultimo);
		}
		else
		{
			NLineaProducto *aux = getCab();

			do
			{
				if (id == aux->getLineaProducto()->getIdProducto())
				{
					//cout << "Ya existe el id " << id << " en registro!" << endl;
					return false;
				}

				if (id < aux->getSgte()->getLineaProducto()->getIdProducto())
				{
					agregarNodoAntesDe(nuevo, aux->getSgte());
					return true;
				}
				else
				{
					aux = aux->getSgte();
				}

			} while (aux != getCab());		
		} // end Segundo else 
	} // end Principal else
	return true;
}  // end método agregar ascendente!
bool LstLineaProductos::modificar(int _idProducto, LineaProducto *_lineaProducto)
{
	if (vacia())
		return false;
	else
	{
		NLineaProducto *aux = dirNodo(_idProducto);
		if (aux != NULL)
		{
			aux->setLineaProducto(_lineaProducto);
			return true;
		}
		else
			return false;

	}
	return true;
}
bool LstLineaProductos::eliminar(int _idProdcuto)
{
	if (vacia())
		return false;
	else
	{
		NLineaProducto *aux = dirNodo(_idProdcuto);
		if (aux != NULL)
		{
			if (getSize() == 1)
			{
				aux->getSgte()->setAnte(aux->getAnte());
				aux->getAnte()->setSgte(aux->getSgte());
				delete aux;
				setCab(NULL);
				setSize(getSize() - 1);
			}
			else
			{
				if (aux == getCab())
				{
					aux->getSgte()->setAnte(aux->getAnte());
					aux->getAnte()->setSgte(aux->getSgte());

					setCab(aux->getSgte());
					delete aux;
					setSize(getSize() - 1);
					aux = getCab();
				}
				else
				{
					aux->getSgte()->setAnte(aux->getAnte());
					aux->getAnte()->setSgte(aux->getSgte());
					delete aux;
					setSize(getSize() - 1);
				}

			}
		}
		else
			return false;
	} // end else principal
	return true;
}
bool LstLineaProductos::eliminarTodos()
{
	if (vacia())
		return false;
	else
	{
		NLineaProducto *aux = getCab();
		do
		{	
			if (getSize() == 1)
			{
				delete aux;
				setCab(NULL);
				aux = getCab();
			}
			else
			{
				aux->getSgte()->setAnte(aux->getAnte());
				aux->getAnte()->setSgte(aux->getSgte());
				setCab(aux->getSgte());
				
				delete aux;
				aux = getCab();
			}
			
			setSize(getSize() - 1);
		} while (aux != NULL);		
	}
	return true;
}
LineaProducto *LstLineaProductos::buscar(int _idProducto)
{
	NLineaProducto *aux = dirNodo(_idProducto);
	if (aux == NULL)
		return NULL;
	else
		return aux->getLineaProducto();
}
void LstLineaProductos::desplegar()
{
	NLineaProducto *aux = getCab();
	if (aux == NULL)
	{
		cout << "La Lista esta Vacia !!" << endl;
	}
	else
	{
		cout << endl;
		cout << "-----------------------------------" << endl;
		do
		{
			cout << "ID: " << aux->getLineaProducto()->getIdProducto() << endl;
			cout << "Descripcion: " << aux->getLineaProducto()->getDescripcion() << endl;
			cout << "-----------------------------------"<< endl;

			aux = aux->getSgte();

		} while (aux != getCab());
	}
	
}