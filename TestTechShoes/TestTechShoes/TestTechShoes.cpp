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



/* void productoMenu()
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

Producto * producto = new Producto(id, descripcion, talla, precio, 0, 0);

lista->agregar(producto);

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

Producto * producto = new Producto(id, descripcion, talla, precio, 0, 0);

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
}*/
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

//void almacenMenu()
//{
//	int id = 0;
//	char ubicacion[30] = "---";
//	int opc = 0;
//
//	LstAlmacenes * lista = new LstAlmacenes();
//
//	do
//	{
//		cout << "================ *** Menu Almacen *** ================" << endl << endl;
//		cout << "(1) Agregar Almacen" << endl;
//		cout << "(2) Modificar Almacen" << endl;
//		cout << "(3) Buscar Almacen" << endl;
//		cout << "(4) Eliminar Almacen" << endl;
//		cout << "(5) Ver todos los Almacenes" << endl;
//		cout << "(0) Salir" << endl << endl;
//		cout << "======================================================" << endl << endl;
//		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;
//
//		switch (opc)
//		{
//		case 1:
//		{
//			cout << "Digite el id del almacen." << endl;
//			cin >> id;
//			cout << "Digite la ubicacion del almacen." << endl;
//			cin >> ubicacion;
//
//
//			Almacen * almacen = new Almacen(id, ubicacion);
//
//			lista->agregaAsc(almacen);
//
//			lista->desplegarLista();
//			system("cls");
//		}
//		break;
//
//		case 2:
//		{
//			int dlt = 0;
//
//			do
//			{
//				cout << "Digite el id del almacen que desea modificar" << endl;
//				cin >> id;
//
//				Almacen * almacen = lista->obtenerAlmacen(id);
//
//				if (almacen == NULL)
//				{
//					cout << "El almacen no existe" << endl;
//					cout << "Digite (1) para intentar modificar de nuevo o (0) para regresar al menu anterior" << endl;
//					cin >> dlt;
//					system("cls");
//				}
//				else
//				{
//					cout << "============================================" << endl;
//					cout << "Id: " << almacen->getIdAlmacen() << endl;
//					cout << "Ubicacion: " << almacen->getUbicacion() << endl;
//					cout << "============================================" << endl;
//					cout << endl;
//					cout << "Esta seguro de que desea modificar esta almacen?" << endl;
//					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;
//
//					cin >> dlt;
//
//					switch (dlt)
//					{
//					case 0:
//					{
//						dlt = 0;
//					}
//					break;
//
//					case 1:
//					{
//						cout << "Digite los nuevos parametros del almacen" << endl << endl;
//
//						cout << "Digite el id del almacen." << endl;
//						cin >> id;
//						cout << "Digite la ubicacion del almacen." << endl;
//						cin >> ubicacion;
//
//						Almacen * almacen = new Almacen(id, ubicacion);
//
//						lista->modificarAlmacen(id, almacen);
//
//						cout << "============================================" << endl;
//						cout << "Id: " << almacen->getIdAlmacen() << endl;
//						cout << "Ubicacion: " << almacen->getUbicacion() << endl;
//						cout << "============================================" << endl;
//						cout << endl;
//
//						cout << "El almacen se ha modificado corretamente" << endl;
//						dlt = 0;
//						system("pause");
//						system("cls");
//					}
//					break;
//					}
//				}
//			} while (dlt != 0);
//		}
//		break;
//
//		case 3:
//		{
//			cout << "Digite el id del almacen que desea buscar" << endl;
//			cin >> id;
//			Almacen * almacen = lista->obtenerAlmacen(id);
//
//			if (almacen != NULL)
//			{
//				cout << "============================================" << endl;
//				cout << "Id: " << almacen->getIdAlmacen() << endl;
//				cout << "Ubicacion: " << almacen->getUbicacion() << endl;
//				cout << "============================================" << endl;
//				system("pause");
//				system("cls");
//			}
//			else
//			{
//				cout << "El almacen no existe" << endl;
//				system("pause");
//				system("cls");
//			}
//		}
//		break;
//
//		case 4:
//		{
//			int dlt = 0;
//
//			do
//			{
//				cout << "Digite el id del almacen que desea eliminar" << endl;
//				cin >> id;
//
//				Almacen * almacen = lista->obtenerAlmacen(id);
//
//				if (almacen == NULL)
//				{
//					cout << "El almacen no existe" << endl;
//					cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
//					cin >> dlt;
//					system("cls");
//				}
//				else
//				{
//					cout << "============================================" << endl;
//					cout << "Id: " << almacen->getIdAlmacen() << endl;
//					cout << "Ubicacion: " << almacen->getUbicacion() << endl;
//					cout << "============================================" << endl;
//					cout << endl;
//					cout << "Esta seguro de que desea eliminar esta almacen?" << endl;
//					cout << "Presione (1) para confirmar, (2) para cancelar o (0) para regresar al menu anterior" << endl;
//
//					cin >> dlt;
//
//					switch (dlt)
//					{
//					case 0:
//					{
//						dlt = 0;
//					}
//					break;
//
//					case 1:
//					{
//						lista->eliminar(id);
//						cout << "El almacen se ha eliminado corretamente" << endl;
//						dlt = 0;
//						system("pause");
//						system("cls");
//					}
//					break;
//
//					case 2:
//					{
//						dlt = 1;
//						system("cls");
//					}
//					break;
//					}
//				}
//			} while (dlt != 0);
//		}
//		break;
//
//		case 5:
//		{
//			lista->desplegarLista();
//		}
//		break;
//
//		}
//		system("cls");
//	} while (opc != 0);
//}

