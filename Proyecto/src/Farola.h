/*
 * Farola.h
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase farola para la gestion de una farola
 */

#ifndef FAROLA_H_
#define FAROLA_H_
#include <iostream>
#include "coords.h"
#include "Via.h"
using namespace std;
class Farola {
	string funcionamiento;
	string proteccion;
	string tipoLuz;
	string material;
	float geo_long;
	int om_potencia;
	string om_tipoLampara;
	float geo_lat;
	int om_altura;
	string om_tipoSoporte;
	int om_circuitos;
	string om_materialL;
	Coords *coordenada;
	Via *via;
public:
	//Constructor por defecto.
	//* PRE:{}
	//* POST:{Crea un objeto farola con los atributos sin valores}
	//* COMPLEJIDAD:{O(1)}
	Farola();

	//Constructor parametrizado
	 //* PRE:{}
	 //* POST:{Crea un objeto farola con los atributos introducidos por los parametros de entrada}
	 //* COMPLEJIDAD:{O(1)}
	Farola (string funcionamiento, string proteccion, string tipoLuz, string material, float geo_long, int om_potencia, string om_tipoLampara,
			float geo_lat, int om_altura, string om_tipoSoporte,int om_circuitos, string om_materialL,Via *via);

	 //* PRE:{Farola de parametro de entrada, inicializado con valores en sus atributos}
	 //* POST:{Crea una copia del objeto farola de una farola introducido por parametro de entrada}
	 //* COMPLEJIDAD:{O(1)}
	Farola (const Farola &f);

	//Destructor por defecto.

	 //* PRE:{Usar un objeto Farola}
	 //* POST:{Elimina el objeto Farola}
	 //* COMPLEJIDAD:{O(1)}
	~Farola();

	void mostrar();

	 //* PRE:{}
	 //* POST:{Devuelve en un string el nombre de la farola}
	 //* COMPLEJIDAD:{O(1)}
	string getFuncionamiento(string &funcionamiento);

	 //* PRE:{}
	 //* POST:{Devuelve en un string la proteccion de la farola}
	 //* COMPLEJIDAD:{O(1)}
	string getProteccion(string &proteccion);

	 //* PRE:{}
	 //* POST:{Almacena en la variable string de entrada-salida el tipo de luz de la farola}
	 //* COMPLEJIDAD:{O(1)}
	void getTipoLuz(string &tipoLuz);

	 //* PRE:{}
	 //* POST:{Devuelve en un string el material de la farola}
	 //* COMPLEJIDAD:{O(1)}
	string getMaterial(string &material);

	 //* PRE:{}
	 //* POST:{Devuelve en un float la longitud de la farola}
	 //* COMPLEJIDAD:{O(1)}
	float getGeo_long(float &geo_long);

	 //* PRE:{}
	 //* POST:{Devuelve en un int la potencia de la farola}
	 //* COMPLEJIDAD:{O(1)}
	int getOm_potencia(int &om_potencia);

	 //* PRE:{}
	 //* POST:{Almacena en la variable string de entrada-salida el tipo de lampara de la farola}
	 //* COMPLEJIDAD:{O(1)}
	void getOm_tipoLampara(string &om_tipoLampara);

	 //* PRE:{}
	 //* POST:{Devuelve en un float la latitud de la farola}
	 //* COMPLEJIDAD:{O(1)}
	float getGeo_lat(float &geo_lat);

	 //* PRE:{}
	 //* POST:{Devuelve en un int la altura de la farola}
	 //* COMPLEJIDAD:{O(1)}
	int getOm_altura(int &om_altura);

	 //* PRE:{}
	 //* POST:{Devuelve en un string el tipo de soporte de la farola}
	 //* COMPLEJIDAD:{O(1)}
	string getOm_tipoSoporte(string &om_tipoSoporte);

	 //* PRE:{}
	 //* POST:{Devuelve en un int los circuitos de la farola}
	 //* COMPLEJIDAD:{O(1)}
	int getOm_circuitos(int &om_circuitos);

	 //* PRE:{}
	 //* POST:{Devuelve en un string el material de la farola}
	 //* COMPLEJIDAD:{O(1)}
	string getOm_materialL(string &om_materialL);

	 //* PRE:{}
	 //* POST:{Almacena en la variable Coords de entrada-salida las coordenadas de la farola}
	 //* COMPLEJIDAD:{O(1)}
	void getCoordenada(Coords *&co);

	 //* PRE:{}
	 //* POST:{Almacena en la variable Via de entrada-salida la via donde se encuentra la farola}
	 //* COMPLEJIDAD:{O(1)}
	void getVia(Via *&v);


	 //* PRE:{}
	 //* POST:{Modifica el atributo funcionamiento de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setFuncionamiento(string funcionamiento);

	 //* PRE:{}
	 //* POST:{Modifica el atributo proteccion de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setProteccion(string proteccion);

	 //* PRE:{}
	 //* POST:{Modifica el atributo tipo de luz de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setTipoLuz(string tipoLuz);

	 //* PRE:{}
	 //* POST:{Modifica el atributo material de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setMaterial(string material);

	 //* PRE:{}
	 //* POST:{Modifica el atributo longitud de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setGeo_long(float geo_long);

	 //* PRE:{}
	 //* POST:{Modifica el atributo potencia de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setOm_potencia(int om_potencia);

	 //* PRE:{}
	 //* POST:{Modifica el atributo tipo de lampara de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setOm_tipoLampara(string om_tipoLampara);

	 //* PRE:{}
	 //* POST:{Modifica el atributo latitud de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setGeo_lat(float geo_lat);

	 //* PRE:{}
	 //* POST:{Modifica el atributo altura de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setOm_altura(int om_altura);

	 //* PRE:{}
	 //* POST:{Modifica el atributo tipo de soporte de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setOm_tipoSoporte(string om_tipoSoporte);

	 //* PRE:{}
	 //* POST:{Modifica el atributo circuitos de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setOm_circuitos(int om_circuitos);

	 //* PRE:{}
	 //* POST:{Modifica el atributo material de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setOm_materialL(string om_materialL);

	 //* PRE:{}
	 //* POST:{Modifica el atributo coordenadas de la farola cambiandolo por el string de entrada}
	 //* COMPLEJIDAD:{O(1)}
	void setCoordenada(Coords *coordenada);


};

#endif /* FAROLA_H_ */
