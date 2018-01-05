/*
 * Body.cpp
 *
 *  Created on: 28 de nov de 2017
 *      Author: rafael
 */

#include "Body.h"
#include <math.h>
#include "headers.h"
#include "globals.h"

Body::Body(GLfloat height) : Circle() {
	// TODO Auto-generated constructor stub

	this->width = 2.5*height/7;
	this->depth = height*0.1;
	this->height = 2*height/7;
	this->z = 0;
	this->originalZ = this->z;

}

GLfloat Body::getDepth() const {
	return depth;
}

void Body::setDepth(GLfloat depth) {
	this->depth = depth;
}

GLfloat Body::getHeight() const {
	return height;
}

void Body::setHeight(GLfloat height) {
	this->height = height;
}

GLfloat Body::getWidth() const {
	return width;
}

GLfloat Body::getZ() const {
	return z;
}

void Body::setZ(GLfloat z) {
	this->z = z;
}

void Body::setWidth(GLfloat width) {
	this->width = width;
}

Body::~Body() {
	// TODO Auto-generated destructor stub
}

void Body::drawBody()
{




	bodyPlayer.draw();

}

void Body::drawHead(Body* circle,GLfloat height, GLfloat R, GLfloat G, GLfloat B)
{





	GLfloat headRadius = 0.65*height/7,
			zHead = headRadius + getZ() + getHeight()/2;
	glPushMatrix();
		glTranslatef(circle->getX(), circle->getY(), zHead);
		glRotatef(getAngle(),0,0,1);


		glutSolidSphere(headRadius,100,100);
	glPopMatrix();
}

GLfloat Body::getOriginalZ() const {
	return originalZ;
}

void Body::setOriginalZ(GLfloat originalZ) {
	this->originalZ = originalZ;
}

void Body::drawArms(Body* circle,GLfloat height, GLfloat R, GLfloat G, GLfloat B)
{




	GLfloat angle = getAngle()*M_PI/180;
	GLfloat wBody = getWidth(),
			dBody = getDepth(),
			hBody = getHeight(),
			zBody = getZ();


	GLfloat wArms = wBody/3,
			dArms = dBody/2,
			hArms = hBody/2;


	glPushMatrix();
		glTranslatef( circle->getX() -cos(angle) * (wBody/2+ wArms/2)  ,
					  circle->getY() -sin(angle) * (wBody/2+ wArms/2) , zBody+hArms/2);
		glRotatef(getAngle(),0,0,1);
		glScalef(wArms,dArms,hArms);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef( circle->getX() + cos(angle) * (wBody/2+ wArms/2) ,
					  circle->getY() + sin(angle) * (wBody/2+ wArms/2) , zBody+hArms/2);

		glRotatef(getAngle(),0,0,1);
		glScalef(wArms,dArms,hArms);
		glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
		glTranslatef( circle->getX() + cos(angle) * (wBody/2+ wArms/2)  ,
					  circle->getY() + sin(angle) * (wBody/2+ wArms/2) , zBody-hArms*0.8);
		glRotatef(getAngle(),0,0,1);
		glScalef(wArms,dArms,hArms*1.6);
		glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef( circle->getX() - cos(angle) * (wBody/2+ wArms/2 ) + sin(angle) * (hArms/2 + dArms/3),
					  circle->getY() - sin(angle) * (wBody/2+ wArms/2 ) - cos(angle) * (hArms/2 + dArms/3) , zBody-dArms/2);
		glRotatef(getAngle(),0,0,1);
		glRotatef(90,1,0,0);
		glScalef(wArms,dArms,hArms*1.6);
		glutSolidCube(1);
	glPopMatrix();




}
