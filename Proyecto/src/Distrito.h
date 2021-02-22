/*
 * Distrito.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
  *      Clase Distrito para la gestion de un Distrito
 */

#ifndef DISTRITO_H_
#define DISTRITO_H_
#include <iostream>
namespace std {

class Distrito {
	string nombre;
public:
	//Constructor por defecto.
	//* PRE:{}
	//* POST:{Crea un objeto distrito con los atributos sin valores}
	//* COMPLEJIDAD:{O(1)}
	Distrito();

	//Constructor parametrizado
	//* PRE:{}
	//* POST:{Crea un objeto distrito con los atributos introducidos por los parametros de entrada}
	//* COMPLEJIDAD:{O(1)}
	Distrito(string nombre);

	 //* PRE:{Usar un objeto Distrito}
	 //* POST:{Muestra el distrito}
	 //* COMPLEJIDAD:{O(1)}
	void mostrar();

	 //* PRE:{Usar un objeto Distrito}
	 //* POST:{Me hace una copia del Distrito introducido como parametro de entrada}
	 //* COMPLEJIDAD:{O(1)}
	Distrito(const Distrito &d);

	 //* PRE:{Usar un objeto Distrito}
	 //* POST:{Elimina el objeto Distrito}
	 //* COMPLEJIDAD:{O(1)}
	~Distrito();

	 //* PRE:{Usar un objeto Distrito}
	 //* POST:{Devuelve en un string el nombre del distrito}
	 //* COMPLEJIDAD:{O(1)}
	string getNombre(string &nombre);

	 //* PRE:{Usar un objeto Distrito}
	 //* POST:{Modifica el nombre del distrito cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setNombre(string nombre);
};

} /* namespace std */

#endif /* DISTRITO_H_ */
