/*
 * PruebasDeModulosProyecto.h
 *
 *  Created on: 28 may. 2017
 *      Author: carlos
 */

#ifndef PRUEBASDEMODULOSPROYECTO_H_
#define PRUEBASDEMODULOSPROYECTO_H_
#include <string>
#include "OpenDataCc.h"

class PruebasDeModulosProyecto {
	//Atributos de la clase
	Vias *pruebasCalles;
	Distritos *pruebasDistritos;
	Barrios *pruebasBarrios;
	Farola *faux1, *faux2;
	Via *vaux1, *vaux2;
	Distrito *daux1, *daux2;
	Barrio *baux1, *baux2;

	//Arbol
	Arbol<Via*, CompararPtrVias> *Av;

public:
	PruebasDeModulosProyecto();

	void pruebaModulo2();
	void pruebaModulo3();
	void pruebaModulo4();
	void pruebaModulo5();
	void pruebaModulo6();
	void pruebaModulo7();
	void pruebaModulo8();
	void pruebaModulo9();
	void pruebaModulo10();

	~PruebasDeModulosProyecto();
};

#endif /* PRUEBASDEMODULOSPROYECTO_H_ */
