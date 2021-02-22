/*
 * Barrios.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Barrios para la gestion de los barrios con una lista
 *
 */

#ifndef BARRIOS_H_
#define BARRIOS_H_
#include "listapi.h"
#include "Barrio.h"
#include <iostream>
#include <fstream>
class Barrios {
	ListaPI <Barrio*> *Lb;
public:
	//Constructor por defecto.
	 //* PRE:{}
	 //* POST:{Crea una lista de barrios vacia}
	 //* COMPLEJIDAD:{O(1)}
	Barrios();

	 //* PRE:{Los atributos del barrio no deben de estar vacios}
	 //* POST:{Inserta un barrio en la lista de barrios al final}
	 //* COMPLEJIDAD:{O(1)}
	void insertarBarrioF(Barrio *b);

	 //* PRE:{Los atributos del barrio no deben de estar vacios}
	 //* POST:{Inserta un barrio en la lista de barrios en orden alfabético}
	 //* COMPLEJIDAD:{O(1)}
	void insertarBarrioOrden(Barrio *b);

	 //* PRE:{Trabajamos sobre una lista de barrios}
	 //* POST:{Muestra los elementos de la lista de barrios}
	 //* COMPLEJIDAD:{O(1)}
	void mostrar();

	 //* PRE:{Trabajamos sobre una lista de barrios}
	 //* POST:{Devuelve true si hay algun barrio en la lista con el mismo nombre que la variable de entrada string
	 	 	 	 	 	 	 	 	 	 	 	 //y me guarda el barrio en la variable de entrada salida Barrio}
	 //* COMPLEJIDAD:{O(1)}
	bool buscarBarrio(Barrio *&b,string s);

	 //* PRE:{Trabajamos sobre una lista de barrios}
	 //* POST:{Devuelve true si hay algun barrio en la lista con el mismo nombre que la variable de entrada string}
	 //* COMPLEJIDAD:{O(1)}
	bool esta(string s);

	 //* PRE:{Trabajamos sobre una lista de barrios}
	 //* POST:{Devuelve true si la lista de barrios está vacia}
	 //* COMPLEJIDAD:{O(1)}
	bool barriosVacio();

	 //* PRE:{Trabajamos sobre una lista de barrios}
	 //* POST:{Destructor de una lista de barrios}
	 //* COMPLEJIDAD:{O(1)}
	virtual ~Barrios();
};

#endif /* BARRIOS_H_ */
