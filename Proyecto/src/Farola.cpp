/*
 * Farola.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase farola para la gestion de una farola
 */

#include "Farola.h"
Farola::Farola() {
	this->funcionamiento = "";
	this->geo_lat = 0.0;
	this->geo_long = 0.0;
	this->material = "";
	this->om_altura = 0.0;
	this->om_circuitos = 0.0;
	this->om_materialL = "";
	this->om_potencia = 0.0;
	this->om_tipoLampara = "";
	this->om_tipoSoporte = "";
	this->proteccion = "";
	this->tipoLuz = "";
	this->coordenada = NULL;
	this->via=NULL;

}
Farola::Farola(string funcionamiento, string proteccion, string tipoLuz,
		string material, float geo_long, int om_potencia, string om_tipoLampara,
		float geo_lat, int om_altura, string om_tipoSoporte, int om_circuitos,
		string om_materialL,Via *via) {
	this->funcionamiento = funcionamiento;
	this->proteccion = proteccion;
	this->tipoLuz = tipoLuz;
	this->material = material;
	this->geo_long = geo_long;
	this->om_potencia = om_potencia;
	this->om_tipoLampara = om_tipoLampara;
	this->geo_lat = geo_lat;
	this->om_altura = om_altura;
	this->om_tipoSoporte = om_tipoSoporte;
	this->om_circuitos = om_circuitos;
	this->om_materialL = om_materialL;
	this->coordenada = new Coords(geo_lat, geo_long);
	this->via=via;
}
Farola::Farola(const Farola &f) {
	this->funcionamiento = f.funcionamiento;
	this->proteccion = f.proteccion;
	this->tipoLuz = f.tipoLuz;
	this->material = f.material;
	this->geo_long = f.geo_long;
	this->om_potencia = f.om_potencia;
	this->om_tipoLampara = f.om_tipoLampara;
	this->geo_lat = f.geo_lat;
	this->om_altura = f.om_altura;
	this->om_tipoSoporte = f.om_tipoSoporte;
	this->om_circuitos = f.om_circuitos;
	this->om_materialL = f.om_materialL;
	this->coordenada = new Coords(*f.coordenada);
	this->via=f.via;

}
Farola::~Farola() {
if(this->coordenada!=NULL)
	delete this->coordenada;
}

string Farola::getFuncionamiento(string &funcionamiento) {
	funcionamiento = this->funcionamiento;
	return funcionamiento;
}

void Farola::setFuncionamiento(string funcionamiento) {
	this->funcionamiento = funcionamiento;
}

string Farola::getProteccion(string &proteccion) {
	proteccion = this->proteccion;
	return proteccion;
}

void Farola::setProteccion(string proteccion) {
	this->proteccion = proteccion;
}

void Farola::getTipoLuz(string &tipoLuz) {
	tipoLuz = this->tipoLuz;
}

void Farola::setTipoLuz(string tipoLuz) {
	this->tipoLuz = tipoLuz;
}

string Farola::getMaterial(string &material) {
	material = this->material;
	return material;
}

void Farola::setMaterial(string material) {
	this->material = material;
}

float Farola::getGeo_long(float &geo_long) {
	geo_long = this->geo_long;
	return geo_long;
}

void Farola::setGeo_long(float geo_long) {
	this->geo_long = geo_long;
}

int Farola::getOm_potencia(int &om_potencia) {
	om_potencia = this->om_potencia;
	return om_potencia;
}
void Farola::setOm_potencia(int om_potencia) {
	this->om_potencia = om_potencia;
}

void Farola::getOm_tipoLampara(string &om_tipoLampara) {
	om_tipoLampara = this->om_tipoLampara;
}
void Farola::setOm_tipoLampara(string om_tipoLampara) {
	this->om_tipoLampara = om_tipoLampara;
}

float Farola::getGeo_lat(float &geo_lat) {
	geo_lat = this->geo_lat;
	return geo_lat;
}
void Farola::setGeo_lat(float geo_lat) {
	this->geo_lat = geo_lat;
}

int Farola::getOm_altura(int &om_altura) {
	om_altura = this->om_altura;
	return om_altura;
}
void Farola::setOm_altura(int om_altura) {
	this->om_altura = om_altura;
}

string Farola::getOm_tipoSoporte(string &om_tipoSoporte) {
	om_tipoSoporte = this->om_tipoSoporte;
	return om_tipoSoporte;
}
void Farola::setOm_tipoSoporte(string om_tipoSoporte) {
	this->om_tipoSoporte = om_tipoSoporte;
}

int Farola::getOm_circuitos(int &om_circuitos) {
	om_circuitos = this->om_circuitos;
	return om_circuitos;
}

void Farola::setOm_circuitos(int om_circuitos) {
	this->om_circuitos = om_circuitos;
}

string Farola::getOm_materialL(string &om_materialL) {
	om_materialL = this->om_materialL;
	return om_materialL;
}
void Farola::setOm_materialL(string om_materialL) {
	this->om_materialL = om_materialL;
}
void Farola::getCoordenada(Coords *&co) {
	co = this->coordenada;
}
void Farola::setCoordenada(Coords *coordenada){
	this->coordenada=coordenada;
}
void Farola::getVia(Via *&v){
	v=this->via;
}
void Farola::mostrar() {
	string n;
	this->via->getNombre(n);
	cout << funcionamiento << " " << proteccion << " " << tipoLuz << " "
			<< material << " " << geo_long << " " << om_potencia << " "
			<< om_tipoLampara << " " << geo_lat << " " << om_altura << " "
			<< om_tipoSoporte << " " << om_circuitos << " " << om_materialL<<" via: "<<n
			<< endl;
}
