/*
 * Barrios.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Barrios para la gestion de los barrios con una lista
 */
#include "Barrios.h"

Barrios::Barrios() {
	Lb = new ListaPI<Barrio*>;

}
bool Barrios::barriosVacio(){
	return Lb->estaVacia();
}
Barrios::~Barrios() {
	Barrio *b;
	Lb->moverInicio();	//mueve el PI al inicio
	while (!Lb->finLista()) {
		Lb->consultar(b);
		delete b;
		Lb->borrar();
	}
	Lb = NULL;
}
void Barrios::mostrar() {
	Barrio *b;
	Lb->moverInicio();
	while (!Lb->finLista()) {
		Lb->consultar(b);
		b->mostrar();
		Lb->avanzar();
	}
}
void Barrios::insertarBarrioF(Barrio *b) {
	Lb->enFin();
	Lb->avanzar();
	Lb->insertar(b);
}
bool Barrios::buscarBarrio(Barrio *&b, string s) {
	Lb->moverInicio();
	string nombre = "";
	bool encontrado = false;
	while (!Lb->finLista() && !encontrado) {
		Lb->consultar(b);
		b->getNombreBarrio(nombre);
		if (s == nombre)
			encontrado = true;
		else
			Lb->avanzar();

	}
	return encontrado;
}
bool Barrios::esta(string s) {
	Barrio *b;
	Lb->moverInicio();
	string nombre = "";
	bool encontrado = false;
	while (!Lb->finLista() && !encontrado) {
		Lb->consultar(b);
		b->getNombreBarrio(nombre);
		if (s == nombre)
			encontrado = true;
		else
			Lb->avanzar();

	}
	return encontrado;
}

void Barrios::insertarBarrioOrden(Barrio *b) {
	bool enc = false;
	Lb->moverInicio();
	Barrio *bAux;
	while (!Lb->finLista() && !enc) {
		Lb->consultar(bAux);
		if (*bAux > *b)
			enc = true;
		else
			Lb->avanzar();

	}
	if (enc == true)
		Lb->insertar(b);
	else
		insertarBarrioF(b);
}
