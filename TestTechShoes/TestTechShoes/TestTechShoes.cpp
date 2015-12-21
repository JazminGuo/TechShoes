// Proyecto Tech Shoes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LstAlmacenes.h"
#include "LstLineaProductos.h"


/*----------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------ MENU INDEPEDIENTE -------------------------------------------------- */
/*----------------------------------------------------------------------------------------------------------------------------------*/

// MENU PARA MUNDO A
void menuAlmacen(LstAlmacenes * lstAlmacenes, LstLineaProductos * lstLineas)
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
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Agregar Almacen." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el id del almacen." << endl;
			cin >> idAlmacen;
			cout << "Digite la ubicacion del almacen." << endl;
			cin >> ubicacion;


			Almacen * almacen = new Almacen(idAlmacen, ubicacion);
			LstProductos *listaProductos = new LstProductos();

			//lstAlmacenes->agregaAsc(almacen, lstLineas);

			if (lstAlmacenes->agregaAsc(almacen, lstLineas))
			{
				lstAlmacenes->autoAgregar(idAlmacen, lstLineas);
			}
			else
			{
				cout << "No se agrego el almacen" << endl;
			}

			lstAlmacenes->desplegarLista();
			system("pause");
			system("cls");
		}
		break;

		case 2:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Buscar Almacen." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el id del almacen que desea buscar" << endl;
			cin >> idAlmacen;
			cout << "Digite el id del inventario que desea buscar" << endl;
			cin >> idProducto;

			lstAlmacenes->desplegarUnInventarioDeUnAlmacen(idAlmacen, idProducto);

			//Almacen * almacen = lstAlmacenes->obtenerAlmacen(idAlmacen);

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
				system("cls");
				cout << "==========================================================" << endl;
				cout << "Eliminar Almacen." << endl;
				cout << "==========================================================" << endl << endl;
				cout << "Digite el id del almacen que desea eliminar" << endl;
				cin >> idAlmacen;

				Almacen * almacen = lstAlmacenes->obtenerAlmacen(idAlmacen);

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
						lstAlmacenes->eliminar(idAlmacen);
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
			lstAlmacenes->desplegarTodosInventariosDeTodosAlmacenes();
			system("pause");
		}
		break;
		}
		system("cls");
	} while (opc != 0);
}

void menuEntradas(LstAlmacenes * lstAlmacenes, LstLineaProductos * lstLineas)
{
	int opcion = 0;

	int idAlmacen;
	int idLinea;
	int idSublinea;
	int idProducto;
	int idArticulo;
	int existencia;

	do
	{
		system("cls");
		cout << "================ *** Menu Entradas *** ================" << endl << endl;
		cout << "(1) Nueva Entrada" << endl;
		cout << "(2) Anular Entrada" << endl;
		cout << "(3) Ver Entradas por Almacen" << endl;
		cout << "(4) Ver Todas las Entradas" << endl;
		cout << "(0) Salir" << endl;
		cout << "====================================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;
		switch (opcion)
		{
		case 1:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Nueva Entrada." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID del Almacen: "; cin >> idAlmacen;
			cout << "Digite el ID de la Linea: "; cin >> idLinea;
			cout << "Digite el ID de la Sublinea: "; cin >> idSublinea;
			cout << "Digite el ID del Producto: "; cin >> idProducto;

			if (lstLineas->dirNodoGlobal(idLinea, idSublinea, idProducto))
			{
				cout << "Digite la cantidad de entrada: "; cin >> existencia; cout << endl;

				Entrada * entrada = new Entrada(idLinea, idSublinea, idProducto, existencia);

				lstAlmacenes->agregarEntrada(idAlmacen, entrada);
				lstAlmacenes->sumarExistencia(idAlmacen, idLinea, idSublinea, idProducto, existencia);

				cout << "Entrada agregada correctamente" << endl;
			}
			else
			{
				cout << "Imposible agregar entrada, el articulo no existe." << endl;
			}
		}
		break;

		case 2:
		{
			system("cls");
			cout << endl;
			cout << "------- Anulando Una Entrada de Un Almacen --------" << endl << endl;
			cout << "Digite el ID Almacen Existente: "; cin >> idAlmacen;
			cout << "Digite el ID Articulo Existente: "; cin >> idArticulo;
			switch (lstAlmacenes->anularUnaEntradaDeUnAlmacen(idAlmacen, idArticulo))
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
			lstAlmacenes->desplegarUnaEntradaDeUnAlmacen(idAlmacen, idArticulo);
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			cout << endl;
			cout << "------- Desplegando Una Entrada de Un Almacen --------" << endl << endl;
			lstAlmacenes->desplegarTodosEntradaDeTodosAlmacen();
			system("pause");
			break;
		}
		}
	} while (opcion != 0);
}

