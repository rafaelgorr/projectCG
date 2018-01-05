/*
 * Circle.cpp
 *
 *  Created on: 14 de set de 2017
 *      Author: rafael
 */

#include "Circle.h"

Circle::Circle() {
	// TODO Auto-generated constructor stub
	x = 0;
	y = 0;
	colorR = 0;
	colorG = 0;
	colorB = 0;
	angle = 0;
	radius = 0;

}

GLfloat Circle::getColorB() const {
	return colorB;
}

void Circle::setColorB(GLfloat colorB) {
	this->colorB = colorB;
}

GLfloat Circle::getColorG() const {
	return colorG;
}

void Circle::setColorG(GLfloat colorG) {
	this->colorG = colorG;
}

GLfloat Circle::getColorR() const {
	return colorR;
}

void Circle::setColorR(GLfloat colorR) {
	this->colorR = colorR;
}


Circle::~Circle() {
	// TODO Auto-generated destructor stub
}

GLfloat Circle::getX() const {
	return x;
}

void Circle::setX(GLfloat x) {
	this->x = x;
}

GLfloat Circle::getY() const {
	return y;
}

void Circle::setY(GLfloat y) {
	this->y = y;
}

GLfloat Circle::getRadius() const {
	return radius;
}

void Circle::setRadius(GLfloat radius) {
	this->radius = radius;
}

int Circle::getId() const {
	return id;
}

void Circle::setId(int id) {
	this->id = id;
}



const std::string& Circle::getColor() const {
	return color;
}

void Circle::setColor(const std::string& color) {
	this->color = color;
}

GLfloat Circle::getAngle() const {
	return angle;
}

void Circle::setAngle(GLfloat angle) {
	this->angle = angle;
}



GLfloat Circle::getAngleGun() const {
	return angleGun;
}

void Circle::setAngleGun(GLfloat angleGun) {
	this->angleGun = angleGun;
}
