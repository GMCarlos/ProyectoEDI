/*
 * Distritos.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Distritos para la gestion de distritos mediante una lista
 */

#include "Distritos.h"

Distritos::Distritos() {
	Ld = new ListaPI<Distrito*>;

}
bool Distritos::esta(string s) {
	Distrito *b;
	Ld->moverInicio();
	string nombre = "";
	bool encontrado = false;
	while (!Ld->finLista() && !encontrado) {
		Ld->consultar(b);
		b->getNombre(nombre);
		if (s == nombre)
			encontrado = true;
		else
			Ld->avanzar();

	}
	return encontrado;
}
void Distritos::insertarDistritoFinal(Distrito *d) {
	Ld->enFin();
	Ld->avanzar();
	Ld->insertar(d);
}
void Distritos::mostrar() {
	Distrito *d;
	Ld->moverInicio();
	while (!Ld->finLista()) {
		Ld->consultar(d);
		d->mostrar();
		Ld->avanzar();
	}
}
bool Distritos::buscarDistrito(Distrito *&d, string s) {
	bool encontrado = false;
	string aux = "";
	Ld->moverInicio();
	while (!Ld->finLista() && !encontrado) {
		Ld->consultar(d);
		d->getNombre(aux);
		if (aux == s)
			encontrado = true;
		else
			Ld->avanzar();
	}
	return encontrado;
}
bool Distritos::distritosVacios(){
	return Ld->estaVacia();
}
Distritos::~Distritos() {
	Distrito *d;
	Ld->moverInicio();
	while (!Ld->finLista()) {
		Ld->consultar(d);
		delete d;
		Ld->borrar();
	}
	Ld = NULL;
}
