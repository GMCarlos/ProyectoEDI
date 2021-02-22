/*
 * Barrio.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 */

#include "Barrio.h"
#include <iostream>
using namespace std;
//Clase::Método
Barrio::Barrio() {
	//Inicia los atributos.
	nombreBarrio = "";
	distritoAlQuePertenece = NULL;
	//cout << "Ejecutando el constructor por defecto." <<endl;

}
Barrio::Barrio(string nombreBarrio, Distrito *nombreD){
	this ->nombreBarrio = nombreBarrio;
	this->distritoAlQuePertenece = nombreD;

}
Barrio::Barrio(const Barrio &b){
	this->nombreBarrio=b.nombreBarrio;
	this->distritoAlQuePertenece=b.distritoAlQuePertenece;
}

void Barrio::setNombreBarrio(string &nombreBarrio){
	this->nombreBarrio = nombreBarrio;
}

void Barrio::getNombreBarrio(string &nombreBarrio){
	nombreBarrio = this->nombreBarrio;
}
void Barrio:: getDistrito(Distrito *&distrito){
	distrito=this->distritoAlQuePertenece;
}
void Barrio:: setDistrito(Distrito *distrito){
	this->distritoAlQuePertenece=distrito;
}
bool Barrio::operator==(const Barrio &b){
	return(nombreBarrio==b.nombreBarrio);

}
bool Barrio::operator!=(const Barrio &b){
	return(nombreBarrio!=b.nombreBarrio);

}
bool Barrio::operator>(const Barrio &b){
	return(nombreBarrio>b.nombreBarrio);

}
void Barrio::getNombreDistrito(string &nombre){
    string aux;
    this->distritoAlQuePertenece->getNombre(aux);
    nombre=aux;
}

void Barrio::mostrar(){
	string s;
	distritoAlQuePertenece->getNombre(s);
	cout<<"Barrio: "<<nombreBarrio<< " Distrito: "<<s<<endl;
}

Barrio::~Barrio() {
	if(distritoAlQuePertenece!=NULL)
	delete distritoAlQuePertenece;
}
