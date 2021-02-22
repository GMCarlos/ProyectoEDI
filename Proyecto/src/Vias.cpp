/*
 * Vias.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Víctor Manuel Álvarez Redondo
 *      Author: Carlos Guillen Moreno
 *      Grupo: 01
 *      Clase para la gestion de vias mediante listas y arboles
 */

#include "Vias.h"
Vias::Vias() {
	Lv = new ListaPI<Via*>;
	Lf = new ListaPI<Farola*>;
	Av = new Arbol<Via*, CompararPtrVias>;

}

Vias::~Vias() {
	Via *v;
	Lv->moverInicio();
	while (!Lv->finLista()) {
		Lv->consultar(v);
		delete v;
		Lv->borrar();
	}
	Lv = NULL;
	Farola *f;
	Lf->moverInicio();
	while (!Lf->finLista()) {
		Lf->consultar(f);
		delete f;
		Lf->borrar();
	}
	Lf = NULL;
	delete Av;
}
void Vias::mostrar() {
	Via *v;
	Lv->moverInicio();
	while (!Lv->finLista()) {
		Lv->consultar(v);
		v->mostrar();
		Lv->avanzar();
	}
}
void Vias::insertarViaF(Via *v) {
	Lv->enFin();
	Lv->avanzar();
	Lv->insertar(v);
}
void Vias::insertarViasEnArbol(Via *v) {
	Av->insertar(v);
}

void Vias::insertarViaOrden(Via *v) {
	bool enc = false;
	Lv->moverInicio();
	Via *vAux;
	while (!Lv->finLista() && !enc) {
		Lv->consultar(vAux);
		if (*vAux > *v)
			enc = true;
		else
			Lv->avanzar();

	}
	if (enc == true)
		Lv->insertar(v);
	else
		insertarViaF(v);
}
void Vias::buscarCallesBarrio(Vias *&c, string s) {
	Lv->moverInicio();
	string aux = "";
	Via *v;
	Barrio *b;
	while (!Lv->finLista()) {
		Lv->consultar(v);
		v->getSituadaEnBarrio(b);
		b->getNombreBarrio(aux);
		if (s == aux)
			c->insertarViaOrden(v);
		Lv->avanzar();
	}
}
void Vias::buscarBarriosAdyacentes(Vias *v, Barrio *&b, Barrios *&barrios) {
	Lv->moverInicio();
	Via *via;
	Via *viaux;
	Barrio *aux;
	string nombre = "";
	while (!Lv->finLista()) {
		Lv->consultar(via);
		v->Lv->moverInicio();
		while (!v->Lv->finLista()) {
			v->Lv->consultar(viaux);
			if (via->viasBarriosAdyacentes(viaux)) {
				viaux->getSituadaEnBarrio(aux);
				aux->getNombreBarrio(nombre);
				if (!barrios->esta(nombre) && b != aux) {
					barrios->insertarBarrioF(aux);
				}
			}
			v->Lv->avanzar();

		}
		Lv->avanzar();
	}
}
void Vias::farolasEnVias(Via *&v, float lat, float lon) {
	if (lat != 0 && lon != 0) {
		Coords *coordenada = new Coords(lat, lon);
		Via *aux;
		Lv->moverInicio();
		Lv->consultar(aux);
		float distancia;
		float distanciaAux;
		float longitud;
		string nombre;
		aux->distanciaVia(coordenada, distancia);
		while (!Lv->finLista()) {
			Lv->consultar(aux);
			aux->getLongitudVia(longitud);
			if (longitud != 0) {
				aux->distanciaVia(coordenada, distanciaAux);
				if (distanciaAux < distancia) {
					v = aux;
					distancia = distanciaAux;
				}
			}
			Lv->avanzar();
		}
		v->getNombre(nombre);
	}
}
void Vias::insertarFarolaFinal(Farola *f) {
	Lf->enFin();
	Lf->avanzar();
	Lf->insertar(f);
}
bool Vias::esta(Via *via) {
	Via *v;
	Lv->moverInicio();
	string nombre = "";
	bool encontrado = false;
	while (!Lv->finLista() && !encontrado) {
		Lv->consultar(v);
		if (via == v)
			encontrado = true;
		else
			Lv->avanzar();

	}
	return encontrado;
}
void Vias::mostrarFarolas() {
	Farola *f;
	Lf->moverInicio();
	while (!Lf->finLista()) {
		Lf->consultar(f);
		f->mostrar();
		Lf->avanzar();
	}
}
void Vias::viaMayorConcentracion(Via *&v, float &p) {
	Via *aux;
	Via *viafarola;
	int numeroFarolasAux;
	float longitudAux = 0.0;
	Farola *f;
	Lv->moverInicio();
	while (!Lv->finLista()) {
		numeroFarolasAux = 0;
		Lv->consultar(aux);
		Lf->moverInicio();
		while (!Lf->finLista()) {
			Lf->consultar(f);
			f->getVia(viafarola);
			if (aux == viafarola)
				numeroFarolasAux++;
			Lf->avanzar();

		}
		aux->getLongitudVia(longitudAux);
		if (longitudAux != 0.0) {
			longitudAux = numeroFarolasAux / longitudAux;
			if (longitudAux > p) {
				v = aux;
				p = longitudAux;
			}
		}
		Lv->avanzar();
	}
}
void Vias::obtenerViasDelDistrito(string Distrito) {
	Via *vaux;
	Barrio *baux;
	string s;
	string aux;
	ofstream fsal;
	fsal.open("ViasPorDistrito.csv");
	Lv->moverInicio();

	while (!Lv->finLista()) {
		Lv->consultar(vaux);
		vaux->getSituadaEnBarrio(baux);
		baux->getNombreDistrito(s);
		if (s == Distrito) {
			vaux->getNombre(aux);
			fsal << aux << endl;

		}
		Lv->avanzar();
	}
	fsal.close();

}

