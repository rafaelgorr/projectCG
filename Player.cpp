/*
 * Player.cpp
 *
 *  Created on: 19 de out de 2017
 *      Author: rafael
 */

#include "Player.h"
#include "globals.h"

Player::Player(GLfloat bS, GLfloat speed) {

	this->bulletSpeed = bS;
	this->speed = speed;
	this->body = NULL;


	jumping = false;
	overObstacle = false;
	jumpedOverObstacle = false;


	angleLegs = 0;

	angleArmX = 0;
	angleArmZ = 0;
	indexLeg = 0;
}

void Player:: drawPlayer()
{
	glBindTexture (GL_TEXTURE_2D, bodyPlayer.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );



	glPushMatrix();
		glTranslated(getBody()->getX(), getBody()->getY(),getBody()->getZ());
		glRotated(getBody()->getAngle(),0,0,1);

		glScaled(getHeight(),getHeight(),getHeight());


		legs[indexLeg].draw();
		bodyPlayer.draw();
		drawHead();
		drawEyes();
		drawNavy();
		drawSumka();
		drawLeftHand();


		drawArm();
	glPopMatrix();
}

void Player::drawArm() {
	glPushMatrix();
		glBindTexture (GL_TEXTURE_2D, arm.getMeshTex());
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );


		glTranslated(upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
		glRotated(angleArmZ,0,0,1);
		glRotated(angleArmX,1,0,0);

		arm.draw();
		drawRightHand();
		drawGun();
	glPopMatrix();
}

