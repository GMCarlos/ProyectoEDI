/*
 * ui.cpp
 *
 *  Created on: 09/04/2017
 *      Author: Profesores de EDI
 */

#include <fstream>
#include <iostream>
#include "ui.h"
#include "timer.h"
using namespace std;

UI::UI() {
	// TODO falta por terminar
	ejecutar();
}

void UI::ejecutar() {
	OpenDataCc *open = new OpenDataCc;
	int opcion;
	string s;
	string t;
	string lampara1;
	string lampara2;
	PruebasDeModulosProyecto *pruebas = new PruebasDeModulosProyecto;
	int op;
	double t_start, t_end;
	bool salir = false;
	do {
		opcion = menu();
		switch (opcion) {
		case 1:
			t_start = Timer::getTime();
			cout << "Cargando datos ... " << endl;
			open->cargarDistritos();
			open->cargarBarrios();
			open->cargarVias();
			open->cargarFarolas();
			cout << "Carga finalizada ... " << endl;
			t_end = Timer::getTime();
			cout << "Realizado en " << std::fixed << std::setprecision(6)
								<< t_end - t_start << " secs." << endl;
						cout<<"------------------------------------------------------"<<endl;
			break;
		case 2:
			t_start = Timer::getTime();
			cout << "Inserta un barrio" << endl;
			getline(cin, s, '\n');
			open->buscarViasBarrio(s);
			t_end = Timer::getTime();
					cout << "Realizado en " << std::fixed << std::setprecision(6)
										<< t_end - t_start << " secs." << endl;
								cout<<"------------------------------------------------------"<<endl;
			break;
		case 3:
			t_start = Timer::getTime();
			cout << "Inserta un Distrito" << endl;
			getline(cin, s, '\n');
			open->obtenerViasDeDistrito(s);
			t_end = Timer::getTime();
					cout << "Realizado en " << std::fixed << std::setprecision(6)
										<< t_end - t_start << " secs." << endl;
								cout<<"------------------------------------------------------"<<endl;
			break;
		case 4:
			t_start = Timer::getTime();
			cout << "Introduzca un barrio" << endl;
			getline(cin, s, '\n');
			open->barriosAdyacentes(s);
			t_end = Timer::getTime();
					cout << "Realizado en " << std::fixed << std::setprecision(6)
										<< t_end - t_start << " secs." << endl;
								cout<<"------------------------------------------------------"<<endl;
			break;
		case 5:
			t_start = Timer::getTime();
			open->concentracionFarolas();
			t_end = Timer::getTime();
					cout << "Realizado en " << std::fixed << std::setprecision(6)
										<< t_end - t_start << " secs." << endl;
								cout<<"------------------------------------------------------"<<endl;
			break;
		case 6:
			t_start = Timer::getTime();
			cout << "Introduzca un tipo de lampara:" << endl;
			getline(cin, s, '\n');
			open->obtenerViasConTipoDeFarola(s);
			t_end = Timer::getTime();
					cout << "Realizado en " << std::fixed << std::setprecision(6)
										<< t_end - t_start << " secs." << endl;
								cout<<"------------------------------------------------------"<<endl;
			break;
		case 7:
			cout << "Introduzca caracteres por los que buscar:" << endl;
			getline(cin, s, '\n');
			//Por arboles
			cout << "CON ARBOLES..." << endl;
			t_start = Timer::getTime();
			open->buscarEmpizaPor(s);
			t_end = Timer::getTime();
			cout << "Realizado en " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			cout<<"------------------------------------------------------"<<endl;
			//Por lista
			cout << "CON LISTAS..." << endl;
			t_start = Timer::getTime();
			open->buscarViaQueEmpiezaPorLista(s);
			t_end = Timer::getTime();
			cout << "Realizado en " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			cout<<"------------------------------------------------------"<<endl;
			break;

		case 8:
			cout << "CON LISTAS..." << endl;
			t_start = Timer::getTime();
			open->consumoDistrito();
			t_end = Timer::getTime();
			cout << "Realizado en " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			cout<<"------------------------------------------------------"<<endl;
			cout << "CON ARBOLES..." << endl;
			t_start = Timer::getTime();
			open->consumoDistritoArbol();
			t_end = Timer::getTime();
			cout << "Realizado en " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			cout<<"------------------------------------------------------"<<endl;

			break;
		case 9:
			cout << "Introduzca el primer tipo de lampara" << endl;
			cin >> lampara1;
			cout << "Introduzca el segundo tipo de lampara" << endl;
			cin >> lampara2;
			t_start = Timer::getTime();
			open->ahorroConsumo(lampara1, lampara2);
			t_end = Timer::getTime();
						cout << "Realizado en " << std::fixed << std::setprecision(6)
								<< t_end - t_start << " secs." << endl;
						cout<<"------------------------------------------------------"<<endl;

			break;
		case 10:
			// TODO llamada a el método
			cout << "Introduzca el nombre de la via que desea cambiar:" << endl;
			getline(cin, s, '\n');
			cout << "Introduzca el nuevo nombre de la via:" << endl;
			getline(cin, t, '\n');
			cout<<"0. Listas \n1. Arboles"<<endl;
			cin>>op;
			if(op==0){
			cout<<"POR LISTAS...."<<endl;
			t_start = Timer::getTime();
			open->cambiarNombreVia(s, t);
			t_end = Timer::getTime();
						cout << "Realizado en " << std::fixed << std::setprecision(6)
								<< t_end - t_start << " secs." << endl;
						cout<<"------------------------------------------------------"<<endl;
			}else if(op ==1){
				cout<<"POR ARBOLES..."<<endl;
				t_start = Timer::getTime();
			open->cambiarNombreViaArbol(s, t);
			t_end = Timer::getTime();
									cout << "Realizado en " << std::fixed << std::setprecision(6)
											<< t_end - t_start << " secs." << endl;
									cout<<"------------------------------------------------------"<<endl;
			}
			break;
		case 11:
		            cout<<"Prueba del modulo 2"<<endl;
		            pruebas->pruebaModulo2();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 3"<<endl;
		            pruebas->pruebaModulo3();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 4"<<endl;
		            pruebas->pruebaModulo4();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 5"<<endl;
		            pruebas->pruebaModulo5();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 6"<<endl;
		            pruebas->pruebaModulo6();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 7"<<endl;
		            pruebas->pruebaModulo7();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 8"<<endl;
		            pruebas->pruebaModulo8();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 9"<<endl;
		            pruebas->pruebaModulo9();
		            cout<<"-------------------------------------------------"<<endl;

		            cout<<"Prueba del modulo 10"<<endl;
		            pruebas->pruebaModulo10();
		            cout<<"-------------------------------------------------"<<endl;

		            break;


		case 0:


			salir = true;
			break;
		default:
			cout << "ERROR en la opcion de menu" << endl;
			break;
		}

	} while (!salir);
}

int UI::menu() {

	int opcion;

	do {
		cout << endl;
		cout << "__________________ MENU PRINCIPAL ________________" << endl
				<< endl;

		cout << "   1. Carga de datos                          " << endl;
		cout << "   2. Mostrar vías de un barrio               " << endl;
		cout << "   3. Generar fichero vías de un distrito     " << endl;
		cout << "   4. Barrios adyacentes                      " << endl;
		cout << "   5. Vía con mayor concentración de farolas  " << endl;
		cout << "   6. Generar fichero de farolas según lámpara" << endl;
		cout << "   7. Buscar vías, empieza por...             " << endl;
		cout << "   8. Consumo eléctrico por distrito          " << endl;
		cout << "   9. Informe de ahorro                       " << endl;
		cout << "   10. Cambiar nombre a una vía                " << endl;
		cout << "   11. Pruebas               " << endl;
		cout << endl;
		cout << "   0. Finalizar.                              " << endl;
		cout << "Opcion:  ";
		cin >> opcion;
		cin.ignore();
	} while ((opcion < 0) || (opcion > 12));

	return opcion;
}

UI::~UI() {
	// TODO falta por hacer
}

int main() {
	UI ui;
}