void Vias::obtenerViasConFarolaEspecifica(string farolilla) {
	Vias *vias = new Vias;
	Farola *faux;
	Via *vaux;
	ofstream fsal;
	string s = "";
	string aux;
	string codigo="";
	fsal.open("ViasConFarolaEspecifica.txt");
	Lf->moverInicio();
	while (!Lf->finLista()) {
		Lf->consultar(faux);
		faux->getOm_tipoLampara(s);
		if (s == farolilla) {
			faux->getVia(vaux);
			if (!vias->esta(vaux)) {
				vias->insertarViaF(vaux);
				vaux->getNombre(aux);
				if (aux != ""){
					fsal << aux << " "<<vaux->getTieneCodigoVia()<<endl;
				}
			}
		}
		Lf->avanzar();
	}
	fsal.close();
}

void Vias::ConsumoPorDistrito() {
	Farola *faux;
	Via *vaux;
	ofstream fsal;
	string s = "";
	Barrio *b;
	int potencia = 0;
	float Centro = 0.0;
	float Norte = 0.0;
	float Sur = 0.0;
	float Pedanias = 0.0;
	float Oeste = 0.0;
	fsal.open("consumoDistritos.txt");
	Lf->moverInicio();
	while (!Lf->finLista()) {
		Lf->consultar(faux);
		faux->getVia(vaux);
		faux->getOm_potencia(potencia);
		vaux->getSituadaEnBarrio(b);
		if (b != NULL)
			b->getNombreDistrito(s);
		if (s == "Centro") {
			Centro = Centro + (8 * potencia * 0.12149);
		} else if (s == "Norte")
			Norte = Norte + (8 * potencia * 0.12149);
		else if (s == "Sur")
			Sur = Sur + (8 * potencia * 0.12149);
		else if (s == "Pedanías")
			Pedanias = Pedanias + (8 * potencia * 0.12149);
		else if (s == "Oeste")
			Oeste = Oeste + (8 * potencia * 0.12149);
		Lf->avanzar();
	}
	fsal << "Consumo Centro:" << endl;
	fsal << fixed << setprecision(4) << Centro << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Norte:" << endl;
	fsal << fixed << setprecision(4) << Norte << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Sur:" << endl;
	fsal << fixed << setprecision(4) << Sur << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Oeste:" << endl;
	fsal << fixed << setprecision(4) << Oeste << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Pedanias:" << endl;
	fsal << fixed << setprecision(4) << Pedanias << " euros" << endl;
	fsal << "----------------------" << endl;

	fsal.close();
}
bool Vias::ahorroConsumo(string lampara1, string lampara2) {
	bool enc = true;
	double consumo = 0.0;
	double consumo2 = 0.0;
	Farola *faux;
	Via *vaux;
	ofstream fsal;
	string s1 = "";
	int potencia1 = 0;
	int potencia2 = 0;
	int numerolamparas1 = 0;
	int numerolamparas2 = 0;
	float aux = 0.0;
	fsal.open("ahorroConsumo.txt");
	Lf->moverInicio();
	while (!Lf->finLista()) {
		Lf->consultar(faux);
		faux->getVia(vaux);
		faux->getOm_tipoLampara(s1);
		if (s1 == lampara1) {
			if (potencia1 == 0) {
				faux->getOm_potencia(potencia1);
			}
			numerolamparas1++;
			consumo = consumo + (8 * potencia1 * 0.12149);
		} else if (s1 == lampara2) {
			if (potencia2 == 0) {
				faux->getOm_potencia(potencia2);
			}
			numerolamparas2++;
			consumo2 = consumo2 + (8 * potencia2 * 0.12149);
		}
		Lf->avanzar();
	}
	if (potencia1 == 0 || potencia2 == 0)
		enc = false;
	if (enc) {
		fsal << "El consumo de lamparas " << lampara1 << " es de:" << endl;
		fsal << fixed << setprecision(2) << consumo / 1000 << " euros con "
				<< numerolamparas1 << " lamparas con potencia de " << potencia1
				<< "W" << endl;
		fsal << "El consumo de lamparas " << lampara2 << " es de:" << endl;
		fsal << fixed << setprecision(2) << consumo2 / 1000 << " euros con "
				<< numerolamparas2 << " lamparas con potencia de " << potencia2
				<< "W" << endl;
		aux = (consumo + consumo2) / 1000;
		fsal << "El consumo total de las dos lamparas es de: " << aux << endl;
		fsal << "Si sustituimos las lamparas " << lampara1
				<< " por las lamparas " << lampara2
				<< " el consumo de las dos lamparas es de: " << endl;
		aux = (consumo2) + ((8 * potencia2 * 0.12149 * numerolamparas1) / 1000);
		fsal << fixed << setprecision(2) << aux << " euros";

		fsal.close();
	}

	return enc;
}

