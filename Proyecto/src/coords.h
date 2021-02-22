/*
 * coords.h
 *
 *  Created on: 6 de feb. de 2017
 *      Author: Profesores de la asignatura EDI
 */

#ifndef COORDS_H_
#define COORDS_H_

const float PI = 3.14159265;

class Coords {

private:

	float latitude;
	float longitude;

public:

	/*
	 * Default Constructor
	 * PRE:
	 * POST: {object initialized (latitude = longitude = 0.0)}
	 * COMPLEJIDAD: O(1)
	 */
	Coords();
	/*
	 * Parametrized Constructor
	 * PRE:
	 * POST:object initialized with the parameter values
	 * COMPLEJIDAD: O(1)
	 */
	Coords(float latitude, float longitude);
	/*
	 * Copy constructor.
	 * PRE:
	 * POST:Returns a Coords instance as a copy of the parameter values.
	 * COMPLEJIDAD
	 */

	Coords(const Coords &c);
	/*
	 * PRE: {latitude <> 0}
	 * POST: {Modify the latitude attribute with the value in the input parameter.}
	 * COMPLEJIDAD: O(1)
	 */
	void setLatitude(float latitude);
	/*
	 * PRE: {longitude <>0}
	 * POST: { Modify the longitude attribute with the value in the input parameter.}
	 * COMPLEJIDAD: O(1)
	 */
	void setLongitude(float longitude);

	/*
	 * PRE: {c <> NULL}
	 * POST:  Distance in meters between two points identified by decimal degrees coords.
	 * COMPLEJIDAD: O(1)
	 */
	float distanceTo(Coords *c);

	/*
	 * PRE:  {latitude<> 0 and longitude<>0}
	 * POST:  Distance in meters between two points identified by decimal degrees coords.
	 * COMPLEJIDAD: O(1)
	 */
	float distanceTo(float latitude, float longitude);
	/*
	 * PRE:  {}
	 * POST: {}
	 * COMPLEJIDAD: O(1)
	 */
	void show();

	~Coords();
};

#endif /* COORDS_H_ */