void menuFacturacion(LstAlmacenes * lstAlmacenes, LstLineaProductos * lstLineas)
{
	SYSTEMTIME st;

	GetSystemTime(&st);

	int dia = st.wDay;
	int mes = st.wMonth;
	int anno = st.wYear;

	char date[12];
	sprintf_s(date, "%02d/%02d/%02d", dia, mes, anno);

	int opcion = 0;

	int idAlmacen = 0;
	int idLinea = 0;
	int idSublinea = 0;
	int idProducto = 0;
	int cantidad = 0;
	int idFactura = 0;
	int numLinea = 0;

	char cliente[30] = "---";
	int opc = 0;

	do
	{
		system("cls");
		cout << "======================== *** Facturacion *** ========================" << endl << endl;
		cout << "(1) Facturar" << endl;
		cout << "(2) Anular Factura" << endl;
		cout << "(3) Buscar Factura" << endl;
		cout << "(4) Ver Facturas por Almacen" << endl;
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
			cout << "Digite el ID del Almacen: "; cin >> idAlmacen;
			idFactura = lstAlmacenes->ultimaFactura(idAlmacen) + 1;
			cout << "Digite el nombre del cliente: "; cin >> cliente;

			Factura * factura = new Factura(idFactura, date, cliente);

			switch (lstAlmacenes->agregarFactura(idAlmacen, factura))
			{
			case 1:
			{
				int dlt = 0;

				cout << "======================== *** Facturacion *** ========================" << endl << endl;
				cout << "(1) Anadir Productos" << endl;
				cout << "(0) Terminar Factura" << endl << endl;
				cout << "=====================================================================" << endl << endl;
				cout << "Opcion Seleccionada: "; cin >> dlt; cout << endl;

				do
				{
					switch (dlt)
					{ 
						case 1:
						{
							system("cls");
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

								if (lstAlmacenes->restarExistencia(idAlmacen, idLinea, idSublinea, idProducto, cantidad))
								{
									LineaFactura * nueva = new LineaFactura(idFactura, numLinea, idLinea, idSublinea, idProducto, cantidad);

									lstAlmacenes->agregarLineaFactura(idAlmacen, idFactura, nueva);

									system("cls");
									cout << "Producto agregado a la Factura" << endl << endl;
									lstAlmacenes->imprimirFactura(idAlmacen, idFactura, lstLineas);

									cout << endl << endl;
									cout << "Seleccione una opcion" << endl;
									cout << "(1) Anandir mas Productos" << endl;
									cout << "(2) Eliminar Linea" << endl;
									cout << "(0) Terminar Factura" << endl;
									cout << "Opcion selecionada: "; cin >> dlt; cout << endl << endl;
								}
								else
								{
									cout << "No se puede agregar el Producto por que no hay suficientes en el Inventario" << endl << endl;
									cout << "Seleccione una opcion" << endl;
									cout << "(1) Anandir mas Productos" << endl;
									cout << "(0) Terminar Factura" << endl;
									cout << "Opcion selecionada: "; cin >> dlt; cout << endl << endl;
								}
							}
							else
							{
								cout << "El producto que desea anadir a la factura no existe." << endl << endl;
								cout << "Seleccione una opcion" << endl;
								cout << "(1) Anandir mas Productos" << endl;
								cout << "(2) Eliminar Linea" << endl;
								cout << "(0) Terminar Factura" << endl;
								cout << "Opcion selecionada: "; cin >> dlt; cout << endl << endl;
							}
						}
						break;

						case 2:
						{
							system("cls");
							switch (lstAlmacenes->elimniarLineaFactura(idAlmacen, idFactura, numLinea))
							{
							case 1:
							{
								cout << "Linea eliminada correctamente" << endl << endl;
								lstAlmacenes->sumarExistencia(idAlmacen, idLinea, idSublinea, idProducto, cantidad);
								lstAlmacenes->imprimirFactura(idAlmacen, idFactura, lstLineas);
								cout << endl << endl;
								cout << "Seleccione una opcion" << endl;
								cout << "(1) Anandir mas Productos" << endl;
								cout << "(2) Eliminar Linea" << endl;
								cout << "(0) Terminar Factura" << endl;
								cout << "Opcion selecionada: "; cin >> dlt; cout << endl << endl;
							}
							break;

							case 2:
							{
								cout << endl; cout << "No se puede eliminar la Linea por que la Factura no existe" << endl;
								cout << endl << endl;
								cout << "Seleccione una opcion" << endl;
								cout << "(1) Anandir mas Productos" << endl;
								cout << "(2) Eliminar Linea" << endl;
								cout << "(0) Terminar Factura" << endl;
								cout << "Opcion selecionada: "; cin >> dlt; cout << endl << endl;
							}
							break;

							case 3:
							{
								cout << endl; cout << "No se puede eliminar la Linea por que la Linea no existe" << endl;
								cout << endl << endl;
								cout << "Seleccione una opcion" << endl;
								cout << "(1) Anandir mas Productos" << endl;
								cout << "(2) Eliminar Linea" << endl;
								cout << "(0) Terminar Factura" << endl;
								cout << "Opcion selecionada: "; cin >> dlt; cout << endl << endl;
							}
							break;

							case 4:
							{
								cout << endl; cout << "No se puede eliminar la Linea por que El Almacen no existe" << endl;
								cout << endl << endl;
								cout << "Seleccione una opcion" << endl;
								cout << "(1) Anandir mas Productos" << endl;
								cout << "(2) Eliminar Linea" << endl;
								cout << "(0) Terminar Factura" << endl;
								cout << "Opcion selecionada: "; cin >> dlt; cout << endl << endl;
							}
							break;
							}
						}
						break;
					}
				} while (dlt != 0);
			}
			break;

			case 2:
			{
				cout << endl; cout << "No se puede crear la Factura por que el Almacen no existe" << idAlmacen << " !" << endl;
				break;
			}
			case 3:
			{
				cout << endl; cout << "No se puede crea la Factura por que la Factura ya existe" << endl;
				break;
			}
			}
			system("pause");
			break;
		}
		case 2:
		{

			system("cls");
			cout << "==========================================================" << endl;
			cout << "Anular Factura." << endl;
			cout << "==========================================================" << endl << endl;
			cout << "Digite el ID del Almacen: "; cin >> idAlmacen;
			cout << "Digite el ID de la Factura: "; cin >> idFactura;
			switch (lstAlmacenes->elimniarFactura(idAlmacen, idFactura))
			{
			case 1:
			{
				cout << endl; cout << "Se Elimino la Factura " << idFactura << " Correctamente!" << endl;
				break;
			}
			case 2:
			{
				cout << endl; cout << "No se puede eliminar la Factura por que el Almacen no existe" << idAlmacen << " !" << endl;
				break;
			}
			case 3:
			{
				cout << endl; cout << "No se puede eliminar la Factura por que la Factura no existe" << endl;
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


// MENU PARA MUNDO B
void menuLinea(LstLineaProductos * _lstLinea, LstAlmacenes * listaAlmacenes)
{
	int opcion = 0;

	int idRef;
	int vidProducto;
	char vdescripcion[30];

	do
	{
		system("cls");
		cout << "================= *** Menu de Categorias *** ==================" << endl << endl;
		cout << "(1) Agregar Categoria." << endl;
		cout << "(2) Eliminar Categoria." << endl;
		cout << "(3) Buscar Categoria." << endl;
		cout << "(4) Ver Categorias." << endl;
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
			cout << "Eliminar Categoria" << endl;
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
		case 3:
		{
			system("cls");
			cout << "==========================================================" << endl << endl;
			cout << "Buscar Categoria." << endl;
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
		case 4:
		{
			system("cls");
			cout << "==========================================================" << endl;
			cout << "Ver Categorias." << endl;
			cout << "==========================================================" << endl << endl;
			_lstLinea->desplegar();
			system("pause");
			break;
		}
		}
		//system("pause");
	} while (opcion != 0);
}

void menuSubLinea(LstLineaProductos * _lstLinea, LstAlmacenes * listaAlmacenes)
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

void menuProducto(LstLineaProductos * _lstLinea, LstAlmacenes * listaAlmacenes)
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
			//cout << "Digite el ID del Producto" << endl;
			//cin >> idProducto;
			cout << "Digite la descripcion del Producto" << endl;
			cin >> descripcion;
			cout << "Digite la talla del Producto" << endl;
			cin >> talla;
			cout << "Digite el precio del Producto" << endl;
			cin >> precio;

			idProducto = _lstLinea->dirNodo(idLinea)->getLstSubLineaProductos()->dirNodo(idSubLinea)->getLstProductos()->getSize() + 1;

			Producto * producto = new Producto(idProducto, descripcion, talla, precio, idLinea, idSubLinea);


			switch (_lstLinea->agregarProducto(idLinea, idSubLinea, producto))
			{
			case 1:
			{
				listaAlmacenes->actualizarInventariosDeTodosAlmacenAuto(_lstLinea);
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
			cout << "Buscar Productos" << endl;
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
		cout << "================ *** Menu Principal *** ================" << endl << endl;
		cout << "(1) Almacenes" << endl;
		cout << "(2) Inventario" << endl;
		cout << "(3) Entradas" << endl;
		cout << "(4) Facturacion" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "========================================================" << endl << endl;
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
			menuEntradas(lstAlmacenes, lstLineas);
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
void menuMundoB(LstLineaProductos * _lstLinea, LstAlmacenes * listaAlmacenes)
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** Menu Principal *** ================" << endl << endl;
		cout << "(1) Categorias" << endl;
		cout << "(2) Subcategorias" << endl;
		cout << "(3) Productos" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "========================================================" << endl << endl;
		cout << "Opcion Seleccionada: "; cin >> opcion; cout << endl;

		switch (opcion)
		{
		case 1:
		{
			menuLinea(_lstLinea, listaAlmacenes);
		}
		break;

		case 2:
		{
			menuSubLinea(_lstLinea, listaAlmacenes);
		}
		break;

		case 3:
		{
			menuProducto(_lstLinea, listaAlmacenes);
		}
		break;
		}
	} while (opcion != 0);
}

// Aqui van Mundo A y Mundo B
void menuPrincipalAB(LstAlmacenes * listaAlmacenes, LstLineaProductos * listaLineaProductos)
{
	int opcion = 0;

	do
	{
		system("cls");
		cout << "================ *** Menu Principal *** ================" << endl << endl;
		cout << "(1) (Almacenes, Facturacion, Entradas, Inventario)" << endl;
		cout << "(2) (Categorias, Subcategorias, Productos)" << endl;
		cout << "(0) Salir" << endl << endl;
		cout << "========================================================" << endl << endl;
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
			menuMundoB(listaLineaProductos, listaAlmacenes);
			break;
		}
		}
		system("pause");
	} while (opcion != 0);

}



int main()
{
	LstAlmacenes * lstAlmacenes = new LstAlmacenes();
	LstLineaProductos * lstLineas = new LstLineaProductos();

	menuPrincipalAB(lstAlmacenes, lstLineas);
	return 0;
}

