#include "globals.h"

int keyFlags[256];

WindowSettings settings;

Circle *biggerCircle,  *centerCircle;

time_t currentTime, lastIdleTime;

Player *player;
set<Circle*> obstacles;
set<Vertec*> shots, enemiesShots;
set<Enemy*> enemies;

GLfloat obstacleHeight, speedShotEnem;
int defEnemies = 0, numberEnemies, lastX, lastY, lastButton, lastXPassive = 0, lastYPassive = 0,
		lightMode = 1; // Light at center of arena is mode 1
					  // Light above player is mode 2;

bool endGame = false, win = true ,buttonDown = false,
		lightOn = true, spotLightOn = false, textureOn = true; // Light, spotlight and texture controls


/* New Variables For Final Assignment */

/* 1 = First Person (Default) / 2 = Third Person */
int toggleCam = 1;
GLfloat longitudeCam3 = 0;
GLfloat latitudeCam3 = 0;

GLfloat fpsTime = 0.0, frames = 0.0, fps;

GLfloat scalePistol = 0.25;

GLuint textureArenaWall, textureCenterArena, textureGround, textureSky, textureObstacles,
		texturePlayer;

GLfloat timeStopedPlayer = 0.0;

Mesh bodyPlayer, arm, rightLegBl, leftLegBl,  *legs, pistol, head, eyes, navy, sumka, rightHand, leftHand;

Vertec cameraPosition;

string *textMode = new string("");
GLfloat textTime = INFINITY;

Vertec upperBody_Arm(-0.23522,-0.0361,1.30206),
		eyePlayer(0.03691,-0.17534,1.75693),

		cameraAboveGun(0.00555,-0.44572,0.57378),
		directionCameraAboveGun(0.00555,-0.49572,0.57377),
		normalCameraAboveGun(0.00555,-0.44572,0.61378),


		bulletPosition(0,-1.00187,0.38553),
		bulletDirection(0,-1.05187,0.38553),

		spotLightPosition(0,-1.00187,0.27553),
		spotLightDirection(0,-1.05187,0.27553),

		cameraEyes(0.03691,-0.23534,1.73693),
		cameraEyesDirection(0.03691,-0.24534,1.73193),
		cameraEyesUp(0.03691,-0.23534,1.74693),

		gunPosition(0.01453,-0.38814,-0.00968);







