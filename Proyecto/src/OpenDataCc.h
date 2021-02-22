/*
 * OpenDataCc.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guilen Moreno
 *      Clase que gestiona las acciones a realizar
 */

#ifndef OPENDATACC_H_
#define OPENDATACC_H_
#include "Distritos.h"
#include "Barrios.h"
#include "fstream"
#include "Vias.h"

class OpenDataCc {

	Vias *calles;
	Distritos *distritos;
	Barrios *barrios;

public:
	//Constructor por defecto.
	//* PRE:{}
	//* POST:{Crea un objeto OpenData(lista de calles, barrios y distritos) con las listas vacias}
	//* COMPLEJIDAD:{O(1)}
	OpenDataCc();

	//* PRE:{}
	//* POST:{Carga la lista de vias}
	//* COMPLEJIDAD:{O(n2)}
	void cargarVias();

	//* PRE:{}
	//* POST:{Carga la lista de distritos}
	//* COMPLEJIDAD:{O(n2)}
	void cargarDistritos();

	//* PRE:{}
	//* POST:{Carga la lista de barrios}
	//* COMPLEJIDAD:{O(n2)}
	void cargarBarrios();

	//* PRE:{}
	//* POST:{Carga la lista de farolas}
	//* COMPLEJIDAD:{O(n2)}
	void cargarFarolas();

	//* PRE:{}
	//* POST:{Muestra si hay alguna via en el barrio que se llame como el parametro de entrada string}
	//* COMPLEJIDAD:{O(1)}
	void buscarViasBarrio(string s);

	//* PRE:{}
	//* POST:{Muestra los barrios adyacentes al pasado por string como parametro de entrada}
	//* COMPLEJIDAD:{O(n2)}
	void barriosAdyacentes(string s);

	//* PRE:{}
	//* POST:{Muestra la via con mayor concentracion de farolas y la proporcion de farolas}
	//* COMPLEJIDAD:{O(n2)}
	void concentracionFarolas();

	//* PRE:{tiene que existir el distrito que se busca}
	//* POST:{Muestra las vias del distrito introducido por string de parametro de entrada}
	//* COMPLEJIDAD:{O(n)}
	void obtenerViasDeDistrito(string s);

	//* PRE:{tiene que existir el tipo de farola}
	//* POST:{Muestra las vias con el tipo de farola especificado por el parametro string de entrada}
	//* COMPLEJIDAD:{O(n)}
	void obtenerViasConTipoDeFarola(string s);

	//* PRE:{}
	//* POST:{Busca en arbol las vias que empiezan por el mismo nombre que el parametro string de entrada }
	//* COMPLEJIDAD:{O(n/2)}
	void buscarEmpizaPor(string s);

	//* PRE:{}
	//* POST:{Muestra el consumo por distrito por medio de listas}
	//* COMPLEJIDAD:{O(n)}
	void consumoDistrito();

	//* PRE:{}
	//* POST:{Muestra el consumo por distrito por medio de arboles}
	//* COMPLEJIDAD:{O(n/2)}
	void consumoDistritoArbol();

	//* PRE:{}
	//* POST:{Muestra el ahorro por utilizar una lampara1 o una lampara 2 en las farolas de una via}
	//* COMPLEJIDAD:{O(n)}
	void ahorroConsumo(string lampara1, string lampara2);

	 //* PRE:{Usar un objeto OpenData}
	 //* POST:{Elimina el objeto OpenData}
	 //* COMPLEJIDAD:{O(1)}
	virtual ~OpenDataCc();

	//* PRE:{}
	//* POST:{Busca en lista las vias que empiezan por el mismo nombre que el parametro string de entrada }
	//* COMPLEJIDAD:{O(n)}
	void buscarViaQueEmpiezaPorLista(string s);

	//* PRE:{Debe de existir la via s}
	//* POST:{Cambia el nombre de la via "s" por la variable string "t" por medio de listas }
	//* COMPLEJIDAD:{O(n)}
	void cambiarNombreVia(string s, string t);

	//* PRE:{Debe de existir la via s}
	//* POST:{Cambia el nombre de la via "s" por la variable string "t" por medio de arboles }
	//* COMPLEJIDAD:{O(n/2)}
	void cambiarNombreViaArbol(string s, string t);

	//* PRE:{}
	//* POST:{Devuelve la lista de vias }
	//* COMPLEJIDAD:{O(1}
	Vias getCalles();

	//* PRE:{}
	//* POST:{Devuelve la lista de distritos }
	//* COMPLEJIDAD:{O(1}
	Distritos getDistritos();

	//* PRE:{}
	//* POST:{Devuelve la lista de barrios }
	//* COMPLEJIDAD:{O(1}
	Barrios getBarrios();
};

#endif /* OPENDATACC_H_ */
