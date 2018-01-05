/*
 * Body.h
 *
 *  Created on: 28 de nov de 2017
 *      Author: rafael
 */

#ifndef BODY_H_
#define BODY_H_
#include <GL/glut.h>
#include "Circle.h"
class Body : public Circle{
	GLfloat width, height, depth, z, originalZ;
public:
	Body(GLfloat height);
	virtual ~Body();
	GLfloat getDepth() const;
	void setDepth(GLfloat depth);
	GLfloat getHeight() const;
	void setHeight(GLfloat height);
	GLfloat getWidth() const;
	void setWidth(GLfloat width);
	GLfloat getZ() const;
	void setZ(GLfloat z);
	GLfloat getOriginalZ() const;
	void setOriginalZ(GLfloat originalZ);


	void drawBody(); //Upper body
	void drawHead(Body *circle,GLfloat height, GLfloat R, GLfloat G, GLfloat B);
	void drawArms(Body *circle,GLfloat height, GLfloat R, GLfloat G, GLfloat B);

};

#endif /* BODY_H_ */
