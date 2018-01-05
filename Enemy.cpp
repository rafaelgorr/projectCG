/*
 * Enemy.cpp
 *
 *  Created on: 14 de nov de 2017
 *      Author: rafael
 */

#include "Enemy.h"
#include "globals.h"

Enemy::Enemy(GLfloat bS, GLfloat spd) : Player( bS, spd) {
	// TODO Auto-generated constructor stub

	lastTimeShot = 0;
	lasTimeWalk = 0;
	factor = 0;


}

time_t Enemy::getLasTimeWalk() const {
	return lasTimeWalk;
}

void Enemy::setLasTimeWalk(time_t lasTimeWalk) {
	this->lasTimeWalk = lasTimeWalk;
}

time_t Enemy::getLastTimeShot() const {
	return lastTimeShot;
}

void Enemy::setLastTimeShot(time_t lastTimeShot) {
	this->lastTimeShot = lastTimeShot;
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

GLfloat Enemy::getFreqShot() const {
	return freqShot;
}

void Enemy::setFreqShot(GLfloat freqShot) {
	this->freqShot = freqShot;
}

time_t Enemy::getLastTimeRotate() const {
	return lastTimeRotate;
}

int Enemy::getFactor() const {
	return factor;
}

void Enemy::setFactor(int factor) {
	this->factor = factor;
}

void Enemy::setLastTimeRotate(time_t lastTimeRotate) {
	this->lastTimeRotate = lastTimeRotate;
}

time_t Enemy::getWalkBackEffect() const {
	return walkBackEffect;
}

void Enemy::setWalkBackEffect(time_t walkBackEffect) {
	this->walkBackEffect = walkBackEffect;
}

bool Enemy::checkCollision() {
	GLfloat distCenters;

	GLfloat currentTime = glutGet(GLUT_ELAPSED_TIME);


	distCenters = sqrt(pow(biggerCircle->getX() - getBody()->getX(),2) + pow(biggerCircle->getY() -getBody()->getY(),2));
	if(distCenters > biggerCircle->getRadius() - getCollisionCircle())
	{
		factor = 1;
		return true;
	}





	distCenters = sqrt(pow(centerCircle->getX() - getBody()->getX(),2) + pow(centerCircle->getY() - getBody()->getY(),2));
	if(distCenters < centerCircle->getRadius() + getCollisionCircle())
	{
		factor = 1;
		return true;
	}




	distCenters = sqrt(pow(player->getBody()->getX() - getBody()->getX(),2) + pow(player->getBody()->getY() - getBody()->getY(),2));
	if(distCenters < player->getCollisionCircle() + getCollisionCircle())
	{
		factor = 0;
		return true;
	}

	for(auto& ene: enemies)
	{
		if(ene == this)
			continue;

		distCenters = sqrt(pow(ene->getBody()->getX() - getBody()->getX(),2) + pow(ene->getBody()->getY() -  getBody()->getY(),2));
		if(distCenters < ene->getCollisionCircle() +  getCollisionCircle())
			return true;
	}

	size_t aux = 0; //Aux cont the number of obstacles
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	for(auto& obs : obstacles) //Check if the player is over some obstacle
	{
		distCenters = sqrt(pow(obs->getX() -  getBody()->getX(),2) + pow(obs->getY() -  getBody()->getY(),2));


		if(distCenters < obs->getRadius() +  getCollisionCircle())
		{

			if( isJumping() && (currentTime - getJumpedTime())/1000.0 > (obstacleHeight/100)
							&& (currentTime - getJumpedTime())/1000.0 < 2 - (obstacleHeight/100) )
			{
				 setOverObstacle( true);

				break;
			}
			if(isOverObstacle())
				break;

		}
		aux++;


	}
	if(aux == obstacles.size())//Check if the player isn't over some obstacle
		 setOverObstacle(false);


	for(auto& obs : obstacles)
	{
		if( isOverObstacle())
			break;

		distCenters = sqrt(pow(obs->getX() -  getBody()->getX(),2) + pow(obs->getY() -  getBody()->getY(),2));


		if(distCenters < obs->getRadius() + getCollisionCircle() )
		{
			if(!isJumping()) //Bot jump if collide with some obstacle
			{
				setJumpedTime(glutGet(GLUT_ELAPSED_TIME));
				setJumping(true);

				if(isOverObstacle())
					setJumpedOverObstacle(true);
				else
					setJumpedOverObstacle(false);
			}
			factor = 0;
			return true;
		}

	}

	factor = 0;

	return false;
}


