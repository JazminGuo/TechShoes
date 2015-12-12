// Proyecto Tech Shoes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LstProductos.h"
#include "LstFacturas.h"
#include "LstAlmacenes.h"
#include "LstInventario.h"

#include "LstLineaProductos.h"
#include "LstSubLineaProductos.h"
#include "LstLineaFacturas.h"
#include "LstEntradas.h"

void productoMenu()
{
	int id = 0;
	char descripcion[30] = "---";
	double talla = 0.0;
	double precio = 0.0;
	int opc = 0;

	LstProductos * lista = new LstProductos();

	do
	{
		cout << "================ *** Menu Productos *** ================" << endl << endl;
		cout << "(1) Agregar Producto" << endl;
		cout << "(2) Modificar Producto" << endl;
		cout << "(3) Buscar Producto" << endl;
		cout << "(4) Eliminar Producto" << endl;
		cout << "(5) Ver todos los Productos" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "========================================================" << endl << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{
		case 1:
		{
			cout << "Digite el id del producto." << endl;
			cin >> id;
			cout << "Digite el descripcion del producto." << endl;
			cin >> descripcion;
			cout << "Digite la talla del producto." << endl;
			cin >> talla;
			cout << "Digite el precio del producto." << endl;
			cin >> precio;

			Producto * producto = new Producto(id, descripcion, talla, precio);

			lista->agregaAsc(producto);

			lista->desplegarLista();
			system("cls");
		}
		break;

		case 2:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el id del producto que desea modificar" << endl;
				cin >> id;

				Producto * producto = lista->obtenerProducto(id);

				if (producto == NULL)
				{
					cout << "El producto no existe" << endl;
					cout << "Digite (1) para intentar modificar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << producto->getIdProducto() << endl;
					cout << "Descripcion: " << producto->getDescripcion() << endl;
					cout << "Talla: " << producto->getTalla() << endl;
					cout << "Precio: " << producto->getPrecio() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea modificar este producto?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						cout << "Digite los nuevos parametros del producto" << endl << endl;

						cout << "Digite el id del producto." << endl;
						cin >> id;
						cout << "Digite el descripcion del producto." << endl;
						cin >> descripcion;
						cout << "Digite la talla del producto." << endl;
						cin >> talla;
						cout << "Digite el precio del producto." << endl;
						cin >> precio;

						Producto * producto = new Producto(id, descripcion, talla, precio);

						lista->modificarProducto(id, producto);

						cout << "============================================" << endl;
						cout << "Id: " << producto->getIdProducto() << endl;
						cout << "Descripcion: " << producto->getDescripcion() << endl;
						cout << "Talla: " << producto->getTalla() << endl;
						cout << "Precio: " << producto->getPrecio() << endl;
						cout << "============================================" << endl;
						cout << endl;

						cout << "El producto se ha modificado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 3:
		{
			cout << "Digite el id del producto que desea buscar" << endl;
			cin >> id;
			Producto * producto = lista->obtenerProducto(id);

			if ((producto != NULL) && (producto->getIdProducto() == id))
			{
				cout << "============================================" << endl;
				cout << "Id: " << producto->getIdProducto() << endl;
				cout << "Descripcion: " << producto->getDescripcion() << endl;
				cout << "Talla: " << producto->getTalla() << endl;
				cout << "Precio: " << producto->getPrecio() << endl;
				cout << "============================================" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "El producto no existe" << endl;
				system("pause");
				system("cls");
			}
		}
		break;

		case 4:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el id del producto que desea eliminar" << endl;
				cin >> id;

				Producto * producto = lista->obtenerProducto(id);

				if (producto == NULL)
				{
					cout << "El producto no existe" << endl;
					cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << producto->getIdProducto() << endl;
					cout << "Descripcion: " << producto->getDescripcion() << endl;
					cout << "Talla: " << producto->getTalla() << endl;
					cout << "Precio: " << producto->getPrecio() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea eliminar este producto?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						lista->eliminar(id);
						cout << "El producto se ha eliminado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;

					case 2:
					{
						dlt = 1;
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 5:
		{
			lista->desplegarLista();
		}
		break;

		}
		system("cls");
	} while (opc != 0);
}

void facturaMenu()
{
	int id = 0;
	char fecha[30] = "---";
	char cliente[30] = "---";
	int opc = 0;

	LstFacturas * lista = new LstFacturas();

	do
	{
		cout << "================ *** Menu Facturas *** ================" << endl << endl;
		cout << "(1) Agregar Factura" << endl;
		cout << "(2) Modificar Factura" << endl;
		cout << "(3) Buscar Factura" << endl;
		cout << "(4) Eliminar Factura" << endl;
		cout << "(5) Ver todas los Facturas" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "=======================================================" << endl << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{
		case 1:
		{
			cout << "Digite el id de la factura." << endl;
			cin >> id;
			cout << "Digite la fecha de la factura." << endl;
			cin >> fecha;
			cout << "Digite el cliente de la factura." << endl;
			cin >> cliente;

			Factura * factura = new Factura(id, fecha, cliente);

			lista->agregaAsc(factura);

			lista->desplegarLista();
			system("cls");
		}
		break;

		case 2:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el id de la factura que desea modificar" << endl;
				cin >> id;

				Factura * factura = lista->obtenerFactura(id);

				if (factura == NULL)
				{
					cout << "La factura no existe" << endl;
					cout << "Digite (1) para intentar modificar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << factura->getIdFactura() << endl;
					cout << "Fecha: " << factura->getFecha() << endl;
					cout << "Cliente: " << factura->getCliente() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea modificar esta factura?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						cout << "Digite los nuevos parametros de la factura" << endl << endl;

						cout << "Digite el id de la factura." << endl;
						cin >> id;
						cout << "Digite la fecha de la factura." << endl;
						cin >> fecha;
						cout << "Digite el cliente de la factura." << endl;
						cin >> cliente;

						Factura * factura = new Factura(id, fecha, cliente);

						lista->modificarFactura(id, factura);

						cout << "============================================" << endl;
						cout << "Id: " << factura->getIdFactura() << endl;
						cout << "Fecha: " << factura->getFecha() << endl;
						cout << "Cliente: " << factura->getCliente() << endl;
						cout << "============================================" << endl;
						cout << endl;

						cout << "La factura se ha modificado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 3:
		{
			cout << "Digite el id de la factura que desea buscar" << endl;
			cin >> id;
			Factura * factura = lista->obtenerFactura(id);

			if (factura != NULL)
			{
				cout << "============================================" << endl;
				cout << "Id: " << factura->getIdFactura() << endl;
				cout << "Fecha: " << factura->getFecha() << endl;
				cout << "Cliente: " << factura->getCliente() << endl;
				cout << "============================================" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "La factura no existe" << endl;
				system("pause");
				system("cls");
			}
		}
		break;

		case 4:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el id de la factura que desea eliminar" << endl;
				cin >> id;

				Factura * factura = lista->obtenerFactura(id);

				if (factura == NULL)
				{
					cout << "La factura no existe" << endl;
					cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << factura->getIdFactura() << endl;
					cout << "Fecha: " << factura->getFecha() << endl;
					cout << "Cliente: " << factura->getCliente() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea eliminar esta factura?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						lista->eliminar(id);
						cout << "La factura se ha eliminado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;

					case 2:
					{
						dlt = 1;
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 5:
		{
			lista->desplegarLista();
		}
		break;

		}
		system("cls");
	} while (opc != 0);
}

void almacenMenu()
{
	int id = 0;
	char ubicacion[30] = "---";
	int opc = 0;

	LstAlmacenes * lista = new LstAlmacenes();

	do
	{
		cout << "================ *** Menu Almacen *** ================" << endl << endl;
		cout << "(1) Agregar Almacen" << endl;
		cout << "(2) Modificar Almacen" << endl;
		cout << "(3) Buscar Almacen" << endl;
		cout << "(4) Eliminar Almacen" << endl;
		cout << "(5) Ver todos los Almacenes" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "======================================================" << endl << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{
		case 1:
		{
			cout << "Digite el id del almacen." << endl;
			cin >> id;
			cout << "Digite la ubicacion del almacen." << endl;
			cin >> ubicacion;


			Almacen * almacen = new Almacen(id, ubicacion);

			lista->agregaAsc(almacen);

			lista->desplegarLista();
			system("cls");
		}
		break;

		case 2:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el id del almacen que desea modificar" << endl;
				cin >> id;

				Almacen * almacen = lista->obtenerAlmacen(id);

				if (almacen == NULL)
				{
					cout << "El almacen no existe" << endl;
					cout << "Digite (1) para intentar modificar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << almacen->getIdAlmacen() << endl;
					cout << "Ubicacion: " << almacen->getUbicacion() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea modificar esta almacen?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						cout << "Digite los nuevos parametros del almacen" << endl << endl;

						cout << "Digite el id del almacen." << endl;
						cin >> id;
						cout << "Digite la ubicacion del almacen." << endl;
						cin >> ubicacion;

						Almacen * almacen = new Almacen(id, ubicacion);

						lista->modificarAlmacen(id, almacen);

						cout << "============================================" << endl;
						cout << "Id: " << almacen->getIdAlmacen() << endl;
						cout << "Ubicacion: " << almacen->getUbicacion() << endl;
						cout << "============================================" << endl;
						cout << endl;

						cout << "El almacen se ha modificado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 3:
		{
			cout << "Digite el id del almacen que desea buscar" << endl;
			cin >> id;
			Almacen * almacen = lista->obtenerAlmacen(id);

			if (almacen != NULL)
			{
				cout << "============================================" << endl;
				cout << "Id: " << almacen->getIdAlmacen() << endl;
				cout << "Ubicacion: " << almacen->getUbicacion() << endl;
				cout << "============================================" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "El almacen no existe" << endl;
				system("pause");
				system("cls");
			}
		}
		break;

		case 4:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el id del almacen que desea eliminar" << endl;
				cin >> id;

				Almacen * almacen = lista->obtenerAlmacen(id);

				if (almacen == NULL)
				{
					cout << "El almacen no existe" << endl;
					cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << almacen->getIdAlmacen() << endl;
					cout << "Ubicacion: " << almacen->getUbicacion() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea eliminar esta almacen?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						lista->eliminar(id);
						cout << "El almacen se ha eliminado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;

					case 2:
					{
						dlt = 1;
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 5:
		{
			lista->desplegarLista();
		}
		break;

		}
		system("cls");
	} while (opc != 0);
}

void inventarioMenu()
{
	int codArticulo = 0;
	int codAlmacen = 0;
	int existencia = 0;
	int opc = 0;

	LstInventario * lista = new LstInventario();

	do
	{
		cout << "================ *** Menu Inventarios *** ================" << endl << endl;
		cout << "(1) Agregar al Inventario" << endl;
		cout << "(2) Modificar el Inventario" << endl;
		cout << "(3) Buscar en Inventario" << endl;
		cout << "(4) Eliminar del Inventario" << endl;
		cout << "(5) Ver todos los articulos del Inventario" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "========================================================" << endl << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{
		case 1:
		{
			cout << "Digite el codigo del articulo." << endl;
			cin >> codArticulo;
			cout << "Digite el codigo del almacen." << endl;
			cin >> codAlmacen;
			cout << "Digite cantidad del articulo." << endl;
			cin >> existencia;

			Inventario * articulo = new Inventario(codArticulo, codAlmacen, existencia);

			lista->agregaAsc(articulo);

			lista->desplegarLista();
			system("cls");
		}
		break;

		case 2:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el codigo del articulo que desea modificar" << endl;
				cin >> codArticulo;

					Inventario * articulo = lista->obtenerInventario(codArticulo);

				if (articulo == NULL)
				{
					cout << "El articulo no existe" << endl;
					cout << "Digite (1) para intentar modificar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Codigo de articulo: " << articulo->getCodArticulo() << endl;
					cout << "Codigo de almacen: " << articulo->getCodAlmacen() << endl;
					cout << "Existencia: " << articulo->getExistencia() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea modificar este articulo?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						cout << "Digite los nuevos parametros del articulo" << endl << endl;

						cout << "Digite el codigo del articulo." << endl;
						cin >> codArticulo;
						cout << "Digite el codigo del almacen." << endl;
						cin >> codAlmacen;
						cout << "Digite la existencia del articulo." << endl;
						cin >> existencia;


						Inventario * articulo = new Inventario(codArticulo, codAlmacen, existencia);

						lista->modificarInventario(codArticulo, articulo);

						cout << "============================================" << endl;
						cout << "Codigo de articulo: " << articulo->getCodArticulo() << endl;
						cout << "Codigo de almacen: " << articulo->getCodAlmacen() << endl;
						cout << "Existencia: " << articulo->getExistencia() << endl;
						cout << "============================================" << endl;
						cout << endl;

						cout << "El articulo se ha modificado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 3:
		{
			cout << "Digite el codigo del articulo que desea buscar" << endl;
			cin >> codArticulo;
			Inventario * articulo = lista->obtenerInventario(codArticulo);

			if (articulo != NULL)
			{
				cout << "============================================" << endl;
				cout << "Codigo de articulo: " << articulo->getCodArticulo() << endl;
				cout << "Codigo de almacen: " << articulo->getCodAlmacen() << endl;
				cout << "Existencia: " << articulo->getExistencia() << endl;
				cout << "============================================" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "El articulo no existe" << endl;
				system("pause");
				system("cls");
			}
		}
		break;

		case 4:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el codigo del articulo que desea eliminar" << endl;
				cin >> codArticulo;

				Inventario * articulo = lista->obtenerInventario(codArticulo);

				if (articulo == NULL)
				{
					cout << "El articulo no existe" << endl;
					cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Codigo de articulo: " << articulo->getCodArticulo() << endl;
					cout << "Codigo de almacen: " << articulo->getCodAlmacen() << endl;
					cout << "Existencia: " << articulo->getExistencia() << endl;
					cout << "============================================" << endl;
					cout << endl;
					cout << "Esta seguro de que desea eliminar este articulo?" << endl;
					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;

					cin >> dlt;

					switch (dlt)
					{
					case 0:
					{
						dlt = 0;
					}
					break;

					case 1:
					{
						lista->eliminar(codArticulo);
						cout << "El articulo se ha eliminado corretamente" << endl;
						dlt = 0;
						system("pause");
						system("cls");
					}
					break;

					case 2:
					{
						dlt = 1;
						system("cls");
					}
					break;
					}
				}
			} while (dlt != 0);
		}
		break;

		case 5:
		{
			lista->desplegarLista();
		}
		break;

		}
		system("cls");
	} while (opc != 0);
}


void menuLineaProducto()
{

	LstLineaProductos *lstLineaProducto = new LstLineaProductos();
	int opcion = 0;

	int idRef;
	int vidProducto;
	char vdescripcion[30];

	do
	{
		system("cls");
		cout << "================ *** Menu LineaProducto *** ================" << endl << endl;
		cout << "(1) Agregar Un Linea de Producto" << endl;
		cout << "(2) Modificar Un Linea de Producto" << endl;
		cout << "(3) Eliminar Un Linea de Producto" << endl;
		cout << "(4) Eliminar Todos Lineas de Producto" << endl;
		cout << "(5) Buscar Un Linea de Producto" << endl;
		cout << "(6) Desplegar Todos Lineas de Producto" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "============================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl; 


		switch (opcion)
		{
		case 1:
		{
			system("cls");
			cout << "------- Agregando Un Linea de Producto --------" << endl;
			cout << "Digite el ID de Linea Producto: "; cin >> vidProducto;
			cout << "Digite el descripcion de Linea Producto: "; cin >> vdescripcion;
			cout << "                                          " << endl;

			LineaProducto *lp = new LineaProducto(vidProducto, vdescripcion);

			if (lstLineaProducto->agregar(lp))
				cout << "Agregar Nuevo Linea Producto Correctamente!" << endl;
			else
				cout << "Agregar Incorrecto!!!" << endl;

			system("pause");
			break;

		}
		case 2:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Modificando Un Linea de Producto --------" << endl;
			cout << "Digite el ID de Linea Producto que desea Mofidicar: "; cin >> idRef;
			//cout << "Digite el Nuevo ID de Linea Producto: "; cin >> vidProducto;
			cout << "Digite el Nuevo Descripcion de Linea Producto: "; cin >> vdescripcion;
			cout << "                                          " << endl;
			LineaProducto *lp = new LineaProducto(vidProducto, vdescripcion);


			if (lstLineaProducto->modificar(idRef, lp))
			{
				cout << "El ID Linea Producto " << idRef << " modificado Corretamente" << endl;
			}
			else
				cout << "El ID Linea Producto " << idRef << " modificado Incorreto" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Eliminando Un Linea de Producto --------" << endl;
			cout << "Digite el ID de Linea Producto que desea Eliminar: "; cin >> idRef;
			if (lstLineaProducto->eliminar(idRef))
				cout << "ID Linea Producto " << idRef << " Eliminado Correctamente!" << endl;
			else
				cout << "ID Linea Producto " << idRef << " Eliminado Incorrecto!" << endl;

			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Eliminando Todos Lineas de Producto --------" << endl;
			lstLineaProducto->eliminarTodos();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Buscando Un Linea de Producto --------" << endl;
			cout << "Digite el ID de Linea Producto que desea Buscar: "; cin >> idRef;
			cout << "                                          " << endl;
			LineaProducto *aux = lstLineaProducto->buscar(idRef);
			if (aux == NULL)
				cout << "No Existe el ID Linea Producto: " << idRef << endl;
			else
			{
				//cout << "                                          " << endl;
				cout << "------------------------------" << endl;
				cout << "ID: " << aux->getIdLineaProducto() << endl;
				cout << "Descripcion: " << aux->getDescripcion() << endl;
				cout << "------------------------------" << endl;
			}
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Desplegando Todos Lineas de Producto --------" << endl;
			lstLineaProducto->desplegar();
			system("pause");
			break;
		}
		
		}
		//system("pause");
		system("cls");
	} while (opcion != 0);
}
void menuSubLineaProducto()
{
	int opcion = 0;

	int idSubLineRef;
	int vidSubLinea;
	char vdescripcion[30];
	int vidLinea;

	LstSubLineaProductos *lstSubLineaProductos = new LstSubLineaProductos();
	do
	{
		system("cls");
		cout << "================ *** Menu SubLinea Producto *** ================" << endl << endl;
		cout << "(1) Agregar Un SubLinea de Producto" << endl;
		cout << "(2) Modificar Un SubLinea de Producto" << endl;
		cout << "(3) Eliminar Un SubLinea de Producto" << endl;
		cout << "(4) Eliminar Todos SubLineas de Producto" << endl;
		cout << "(5) Buscar Un SubLinea de Producto" << endl;
		cout << "(6) Desplegar Todos SubLineas de Producto" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "================================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			cout << "------- Agregando Un SubLinea de Producto --------" << endl;
			cout << "Digite el ID de Sub Linea Producto: "; cin >> vidSubLinea;
			cout << "Digite el descripcion de SubLinea Producto: "; cin >> vdescripcion;
			cout << "Digite el ID de Linea Producto: "; cin >> vidLinea;
			cout << "                                          " << endl;

			SubLineaProducto *slp = new SubLineaProducto(vidSubLinea, vdescripcion, vidLinea);
			if (lstSubLineaProductos->agregar(slp))
				cout << "Agregar Nuevo Linea Producto Correctamente!" << endl;
			else
				cout << "Agregar Incorrecto!!!" << endl;

			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Modificando Un SubLinea de Producto --------" << endl;
			cout << "Digite el ID de SubLinea Producto que desea Mofidicar: "; cin >> idSubLineRef;
			//cout << "Digite el Nuevo ID de SubLinea Producto: "; cin >> vidSubLinea;
			cout << "Digite el Nuevo ID de Linea Producto: "; cin >> vidLinea;
			cout << "Digite el Nuevo Descripcion de SubLinea Producto: "; cin >> vdescripcion;
			cout << "                                          " << endl;

			SubLineaProducto *nuevo = new SubLineaProducto(vidSubLinea, vdescripcion, vidLinea);

			if (lstSubLineaProductos->modificar(idSubLineRef, nuevo))
				cout << "El ID SubLinea Producto " << idSubLineRef << " modificado Corretamente" << endl;
			else
				cout << "El ID SubLinea Producto " << idSubLineRef << " modificado Incorreto" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Eliminando Un SubLinea de Producto --------" << endl;
			cout << "Digite el ID de Linea Producto que desea Eliminar: "; cin >> idSubLineRef;
			if (lstSubLineaProductos->eliminar(idSubLineRef))
				cout << "ID SubLinea Producto " << idSubLineRef << " Eliminado Correctamente!" << endl;
			else
				cout << "ID SubLinea Producto " << idSubLineRef << " Eliminado Incorrecto!" << endl;

			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Eliminando Todos SubLineas de Producto --------" << endl;
			lstSubLineaProductos->eliminarTodos();

			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Buscando Un SubLinea de Producto --------" << endl;
			cout << "Digite el ID de Linea Producto que desea Buscar: "; cin >> idSubLineRef;
			cout << "                                          " << endl;
			SubLineaProducto *aux = lstSubLineaProductos->buscar(idSubLineRef);
			if (aux == NULL)
				cout << "No Existe el ID SubLinea de Producto: " << idSubLineRef << endl;
			else
			{
				cout << "------------------------------" << endl;
				cout << "ID SubLinea: " << aux->getIdSubLinea() << endl;
				cout << "ID Linea Producto: " << aux->getIdLinea() << endl;
				cout << "Descripcion: " << aux->getDescripcion() << endl;
				cout << "------------------------------" << endl;
			}

			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Desplegando Todos SubLineas de Producto --------" << endl;
			lstSubLineaProductos->desplegar();

			system("pause");
			break;
		}
		//default: cout << "Opcion No Valida!" << endl;
		}
		//system("pause");
		system("cls");
	} while (opcion != 0);
}
void menuLineaFactura()
{
	int opcion = 0;

	int idLineaFacturaRef;
	int vidLineaFactura;
	char vfecha[10];
	char vcliente[10];

	LstLineaFacturas *lstLineaFacturas = new LstLineaFacturas();

	do
	{
		system("cls");
		cout << "================ *** Menu Linea Factura *** ================" << endl << endl;
		cout << "(1) Agregar Un Linea de Factura" << endl;
		cout << "(2) Modificar Un Linea de Factura" << endl;
		cout << "(3) Eliminar Un Linea de Factura" << endl;
		cout << "(4) Eliminar Todos Lineas de Factura" << endl;
		cout << "(5) Buscar Un Linea de Factura" << endl;
		cout << "(6) Desplegar Todos Lineas de Factura" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "============================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			cout << "------- Agregando Un Linea de Factura --------" << endl;
			cout << "Digite el ID de Linea Factura: "; cin >> vidLineaFactura;
			cout << "Digite la fecha de Linea Factura: "; cin >> vfecha;
			cout << "Digite el Cliente de Linea Factura: "; cin >> vcliente;
			cout << "                                          " << endl;
			LineaFactura *nuevo = new LineaFactura(vidLineaFactura, vfecha, vcliente);
			if (lstLineaFacturas->agregar(nuevo))
				cout << "Agregar Nuevo Linea Factura Correctamente!" << endl;
			else
				cout << "Agregar Incorrecto!!!" << endl;

			system("pause");
			break;

		}
		case 2:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Modificando Un Linea de Factura --------" << endl;
			cout << "Digite el ID de Linea de Factura que desea Mofidicar: "; cin >> idLineaFacturaRef;
			//cout << "Digite el Nuevo ID de Linea de Factura: "; cin >> vidLineaFactura;
			cout << "Digite el Nuevo Fecha de Linea de Factura: "; cin >> vfecha;
			cout << "Digite el Nuevo Cliente de Linea de Factura: "; cin >> vcliente;
			cout << "                                          " << endl;

			LineaFactura *nuevo = new LineaFactura(vidLineaFactura, vfecha, vcliente);

			if (lstLineaFacturas->modificar(idLineaFacturaRef, nuevo))
				cout << "El ID SubLinea Producto " << idLineaFacturaRef << " modificado Corretamente" << endl;
			else
				cout << "El ID SubLinea Producto " << idLineaFacturaRef << " modificado Incorreto" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Eliminando Un Linea de Factura --------" << endl;
			cout << "Digite el ID de Linea Producto que desea Eliminar: "; cin >> idLineaFacturaRef;
			if (lstLineaFacturas->eliminar(idLineaFacturaRef))
				cout << "ID Linea de Factura " << idLineaFacturaRef << " Eliminado Correctamente!" << endl;
			else
				cout << "ID Linea de Factura " << idLineaFacturaRef << " Eliminado Incorrecto!" << endl;

			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Eliminando Todos Lineas de Factura --------" << endl;
			lstLineaFacturas->eliminarTodos();

			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Buscando Un Linea de Factura --------" << endl;
			cout << "Digite el ID de Linea de Factura que desea Buscar: "; cin >> idLineaFacturaRef;
			cout << "                                          " << endl;
			LineaFactura *aux = lstLineaFacturas->buscar(idLineaFacturaRef);
			if (aux == NULL)
				cout << "No Existe el ID Linea de Factura: " << idLineaFacturaRef << endl;
			else
			{
				cout << "------------------------------" << endl;
				cout << "ID Linea Factura: " << aux->getIdLineaFactura() << endl;
				cout << "Fecha: " << aux->getFecha() << endl;
				cout << "Descripcion: " << aux->getCliente() << endl;
				cout << "------------------------------" << endl;
			}

			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Desplegando Todos Linea de Factura --------" << endl;
			lstLineaFacturas->desplegar();

			system("pause");
			break;
		}
		//default:cout << "Opcion No Valida!" << endl;

		}
		//system("pause");
		system("cls");
	} while (opcion != 0);

}
void menuEntrada()
{
	int opcion = 0;
	LstEntradas *lstEntradas = new LstEntradas();

	int refIdProducto;

	int vidProducto;
	int vcantidadProducto;

	do
	{
		system("cls");
		cout << "================ *** Menu Entrada *** ================" << endl << endl;
		cout << "(1) Agregar Una Entrada" << endl;
		cout << "(2) Modificar Una Entrada" << endl;
		cout << "(3) Eliminar Una Una Entrada" << endl;
		cout << "(4) Eliminar Todos Entrada" << endl;
		cout << "(5) Buscar Una Entrada" << endl;
		cout << "(6) Desplegar Todos Entradas" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "======================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			system("cls");
			cout << "------- Agregando Una Entrada --------" << endl;
			cout << "Digite el Id de Producto: "; cin >> vidProducto;
			cout << "Digite Nuevo Cantidades de Producto: "; cin >> vcantidadProducto;
			Entrada *nuevo = new Entrada(vidProducto, vcantidadProducto);
			if (lstEntradas->agregar(nuevo))
				cout << "Agregado nuevo Entrada Existosamente" << endl;
			else
				cout << "Agregado nuevo Entrada Incorrecto" << endl;

			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "------- Modificando Un Entrada --------" << endl;
			cout << "Digite el Id Existente de Producto que desea modificar: "; cin >> refIdProducto;
			cout << "Digite Nuevo Cantidades de Producto: "; cin >> vcantidadProducto;
			Entrada *nuevo = new Entrada(refIdProducto, vcantidadProducto);
			if (lstEntradas->modificar(refIdProducto, nuevo))
				cout << "El Id Producto " << refIdProducto << " se ha modificado Correctamente" << endl;
			else
				cout << "El Id Producto " << refIdProducto << " No se Modifico!!" << endl;

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "------- Eliminando Un Entrada --------" << endl;
			cout << "Digite el ID Existente de Producto que desea eliminar: "; cin >> refIdProducto;
			if (lstEntradas->eliminar(refIdProducto))
				cout << "Eliminado Exitosamente" << endl;
			else
				cout << "No se Elimino" << endl;

			system("pause");
			break;
		}
		case 4:
		{

			system("cls");
			cout << "------- Eliminando Todos Entradas --------" << endl;
			lstEntradas->eliminarTodos();

			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Buscando Una Entrada --------" << endl;
			cout << "Digite el ID Existente de Producto que desea buscar: "; cin >> refIdProducto;
			Entrada *aux = lstEntradas->buscar(refIdProducto);
			if (aux != NULL)
			{
				cout << endl;
				cout << "-----------------------------------" << endl;
				cout << "ID Producto: " << aux->getIdProducto() << endl;
				cout << "Cantidades Productos: " << aux->getCantidadProducto() << endl;
				cout << "-----------------------------------" << endl;
			}
			else
			{
				cout << endl;
				cout << "No existe el ID Producto " << refIdProducto << " en la lista" << endl;
			}

			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			cout << "                                          " << endl;
			cout << "------- Desplegando Todos Linea de Factura --------" << endl;
			lstEntradas->desplegar();

			system("pause");
			break;
		}
	
		}
		//system("pause");
		system("cls");
	} while (opcion != 0);
}

