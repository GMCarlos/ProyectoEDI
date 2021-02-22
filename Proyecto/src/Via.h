/*
 * Via.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase via para la gestion de un objeti Via
 */

#ifndef VIA_H_
#define VIA_H_
#include "coords.h"
#include "Barrio.h"

#include <string>
using namespace std;


class Via {
	string  nombreVia;
	float   longitudVia;
	string  tipoVia;
	string  tieneCodigoVia;
	Barrio  *situadaEnBarrio;


	Coords  * coordInicioVia;  // Composición
	Coords  * coordMedioVia;
	Coords  * coordFinalVia;

public:

	//Constructor por defecto.
	//* PRE:{}
	//* POST:{Crea un objeto via con los atributos sin valores}
	//* COMPLEJIDAD:{O(1)}
	Via();

	//Constructor parametrizado.
	//* PRE:{}
	//* POST:{Crea un objeto via con los atributos introducidos por los parametros de entrada}
	//* COMPLEJIDAD:{O(1)}
	Via (string  nombreVia, float longitudVia,string  tipoVia, string tieneCodigoVia, float laI, float lonI,
			float laM, float lonM, float laF, float lonF,Barrio  *situadaEnBarrio);

	// constructor copia
	 //* PRE:{Via de parametro de entrada, inicializado con valores en sus atributos}
	 //* POST:{Crea una copia del objeto via de una via introducido por parametro de entrada}
	 //* COMPLEJIDAD:{O(1)}
	Via (const Via &v);

	//* PRE:{Usar un objeto Via}
	//* POST:{Muestra la via}
	//* COMPLEJIDAD:{O(1)}
	void   mostrar();


	//GETTERS

	 //* PRE:{Usar un objeto Via}
	 //* POST:{Devuelve en un string el nombre del distrito (se usa en arboles)}
	 //* COMPLEJIDAD:{O(1)}
	string getName() const;

	 //* PRE:{Usar un objeto Via}
	 //* POST:{Almacena en la variable string de entrada-salida el nombre de la via(se usa en listas)}
	 //* COMPLEJIDAD:{O(1)}
	void getNombre(string &nombre);

	 //* PRE:{Usar un objeto Via}
	 //* POST:{Devuelve en un string el tipo de Via}
	 //* COMPLEJIDAD:{O(1)}
	string getTipoVia        () ;

	 //* PRE:{Usar un objeto Via}
	 //* POST:{Devuelve en un string el codigo de la Via}
	 //* COMPLEJIDAD:{O(1)}
	string getTieneCodigoVia () ;

	 //* PRE:{Usar un objeto Via}
	 //* POST:{Almacena en la variable Barrio de entrada-salida el barrio de la via}
	 //* COMPLEJIDAD:{O(1)}
	void getSituadaEnBarrio(Barrio *&b) ;

	//* PRE:{Usar un objeto Via}
	//* POST:{Almacena en la variable float de entrada-salida la longitud de la via}
	//* COMPLEJIDAD:{O(1)}
	void  getLongitudVia    (float &longitud) ;

	//* PRE:{Usar un objeto Via}
	//* POST:{Almacena en la variable Coords de entrada-salida las coordenadas de inicio de la via}
	//* COMPLEJIDAD:{O(1)}
	void   getInicioVia      (Coords *&inicioVia) ;

	//* PRE:{Usar un objeto Via}
	//* POST:{Almacena en la variable Coords de entrada-salida las coordenadas de la mitad de la via}
	//* COMPLEJIDAD:{O(1)}
	void   getMedioVia       (Coords *&medioVia);

	//* PRE:{Usar un objeto Via}
	//* POST:{Almacena en la variable Coords de entrada-salida las coordenadas de final de la via}
	//* COMPLEJIDAD:{O(1)}
	void   getFinalVia       (Coords *&finalVia);

	//SETTERS

	 //* PRE:{}
	 //* POST:{Modifica el atributo nombre de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setNombreVia      ( string nombreVia);

	 //* PRE:{}
	 //* POST:{Modifica el atributo tipo de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setTipoVia        ( string tipoVia);

	 //* PRE:{}
	 //* POST:{Modifica el atributo codigo de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setTieneCodigoVia (string tieneCodigoVia);

	 //* PRE:{}
	 //* POST:{Modifica el atributo situada en barrio de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setSituadaEnBarrio( Barrio *&situadaEnBarrio);

	 //* PRE:{}
	 //* POST:{Modifica el atributo longitud de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setLongitudVia    (float longitudVia);

	 //* PRE:{}
	 //* POST:{Modifica el atributo inicio de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setInicioVia      (float latitud,float longitud);

	 //* PRE:{}
	 //* POST:{Modifica el atributo mitad de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setMedioVia       (float latitud,float longitud);

	 //* PRE:{}
	 //* POST:{Modifica el atributo final de la via cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void   setFinalVia       (float latitud,float longitud);


	 //* PRE:{Tiene que existir la via}
	 //* POST:{Devuelve true si la via es adyacente a otra}
	 //* COMPLEJIDAD:{O(1)}
	bool viasBarriosAdyacentes(Via *v);

	 //* PRE:{}
	 //* POST:{Devuelve la distancia entre dos vias}
	 //* COMPLEJIDAD:{O(1)}
	float  distancia		 (Via *v);

	 //* PRE:{}
	 //* POST:{Redefinicion del operador == adaptandolo a la clase Via}
	 //* COMPLEJIDAD:{O(1)}
	bool operator==(const Via &v);

	 //* PRE:{}
	 //* POST:{Redefinicion del operador > adaptandolo a la clase Via}
	 //* COMPLEJIDAD:{O(1)}
	bool operator>(const Via &v);

	 //* PRE:{}
	 //* POST:{Redefinicion del operador < adaptandolo a la clase Via}
	 //* COMPLEJIDAD:{O(1)}
	bool operator<(const Via &v);


	 //* PRE:{Usar un objeto Via}
	 //* POST:{Elimina el objeto Via}
	 //* COMPLEJIDAD:{O(1)}
	~Via();


	 //* PRE:{}
	 //* POST:{Almacena en distancia la distancia menor entre las coordenadas de la via}
	 //* COMPLEJIDAD:{O(1)}
	void distanciaVia(Coords *coordenada,float &distancia);
};
class CompararPtrVias {

public:

	int operator()(const Via *v1, const Via *v2) {
		int resultado;
		if(v1->getName()==v2->getName()){
			resultado=0;
		}
		if(v1->getName()>v2->getName()){
			resultado=1;
		}
		if(v1->getName()<v2->getName()){
			resultado=-1;
		}
	return resultado;

	}

};
#endif /* VIA_H_ */