bool Vias::empiezaPor(string str, string substr) {
	bool comienza = false;
	if (str.find(substr) == 0)
		comienza = true;

	return comienza;
}

void Vias::filtroInOrden(Arbol<Via *, CompararPtrVias> *bst,
		const string &nombre) {

	//TODO Completar
	Arbol<Via *, CompararPtrVias> *aux;
	Via *vaux;

	if (!bst->vacio()) {

		aux = bst->hijoIzq();
		if (aux != NULL) {
			filtroInOrden(aux, nombre);
		}
		vaux = bst->raiz();
		if (empiezaPor(vaux->getName(), nombre)) {

			cout << vaux->getName() << endl;
		}

		aux = bst->hijoDer();
		if (aux != NULL) {
			filtroInOrden(aux, nombre);
		}

	}
}
Arbol<Via *, CompararPtrVias> * Vias::arbol_similar(
		Arbol<Via *, CompararPtrVias> *bst, const string &nombre) {

	Arbol<Via *, CompararPtrVias> *aux;
	Via *vaux;

	if (!bst->vacio()) {
		vaux = bst->raiz();
		if (empiezaPor(vaux->getName(), nombre)) {
			aux = bst;

		} else {

			if (vaux->getName() > nombre) {
				aux = bst->hijoIzq();
				if (aux != NULL) {
					aux = arbol_similar(aux, nombre);
				}
			} else {
				aux = bst->hijoDer();
				if (aux != NULL) {
					aux = arbol_similar(aux, nombre);
				}
			}
		}

	}
	return aux;
}
void Vias::similar(const string &nombre) {

	Arbol<Via *, CompararPtrVias> *bst;

	if (!this->Av->vacio()) {

		bst = this->arbol_similar(this->Av, nombre);
		if (bst != NULL) {
			cout << "Mostrando las coincidencias de: " << nombre << endl;
			filtroInOrden(bst, nombre);
		} else {
			cout << "Ninguna via comienza por: " << nombre << endl;
		}
	}
}
bool Vias::buscarEnArbol(Arbol<Via *, CompararPtrVias> *bst, string &nombre,
		 string &t) {

	//TODO completar
	Arbol<Via *, CompararPtrVias> *aux;
	bool enc = false;
	Via *vaux;

	if (!bst->vacio()) {
		vaux = bst->raiz();
		if (nombre == vaux->getName()) {
			enc = true;
			cout << "Via encontrada" << endl;
			vaux->setNombreVia(t);
			cout << "La via ahora se llama " << vaux->getName()<<endl;

		} else {
			if (vaux->getName() > nombre) {
				aux = bst->hijoIzq();
				if (aux != NULL) {
					enc = buscarEnArbol(aux, nombre, t);
				}
			} else {
				aux = bst->hijoDer();
				if (aux != NULL) {
					enc = buscarEnArbol(aux, nombre, t);
				}
			}
		}
	}
	return enc;
}
void Vias::empiezaPorUsandoLista(string str) {
	Via *v;
	Lv->moverInicio();
	string aux;
	while (!Lv->finLista()) {
		Lv->consultar(v);
		v->getNombre(aux);
		if (empiezaPor(aux, str)) {
			cout << aux << endl;
		}
		Lv->avanzar();
	}
}
void Vias::cambiarNombre(string s, string t) {
	Via *v;
	string aux;
	bool enc = false;
	Lv->moverInicio();
	while (!Lv->finLista() && !enc) {
		Lv->consultar(v);
		v->getNombre(aux);
		if (aux == s) {
			v->setNombreVia(t);
			enc = true;
			aux = v->getName();
			cout << "Nombre de via cambiado con exito: " << aux << endl;
		}
		Lv->avanzar();
	}
}
bool Vias::viasVacia() {
	return Lv->estaVacia();
}
bool Vias::buscar(string nombre, string t) {
	bool enc = false;
	if (this->Av != NULL)
		enc = buscarEnArbol(this->Av, nombre,  t);
	return enc;
}