void listasMenu()
{
	int opc = 0;

	do
	{
		cout << "================ *** Menu Listas *** ================" << endl << endl;
		cout << "(1) Lista Productos" << endl;
		cout << "(2) Lista Facturas" << endl;
		cout << "(3) Lista Almacenes" << endl;
		cout << "(4) Lista Inventario" << endl;
		cout << "(5) Lista Linea Producto" << endl;
		cout << "(6) Lista SubLinea Producto" << endl;
		cout << "(7) Lista Linea Factura" << endl;
		cout << "(8) Lista Entrada" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "=====================================================" << endl << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{
		case 1:
		{
			system("cls");
			productoMenu();
		}
		break;

		case 2:
		{
			system("cls");
			facturaMenu();
		}
		break;

		case 3:
		{
			system("cls");
			almacenMenu();
		}
		break;

		case 4:
		{
			system("cls");
			inventarioMenu();
		}
		break;

		case 5:
		{
			system("cls");
			menuLineaProducto();
		}
		break;

		case 6:
		{
			system("cls");
			menuSubLineaProducto();
		}
		break;

		case 7:
		{
			system("cls");
			menuLineaFactura();
		}
		break;

		case 8:
		{
			system("cls");
			menuEntrada();
		}
		break;

		case 0:
		{
			opc = 0;
		}
		break;

		default:
		{
			cout << "Opcion incorrecta" << endl;
			system("pause");
			system("cls");
		}

		}

	} while (opc != 0);
}


