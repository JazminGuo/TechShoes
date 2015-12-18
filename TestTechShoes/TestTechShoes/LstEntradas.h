#pragma once
#include "NEntrada.h"
class LstEntradas
{
private:
	NEntrada *cab;
	int size;

	// Métodos Privados
	NEntrada *dirNodo(int);
	NEntrada *dirAnterior(int);
	NEntrada *dirUltimo(int);
	void agregarNodoAntesDe(NEntrada *, NEntrada *);
	void agregarNodoDespuesDe(NEntrada *, NEntrada *);

public:
	LstEntradas();
	~LstEntradas();

	NEntrada *getCab();
	void setCab(NEntrada *);

	int getSize();
	void setSize(int);

	// Métodos Publicos

	bool vacia();
	bool agregar(Entrada *);
	bool modificar(int, Entrada *);
	bool eliminar(int);
	bool eliminarTodos();
	Entrada *buscar(int);
	void desplegar();
	Entrada *obtenerEntrada(int);

	/*------------------------------ MULTILISTA: Lista de Listas Salteada --------------------------------------------*/

	// Inventario hacer Un Salto Hacia Producto
	int agregarUnCantidadProductoEnUnaEntrada(int, Entrada *);
	int anularUnaEntrada(int);

};

