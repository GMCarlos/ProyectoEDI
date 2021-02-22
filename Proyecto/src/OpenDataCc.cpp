/*
 * OpenDataCc.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase que gestiona las acciones a realizar
 */

#include "OpenDataCc.h"

OpenDataCc::OpenDataCc() {
	barrios = new Barrios;
	distritos = new Distritos;
	calles = new Vias;

}
OpenDataCc::~OpenDataCc() {
	if (distritos != NULL)
		delete distritos;
	if (calles != NULL)
		delete calles;
	if (barrios != NULL)
		delete barrios;
}
void OpenDataCc::obtenerViasDeDistrito(string s) {
	if(distritos->esta(s)){
	calles->obtenerViasDelDistrito(s);
	}else
		cout<<"El distrito no existe"<<endl;
}
void OpenDataCc::obtenerViasConTipoDeFarola(string s) {
	calles->obtenerViasConFarolaEspecifica(s);

}
void OpenDataCc::concentracionFarolas() {
	Via *v;
	string nombre;
	float p;
	calles->viaMayorConcentracion(v, p);
	cout << "Via con mayor concentracion de farolas:" << endl;
	v->getNombre(nombre);
	cout << nombre << " proporcion:" << p << endl;
}
void OpenDataCc::buscarViasBarrio(string s) {
	if (barrios->esta(s)) {
		Vias *c = new Vias;
		calles->buscarCallesBarrio(c, s);
		c->mostrar();
		c->~Vias();
	}else
		cout<<"El barrio introducido no existe"<<endl;

}
void OpenDataCc::barriosAdyacentes(string s) {
	if (barrios->esta(s)) {
		Vias *c = new Vias;
		//vias del barrio
		calles->buscarCallesBarrio(c, s);
		Barrio *b;
		Barrios *barriosaux = new Barrios;
		barrios->buscarBarrio(b, s);
		c->buscarBarriosAdyacentes(calles, b, barriosaux);
		barriosaux->mostrar();
	}else
		cout<<"El barrio introducido no existe"<<endl;

}
void OpenDataCc::cargarVias() {
	if (calles->viasVacia()) {
		ifstream fent;
		string linea;
		string vector[11];
		fent.open("Via.csv");
		if (fent.is_open()) {
			getline(fent, linea);
			while (!fent.eof()) {
				for (int i = 0; i < 10; i++) {
					getline(fent, vector[i], ';');
				}
				Barrio *b;
				getline(fent, vector[10]);
				Via* v;
				if (barrios->buscarBarrio(b, vector[10])) {
					v = new Via(vector[0], atof(vector[1].c_str()), vector[2],
							vector[3], atof(vector[6].c_str()),
							atof(vector[7].c_str()), atof(vector[8].c_str()),
							atof(vector[9].c_str()), atof(vector[5].c_str()),
							atof(vector[4].c_str()), b);
				} else
					v = new Via(vector[0], atof(vector[1].c_str()), vector[2],
							vector[3], atof(vector[6].c_str()),
							atof(vector[7].c_str()), atof(vector[8].c_str()),
							atof(vector[9].c_str()), atof(vector[5].c_str()),
							atof(vector[4].c_str()), NULL);

				calles->insertarViaOrden(v);
				calles->insertarViasEnArbol(v);

			}
			fent.close();
		}
	}
}
void OpenDataCc::cargarDistritos() {
	if (distritos->distritosVacios()) {
		ifstream fent;
		string linea;
		fent.open("Distrito.csv");
		getline(fent, linea);
		if (fent.is_open()) {
			while (!fent.eof()) {
				getline(fent, linea, ';');
				getline(fent, linea, '\r');
				Distrito *d = new Distrito(linea);
				distritos->insertarDistritoFinal(d);
			}
		} else
			cout << "error al abrir el fichero" << endl;
		fent.close();
	}
}
void OpenDataCc::cargarBarrios() {
	if (barrios->barriosVacio()) {
		fstream fent;
		string linea;
		string linea2;
		Distrito *d;
		fent.open("Barrio.csv");
		getline(fent, linea);
		if (fent.is_open()) {
			while (!fent.eof()) {
				getline(fent, linea, ';');
				getline(fent, linea, ';');
				getline(fent, linea2, ';');
				getline(fent, linea2);
				Barrio *b;
				if (distritos->buscarDistrito(d, linea2)) {
					b = new Barrio(linea, d);
				} else
					b = new Barrio(linea, NULL);
				barrios->insertarBarrioF(b);

			}
		} else
			cout << "error al abrir el fichero" << endl;
		fent.close();
	}
}
void OpenDataCc::cargarFarolas() {
	if (calles->farolasVacia()) {
		ifstream fent;
		string linea;
		string vector[12];
		string nombre;
		fent.open("Farola.csv");
		if (fent.is_open()) {
			getline(fent, linea);
			while (!fent.eof()) {
				getline(fent, linea, ',');
				for (int i = 0; i < 11; i++) {
					getline(fent, vector[i], ',');

				}
				Via *v = new Via;
				float lat = atof(vector[7].c_str());
				float lon = atof(vector[4].c_str());
				calles->farolasEnVias(v, lat, lon);
				getline(fent, vector[11]);
				Farola *f;
				if (v != NULL)
					f = new Farola(vector[0], vector[1], vector[2], vector[3],
							atof(vector[4].c_str()), atoi(vector[5].c_str()),
							vector[6], atof(vector[7].c_str()),
							atoi(vector[8].c_str()), vector[9],
							atoi(vector[10].c_str()), vector[11], v);
				else if (v != NULL)
					f = new Farola(vector[0], vector[1], vector[2], vector[3],
							atof(vector[4].c_str()), atoi(vector[5].c_str()),
							vector[6], atof(vector[7].c_str()),
							atoi(vector[8].c_str()), vector[9],
							atoi(vector[10].c_str()), vector[11], NULL);
				calles->insertarFarolaFinal(f);
				//calles->insertarFarolasEnArbol(f);
			}
			fent.close();
		}
	}
}
void OpenDataCc::cambiarNombreViaArbol(string s, string t) {
	bool enc = false;

	enc = calles->buscar(s,  t);

	if (!enc) {

		cout << "Via " << s << " no encontrada!" << endl;
	}

}
void OpenDataCc::cambiarNombreVia(string s, string t) {
	calles->cambiarNombre(s, t);
}
void OpenDataCc::buscarEmpizaPor(string s) {
	calles->similar(s);
}
void OpenDataCc::consumoDistrito() {
	calles->ConsumoPorDistrito();
}
void OpenDataCc::ahorroConsumo(string lampara1, string lampara2) {
	bool enc;
	enc=calles->ahorroConsumo(lampara1, lampara2);
	if(!enc)
		cout<<"Una de las dos lamparas no existe"<<endl;

}
void OpenDataCc::buscarViaQueEmpiezaPorLista(string s) {
	calles->empiezaPorUsandoLista(s);
}
void OpenDataCc::consumoDistritoArbol() {
	calles->generarConsumoArbol();
}
Vias OpenDataCc::getCalles() {
	return *calles;
}
Distritos OpenDataCc::getDistritos() {
	return *distritos;
}
Barrios OpenDataCc::getBarrios() {
	return *barrios;
}

