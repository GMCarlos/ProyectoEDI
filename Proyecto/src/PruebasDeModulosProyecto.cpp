/*
 * PruebasDeModulosProyecto.cpp
 *
 *  Created on: 28 may. 2017
 *      Author: carlos
 */

#include "PruebasDeModulosProyecto.h"

PruebasDeModulosProyecto::PruebasDeModulosProyecto() {
	this->pruebasCalles = new Vias;
	this->pruebasDistritos =  new Distritos;
	this->pruebasBarrios = new Barrios;
	this->daux1 = new Distrito("Centro");
	this->daux2 = new Distrito("Norte");
	pruebasDistritos->insertarDistritoFinal(daux1);
	pruebasDistritos->insertarDistritoFinal(daux2);
	this->baux1 = new Barrio("Barrio 1", daux1 );
	this->baux2 = new Barrio("Barrio 2", daux2 );
	pruebasBarrios->insertarBarrioF(baux1);
	pruebasBarrios->insertarBarrioF(baux2);
	this->vaux1=new Via("Via 1",1000.00,"tipo via 1","0135",100, 200, 300, 400, 500,600, baux1);
	this->vaux2=new Via("Via 2",4000.00,"tipo via 2","2135",400, 500, 600, 700, 800, 900, baux2);

	pruebasCalles->insertarViaF(vaux1);
	pruebasCalles->insertarViaF(vaux2);

	string tipolampara = "Prueba tipo Lampara";


	this->faux1 = new Farola("Funcionamiento de prueba","Proteccion Prueba","Tipo de luz prueba", "Material prueba", 1,2, tipolampara,3,4,"Prueba tipo soporte", 5, "Material prueba", vaux1);
	this->faux2 = new Farola("Funcionamiento de prueba","Proteccion Prueba","Tipo de luz prueba", "Material prueba", 1,2, tipolampara,3,4,"Prueba tipo soporte", 5, "Material prueba", vaux2);

	pruebasCalles->insertarFarolaFinal(faux1);
	pruebasCalles->insertarFarolaFinal(faux2);


	Av = new Arbol<Via*, CompararPtrVias>;
	pruebasCalles->insertarViasEnArbol(vaux1);
	pruebasCalles->insertarViasEnArbol(vaux2);
}



void PruebasDeModulosProyecto::pruebaModulo2() {

	if (pruebasBarrios->esta("Barrio 1")) {
		Vias *c = new Vias;
		pruebasCalles->buscarCallesBarrio(c, "Barrio 1");
		c->mostrar();
	}else
		cout<<"El barrio introducido no existe"<<endl;


}