void inventarioMenu()
{
	int codArticulo = 0;
	int codAlmacen = 0;
	int existencia = 0;
	int opc = 0;

	LstInventario * lista = new LstInventario();

	/*do
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
	} while (opc != 0);*/
}


void LineaProductoMenu()
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

/*void listasMenu()
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
//menuLineaProducto();
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
}*/


/*----------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------ MENU INDEPEDIENTE -------------------------------------------------- */
/*----------------------------------------------------------------------------------------------------------------------------------*/

// MENU PARA MUNDO A
void menuAlmacen(LstAlmacenes * listaAlmacenes, LstLineaProductos *listaLineaProductos)
{
	int idAlmacen = 0;
	int idProducto = 0;
	char ubicacion[30] = "---";
	int opc = 0;

	//LstAlmacenes * lista = new LstAlmacenes();

	do
	{
		system("cls");
		cout << "================ *** Menu Almacen *** ================" << endl << endl;
		cout << "(1) Agregar Almacen" << endl;
		cout << "(2) Buscar Almacen" << endl;
		cout << "(3) Eliminar Almacen" << endl;
		cout << "(4) Ver todos los Almacenes" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "======================================================" << endl << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{
		case 1:
		{
			cout << "Digite el id del almacen." << endl;
			cin >> idAlmacen;
			cout << "Digite la ubicacion del almacen." << endl;
			cin >> ubicacion;


			Almacen * almacen = new Almacen(idAlmacen, ubicacion);
			LstProductos *listaProductos = new LstProductos();

			//listaAlmacenes->agregaAsc(almacen, listaLineaProductos);

			if (listaAlmacenes->agregaAsc(almacen, listaLineaProductos))
			{
				listaAlmacenes->autoAgregar(idAlmacen, listaLineaProductos);
			}
			else
			{
				cout << "No se agrego el almacen" << endl;
			}

			listaAlmacenes->desplegarLista();
			system("pause");
			system("cls");
		}
		break;

		case 2:
		{
			cout << "Digite el id del almacen que desea buscar" << endl;
			cin >> idAlmacen;
			cout << "Digite el id del inventario que desea buscar" << endl;
			cin >> idProducto;

			listaAlmacenes->desplegarUnInventarioDeUnAlmacen(idAlmacen, idProducto);

			//Almacen * almacen = listaAlmacenes->obtenerAlmacen(idAlmacen);

			/*		if (almacen != NULL)
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
			}*/
			system("pause");
		}
		break;

		case 3:
		{
			int dlt = 0;

			do
			{
				cout << "Digite el id del almacen que desea eliminar" << endl;
				cin >> idAlmacen;

				Almacen * almacen = listaAlmacenes->obtenerAlmacen(idAlmacen);

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
						listaAlmacenes->eliminar(idAlmacen);
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

		case 4:
		{
			listaAlmacenes->desplegarTodosInventariosDeTodosAlmacenes();
			system("pause");
		}
		break;
		}
		system("cls");
	} while (opc != 0);
}
//void menuAlmacen_Inventario(LstAlmacenes * listaAlmacenes)
//{
//	//LstAlmacenes *listaAlmacenes = new LstAlmacenes();
//	int opcion = 0;
//
//	int idAlmacenRef;
//	int codArticulo;
//	int codAlmacen;
//	int existencia;
//	do
//	{
//		system("cls");
//		cout << "================ *** Menu Almacen e Inventarios *** ================" << endl << endl;
//		cout << "(1) Agregar Un Inventario En Un Almacen" << endl;
//		cout << "(2) Consultar Un Inventario de Un Almacen" << endl;
//		cout << "(3) Desplegar Todos Inventarios de Todos Almacenes" << endl;
//		//cout << endl;
//		//cout << "(4) Agregar Producto Inventarios de Todos Almacenes" << endl;
//		cout << "(0) Salir" << endl;
//		cout << "====================================================================" << endl << endl;
//		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;
//		switch (opcion)
//		{
//		case 1:
//		{
//			system("cls");
//			cout << endl;
//			cout << "------- Agregar Un Inventario En Un Almacen --------" << endl << endl;
//			cout << "Digite el codigo del almacen: "; cin >> idAlmacenRef;
//			cout << "Digite el codigo del articulo: "; cin >> codArticulo;
//			//cout << "Digite cantidad del articulo: "; cin >> existencia;
//
//
//			/*	1. Se inserto exitosamente
//			2. No se inserto porque el Almacen no existe
//			3. No se insertó porque el Inventario ya existe, ya fue registrado*/
//			Inventario * inventario = new Inventario(codArticulo, idAlmacenRef,);
//
//			switch (listaAlmacenes->agregarUnInventarioEnUnAlmacen(idAlmacenRef, inventario))
//			{
//			case 1:
//			{
//				cout << endl; cout << "Se Inserto el Nuevo Inventario en Almacen " << idAlmacenRef << " Correctamente!" << endl;
//				break;
//			}
//			case 2:
//			{
//				cout << endl; cout << "NO se Inserto el Nuevo Inventario,  porque NO EXISTE Almacen " << idAlmacenRef << " !" << endl;
//				break;
//			}
//			case 3:
//			{
//				cout << endl; cout << "NO se Inserto el Nuevo Inventario,  porque YA EXISTE !" << endl;
//				break;
//			}
//			}
//			system("pause");
//			break;
//		}
//		case 2:
//		{
//			system("cls");
//			cout << endl;
//			cout << "------- Consultar Todos Inventarios de Un Almacen --------" << endl << endl;
//			cout << "Digite el ID Almacen Existente: "; cin >> idAlmacenRef;
//			listaAlmacenes->desplegarTodosInventariosDeUnAlmacen(idAlmacenRef);
//			system("pause");
//			break;
//		}
//		case 3:
//		{
//			system("cls");
//			cout << endl;
//			cout << "------- Desplegando Todos Inventariso de Todos Almacenes --------" << endl << endl;
//			listaAlmacenes->desplegarTodosInventariosDeTodosAlmacenes();
//			system("pause");
//			break;
//		}
//		}
//	} while (opcion != 0);
//} // NO EXISTE //NO EXISTE


void menuAlmacen_Entrada(LstAlmacenes * listaAlmacenes, LstLineaProductos *listaLineaProductos)
{
	int opcion = 0;

	int idAlmacen;
	int idArticulo;
	int existencia;

	do
	{
		system("cls");
		cout << "================ *** Menu Almacen y Entrada *** ================" << endl << endl;
		cout << "(1) Agregar Una Entrada En Un Almacen" << endl;
		cout << "(2) Anular Una Entrada de Un Almacen" << endl;
		cout << "(3) Consultar Todos Inventarios de Un Almacen" << endl;
		cout << "(0) Salir" << endl;
		cout << "====================================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;
		switch (opcion)
		{
		case 1:
		{
			system("cls");
			cout << endl;
			cout << "------- Agregando Una Entrada En Un Almacen --------" << endl << endl;
			cout << "Digite el codigo del almacen: "; cin >> idAlmacen;
			cout << "Digite el codigo del almacen: "; cin >> idAlmacen;
			cout << "Digite el codigo del almacen: "; cin >> idAlmacen;
			cout << "Digite el codigo del articulo: "; cin >> idArticulo;
			cout << "Digite cantidad del articulo: "; cin >> existencia;


			/*	1. Se inserto exitosamente
			2. No se inserto porque el Almacen no existe
			3. No se insertó porque el Inventario ya existe, ya fue registrado*/
			Entrada * entrada = new Entrada(idArticulo, existencia);



			/*switch (listaAlmacenes->agregarUnaEntradaEnUnAlmacen(idAlmacen, idArticulo, entrada, listaLineaProductos))
			{
			case 1:
			{
				cout << endl; cout << "Se Agrego el Nuevo Entrada en Almacen " << idAlmacen << " Correctamente!" << endl;
				break;
			}
			case 2:
			{
				cout << endl; cout << "NO se Agrego el Nuevo Entrada,  porque YA EXISTE !" << endl;
				break;
			}
			case 3:
			{
				cout << endl; cout << "NO se Agrego porque NO EXISTE ID Ariticulo " << idArticulo << endl;
				break;
			}
			case 4:
			{
				cout << endl; cout << "No se Agrego porque el Almacen " << idAlmacen << " NO EXISTE" << endl;
			}
			}
			system("pause");
			break;*/
		}
		case 2:
		{
			system("cls");
			cout << endl;
			cout << "------- Anulando Una Entrada de Un Almacen --------" << endl << endl;
			cout << "Digite el ID Almacen Existente: "; cin >> idAlmacen;
			cout << "Digite el ID Articulo Existente: "; cin >> idArticulo;
			switch (listaAlmacenes->anularUnaEntradaDeUnAlmacen(idAlmacen, idArticulo))
			{
			case 1:
			{
				cout << endl; cout << "Se anulo la Entrada en Almace " << idAlmacen << " Correctamente!" << endl;
				break;
			}
			case 2:
			{
				cout << endl; cout << "NO se anulo la Entrada,  porque NO EXISTE !" << endl;
				break;
			}
			case 3:
			{
				cout << endl; cout << "NO SE ANULO porque NO EXISTE el Almacen " << idAlmacen << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << endl;
			cout << "------- Desplegando Una Entrada de Un Almacen --------" << endl << endl;
			cout << "Digite el ID Almacen Exsitente que desea Consultar: "; cin >> idAlmacen;
			cout << "Digite el ID Articulo Existente que desea Consultar: "; cin >> idArticulo;
			listaAlmacenes->desplegarUnaEntradaDeUnAlmacen(idAlmacen, idArticulo);
			system("pause");
			break;
		}
		}
	} while (opcion != 0);
}

void menuFacturacion(LstAlmacenes * lstAlmacenes, LstLineaProductos * lstLineas)
{
	int opcion = 0;

	int idAlmacen = 0;
	int idLinea = 0;
	int idSublinea = 0;
	int idProducto = 0;
	int cantidad = 0;
	int idFactura = 0;
	int numLinea = 0;

	char fecha[30] = "---";
	char cliente[30] = "---";
	int opc = 0;

	do
	{

		system("cls");
		cout << "======================== *** Facturacion *** ========================" << endl << endl;
		cout << "(1) Facturar" << endl;
		cout << "(2) Anular Factura" << endl;
		cout << "(3) Buscar Factura" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "=====================================================================" << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{ 
			system("cls");
			cout << endl;
			cout << "==========================================================" << endl;
			cout << "Facturacion." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID del Almacen"; cin >> idAlmacen;
			idFactura = lstAlmacenes->ultimaFactura(idAlmacen) + 1;
			cout << "Digite la fecha de la factura: "; cin >> fecha;
			cout << "Digite el nombre del cliente: "; cin >> cliente;

			Factura * factura = new Factura(idFactura, fecha, cliente);

			switch (lstAlmacenes->agregarFactura(idAlmacen, factura))
			{
			case 1:
			{
				int dlt = 0;

				cout << "======================== *** Facturacion *** ========================" << endl << endl;
				cout << "(1) Anadir Productos" << endl;
				cout << "(0) Terminar Factura" << endl;
				cout << "=====================================================================" << endl << endl;
				cout << "Opcion Seleccionada: "; cin >> dlt; cout << endl;

				do
				{
					switch (dlt)
					{ 
						case 1:
						{
							cout << "==========================================================" << endl;
							cout << "Anadir Productos." << endl;
							cout << "==========================================================" << endl << endl;

							cout << "Digite el ID de la Linea" << endl;
							cin >> idLinea;
							cout << "Digite el ID de la Sublinea" << endl;
							cin >> idSublinea;
							cout << "Digite el ID del Producto" << endl;
							cin >> idProducto;

							if (lstLineas->dirNodoGlobal(idLinea, idSublinea, idProducto))
							{
								cout << "Digite la cantidad" << endl;
								cin >> cantidad;

								numLinea = lstAlmacenes->ultimaLinea(idAlmacen, idFactura) + 1;
								LineaFactura * nueva = new LineaFactura(idFactura, numLinea, idLinea, idSublinea, idProducto, cantidad);

								lstAlmacenes->agregarLineaFactura(idAlmacen, idFactura, nueva);

								cout << "Producto agregado a la Factura" << endl << endl;

								cout << "Desea anadir mas Productos?" << endl << endl;
								cout << "Si (1)" << endl;
								cout << "No (0)" << endl;
								cout << "Opcion selecionada: "; cin >> dlt; cout << endl;

								lstAlmacenes->imprimirFactura(idAlmacen, idFactura, lstLineas);
							}
							else
							{
								cout << "El producto que desea anadir a la factura no existe." << endl;
								system("pause");
								dlt = 1;
							}
						}
						break;

						case 2:
						{
							cout << "Ha salido del menu de facturas." << endl;
							system("pause");
							dlt = 0;
						}
						break;
					}
				} while (dlt != 0);
			}
			break;

			case 2:
			{
				cout << endl; cout << "NO se Inserto el Nuevo Factura,  porque NO EXISTE Almacen " << idAlmacen << " !" << endl;
				break;
			}
			case 3:
			{
				cout << endl; cout << "NO se Inserto el Nuevo Factura,  porque YA EXISTE !" << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			cout << endl;
			cout << "------- Anulando Una Factura En Un Almacen --------" << endl << endl;
			cout << "Digite el ID Almacen Existente: "; cin >> idAlmacen;
			cout << "Digite el ID Factura Existente: "; cin >> idFactura;
			switch (lstAlmacenes->elimniarFactura(idAlmacen, idFactura))
			{
			case 1:
			{
				cout << endl; cout << "Se Elimino la Factura " << idFactura << " Correctamente!" << endl;
				break;
			}
			case 2:
			{
				cout << endl; cout << "NO se Elimino la Factura,  porque NO EXISTE Almacen " << idAlmacen << " !" << endl;
				break;
			}
			case 3:
			{
				cout << endl; cout << "NO se Elimino la Factura,  porque NO EXISTE !" << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << endl;
			cout << "------- Consultando Todos Facturas de Un Almacen --------" << endl << endl;
			cout << "Digite el ID Almacen Existente: "; cin >> idAlmacen;
			lstAlmacenes->desplegarFacturasDeAlmacen(idAlmacen);
		}
		}

	} while (opcion != 0);
}

void menuAlmacen_Factura_lineaFactura(LstAlmacenes * listaAlmacenes)
{
	int opcion = 0;

	int idFactura;
	int idProducto;
	int cantidadVendida;

	/*do
	{


		switch (opcion)
		{

			system("cls");
			cout << "================ *** Menu Almacen e Factura_LineaFactura *** ================" << endl << endl;
			cout << "(1) Agregar Una Linea de Factura En Una Factura" << endl;
			cout << "(2) Anular Una Linea de Factura de Una Factura" << endl;
			cout << "(3) Consultar Una Factura de Todos Almacenes" << endl;
			cout << "(0) Salir" << endl;
			cout << "=============================================================================" << endl << endl;
			cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		case 1:
		{
			system("cls");
			cout << endl;
			cout << "------- Agregar Una Factura En Un Almacen --------" << endl << endl;
			cout << "Digite el ID Factura Existente: "; cin >> idFactura;
			cout << "Digite el ID Producto Existente: "; cin >> idProducto;
			cout << "Digite la Cantidad de Producto que se vendio: "; cin >> cantidadVendida;

			LineaFactura *lineaFactura = new LineaFactura(idFactura, idProducto, cantidadVendida);
			switch (listaAlmacenes->agregarUnaFacturaEnUnAlmacen(idAlmacenRef, factura))
			{
			case 1:
			{
				cout << endl; cout << "Se Inserto el Nuevo Factura en Almacen " << idAlmacenRef << " Correctamente!" << endl;
				break;
			}
			case 2:
			{
				cout << endl; cout << "NO se Inserto el Nuevo Factura,  porque NO EXISTE Almacen " << idAlmacenRef << " !" << endl;
				break;
			}
			case 3:
			{
				cout << endl; cout << "NO se Inserto el Nuevo Factura,  porque YA EXISTE !" << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		}

	} while (opcion != 0);*/
}


// MENU PARA MUNDO B
void menuLinea(LstLineaProductos * _lstLinea)
{
	int opcion = 0;

	int idRef;
	int vidProducto;
	char vdescripcion[30];

	do
	{
		system("cls");
		cout << "================= *** Menu de Linea *** ==================" << endl << endl;
		cout << "(1) Agregar Linea." << endl;
		cout << "(2) Modificar Linea." << endl;
		cout << "(3) Eliminar Linea." << endl;
		cout << "(4) Eliminar todas las Lineas." << endl;
		cout << "(5) Buscar Linea." << endl;
		cout << "(6) Desplegar Lineas." << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "==========================================================" << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;


		switch (opcion)
		{
		case 1:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Agregar Linea." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de la Linea. " << endl;
			cin >> vidProducto;
			cout << "Digite la descripcion de la Linea." << endl;
			cin >> vdescripcion;

			LineaProducto * lp = new LineaProducto(vidProducto, vdescripcion);

			if (_lstLinea->agregar(lp))
				cout << "Linea agregada correctamente." << endl;
			else
				cout << "Error no se agrego la Linea." << endl;

			system("pause");
			break;

		}
		case 2:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Modificar Linea." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de Linea que desea Mofidicar." << endl;
			cin >> idRef;
			//cout << "Digite el Nuevo ID de Linea Producto: "; cin >> vidProducto;
			cout << "Digite el Nuevo Descripcion de Linea." << endl;
			cin >> vdescripcion;
			LineaProducto *lp = new LineaProducto(vidProducto, vdescripcion);


			if (_lstLinea->modificar(idRef, lp))
			{
				cout << "El ID Linea" << idRef << " se modifico corretamente." << endl;
			}
			else
				cout << "El ID Linea" << idRef << " no se modifico." << endl;

			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Eliminar Linea" << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de Linea que desea eliminar." << endl;
			cin >> idRef;

			if (_lstLinea->eliminar(idRef))
				cout << "ID Linea" << idRef << " se eliminado correctamente." << endl;
			else
				cout << "ID Linea" << idRef << " no se eliminado." << endl;

			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Eliminar todas las Lineas." << endl;
			cout << "==========================================================" << endl << endl;
			_lstLinea->eliminarTodos();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "==========================================================" << endl << endl;
			cout << "Buscar Linea." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de Linea Producto que desea Buscar." << endl;
			cin >> idRef;
			LineaProducto *aux = _lstLinea->buscar(idRef);
			if (aux == NULL)
				cout << "No Existe el ID Linea: " << idRef << endl;
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
			cout << "==========================================================" << endl;
			cout << "Desplegar Lineas." << endl;
			cout << "==========================================================" << endl << endl;
			_lstLinea->desplegar();
			system("pause");
			break;
		}

		}
		//system("pause");
		system("cls");
	} while (opcion != 0);
}

void menuSubLinea(LstLineaProductos * _lstLinea)
{
	int opc = 0;

	int idLinea;
	int idSubLinea;
	char descripcion[30];

	do
	{
		system("cls");
		cout << "================ *** Menu de SubLinea *** ================" << endl << endl;
		cout << "(1) Agregar Sublinea." << endl;
		cout << "(2) Elimiar Sublinea." << endl;
		cout << "(3) Buscar Sublinea." << endl;
		cout << "(4) Ver Sublineas." << endl;
		cout << "(5) Ver Lineas con Sublineas." << endl;
		cout << "(0) Salir." << endl << endl;
		cout << "==========================================================" << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{

		case 1:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Agregar Sublinea." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de la Linea en la que va a agregar la Sublinea." << endl;
			cin >> idLinea;
			cout << "Digite el ID de la Sublinea." << endl;
			cin >> idSubLinea;
			cout << "Digite la descripcion de la Sublinea." << endl;
			cin >> descripcion;

			SubLineaProducto * _subLinea = new SubLineaProducto(idSubLinea, descripcion, idLinea);

			switch (_lstLinea->agregarSubLinea(idLinea, _subLinea))
			{
			case 1:
			{
				cout << "Sublinea agregada correctamente." << endl;
			}
			break;

			case 2:
			{
				cout << "No se puede agregar la Sublinea por que la Linea no existe." << endl;
			}
			break;

			case 3:
			{
				cout << "Error! la Sublinea ya existe." << endl;
			}
			break;
			}
		}
		break;

		case 2:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Eliminar Sublinea" << endl;
			cout << "==========================================================" << endl << endl;

			cout << "Digite el ID de la Linea a la que pertenece la Sublinea" << endl;
			cin >> idLinea;
			cout << "Digite el ID de la Sublinea." << endl;
			cin >> idSubLinea;

			switch (_lstLinea->elimniarSubLinea(idLinea, idSubLinea))
			{
			case 1:
			{
				cout << "La Sublinea se elimino correctamente" << endl;
				system("pause");
			}
			break;

			case 2:
			{
				cout << "No se puede eliminar la Sublinea por que la Linea no existe" << endl;
				system("pause");
			}
			break;

			case 3:
			{
				cout << "La Sublinea que desea eliminar no existe" << endl;
				system("pause");
			}
			break;
			}
		}
		break;

		case 3:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "(3) Buscar Sublinea" << endl;
			cout << "==========================================================" << endl << endl;

			cout << "Digite el ID de la Linea " << endl;
			cin >> idLinea;
			cout << "Digite el ID de la Sublinea " << endl;
			cin >> idSubLinea;

			_lstLinea->buscarSublinea(idLinea, idSubLinea);
			system("pause");
		}
		break;

		case 4:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Ver Sublineas" << endl;
			cout << "==========================================================" << endl << endl;

			cout << "Digite el ID de la Linea." << endl;
			cin >> idLinea;

			_lstLinea->desplegarSubLineasDeLinea(idLinea);
			system("pause");
		}
		break;

		case 5:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Ver Lineas con Sublineas" << endl;
			cout << "==========================================================" << endl << endl;

			_lstLinea->desplegarLineasConSubLineas();
		}
		break;
		}
	} while (opc != 0);
}

