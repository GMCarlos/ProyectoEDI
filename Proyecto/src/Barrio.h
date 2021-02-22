/*
 * Barrio.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Barrio para la gestion de un barrio
 */
#ifndef BARRIO_H_
#define BARRIO_H_
#include <string>
#include "Distrito.h"
using namespace std;
class Barrio {
private:
	string nombreBarrio;
	Distrito *distritoAlQuePertenece;

public:
	//Constructor por defecto.
	 //* PRE:{}
	 //* POST:{Crea un objeto barrio con los atributos sin valores}
	 //* COMPLEJIDAD:{O(1)}
	Barrio();

	//Constructor parametrizado.
	 //* PRE:{}
	 //* POST:{Crea un objeto barrio con los atributos introducidos por los parametros de entrada}
	 //* COMPLEJIDAD:{O(1)}
	Barrio(string nombreBarrio, Distrito *nombreD);

	 //* PRE:{Barrio de parametro de entrada, inicializado con valores en sus atributos}
	 //* POST:{Crea una copia del objeto barrio de un barrio introducido por parametro de entrada}
	 //* COMPLEJIDAD:{O(1)}
	Barrio(const Barrio &b);

	 //* PRE:{}
	 //* POST:{Almacena en la variable string de entrada-salida el nombre del distrito}
	 //* COMPLEJIDAD:{O(1)}
	void getNombreDistrito(string &nombre);

	 //* PRE:{}
	 //* POST:{Modifica el nombre del barrio cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setNombreBarrio(string &nombreBarrio);

	 //* PRE:{}
	 //* POST:{Almacena en la variable string de entrada-salida el nombre del barrio}
	 //* COMPLEJIDAD:{O(1)}
	void getNombreBarrio(string &nombreBarrio);

	 //* PRE:{}
	 //* POST:{Modifica el distrito al que pertenece un barrio cambiandolo por el puntero Distrito de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setDistrito(Distrito *distrito);

	 //* PRE:{}
	 //* POST:{Almacena en la variable Distrito de entrada-salida el nombre del distrito al que pertenece un barrio}
	 //* COMPLEJIDAD:{O(1)}
	void getDistrito(Distrito *&distrito);

	 //* PRE:{}
	 //* POST:{Redefinicion del operador == adaptandolo a la clase Barrio}
	 //* COMPLEJIDAD:{O(1)}
	bool operator==(const Barrio &b);

	 //* PRE:{}
	 //* POST:{Redefinicion del operador > adaptandolo a la clase Barrio}
	 //* COMPLEJIDAD:{O(1)}
	bool operator>(const Barrio &b);

	 //* PRE:{}
	 //* POST:{Redefinicion del operador != adaptandolo a la clase Barrio}
	 //* COMPLEJIDAD:{O(1)}
	bool operator!=(const Barrio &b);

	 //* PRE:{Usar un objeto Barrio}
	 //* POST:{Muestra el barrio}
	 //* COMPLEJIDAD:{O(1)}
	void mostrar();

	//Destructor por defecto.

	 //* PRE:{Usar un objeto Barrio}
	 //* POST:{Elimina el objeto Barrio}
	 //* COMPLEJIDAD:{O(1)}
	~Barrio();
};

#endif /* BARRIO_H_ */
