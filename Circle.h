/*
 * Circle.h
 *
 *  Created on: 14 de set de 2017
 *      Author: rafael
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_
#include <GL/glut.h>
#include <string>

class Circle {
private:  int id;
private : GLfloat colorR, colorG, colorB, x, y, radius, angle, angleGun ;
private: std::string color;



public:
	Circle();
	virtual ~Circle();
	GLfloat getColorB() const;
	void setColorB(GLfloat colorB);
	GLfloat getColorG() const;
	void setColorG(GLfloat colorG);
	GLfloat getColorR() const;
	void setColorR(GLfloat colorR);
	GLfloat getX() const;
	void setX(GLfloat x);
	GLfloat getY() const;
	void setY(GLfloat y);
	GLfloat getRadius() const;
	void setRadius(GLfloat radius);
	int getId() const;
	void setId(int id);


	const std::string& getColor() const;
	void setColor(const std::string& color);
	GLfloat getAngle() const;
	void setAngle(GLfloat angle);
	GLfloat getAngleGun() const;
	void setAngleGun(GLfloat angleGun);
};

#endif /* CIRCLE_H_ */
