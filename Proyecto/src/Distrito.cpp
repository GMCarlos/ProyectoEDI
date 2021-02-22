/*
 * Distrito.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Distrito para la gestion de un Distrito
 */

#include "Distrito.h"
#include <iostream>
namespace std {
Distrito::Distrito(string nombre) {
	this->nombre = nombre;
}
Distrito::Distrito() {
	this->nombre = "";

}
Distrito::Distrito(const Distrito &d) {
	this->nombre = d.nombre;
}
void Distrito::setNombre(string nombre) {
	this->nombre=nombre;
}
string Distrito::getNombre(string &nombre) {
	nombre = this->nombre;
	return nombre;
}
void Distrito::mostrar() {
	cout << "Nombre: " << this->nombre << endl;
}
Distrito::~Distrito() {
}

}