void menuProducto(LstLineaProductos * _lstLinea)
{
	int opc = 0;

	int idLinea;
	int idSubLinea;
	int idProducto;
	char descripcion[30];
	double talla;
	double precio;

	do
	{
		system("cls");
		cout << "================ *** Menu de Producto *** ================" << endl << endl;
		cout << "(1) Agregar Producto" << endl;
		cout << "(2) Elimiar Producto" << endl;
		cout << "(3) Buscar Producto" << endl;
		cout << "(4) Ver Productos" << endl;
		cout << "(5) Ver Sublineas con Productos" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "==========================================================" << endl;
		cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

		switch (opc)
		{
		case 1:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Agregar Producto" << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de la Linea en la que va a agregar el producto" << endl;
			cin >> idLinea;
			cout << "Digite el ID de la Sublinea en la que va a agregar el producto" << endl;
			cin >> idSubLinea;
			cout << "Digite el ID del Producto" << endl;
			cin >> idProducto;
			cout << "Digite la descripcion del Producto" << endl;
			cin >> descripcion;
			cout << "Digite la talla del Producto" << endl;
			cin >> talla;
			cout << "Digite el precio del Producto" << endl;
			cin >> precio;

			Producto * producto = new Producto(idProducto, descripcion, talla, precio, idLinea, idSubLinea);


			switch (_lstLinea->agregarProducto(idLinea, idSubLinea, producto))
			{
			case 1:
			{
				cout << "Producto creado correctamaente." << endl;
				system("pause");
			}
			break;

			case 2:
			{
				cout << "No se puede agregar el Producto por que la Sublinea no existe." << endl;
				system("pause");
			}
			break;

			case 3:
			{
				cout << "Error! El Producto ya existe." << endl;
				system("pause");
			}
			break;

			case 4:
			{
				cout << "No se puede agregar el Producto por que la Linea no existe" << endl;
				system("pause");
			}
			break;
			}
		}
		break;

		case 2:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Eliminar Producto" << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de la Linea" << endl;
			cin >> idLinea;
			cout << "Digite el ID de la Sublinea" << endl;
			cin >> idSubLinea;
			cout << "Digite el ID del Producto que desea eliminar" << endl;
			cin >> idProducto;

			switch (_lstLinea->elimniarProducto(idLinea, idSubLinea, idProducto))
			{
			case 1:
			{
				cout << "El Producto se elimino correctamente" << endl;
				system("pause");
			}
			break;

			case 2:
			{
				cout << "No se puede eliminar el Producto por que la Sublinea no existe" << endl;
				system("pause");
			}
			break;

			case 3:
			{
				cout << "La Sublinea que desea eliminar no existe" << endl;
				system("pause");
			}
			break;

			case 4:
			{
				cout << "No se puede eliminar el Producto por que la Linea no existe" << endl;
				system("pause");
			}
			break;
			}
		}
		break;

		case 3:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Buscar Producto" << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID de la Linea " << endl;
			cin >> idLinea;
			cout << "Digite el ID de la SubLinea " << endl;
			cin >> idSubLinea;
			cout << "Digite el ID del Producto" << endl;
			cin >> idProducto;

			_lstLinea->buscarProducto(idLinea, idSubLinea, idProducto);
			system("pause");
		}
		break;

		case 4:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Ver Productos" << endl;
			cout << "==========================================================" << endl << endl;

			cout << "Digite el ID de la Linea." << endl;
			cin >> idLinea;
			cout << "Digite el ID de la Sublinea." << endl;
			cin >> idSubLinea;

			_lstLinea->desplegarProductosDeSubLinea(idLinea, idSubLinea);
			system("pause");
		}
		break;

		case 5:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Ver Sublineas con Productos" << endl;
			cout << "==========================================================" << endl << endl;

			cout << "Digite el ID de la Linea." << endl;
			cin >> idLinea;

			_lstLinea->desplegarSubLineasConProductos(idLinea);
		}
		break;
		}
	} while (opc != 0);
}

