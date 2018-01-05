/*
 * Vertec.h
 *
 *  Created on: 11 de dez de 2017
 *      Author: rafael
 */

#ifndef VERTEC_H_
#define VERTEC_H_

class Vertec {
public:
	Vertec();
	Vertec(float x, float y, float z );
	Vertec(float x, float y, float z, float u, float v, float nx, float ny, float nz);
	//Vertex coordinate
		float X;
		float Y;
		float Z;

	//Vertex normal
		float nX;
		float nY;
		float nZ;

	//Vertex texture coordinate
		float U;
		float V;

	//Direction coordinate
		float dX, dY, dZ;
};

#endif /* VERTEC_H_ */