void Player::drawHead() {
	glBindTexture (GL_TEXTURE_2D, head.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	head.draw();
}

void Player::drawEyes() {
	glBindTexture (GL_TEXTURE_2D, eyes.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	eyes.draw();

}
void Player::drawNavy(){
	glBindTexture (GL_TEXTURE_2D, navy.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	navy.draw();
}
void Player::drawSumka(){
	glBindTexture (GL_TEXTURE_2D, sumka.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	sumka.draw();
}
void Player::drawRightHand(){
	glBindTexture (GL_TEXTURE_2D, rightHand.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	rightHand.draw();
}

void Player::drawLeftHand(){
	glBindTexture (GL_TEXTURE_2D, leftHand.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );

	leftHand.draw();
}

GLfloat Player::getBulletSpeed() const {
	return bulletSpeed;
}

void Player::setBulletSpeed(GLfloat bulletSpeed) {
	this->bulletSpeed = bulletSpeed;
}

GLfloat Player::getSpeed() const {
	return speed;
}

Body* Player::getBody() const {
	return body;
}

void Player::setBody(Body* body) {
	this->body = body;

	if(getBody() != NULL)
	{
		angleGun = 0;

		originalRadius = body->getRadius();
		collisionCircle = body->getRadius()*2;
	}
}

void Player::setSpeed(GLfloat speed) {
	this->speed = speed;
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}
void Player::drawGun()
{
	glBindTexture (GL_TEXTURE_2D, pistol.getMeshTex());
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT);

	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );


	glTranslated(gunPosition.X, gunPosition.Y, gunPosition.Z);
	glScaled(scalePistol,scalePistol,scalePistol);


	pistol.draw();


}



void Player::walk(int dir,GLfloat dTime, bool collision) {
	GLfloat angle = (getBody()->getAngle()-90)*PI/180;
	getBody()->setY( getBody()->getY() + dTime* speed * dir * sin(angle) );
	getBody()->setX(getBody()->getX() + dTime*speed * dir * cos(angle));




}

GLfloat Player::getAngleGun() const {
	return angleGun;
}

void Player::setAngleGun(int x, int y) {
	GLfloat dist, tethaX;
	GLfloat xBody = getBody()->getX(), yBody = getBody()->getY(), angle = getBody()->getAngle()*PI/180, radius =  getBody()->getRadius() ;
	GLfloat baseGunX = cos(angle) * radius*1.5 + xBody; //X coordinate of the gun's base
	GLfloat baseGunY = sin(angle) * radius*1.5 + yBody;// Y coordinate of the gun's base

	dist = sqrt(pow(baseGunX - x, 2) + pow(baseGunY - y, 2));
	tethaX = -asin((x - baseGunX)/dist);


	if(-tethaX <= PI/4 && -tethaX >= -PI/4 )
		this->angleGun = tethaX*180/PI;
	else
	{
		if(-tethaX <= PI/4)
			this->angleGun = 45;

		if(-tethaX >= -PI/4)
			this->angleGun = -45;

	}

}

void Player::rotate(int dir, GLfloat dTime) {
	getBody()->setAngle(getBody()->getAngle() + speed * dir * dTime);

	if(getBody()->getAngle() >= 360)
		getBody()->setAngle(getBody()->getAngle() - 360);

	if(getBody()->getAngle() <= -360)
		getBody()->setAngle(getBody()->getAngle() + 360);

}



Vertec* Player::shoot() {

	Vertec *shot = new Vertec();
	Vertec bulletGlobalPosition;

	bulletGlobalPosition = scale(bulletPosition,scalePistol,scalePistol,scalePistol);
	bulletGlobalPosition = translate(bulletGlobalPosition,gunPosition.X,gunPosition.Y, gunPosition.Z);
	bulletGlobalPosition = rotate_YZ(bulletGlobalPosition, getAngleArmX());
	bulletGlobalPosition = rotate_XY(bulletGlobalPosition, getAngleArmZ());
	bulletGlobalPosition = translate(bulletGlobalPosition, upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
	bulletGlobalPosition = scale(bulletGlobalPosition, getHeight(),getHeight(),getHeight());
	bulletGlobalPosition = rotate_XY(bulletGlobalPosition, getBody()->getAngle());
	bulletGlobalPosition = translate(bulletGlobalPosition, getBody()->getX(),getBody()->getY(),getBody()->getZ());

	Vertec bulletGlobalDirection;
	bulletGlobalDirection = scale(bulletDirection,scalePistol,scalePistol,scalePistol);
	bulletGlobalDirection = translate(bulletGlobalDirection,gunPosition.X,gunPosition.Y, gunPosition.Z);
	bulletGlobalDirection = rotate_YZ(bulletGlobalDirection, getAngleArmX());
	bulletGlobalDirection = rotate_XY(bulletGlobalDirection, getAngleArmZ());
	bulletGlobalDirection = translate(bulletGlobalDirection, upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
	bulletGlobalDirection = scale(bulletGlobalDirection, getHeight(),getHeight(),getHeight());
	bulletGlobalDirection = rotate_XY(bulletGlobalDirection, getBody()->getAngle());
	bulletGlobalDirection = translate(bulletGlobalDirection, getBody()->getX(),getBody()->getY(),getBody()->getZ());




	shot->X = bulletGlobalPosition.X;
	shot->Y = bulletGlobalPosition.Y;
	shot->Z = bulletGlobalPosition.Z;

	shot->dX = bulletGlobalDirection.X - bulletGlobalPosition.X;
	shot->dY = bulletGlobalDirection.Y - bulletGlobalPosition.Y;
	shot->dZ = bulletGlobalDirection.Z - bulletGlobalPosition.Z;



	return shot;


}



GLfloat Player::getOriginalRadius() const {
	return originalRadius;
}

GLfloat Player::getCollisionCircle() const {
	return collisionCircle;
}

void Player::setCollisionCircle(GLfloat collisionCircle) {
	this->collisionCircle = collisionCircle;
}

void Player::setOriginalRadius(GLfloat originalRadius) {
	this->originalRadius = originalRadius;
}


bool Player::isJumping() const {
	return jumping;
}

void Player::setJumping(bool jumping) {
	this->jumping = jumping;
}

bool Player::isOverObstacle() const {
	return overObstacle;
}

void Player::setOverObstacle(bool overObstacle) {
	this->overObstacle = overObstacle;
}

bool Player::checkCollision() {
	GLfloat distCenters;


	distCenters = sqrt(pow(biggerCircle->getX() - getBody()->getX(),2) + pow(biggerCircle->getY() -getBody()->getY(),2));
	if(distCenters > biggerCircle->getRadius() - getCollisionCircle())
		return true;


	distCenters = sqrt(pow(centerCircle->getX() - getBody()->getX(),2) + pow(centerCircle->getY() - getBody()->getY(),2));
	if(distCenters < centerCircle->getRadius() + getCollisionCircle())
			return true;

	for(auto& ene: enemies)
	{
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

			if( isJumping() && (currentTime - jumpedTime)/1000.0 > (obstacleHeight/100)
							&& (currentTime - jumpedTime)/1000.0 < 2 - (obstacleHeight/100) )
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
			return true;

	}

	return false;

}

bool Player::isJumpedOverObstacle() const {
	return jumpedOverObstacle;
}

void Player::setJumpedOverObstacle(bool jumpedOverObstacle) {
	this->jumpedOverObstacle = jumpedOverObstacle;
}

void Player::setGunAngle(GLfloat angle) {
	this->angleGun = angle;
}


void Player::jump() {


	GLfloat dTime = (currentTime - jumpedTime)/1000.0;
	if(dTime<= 1.0)
	{
		if(isJumpedOverObstacle())
			getBody()->setZ( getBody()->getOriginalZ() + obstacleHeight + dTime * 100);
		else
			getBody()->setZ( getBody()->getOriginalZ() + dTime * 100);
	}
	else
	{
		if(overObstacle)
		{
			if(getBody()->getZ()<=obstacleHeight + getBody()->getOriginalZ() )
			{
				getBody()->setZ(obstacleHeight + getBody()->getOriginalZ());
			}
			else
			{
				if(isJumpedOverObstacle())
					getBody()->setZ( getBody()->getOriginalZ() + obstacleHeight+  (2-dTime) * 100);
				else
					getBody()->setZ( getBody()->getOriginalZ() +  (2-dTime) * 100);
			}

		}
		else
		{
			if(isJumpedOverObstacle())
				getBody()->setZ( getBody()->getOriginalZ() + obstacleHeight +  (2-dTime) * 100);
			else
				getBody()->setZ( getBody()->getOriginalZ() +  (2-dTime) * 100);
		}

	}
}

void Player::Jumping() {
	GLfloat dTimeJump =  (currentTime - jumpedTime)/1000.0;

	if(dTimeJump<= 2 && isJumping())
	{
		jump();


	}
	else
	{
		setJumping( false);
		setJumpedOverObstacle(false);
		if(isOverObstacle())
		{
			getBody()->setZ(obstacleHeight + getBody()->getOriginalZ());


		}
		else
		{
			if(getBody()->getZ()> getBody()->getOriginalZ())
			{
				getBody()->setZ( getBody()->getZ() - dTimeJump * obstacleHeight/40 );
			}
			else
				getBody()->setZ( getBody()->getOriginalZ() );
		}


	}
}

time_t Player::getJumpedTime() const {
	return jumpedTime;
}

void Player::setJumpedTime(time_t jumpedTime) {
	this->jumpedTime = jumpedTime;
}

GLfloat Player::getHeight() const {
	return height;
}

void Player::setHeight(GLfloat height) {
	this->height = height;
}

GLfloat Player::getAngleLegs() const {
	return angleLegs;
}

void Player::setAngleLegs(GLfloat angleLegs) {
	this->angleLegs = angleLegs;
}


GLfloat Player::getAngleArmX() const {
	return angleArmX;
}

void Player::setAngleArmX(GLfloat angleArmX) {
	this->angleArmX += angleArmX;

	if(this->angleArmX >= 45)
	{
		this->angleArmX = 45;
		return;
	}
	if(this->angleArmX <= -45)
	{
		this->angleArmX = -45;
		return;
	}
}

GLfloat Player::getAngleArmZ() const {
	return angleArmZ;
}

void Player::setAngleArmZ(GLfloat angleArmZ) {
	this->angleArmZ -= angleArmZ;

	if(this->angleArmZ >= 45)
	{
		this->angleArmZ = 45;
		return;
	}
	if(this->angleArmZ <= -45)
	{
		this->angleArmZ = -45;
		return;
	}
}

int Player::getIndexLeg() const {
	return indexLeg;
}

void Player::setIndexLeg(int indexLeg) {
	this->indexLeg = indexLeg;
}


