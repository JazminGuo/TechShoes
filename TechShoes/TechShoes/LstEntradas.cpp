#include "LstEntradas.h"

// Lista Simple


LstEntradas::LstEntradas()
{
	setCab(NULL);
	setSize(0);
}


LstEntradas::~LstEntradas()
{
}

// Getter y Setter
NEntrada *LstEntradas::getCab()
{
	return this->cab;
}
void LstEntradas::setCab(NEntrada *_ptr)
{
	this->cab = _ptr;  //cab 
}
int LstEntradas::getSize()
{
	return this->size;
}
void LstEntradas::setSize(int _size)
{
	this->size = _size;
}

bool LstEntradas::vacia()
{
	return getCab() == NULL;
}

// Métodos Privados
NEntrada *LstEntradas::dirNodo(int _idProducto)
{
	NEntrada *aux = getCab();
	while (aux != NULL)
	{
		if (_idProducto == aux->getEntrada()->getIdProducto())
			return aux;
		else
			aux = aux->getSgte();
	}
	return NULL;
}
NEntrada *LstEntradas::dirAnterior(int _idProducto)
{
	NEntrada * aux = getCab();
	NEntrada * ant = NULL;

	if (vacia())
		return NULL;
	else
	{
		if (_idProducto == getCab()->getEntrada()->getIdProducto())
		{
			return NULL;
		}
		else
		{
			while ((aux->getSgte() != NULL) && (aux->getEntrada()->getIdProducto() != _idProducto))
			{
				ant = aux;
				aux = aux->getSgte();
			}
		}
		return ant;
		
	}
	return NULL;
}
NEntrada *LstEntradas::dirUltimo(int _idProducto)
{
	if (vacia())
		return NULL;
	else
	{
		NEntrada *aux = getCab();
		while (aux->getSgte() != NULL)
			aux = aux->getSgte();
		return aux;
	}
	return NULL;
}
void LstEntradas::agregarNodoAntesDe(NEntrada *_nuevo, NEntrada *_aux)
{
	NEntrada *ant = dirAnterior(_aux->getEntrada()->getIdProducto());

	_nuevo->setSgte(_aux);
	

	if (_aux == getCab())
		setCab(_nuevo);
	else
		ant->setSgte(_nuevo);
	setSize(getSize() + 1);
}
void LstEntradas::agregarNodoDespuesDe(NEntrada *_nuevo, NEntrada *_aux)
{
	_nuevo->setSgte(_aux->getSgte());
	_aux->setSgte(_nuevo);

	setSize(getSize() + 1);
}

// Métodos Publicos
bool LstEntradas::agregar(Entrada *_entrada)
{
	NEntrada *nuevo = new NEntrada(_entrada);
	if (vacia())
	{
		nuevo->setSgte(getCab());
		setCab(nuevo);
		setSize(getSize() + 1);
		return true;
	}
	else
	{
		NEntrada *aux = getCab();
		int idProducto = _entrada->getIdProducto();

		while ((aux != NULL) && (aux->getSgte() != NULL))
		{
			if (idProducto == aux->getEntrada()->getIdProducto())
				return false;

			if (idProducto < aux->getEntrada()->getIdProducto())
			{
				agregarNodoAntesDe(nuevo, aux);
				return true;
			}
			else
				aux = aux->getSgte();
		}
		if (aux->getSgte() == NULL)
		{
			if (idProducto == aux->getEntrada()->getIdProducto())
				return false;

			if (idProducto < aux->getEntrada()->getIdProducto())
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
bool LstEntradas::modificar(int _idProducto, Entrada *_entrada)
{
	NEntrada *aux = dirNodo(_idProducto);

	if (aux != NULL)
		aux->setEntrada(_entrada);
	else
		return false;
	return true;
}
bool LstEntradas::eliminar(int _idProducto)
{
	if (vacia())
		return false;
	else
	{
		NEntrada *aux = getCab();
		if (_idProducto == getCab()->getEntrada()->getIdProducto())
		{
			getCab()->setSgte(getCab()->getSgte());
			setCab(getCab()->getSgte());
			delete aux;
			setSize(getSize() - 1);
			aux = getCab();
			return true;
		}
		else
		{
			NEntrada *ant = dirAnterior(_idProducto);
			aux = ant->getSgte();
			if (ant != NULL)
			{
				ant->setSgte(aux->getSgte());
				delete aux;
				setSize(getSize() - 1);
				return true;
			}
			else
				return false;
		}
	}
	return true;
}
bool LstEntradas::eliminarTodos() 
{
	NEntrada *aux1 = getCab();

	while (aux1 != NULL)
	{
		setCab(aux1->getSgte());
		delete aux1;
		setSize(getSize() - 1);
		aux1 = getCab();
	}
	return true;
}
Entrada *LstEntradas::buscar(int _idProducto)
{
	NEntrada *aux = dirNodo(_idProducto);
	if (aux != NULL)
		return aux->getEntrada();
	else
		return NULL;
	return NULL;
}
void LstEntradas::desplegar()
{
	NEntrada *aux = getCab();
	if(aux == NULL)
		cout << "La Lista esta vacio!!" << endl;
	else
	{
		cout << endl;
		cout << "-----------------------------------" << endl;
		while (aux != NULL)
		{
			cout << "ID Producto: " << aux->getEntrada()->getIdProducto() << endl;
			cout << "Cantidades Productos: " << aux->getEntrada()->getCantidadProducto() << endl;
			cout << "-----------------------------------" << endl;

			aux = aux->getSgte();

		}
	}
}