void PruebasDeModulosProyecto::pruebaModulo3(){


	if(pruebasDistritos->esta("Centro")){
		pruebasCalles->obtenerViasDelDistrito("Centro");
		}else
			cout<<"El distrito no existe"<<endl;


}
void PruebasDeModulosProyecto::pruebaModulo4(){


	if (pruebasBarrios->esta("Barrio 1")) {
			//vias del barrio
		Vias *c = new Vias;
			pruebasCalles->buscarCallesBarrio(c, "Barrio 1");
			Barrio *b;
			Barrios *barriosaux = new Barrios;
			pruebasBarrios->buscarBarrio(b, "Barrio 1");
			c->buscarBarriosAdyacentes(pruebasCalles, b, barriosaux);
			barriosaux->mostrar();
		}else
			cout<<"El barrio introducido no existe"<<endl;


}
void PruebasDeModulosProyecto::pruebaModulo5(){
	Via *v;
		string nombre;
		float p;
		pruebasCalles->viaMayorConcentracion(v, p);
		cout << "Via con mayor concentracion de farolas:" << endl;
		v->getNombre(nombre);
		cout << nombre << " proporcion:" << p << endl;

}
void PruebasDeModulosProyecto::pruebaModulo6(){
	string distrito = "Distrito prueba 6";
	Distrito *d = new Distrito(distrito);
	pruebasDistritos->insertarDistritoFinal(d);

	string barrio = "Barrio prueba 6";
	Barrio *b = new Barrio(barrio, d);
	pruebasBarrios->insertarBarrioF(b);


	string via = "Via prueba 6";
	Via *v = new Via(via,1,"Tipo via prueba", "1234", 1, 2, 3, 4,5 ,6,b);

	string tipolampara = "Prueba tipo Lampara";
	Farola *f = new Farola("Funcionamiento de prueba","Proteccion Prueba","Tipo de luz prueba", "Material prueba", 1,2, tipolampara,3,4,"Prueba tipo soporte", 5, "Material prueba", v);



	pruebasCalles->insertarViaF(v);

	pruebasCalles->obtenerViasConFarolaEspecifica(tipolampara);
}
void PruebasDeModulosProyecto::pruebaModulo7(){
	string distrito = "Distrito prueba 7";
	Distrito *d = new Distrito(distrito);
	pruebasDistritos->insertarDistritoFinal(d);


	string barrio = "Barrio prueba 7";
	Barrio *b = new Barrio(barrio, d);
	pruebasBarrios->insertarBarrioF(b);


	string via = "Via prueba 7";
	Via *v1 = new Via(via,1,"Tipo via prueba", "1234", 1, 2, 3, 4,5 ,6,b);

	//Para arbol
	pruebasCalles->insertarViasEnArbol(v1);
	//Para lista
	pruebasCalles->insertarViaF(v1);

	//Por arbol
	pruebasCalles->similar(via);

	//Por lista
	pruebasCalles->empiezaPorUsandoLista(via);
}
void PruebasDeModulosProyecto::pruebaModulo8(){
	string distrito = "Distrito prueba 8";
	Distrito *d = new Distrito(distrito);
	pruebasDistritos->insertarDistritoFinal(d);

	string barrio = "Barrio prueba 8";
	Barrio *b = new Barrio(barrio, d);
	pruebasBarrios->insertarBarrioF(b);

	string via = "Via prueba 8";
	Via *v1 = new Via(via,1,"Tipo via prueba", "1234", 1, 2, 3, 4,5 ,6,b);

	//Para arbol
	pruebasCalles->insertarViasEnArbol(v1);
	//Para lista
	pruebasCalles->insertarViaF(v1);

	//Por lista
	pruebasCalles->ConsumoPorDistrito();
	//Por arbol
	pruebasCalles->generarConsumoArbol();

}
void PruebasDeModulosProyecto::pruebaModulo9(){
	string distrito = "Distrito prueba 9";
	Distrito *d = new Distrito(distrito);
	pruebasDistritos->insertarDistritoFinal(d);

	string barrio = "Barrio prueba 9";
	Barrio *b = new Barrio(barrio, d);
	pruebasBarrios->insertarBarrioF(b);

	string via = "Via prueba 9";
	Via *v1 = new Via(via,1,"Tipo via prueba", "1234", 1, 2, 3, 4,5 ,6,b);
	Via *v2 = new Via(via,2,"Tipo via prueba", "1234", 5, 34, 8, 7,12 ,14,b);

	pruebasCalles->insertarViaF(v1);
	pruebasCalles->insertarViaF(v2);

	string tipolampara1 = "Prueba tipo Lampara 1 ";
	string tipolampara2 = "Prueba tipo Lampara 2";
	Farola *f = new Farola("Funcionamiento de prueba","Proteccion Prueba","Tipo de luz prueba", "Material prueba", 1,2, tipolampara1,3,4,"Prueba tipo soporte", 5, "Material prueba", v1);
	Farola *f2 = new Farola("Funcionamiento de prueba","Proteccion Prueba","Tipo de luz prueba", "Material prueba", 1,2, tipolampara2,3,4,"Prueba tipo soporte", 5, "Material prueba", v2);
	pruebasCalles->insertarFarolaFinal(f);
	pruebasCalles->insertarFarolaFinal(f2);
	bool enc;
	enc=pruebasCalles->ahorroConsumo(tipolampara1, tipolampara2);
	if(!enc)
		cout<<"Una de las dos lamparas no existe"<<endl;

}
void PruebasDeModulosProyecto::pruebaModulo10(){

	//Por lista
	pruebasCalles->cambiarNombre("Via 1", "Cambio de nombre de la Via 1");

	//Por arboles
	Via *v = NULL;
		bool enc = false;

		enc = pruebasCalles->buscar("Via 2","Cambio de nombre de la Via 2" );

		if (enc) {
			cout << "Via encontrada" << endl;
			v->setNombreVia("Cambio de nombre de la Via 2");
			cout << "La via ahora se llama " << v->getName();
		} else {
			cout << "Via " << "Via 2" << " no encontrada!" << endl;
		}

}

PruebasDeModulosProyecto::~PruebasDeModulosProyecto() {
	if (pruebasDistritos != NULL)
			delete pruebasDistritos;
		if (pruebasCalles != NULL)
			delete pruebasCalles;
		if (pruebasBarrios != NULL)
			delete pruebasBarrios;
}
