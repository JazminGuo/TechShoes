// Proyecto Tech Shoes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LstProductos.h"
#include "LstFacturas.h"
#include "LstAlmacenes.h"
#include "LstInventario.h"

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
					cout << "Id: " << producto->getId() << endl;
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
						cout << "Id: " << producto->getId() << endl;
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

			if ((producto != NULL) && (producto->getId() == id))
			{
				cout << "============================================" << endl;
				cout << "Id: " << producto->getId() << endl;
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
					cout << "Id: " << producto->getId() << endl;
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
					cout << "Id: " << factura->getId() << endl;
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
						cout << "Id: " << factura->getId() << endl;
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
				cout << "Id: " << factura->getId() << endl;
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
					cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << factura->getId() << endl;
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
					cout << "Id: " << almacen->getId() << endl;
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
						cout << "Id: " << almacen->getId() << endl;
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
				cout << "Id: " << almacen->getId() << endl;
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
					cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
					cin >> dlt;
					system("cls");
				}
				else
				{
					cout << "============================================" << endl;
					cout << "Id: " << almacen->getId() << endl;
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


int main()
{
	listasMenu();
    return 0;
}

