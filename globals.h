/*
 * globals.h
 *
 *  Created on: 21 de out de 2017
 *      Author: rafael
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include "headers.h"
#include "structs.h"


#define PI acos(-1.0)

extern int keyFlags[];

extern WindowSettings settings;
extern Player *player;
extern Circle *biggerCircle, *centerCircle;

extern time_t currentTime, lastIdleTime;

extern std::set<Circle*> obstacles;
extern set<Enemy*> enemies;
extern set<Vertec*> shots, enemiesShots;


extern GLfloat obstacleHeight, speedShotEnem;

extern int defEnemies, numberEnemies, lastX, lastY, lastButton, lastXPassive, lastYPassive, lightMode;


extern bool endGame, win,buttonDown, lightOn, spotLightOn, textureOn;

/* Object Scales */
extern GLfloat scalePistol;

/* New Variables For Final Assignment */

extern int toggleCam;
extern GLfloat longitudeCam3;
extern GLfloat latitudeCam3;

extern GLfloat fpsTime, frames, fps;

extern GLuint textureArenaWall, textureCenterArena, textureGround, textureSky, textureObstacles,
			  texturePlayer;

extern GLfloat timeStopedPlayer;

extern Vertec cameraPosition;

extern Mesh bodyPlayer, arm, rightLegBl, leftLegBl, *legs, pistol, head,  eyes, navy, sumka, rightHand, leftHand;

extern string *textMode;
extern GLfloat textTime;

extern Vertec upperBody_Arm,
		eyePlayer,
		cameraAboveGun,
		normalCameraAboveGun,
		directionCameraAboveGun,
		bulletPosition,
		bulletDirection,
		spotLightPosition,
		spotLightDirection,
		cameraEyes,
		cameraEyesDirection,
		cameraEyesUp,
		gunPosition;





#endif /* GLOBALS_H_ */
