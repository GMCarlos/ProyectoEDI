/*
 * Vias.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase Vias para la gestion de vias mediante listas y arboles.-
 */

#ifndef VIAS_H_
#define VIAS_H_
#include "Via.h"
#include "listapi.h"
#include "Barrios.h"
#include "Farola.h"
#include "arbol.h"
#include <iomanip>
class Vias {
private:
	ListaPI<Via*> *Lv;
	ListaPI<Farola*> *Lf;
	Arbol<Via*, CompararPtrVias> *Av;
	void filtroInOrden (
				Arbol<Via *, CompararPtrVias> *bst, const string &nombre);
	bool empiezaPor (string str, string substr);
	Arbol<Via *, CompararPtrVias> * arbol_similar (
			Arbol<Via *, CompararPtrVias> *bst, const string &nombre);
	bool buscarEnArbol(Arbol<Via *, CompararPtrVias> *bst,
			string &nombre,string &t);
	void generarConsumoArbolImpl(Arbol<Via *, CompararPtrVias> *arbol
			,float &Centro,float &Norte,float &Sur
						,float &Pedanias, float &Oeste);

public:

	//Constructor por defecto.
	//* PRE:{}
	//* POST:{Crea una lista de vias vacia}
	//* COMPLEJIDAD:{O(1)}
	Vias();

	//* PRE:{}
	//* POST:{Devuelve en la variable Distrito el consumo de las farolas de una via por medio de listas}
	//* COMPLEJIDAD:{O(n)}
	void farolasPorVias(Via *v,float &Distrito);

	//* PRE:{}
	//* POST:{Genera un fichero con el consumo de los distritos por medio de arboles}
	//* COMPLEJIDAD:{O(n/2)}
	void generarConsumoArbol();

	//* PRE:{}
	//* POST:{Devuelve true si encuentra la via "nombre" y si la encuentra,
	 	 	 //la almacena en la variable de entrada-salida Via (usando arboles)}
	//* COMPLEJIDAD:{O(n/2)}
	bool buscar (string nombre, string t);

	//* PRE:{}
	//* POST:{Genera un fichero con el ahorro de una via con un tipo de farola u otra}
	//* COMPLEJIDAD:{O(n/2)}
	bool ahorroConsumo(string lampara1,string lampara2);

	//* PRE:{}
	//* POST:{Inserta una farola en la via }
	//* COMPLEJIDAD:{O(1)}
	void insertarFarolaFinal(Farola *f);

	//* PRE:{Usar una lista de vias}
	//* POST:{Muestra las vias de la lista}
	//* COMPLEJIDAD:{O(1)}
	void mostrar();

	//* PRE:{}
	//* POST:{Inserta una via al final de la lista de vias}
	//* COMPLEJIDAD:{O(1)}
	void insertarViaF(Via *v);

	//* PRE:{}
	//* POST:{Inserta una via en orden alfabetico en la lista de vias}
	//* COMPLEJIDAD:{O(1)}
	void insertarViaOrden(Via *v);

	//* PRE:{}
	//* POST:{Muestra las farolas de la lista de farolas}
	//* COMPLEJIDAD:{O(1)}
	void mostrarFarolas();

	//* PRE:{}
	//* POST:{Almacena en una lista de vias, las vias que pertenezcan a un determinado barrio "s"}
	//* COMPLEJIDAD:{O(n)}
	void buscarCallesBarrio(Vias *&c, string s);

	//* PRE:{}
	//* POST:{Devuelve los barrios adyacentes de una Via(introducida como parametro de entrada)
			 //almacenandolos en la lista de Barrios de parametro de entrada-salida}
	//* COMPLEJIDAD:{O(n2)}
	void buscarBarriosAdyacentes(Vias *v, Barrio *&b, Barrios *&barrios);

	//* PRE:{}
	//* POST:{Devuelve la via en la que está la farola}
	//* COMPLEJIDAD:{O(n)}
	void farolasEnVias(Via *&v, float lat, float lon);

	//* PRE:{}
	//* POST:{Devuelve la via con mayor concentracion de farolas y la proporcion}
	//* COMPLEJIDAD:{O(n2)}
	void viaMayorConcentracion(Via *&v, float &p);

	//* PRE:{}
	//* POST:{Genera un fichero con las vias con una farola introducida como parametro de entrada}
	//* COMPLEJIDAD:{O(n)}
	void obtenerViasConFarolaEspecifica(string farolilla);

	//* PRE:{}
	//* POST:{Genera un fichero con las vias de un determinado distrito, introducido por parametro de entrada}
	//* COMPLEJIDAD:{O(n)}
	void obtenerViasDelDistrito(string Distrito);

	//* PRE:{}
	//* POST:{Devuelve true si la via introducida como parametro de entrada se encuentra en la lista de vias}
	//* COMPLEJIDAD:{O(n)}
	bool esta(Via *via);

	//* PRE:{}
	//* POST:{Inserta via en arbol}
	//* COMPLEJIDAD:{O(n/2)}
	void insertarViasEnArbol(Via *v);

	//* PRE:{}
	//* POST:{Muestra las vias que comienzan por la variable string de entrada usando arboles}
	//* COMPLEJIDAD:{O(n/2)}
	void similar (const string &nombre);

	//* PRE:{}
	//* POST:{Genera un fichero con el consumo electrico de cada distrito}
	//* COMPLEJIDAD:{O(n)}
	void ConsumoPorDistrito();

	//* PRE:{}
	//* POST:{Muestra las vias que comienzan por la variable string de entrada usando listas}
	//* COMPLEJIDAD:{O(n)}
	void empiezaPorUsandoLista (string str);

	//* PRE:{}
	//* POST:{devuelve true si la lista de vias está vacia}
	//* COMPLEJIDAD:{O(1)}
	bool viasVacia();

	//* PRE:{}
	//* POST:{devuelve true si la lista de farolas está vacia}
	//* COMPLEJIDAD:{O(1)}
	bool farolasVacia();

	//* PRE:{}
	//* POST:{Cambia el nombre de una via s por t usando listas}
	//* COMPLEJIDAD:{O(n)}
	void cambiarNombre(string s, string t);

	 //* PRE:{Usar una lista de vias}
	 //* POST:{Elimina la lista de vias}
	 //* COMPLEJIDAD:{O(1)
	virtual ~Vias();
};

#endif /* VIAS_H_ */
