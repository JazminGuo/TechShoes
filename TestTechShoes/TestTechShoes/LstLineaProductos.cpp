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

NLineaProducto *LstLineaProductos::dirNodo(int _idLineaProducto)
{
	NLineaProducto *aux = getCab();

	if (vacia())
		return false;
	else
	{
		do
		{
			if (_idLineaProducto == aux->getLineaProducto()->getIdLineaProducto())
			{
				return aux;
			}
			else
				aux = aux->getSgte();
		} while (aux != getCab());
	}
	return NULL;
}
NProducto *LstLineaProductos::dirNodoLSP(int _idLinea, int _subLinea, int _idProducto)
{
	NLineaProducto *auxLineaProducto = dirNodo(_idLinea);
	if (auxLineaProducto != NULL)
	{
		NSubLineaProducto *auxSubLinea = auxLineaProducto->getLstSubLineaProductos()->dirNodo(_subLinea);
		if (auxSubLinea != NULL)
		{
			return auxSubLinea->getLstProductos()->dirNodo(_idProducto);
		}
		else
			return NULL;
	}
	else
		return NULL;
	return NULL;
}
NLineaProducto *LstLineaProductos::dirAnterior(int _idLineaProducto)
{
	return NULL;
}
NLineaProducto *LstLineaProductos::dirUltimo(int _idLineaProducto)
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
		int id = _lineaProducto->getIdLineaProducto();
		NLineaProducto *primero = getCab();
		NLineaProducto *ultimo = getCab()->getAnte();

		if (id < primero->getLineaProducto()->getIdLineaProducto() || id > ultimo->getLineaProducto()->getIdLineaProducto())
		{
			if (id < primero->getLineaProducto()->getIdLineaProducto())
				agregarNodoAntesDe(nuevo, primero);
			if (id > ultimo->getLineaProducto()->getIdLineaProducto())
				agregarNodoDespuesDe(nuevo, ultimo);
		}
		else
		{
			NLineaProducto *aux = getCab();

			do
			{
				if (id == aux->getLineaProducto()->getIdLineaProducto())
				{
					//cout << "Ya existe el id " << id << " en registro!" << endl;
					return false;
				}

				if (id < aux->getSgte()->getLineaProducto()->getIdLineaProducto())
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

bool LstLineaProductos::modificar(int _idLineaProducto, LineaProducto *_lineaProducto)
{
	if (vacia())
		return false;
	else
	{
		NLineaProducto *aux = dirNodo(_idLineaProducto);
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

bool LstLineaProductos::eliminar(int _idLineaProducto)
{
	if (vacia())
		return false;
	else
	{
		NLineaProducto *aux = dirNodo(_idLineaProducto);
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

LineaProducto *LstLineaProductos::buscar(int _idLineaProducto)
{
	NLineaProducto *aux = dirNodo(_idLineaProducto);
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
			cout << "ID: " << aux->getLineaProducto()->getIdLineaProducto() << endl;
			cout << "Descripcion: " << aux->getLineaProducto()->getDescripcion() << endl;
			cout << "-----------------------------------"<< endl;

			aux = aux->getSgte();

		} while (aux != getCab());
	}
}

bool LstLineaProductos::dirNodoGlobal(int _idLinea, int _iSublinea, int _idProducto)
{
	bool exist = false;

	if (dirNodo(_idLinea) != NULL)
	{
		if (dirNodo(_idLinea)->getLstSubLineaProductos()->dirNodo(_iSublinea) != NULL)
		{
			if (dirNodo(_idLinea)->getLstSubLineaProductos()->dirNodo(_iSublinea)->getLstProductos()->dirNodo(_idProducto) != NULL)
			{
				exist = true;
			}
			else
			{
				exist;
			}
		}
		else
		{
			exist;
		}
	}
	else
	{
		exist;
	}
	return exist;
}

// * Metodos de Listas de Listas  SubLinea*//
int LstLineaProductos::agregarSubLinea(int _idLineaProducto, SubLineaProducto * _subLineaProducto)
{
	/*Este metodo agrega a _subLineaProducto en la Linea _idLineaProducto.
	El metodo devuelve:
	1. Si el se inserto correctamente.
	2. No se inserto por que el curso no existe
	3.No se inserto por que el estudiante ya existe
	*/

	NLineaProducto * aux = dirNodo(_idLineaProducto);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getLstSubLineaProductos()->agregar(_subLineaProducto))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

int LstLineaProductos::elimniarSubLinea(int _idLineaProducto, int _idSubLineaProducto)
{
	NLineaProducto * aux = dirNodo(_idLineaProducto);

	if (aux == NULL)
	{
		return 2;
	}
	else
	{
		if (aux->getLstSubLineaProductos()->eliminar(_idSubLineaProducto))
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
}

SubLineaProducto * LstLineaProductos::buscarSublinea(int _idLineaProducto, int _idSubLineaProducto)
{
	NLineaProducto * aux = dirNodo(_idLineaProducto);

	if (aux == NULL)
	{
		cout << "La linea que esta bucando no existe" << endl;
	}
	else
	{
		SubLineaProducto * _subLinea = aux->getLstSubLineaProductos()->buscar(_idSubLineaProducto);

		if (_subLinea == NULL)
		{
			cout << "La sublinea que esta buscando no existe" << endl;
		}
		else
		{
			cout << "======================SubLinea========================" << endl;
			cout << "Id: " << _subLinea->getIdLinea() << endl;
			cout << "Descripcion: " << _subLinea->getDescripcion() << endl;
			cout << "Linea: " << _subLinea->getIdLinea() << endl;
			cout << "======================================================" << endl;
			return _subLinea;
		}
	}
}

void LstLineaProductos::desplegarSubLineasDeLinea(int _idLineaProducto)
{
	NLineaProducto * aux = dirNodo(_idLineaProducto);
	if (aux != NULL)
	{
		cout << "=======================================================" << endl;
		cout << "ID: " << aux->getLineaProducto()->getIdLineaProducto() << endl;
		cout << "Descripcion: " << aux->getLineaProducto()->getDescripcion() << endl;


		aux->getLstSubLineaProductos()->desplegar();
	}
	else
	{
		cout << "La Lista Linea de Producto esta vacia!" << endl;
		cout << endl;
	}
}


void LstLineaProductos::desplegarLineasConSubLineas()
{
	//Desplegar los datos de cada uno de los cursos y cada uno de sus estudiantes.
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		NLineaProducto * aux = getCab();
		int i = 1;
		cout << "============================================" << endl;

		do
		{
			cout << "Linea #" << i << ": " << endl;
			cout << "ID: " << aux->getLineaProducto()->getIdLineaProducto() << endl;
			cout << "Descripcion: " << aux->getLineaProducto()->getDescripcion() << endl;
			cout << "============================================" << endl;
			aux->getLstSubLineaProductos()->desplegar();

			aux = aux->getSgte();
			i++;
		} while (aux != getCab());
		cout << endl << "Fin de la Lista" << endl;
	}
	system("pause");
}


// * Metodos de Listas de Listas  Producto*//
int LstLineaProductos::agregarProducto(int _idLinea, int _idSubLinea, Producto * _producto)
{
	NLineaProducto * aux = dirNodo(_idLinea);

	if (aux == NULL)
	{
		return 4;
	}
	else
	{
		return aux->getLstSubLineaProductos()->agregarProducto(_idSubLinea, _producto);
	}
}

int LstLineaProductos::elimniarProducto(int _idLinea, int _idSubLinea, int _idProducto)
{
	NLineaProducto * aux = dirNodo(_idLinea);

	if (aux == NULL)
	{
		return 4;
	}
	else
	{
		return aux->getLstSubLineaProductos()->elimniarProducto(_idSubLinea, _idProducto);
	}
}

Producto * LstLineaProductos::buscarProducto(int _idLinea, int _idSubLinea, int _idProducto)
{
	NLineaProducto * aux = dirNodo(_idLinea);

	if (aux == NULL)
	{
		return NULL;
	}
	else
	{
		return aux->getLstSubLineaProductos()->buscarProducto(_idSubLinea, _idProducto);
	}
}

void LstLineaProductos::desplegarProductosDeSubLinea(int _idLinea, int _idSubLinea)
{
	NLineaProducto * aux = dirNodo(_idLinea);
	if (aux != NULL)
	{
		aux->getLstSubLineaProductos()->desplegarProductosDeSubLinea(_idSubLinea);
	}
	else
	{
		cout << "La Lista Linea de Producto esta vacia!" << endl;
		cout << endl;
	}
	
}

void LstLineaProductos::desplegarSubLineasConProductos(int _idLinea)
{
	NLineaProducto * aux = dirNodo(_idLinea);
	if (aux != NULL)
	{
		aux->getLstSubLineaProductos()->desplegarSubLineasConProductos();
	}
	else
	{
		cout << "La Lista Linea de Producto esta vacia!" << endl;
		cout << endl;
	}
}