// Aqui van todos lo de Almacen
void menuMundoA(LstAlmacenes * lstAlmacenes, LstLineaProductos * lstLineas)
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** MENU PRINCIPAL *** ================" << endl << endl;
		cout << "(1) OPERACION ALMACENES" << endl;
		cout << "(2) OPERACION ALAMENCES CON INVENTARIOS" << endl;
		cout << "(3) OPERACION ALAMENCES CON ENTRADAS" << endl;
		cout << "(4) Facturacion" << endl;
		cout << "(0) Salir" << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			menuAlmacen(lstAlmacenes, lstLineas);
			break;
		}
		case 2:
		{
			//menuAlmacen_Inventario(listaAlmacenes);
			break;
		}
		case 3:
		{
			//menuAlmacen_Entrada(listaAlmacenes);
			break;
		}
		case 4:
		{
			menuFacturacion(lstAlmacenes, lstLineas);
			break;
		}
		}

	} while (opcion != 0);
}


// Aqui van todos lo de Linea Producto
void menuMundoB(LstLineaProductos * _lstLinea)
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** MENU PRINCIPAL *** ================" << endl << endl;
		cout << "(1) Menu de Lineas" << endl;
		cout << "(2) Menu de SubLineas" << endl;
		cout << "(3) Menu de Productos" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "========================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			menuLinea(_lstLinea);
		}
		break;

		case 2:
		{
			menuSubLinea(_lstLinea);
		}
		break;

		case 3:
		{
			menuProducto(_lstLinea);
		}
		break;
		}
	} while (opcion != 0);
}

