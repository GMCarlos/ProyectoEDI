/*
 * Distritos.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Distritos para la gestion de distritos mediante una lista
 */

#ifndef DISTRITOS_H_
#define DISTRITOS_H_
#include "listapi.h"
#include "Distrito.h"
class Distritos {
	ListaPI <Distrito*> *Ld;
public:
	//Constructor por defecto.
	//* PRE:{}
	//* POST:{Crea una lista de distritos vacia}
	//* COMPLEJIDAD:{O(1)}
	Distritos();

	//* PRE:{Trabajamos sobre una lista de distritos}
	//* POST:{Devuelve true si hay algun distrito en la lista con el mismo nombre que la variable de entrada string}
	//* COMPLEJIDAD:{O(1)}
	bool esta(string s);

	//* PRE:{Los atributos del distrito no deben de estar vacios}
	//* POST:{Inserta un distrito en la lista de distritos al final}
	//* COMPLEJIDAD:{O(1)}
	void insertarDistritoFinal(Distrito *d);

	//* PRE:{Trabajamos sobre una lista de distritos}
	//* POST:{Muestra los elementos de la lista de distritos}
	//* COMPLEJIDAD:{O(1)}
	void mostrar();

	 //* PRE:{Trabajamos sobre una lista de distritos}
	 //* POST:{Devuelve true si hay algun distrito en la lista con el mismo nombre que la variable de entrada string
	 	 	 	 	 	 	 	 	 	 	 	 //y me guarda el distrito en la variable de entrada salida Distrito}
	 //* COMPLEJIDAD:{O(1)}
	bool buscarDistrito(Distrito *&d, string s);

	//* PRE:{Trabajamos sobre una lista de distritos}
	//* POST:{Devuelve true si la lista de distritos está vacia}
	//* COMPLEJIDAD:{O(1)}
	bool distritosVacios();

	//* PRE:{Trabajamos sobre una lista de distritos}
	//* POST:{Destructor de una lista de distritos}
	//* COMPLEJIDAD:{O(1)}
	virtual ~Distritos();
};

#endif /* DISTRITOS_H_ */
