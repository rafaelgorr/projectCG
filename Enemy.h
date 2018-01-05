/*
 * Enemy.h
 *
 *  Created on: 14 de nov de 2017
 *      Author: rafael
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Player.h"


class Enemy : public Player{
	GLfloat freqShot;
	time_t lastTimeShot, lasTimeWalk, lastTimeRotate, walkBackEffect;
	int factor;
public:
	Enemy(GLfloat bS, GLfloat speed) ;
	virtual ~Enemy();
	time_t getLasTimeWalk() const;
	void setLasTimeWalk(time_t lasTimeWalk);
	time_t getLastTimeShot() const;
	void setLastTimeShot(time_t lastTimeShot);
	GLfloat getFreqShot() const;
	void setFreqShot(GLfloat freqShot);
	time_t getLastTimeRotate() const;
	void setLastTimeRotate(time_t lastTimeRotate);
	int getFactor() const;
	void setFactor(int factor);
	time_t getWalkBackEffect() const;
	void setWalkBackEffect(time_t walkBackEffect);

	bool checkCollision();

};

#endif /* ENEMY_H_ */
