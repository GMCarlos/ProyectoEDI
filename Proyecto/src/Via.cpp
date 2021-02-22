/*
 * Via.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Via para la gestion de una via
 */

#include "Via.h"
#include <iostream>
using namespace std;

Via::Via() {
	nombreVia = "";
	longitudVia = 0.0;
	tipoVia = "";
	tieneCodigoVia = "0";
	situadaEnBarrio = NULL;
	coordInicioVia = NULL;
	coordMedioVia = NULL;
	coordFinalVia = NULL;

}

Via::Via(string nombreVia, float longitudVia, string tipoVia,
		string tieneCodigoVia, float laI, float lonI, float laM, float lonM,
		float laF, float lonF, Barrio *situadaEnBarrio) {

	this->nombreVia = nombreVia;
	this->longitudVia = longitudVia;
	this->tipoVia = tipoVia;
	this->tieneCodigoVia = tieneCodigoVia;
	this->situadaEnBarrio = situadaEnBarrio;
	this->coordInicioVia = new Coords(laI, lonI);
	this->coordMedioVia = new Coords(laM, lonM);
	this->coordFinalVia = new Coords(laF, lonF);

}
Via::Via(const Via &v) {
	this->nombreVia = v.nombreVia;
	this->longitudVia = v.longitudVia;
	this->tipoVia = v.tipoVia;
	this->tieneCodigoVia = v.tieneCodigoVia;
	this->situadaEnBarrio = v.situadaEnBarrio;
	this->coordInicioVia = new Coords(*v.coordInicioVia);
	this->coordMedioVia = new Coords(*v.coordMedioVia);
	this->coordFinalVia = new Coords(*v.coordFinalVia);

}

void Via::setLongitudVia(float longitudVia) {
	this->longitudVia = longitudVia;
}

void Via::getLongitudVia(float &longitud) {
	longitud=this->longitudVia;
}

void Via::setNombreVia(string nombreVia) {
	this->nombreVia = nombreVia;
}
string Via::getName()const{
	return this->nombreVia;
}
void Via::getNombre(string &nombre) {
	nombre=this->nombreVia;
}

void Via::setTieneCodigoVia(string tieneCodigoVia) {
	this->tieneCodigoVia = tieneCodigoVia;
}

string Via::getTieneCodigoVia() {
	return tieneCodigoVia;
}

void Via::setTipoVia(string tipoVia) {
	this->tipoVia = tipoVia;
}

string Via::getTipoVia() {
	return tipoVia;
}
void Via::getSituadaEnBarrio(Barrio *&b) {
	b = this->situadaEnBarrio;
}
void Via::setSituadaEnBarrio(Barrio *&b) {
	this->situadaEnBarrio = b;
}

void Via::mostrar() {
	string s="";
	//situadaEnBarrio->getNombreBarrio(s);
	cout << "\t" << tipoVia << " " << nombreVia << ", " << " barrio: "
			<< s << ", " << longitudVia << " m " << endl;
	coordInicioVia->show();
	coordMedioVia->show();
	coordFinalVia->show();
}

void Via::setInicioVia(float latitud, float longitud) {
	if (coordInicioVia == NULL)
		coordInicioVia = new Coords(latitud, longitud);
	else {
		coordInicioVia->setLatitude(latitud);
		coordInicioVia->setLongitude(longitud);
	}

}

float Via::distancia(Via *v) {
	float distancia;
	distancia = this->coordInicioVia->distanceTo(v->coordFinalVia);
	return distancia;
}
bool Via::viasBarriosAdyacentes(Via*v) {
	float inicio=v->coordInicioVia->distanceTo(this->coordInicioVia);
	float medio=v->coordMedioVia->distanceTo(this->coordMedioVia);
	float final=v->coordFinalVia->distanceTo(this->coordFinalVia);
	if(inicio<75 || medio<75 || final<75)
		return true;
	else return false;
}
bool Via::operator ==(const Via &v) {
	return (this->nombreVia == v.nombreVia);
}
bool Via::operator >(const Via &v) {
	return (this->nombreVia > v.nombreVia);

}
bool Via::operator <(const Via &v) {
	return (this->nombreVia < v.nombreVia);

}
void Via::distanciaVia(Coords* coordenada,float &distancia){
	distancia=coordenada->distanceTo(coordInicioVia);
	float medio=coordenada->distanceTo(coordMedioVia);
	if(medio<distancia)
		distancia=medio;
	float fin=coordenada->distanceTo(coordFinalVia);
	if(fin<distancia)
		distancia=fin;

}
void Via::getInicioVia(Coords *&inicioVia){
	inicioVia=this->coordInicioVia;
}
void Via::getMedioVia(Coords *&medioVia){
	medioVia=this->coordMedioVia;
}
void Via::getFinalVia(Coords *&finalVia){
	finalVia=this->coordFinalVia;
}

Via::~Via() {
	if (coordInicioVia != NULL)
		delete coordInicioVia;
	if (coordFinalVia != NULL)
		delete coordFinalVia;
	if (coordMedioVia != NULL)
		delete coordMedioVia;
}