bool Vias::farolasVacia() {
	return Lf->estaVacia();
}
void Vias::generarConsumoArbol() {
	float Centro = 0.0;
	float Norte = 0.0;
	float Sur = 0.0;
	float Pedanias = 0.0;
	float Oeste = 0.0;
	generarConsumoArbolImpl(this->Av, Centro, Norte, Sur, Pedanias, Oeste);
	ofstream fsal;
	fsal.open("consumoDistritosArbol.txt");
	fsal << "Consumo Centro:" << endl;
	fsal << fixed << setprecision(4) << Centro << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Norte:" << endl;
	fsal << fixed << setprecision(4) << Norte << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Sur:" << endl;
	fsal << fixed << setprecision(4) << Sur << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Oeste:" << endl;
	fsal << fixed << setprecision(4) << Oeste << " euros" << endl;
	fsal << "----------------------" << endl;
	fsal << "Consumo Pedanias:" << endl;
	fsal << fixed << setprecision(4) << Pedanias << " euros" << endl;
	fsal << "----------------------" << endl;

	fsal.close();
}
void Vias::generarConsumoArbolImpl(Arbol<Via *, CompararPtrVias> *arbol,
		float &Centro, float &Norte, float &Sur, float &Pedanias,
		float &Oeste) {
	Arbol<Via*, CompararPtrVias> *aux;
	if (!arbol->vacio()) {
		if (arbol->raiz() != NULL) {
			Via *vaux;
			string nombre;
			Barrio *baux;
			vaux = arbol->raiz();
			vaux->getSituadaEnBarrio(baux);
			if (baux != NULL) {
				baux->getNombreDistrito(nombre);
				if (nombre == "Centro") {
					farolasPorVias(vaux, Centro);
				} else if (nombre == "Norte") {
					farolasPorVias(vaux, Norte);
				} else if (nombre == "Sur") {
					farolasPorVias(vaux, Sur);
				} else if (nombre == "Pedanías") {
					farolasPorVias(vaux, Pedanias);
				} else if (nombre == "Oeste") {
					farolasPorVias(vaux, Oeste);
				}
			}
		}
		aux = arbol->hijoIzq();
		if (aux != NULL) {
			if (aux->raiz() != NULL)
				generarConsumoArbolImpl(aux, Centro, Norte, Sur, Pedanias,
						Oeste);

		}

		aux = arbol->hijoDer();
		if (aux != NULL) {
			if (aux->raiz() != NULL)
				generarConsumoArbolImpl(aux, Centro, Norte, Sur, Pedanias,
						Oeste);
		}

	}
}
void Vias::farolasPorVias(Via *v, float &Distrito) {
	Lf->moverInicio();
	Farola *faux;
	Via *vuax;
	int potencia;
	while (!Lf->finLista()) {
		Lf->consultar(faux);
		faux->getVia(vuax);
		if (v == vuax) {
			faux->getOm_potencia(potencia);
			Distrito = Distrito + (8 * potencia * 0.12149);
		}
		Lf->avanzar();
	}
}

