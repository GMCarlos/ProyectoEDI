/*
 * coords.cpp
 *
 *  Created on: 6 de feb. de 2017
 *      Author: Profesores de la asignatura EDI
 */

#include "coords.h"
#include <math.h>
#include <iostream>
using namespace std;

Coords::Coords() {
	this->latitude  = 0.0;
	this->longitude = 0.0;
}
Coords::Coords(float latitude, float longitude) {
	this->latitude  = latitude;
	this->longitude = longitude;
}

Coords::Coords (const Coords &c){
	this->latitude  = c.latitude;
	this->longitude = c.longitude;
}

void Coords::setLatitude  (float latitude){
	this->latitude = latitude;
}
void Coords::setLongitude (float longitude){
	this->longitude = longitude;
}
void Coords::show(){
	cout <<"\t\t"<<"Latitud: "<<latitude<<" Longitud: " <<longitude <<endl;
}

float Coords::distanceTo (Coords *c) {

	float d = 0.0;

	float dlon = (c->longitude - this->longitude) * (PI / 180.0);
	float dlat = (c->latitude  - this->latitude)  * (PI / 180.0);
	float tmplong = sin(dlat/2) * sin(dlat/2);
	float tmplat  = sin(dlon/2) * sin(dlon/2);
	float a = tmplong + cos(this->latitude) * cos(c->latitude) * tmplat;
	float cx = 2 * atan2( sqrt(a), sqrt(1-a) );
	float R = 6367.0; // (where R is the radius of the Earth)

	d = R * cx * 1000.0;

	return d;
}


float Coords::distanceTo (float latitude, float longitude) {

	Coords *tmp = new Coords(latitude, longitude);
	float d = this->distanceTo(tmp);
	delete tmp;
	return d;
}


Coords::~Coords() {
}
