/*
 * Player.h
 *
 *  Created on: 19 de out de 2017
 *      Author: rafael
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Circle.h"
#include "Body.h"
#include <GL/glut.h>
#include "functions.h"
#include <time.h>
#include <math.h>
#include <iostream>

#define PI acos(-1.0)

class Player {
	GLfloat bulletSpeed, speed, angleGun, originalRadius, collisionCircle, height, angleLegs, angleArmZ, angleArmX;

	Body *body;
	bool jumping , overObstacle, jumpedOverObstacle;
	time_t jumpedTime;

	int indexLeg;

public:
	Player(GLfloat bS, GLfloat speed);
	virtual ~Player();

	/* ACTION FUNCTIONS*/
	void walk(int dir,GLfloat dTime, bool collision);
	void rotate(int dir, GLfloat dTime);
	Vertec* shoot();
	void jump();
	void Jumping();
	bool checkCollision();



	/* DRAW PLAYER */
	void drawPlayer();
	void drawGun();
	void drawArm();
	void drawHead();
	void drawEyes();
	void drawNavy();
	void drawSumka();
	void drawLeftHand();
	void drawRightHand();

	/* GETTERS AND SETTERS */
	GLfloat getBulletSpeed() const;
	void setBulletSpeed(GLfloat bulletSpeed);

	GLfloat getSpeed() const;
	void setSpeed(GLfloat speed);

	Body* getBody() const;
	void setBody(Body* body);

	GLfloat getAngleGun() const;
	void setAngleGun(int x, int y);

	void setGunAngle(GLfloat angle);

	GLfloat getOriginalRadius() const;
	void setOriginalRadius(GLfloat originalRadius);

	GLfloat getCollisionCircle() const;
	void setCollisionCircle(GLfloat collisionCircle);

	bool isJumping() const;
	void setJumping(bool jumping);

	bool isOverObstacle() const;
	void setOverObstacle(bool overObstacle);

	bool isJumpedOverObstacle() const;
	void setJumpedOverObstacle(bool jumpedOverObstacle);

	time_t getJumpedTime() const;
	void setJumpedTime(time_t jumpedTime);

	GLfloat getHeight() const;
	void setHeight(GLfloat height);

	GLfloat getAngleLegs() const;
	void setAngleLegs(GLfloat angleLegs);

	GLfloat getAngleArmX() const;
	void setAngleArmX(GLfloat angleArmX);

	GLfloat getAngleArmZ() const;
	void setAngleArmZ(GLfloat angleArmZ);

	int getIndexLeg() const;
	void setIndexLeg(int indexLeg);





};

#endif /* PLAYER_H_ */