// Aqui van Mundo A y Mundo B
void menuPrincipalAB(LstAlmacenes * listaAlmacenes, LstLineaProductos *listaLineaProductos)
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** MENU PRINCIPAL *** ================" << endl << endl;
		cout << "(1) OPERACION MUNDO A (ALMACENES, FACTURAS, ENTRADAS, INVENTARIOS)" << endl;
		cout << "(2) OPERACION MUNDO B (LINEA PRODUCTO, SUBLINEA, PRODUCTO)" << endl;
		cout << "(0) Salir" << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			menuMundoA(listaAlmacenes,listaLineaProductos);
			break;
		}
		case 2:
		{
			menuMundoB(listaLineaProductos);
			break;
		}
		}
		system("pause");
	} while (opcion != 0);

}

/*void MenuLineas(LstLineaProductos * _lstLineaProductos)
{
int opc = 0;

int idLinea;
int idSubLinea;
int idProducto;
char descripcion[30];
int grupo;
int creditos;

int carnet;
char nombre[15];
char apellido[15];


do
{
system("cls");
cout << "================ *** Menu de Linea *** ================" << endl;
cout << "Opciones sobre Cursos" << endl;
cout << "(1) Crear Linea" << endl;
cout << "(2) Editar Linea" << endl;
cout << "(3) Elimiar Linea" << endl;
cout << "(4) Buscar Linea" << endl;
cout << "(5) Ver Lineas" << endl;
cout << "(6) Crear SubLinea" << endl;
cout << "(7) Editar SubLinea" << endl;
cout << "(8) Elimiar SubLinea" << endl;
cout << "(9) Buscar SubLinea" << endl;
cout << "(10) Ver SubLineas" << endl;
cout << "(11) Crear Producto" << endl;
cout << "(12) Editar Producto" << endl;
cout << "(13) Elimiar Producto" << endl;
cout << "(14) Buscar Producto" << endl;
cout << "(15) Ver Productos" << endl;
cout << "(0) Salir" << endl;
cout << "=======================================================" << endl << endl;
cout << "Opcion seleccionada: "; cin >> opc; cout << endl;

switch (opc)
{

case 1:
{
cout << "(1) Crear Linea" << endl;

cout << "Digite le ID del Linea" << endl;
cin >> idLinea;
cout << "Digite la descripcion de la Linea" << endl;
cin >> descripcion;
LineaProducto * nuevo = new LineaProducto(idLinea, descripcion);
_lstLineaProductos->agregar(nuevo);
_lstLineaProductos->desplegar();
}
break;

case 2:
{
cout << "(2) Editar Linea" << endl;

int dlt = 0;

do
{
cout << "Digite el Id de la linea que desea editar" << endl;
cin >> idLinea;

LineaProducto * _linea = _lstLineaProductos->buscar(idLinea);

if (_linea == NULL)
{
cout << "La linea no existe" << endl;
cout << "Digite (1) para intentar editar de nuevo o (0) para regresar al menu anterior" << endl;
cin >> dlt;
system("cls");
}
else
{
cout << "============================================" << endl;
cout << "ID: " << _linea->getIdLineaProducto << endl;
cout << "Descripcion: " << _linea->getDescripcion() << endl;
cout << "============================================" << endl;
cout << endl;
cout << "Esta seguro de que desea editar esta linea?" << endl;
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
cout << "Digite los nuevos parametros de la linea" << endl << endl;

cout << "Digite el codigo de la linea." << endl;
cin >> idLinea;
cout << "Digite el descripcion de la linea." << endl;
cin >> descripcion;

LineaProducto * nuevo = new LineaProducto(idLinea, descripcion);

_lstLineaProductos->modificar(idLinea, nuevo);

cout << "============================================" << endl;
cout << "Codigo: " << _linea->getIdLineaProducto() << endl;
cout << "Descripcion: " << _linea->getDescripcion() << endl;
cout << "============================================" << endl;
cout << endl;

cout << "El _linea se ha modificado corretamente" << endl;
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
cout << "(3) Eliminar Linea" << endl;

int dlt = 0;

do
{
cout << "Digite el ID de la linea que desea eliminar" << endl;
cin >> idLinea;

LineaProducto * _linea = _lstLineaProductos->buscar(idLinea);

if (_linea == NULL)
{
cout << "La linea no existe" << endl;
cout << "Digite (1) para intentar eliminar de nuevo o (0) para regresar al menu anterior" << endl;
cin >> dlt;
system("cls");
}
else
{
cout << "============================================" << endl;
cout << "ID: " << _linea->getIdLineaProducto() << endl;
cout << "Descripcion: " << _linea->getDescripcion() << endl;
cout << "============================================" << endl;
cout << endl;
cout << endl;
cout << "Esta seguro de que desea eliminar esta linea?" << endl;
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
_lstLineaProductos->eliminar(idLinea);
cout << "La linea se ha eliminado corretamente" << endl;
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

case 4:
{
cout << "(4) Buscar Linea" << endl;

cout << "Digite el ID de la linea que desea buscar" << endl;
cin >> idLinea;

LineaProducto * _linea = _lstLineaProductos->buscar(idLinea);

if (_linea != NULL)
{
cout << "============================================" << endl;
cout << "ID: " << _linea->getIdLineaProducto << endl;
cout << "Descripcion: " << _linea->getDescripcion() << endl;
cout << "============================================" << endl;
system("pause");
system("cls");
}
else
{
cout << "El curso no existe" << endl;
system("pause");
system("cls");
}
}
break;

case 5:
{
cout << "(5) Ver Lineas" << endl;

_lstLineaProductos->desplegar();
}
break;

case 6:
{
cout << "(6) Agregar SubLinea" << endl;

cout << "Digite el id de la Sublinea" << endl;
cin >> idSubLinea;
cout << "Digite la descripcion de la sublinea" << endl;
cin >> descripcion;

SubLineaProducto * _subLinea = new SubLineaProducto(idSubLinea, descripcion);

cout << "Digite el codigo de la linea en la que va a agregar la sublinea" << endl;
cin >> idLinea;

switch (_lstLineaProductos->agregarSubLinea(idLinea, _subLinea))
{
case 1:
{
cout << "Se ha agregado la sublinea correctamente" << endl;
}
break;

case 2:
{
cout << "No se puede agregar la sublinea por que la linea no existe" << endl;
}
break;

case 3:
{
cout << "La sublinea habia sido creada anteriormente" << endl;
}
break;
}
}
break;

case 7:
{
cout << "(7) Editar sublinea" << endl;

cout << "Digite el id de la sublinea" << endl;
cin >> idSubLinea;
cout << "Digite el id de la linea a la que pertenece la sublinea" << endl;
cin >> idLinea;
cout << "=======================================================================" << endl;

cout << "Digite la nueva descripcion de la sublinea" << endl;
cin >> idLinea;


}
break;

case 8:
{
cout << "(8) Eliminar sublinea" << endl;

cout << "Digite el id de la sublinea" << endl;
cin >> idSubLinea;
cout << "Digite el id de la linea a la que pertenece la sublinea" << endl;
cin >> idLinea;

switch (_lstLineaProductos->elimniarSubLinea(idLinea, idSubLinea))
{
case 1:
{
cout << "La sublinea se elimino correctamente" << endl;
}
break;

case 2:
{
cout << "No se puede eliminar la sublinea por que la linea no existe" << endl;
}
break;

case 3:
{
cout << "La sublinea que desea eliminar no existe" << endl;
}
break;
}
}
break;
}
} while (opc != 0);
}*/

int main()
{
	//listasMenu();

	LstAlmacenes * lstAlmacenes = new LstAlmacenes();

	LstLineaProductos * lstLineas = new LstLineaProductos();


	menuPrincipalAB(lstAlmacenes, lstLineas);


	system("pause");
	return 0;
}

