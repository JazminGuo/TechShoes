#include "LstLineaFacturas.h"



LstLineaFacturas::LstLineaFacturas()
{
	setCab(NULL);
	setSize(0);
}


LstLineaFacturas::~LstLineaFacturas()
{
}

// Getter y Setter
NLineaFactura * LstLineaFacturas::getCab()
{
	return this->cab;
}
void LstLineaFacturas::setCab(NLineaFactura *_ptr)
{
	this->cab = _ptr;  //cab 
}
int LstLineaFacturas::getSize()
{
	return this->size;
}
void LstLineaFacturas::setSize(int _size)
{
	this->size = _size;
}

bool LstLineaFacturas::vacia()
{
	return getCab() == NULL;
}

// Métodos Privados
NLineaFactura * LstLineaFacturas::dirNodo(int _idLineaFactura)
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		NLineaFactura * aux = getCab();
		while (aux != NULL)
		{
			if (_idLineaFactura == aux->getLineaFactura()->getNumFLinea())
			{
				return aux;
			}

			else
			{
				aux = aux->getSgte();
			}
		}
	}
	return NULL;
}

NLineaFactura *LstLineaFacturas::dirAnterior(int _idLineaFactura)
{
	NLineaFactura *aux = dirNodo(_idLineaFactura);
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
NLineaFactura * LstLineaFacturas::dirUltimo()
{
	if (vacia())
	{
		return NULL;
	}
	else
	{
		NLineaFactura * aux = getCab();
		while (aux->getSgte() != NULL)
		{
			aux = aux->getSgte();
		}
		return aux;
	}
	return NULL;
}
void LstLineaFacturas::agregarNodoAntesDe(NLineaFactura *_nuevo, NLineaFactura *_aux)
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
void LstLineaFacturas::agregarNodoDespuesDe(NLineaFactura *_nuevo, NLineaFactura *_aux)
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

bool LstLineaFacturas::agregar(LineaFactura *_lineaFactura)
{
	NLineaFactura *nuevo = new NLineaFactura(_lineaFactura);
	if (vacia())
	{
		nuevo->setSgte(getCab());
		setCab(nuevo);
		setSize(getSize() + 1);
		return true;
	}
	else
	{
		NLineaFactura *aux = getCab();
		int idLineaFactura = _lineaFactura->getNumFLinea();

		while ((aux != NULL) && (aux->getSgte() != NULL))
		{
			if (idLineaFactura == aux->getLineaFactura()->getNumFLinea())
				return false;

			if (idLineaFactura < aux->getLineaFactura()->getNumFLinea())
			{
				agregarNodoAntesDe(nuevo, aux);
				return true;
			}
			else
				aux = aux->getSgte();
		}
		if (aux->getSgte() == NULL)
		{
			if (idLineaFactura == aux->getLineaFactura()->getNumFLinea())
				return false;

			if (idLineaFactura < aux->getLineaFactura()->getNumFLinea())
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
bool LstLineaFacturas::modificar(int _idLineaFactura, LineaFactura * _lineaFactura)
{
	if (vacia())
		return false;
	else
	{
		NLineaFactura *aux = dirNodo(_idLineaFactura);
		if (aux != NULL)
		{
			aux->setLineaFactura(_lineaFactura);
			return true;
		}
		else
			return false;
	}
	return true;
}
bool LstLineaFacturas::eliminar(int _idLineaFactura)
{
	NLineaFactura *aux1 = dirAnterior(_idLineaFactura);
	

	if (aux1 == NULL)
		return false;
	else
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
			NLineaFactura *aux2 = aux1->getSgte();
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

	return true;
}
bool LstLineaFacturas::eliminarTodos()
{
	NLineaFactura *aux = getCab();

	while (aux != NULL)
	{
		setCab(aux->getSgte());
		delete aux;
		setSize(getSize() - 1);
		aux = getCab();
	}
	return true;
}
LineaFactura *LstLineaFacturas::buscar(int _idLineaFactura)
{
	NLineaFactura *aux = dirNodo(_idLineaFactura);
	if (aux != NULL)
		return aux->getLineaFactura();
	else
		return NULL;
	return NULL;
}


void LstLineaFacturas::desplegar(LstLineaProductos * _lstLineaProducto)
{
	NLineaFactura * aux = getCab();

	if(aux == NULL)
		cout << "No hay lineas en la Factura" << endl;
	else
	{
		double total = 0;
		cout << endl;
		cout << "No. Linea:" << "     " << "Codigo:" << "     " << "Cantidad:" << "     " << "Descripcion:" << "     " << "Talla:" << "     " << "Precio Unitario:" << "     " << "Subtotal:" << endl;
		cout << "__________________________________________________________________________________________________________________" << endl;
		while (aux != NULL)
		{
			Producto * producto = _lstLineaProducto->buscarProducto(aux->getLineaFactura()->getIdLinea(), aux->getLineaFactura()->getIdSublinea(), aux->getLineaFactura()->getIdProducto());
			
			double subtotal = producto->getPrecio() * aux->getLineaFactura()->getCantidad();

			cout << "   " << aux->getLineaFactura()->getNumFLinea(); cout << "           " << aux->getLineaFactura()->getIdLinea() << "-" << aux->getLineaFactura()->getIdSublinea() << "-" << aux->getLineaFactura()->getIdProducto(); cout << "          " << aux->getLineaFactura()->getCantidad(); cout << "          " << producto->getDescripcion(); cout << "              " << producto->getTalla(); cout << "          " << producto->getPrecio(); cout << "               " << producto->getPrecio() * aux->getLineaFactura()->getCantidad() << endl;
			cout << "__________________________________________________________________________________________________________________" << endl;

			total = total += subtotal;
			aux = aux->getSgte();
		}
		cout << "Total: " << total << endl;
		cout << "==================================================================================================================" << endl;
	}
}

int LstLineaFacturas::ultimaLinea() 
{
	if (vacia())
	{
		return 0;
	}
	else
	{
		NLineaFactura * aux = dirUltimo();

		if (aux == NULL)
		{
			return 0;
		}
		else
		{
			return aux->getLineaFactura()->getNumFLinea();
		}
	}
	return 0;
}