/*----------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------ MENU INDEPEDIENTE -------------------------------------------------- */
/*----------------------------------------------------------------------------------------------------------------------------------*/

// MENU PARA MUNDO A
void menuAlmacen_Inventario()
{

}
void menuAlmacen_Entrada()
{

}
void menuAlmacen_Factura()
{

}

// MENU PARA MUNDO B
void menuLineaProducto_SubLinea()
{

}
void menuLSubLinea_Producto()
{

}

// Aqui van todos lo de Almacen
void menuMundoA()
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** MENU PRINCIPAL *** ================" << endl << endl;
		cout << "(1) OPERACION ALMACENES" << endl;
		cout << "(2) OPERACION ALAMENCES CON INVENTARIOS" << endl;
		cout << "(3) OPERACION ALAMENCES CON ENTRADAS" << endl;
		cout << "(4) OPERACION ALAMENCES CON FACTURAS" << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		}

	} while (opcion != 0);
}
// Aqui van todos lo de Linea Producto
void menuMundoB()
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** MENU PRINCIPAL *** ================" << endl << endl;
		cout << "(1) OPERACION LINEA PRODUCTO" << endl;
		cout << "(2) OPERACION LINEA PRODUCTO CON SUBLINEA PRODUCTO" << endl;
		cout << "(3) OPERACION SUBLINEA PRODUCTO CON PRODUCTO" << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		}

	} while (opcion != 0);
}
// Aqui van Mundo A y Mundo B
void menuPrincipalAB()
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** MENU PRINCIPAL *** ================" << endl << endl;
		cout << "(1) OPERACION MUNDO A (ALMACENES, FACTURAS, ENTRADAS, INVENTARIOS)" << endl;
		cout << "(2) OPERACION MUNDO B (LINEA PRODUCTO, SUBLINEA, PRODUCTO)" << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			menuMundoA();
			break;
		}
		case 2:
		{
			menuMundoB();
			break;
		}
		}
		system("pause");
	} while (opcion != 0);

}

int main()
{
	listasMenu();
    return 0;
}

