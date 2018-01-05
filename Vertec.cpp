/*
 * Vertec.cpp
 *
 *  Created on: 11 de dez de 2017
 *      Author: rafael
 */

#include "Vertec.h"


Vertec::Vertec(){
	X=0;
	Y=0;
	Z=0;

	U=0;
	V=0;

	nX=0;
	nY=0;
	nZ=0;
}

Vertec::Vertec(float x, float y, float z , float u, float v, float nx, float ny, float nz){
	X=x;
	Y=y;
	Z=z;
	U=u;
	V=v;
	nX=nx;
	nY=ny;
	nZ=nz;
}

Vertec::Vertec(float x, float y, float z ){
	X=x;
	Y=y;
	Z=z;

}
