#include "functions.h"
#include "globals.h"
#include "Image.h"



/*
********************
***** INIT & DISPLAY FUNC
********************
*/

void init (void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable( GL_TEXTURE_2D );


	glEnable(GL_LIGHTING);
	glShadeModel (GL_SMOOTH);

	glDepthFunc(GL_LEQUAL);

	glEnable(GL_LIGHT0);



 	glLoadIdentity ();




 	textureCenterArena = LoadTextureRAW("BMP-Files/largewood.bmp");
 	textureGround = LoadTextureRAW("BMP-Files/floor.bmp");
 	textureArenaWall = LoadTextureRAW("BMP-Files/arena.bmp");
 	textureSky = LoadTextureRAW("BMP-Files/sky.bmp");
 	textureObstacles = LoadTextureRAW("BMP-Files/rock.bmp");

 	loadOBJ();




}
void			loadOBJ					()
{

	legs = (Mesh*) calloc(80,sizeof(Mesh));
	legs[0].loadMesh("OBJ/Soldier/New Leg/leg_000001.obj");
	legs[1].loadMesh("OBJ/Soldier/New Leg/leg_000002.obj");
	legs[2].loadMesh("OBJ/Soldier/New Leg/leg_000003.obj");
	legs[3].loadMesh("OBJ/Soldier/New Leg/leg_000004.obj");
	legs[4].loadMesh("OBJ/Soldier/New Leg/leg_000005.obj");
	legs[5].loadMesh("OBJ/Soldier/New Leg/leg_000006.obj");
	legs[6].loadMesh("OBJ/Soldier/New Leg/leg_000007.obj");
	legs[7].loadMesh("OBJ/Soldier/New Leg/leg_000008.obj");
	legs[8].loadMesh("OBJ/Soldier/New Leg/leg_000009.obj");
	legs[9].loadMesh("OBJ/Soldier/New Leg/leg_000010.obj");
	legs[10].loadMesh("OBJ/Soldier/New Leg/leg_000011.obj");
	legs[11].loadMesh("OBJ/Soldier/New Leg/leg_000012.obj");
	legs[12].loadMesh("OBJ/Soldier/New Leg/leg_000013.obj");
	legs[13].loadMesh("OBJ/Soldier/New Leg/leg_000014.obj");
	legs[14].loadMesh("OBJ/Soldier/New Leg/leg_000015.obj");
	legs[15].loadMesh("OBJ/Soldier/New Leg/leg_000016.obj");
	legs[16].loadMesh("OBJ/Soldier/New Leg/leg_000017.obj");
	legs[17].loadMesh("OBJ/Soldier/New Leg/leg_000018.obj");
	legs[18].loadMesh("OBJ/Soldier/New Leg/leg_000019.obj");
	legs[19].loadMesh("OBJ/Soldier/New Leg/leg_000020.obj");
	legs[20].loadMesh("OBJ/Soldier/New Leg/leg_000021.obj");
	legs[21].loadMesh("OBJ/Soldier/New Leg/leg_000022.obj");
	legs[22].loadMesh("OBJ/Soldier/New Leg/leg_000023.obj");
	legs[23].loadMesh("OBJ/Soldier/New Leg/leg_000024.obj");
	legs[24].loadMesh("OBJ/Soldier/New Leg/leg_000025.obj");
	legs[25].loadMesh("OBJ/Soldier/New Leg/leg_000026.obj");
	legs[26].loadMesh("OBJ/Soldier/New Leg/leg_000027.obj");
	legs[27].loadMesh("OBJ/Soldier/New Leg/leg_000028.obj");
	legs[28].loadMesh("OBJ/Soldier/New Leg/leg_000029.obj");
	legs[29].loadMesh("OBJ/Soldier/New Leg/leg_000030.obj");
	legs[30].loadMesh("OBJ/Soldier/New Leg/leg_000031.obj");
	legs[31].loadMesh("OBJ/Soldier/New Leg/leg_000032.obj");
	legs[32].loadMesh("OBJ/Soldier/New Leg/leg_000033.obj");
	legs[33].loadMesh("OBJ/Soldier/New Leg/leg_000034.obj");
	legs[34].loadMesh("OBJ/Soldier/New Leg/leg_000035.obj");
	legs[35].loadMesh("OBJ/Soldier/New Leg/leg_000036.obj");
	legs[36].loadMesh("OBJ/Soldier/New Leg/leg_000037.obj");
	legs[37].loadMesh("OBJ/Soldier/New Leg/leg_000038.obj");
	legs[38].loadMesh("OBJ/Soldier/New Leg/leg_000039.obj");
	legs[39].loadMesh("OBJ/Soldier/New Leg/leg_000040.obj");
	legs[40].loadMesh("OBJ/Soldier/New Leg/leg_000041.obj");
	legs[41].loadMesh("OBJ/Soldier/New Leg/leg_000042.obj");
	legs[42].loadMesh("OBJ/Soldier/New Leg/leg_000043.obj");
	legs[43].loadMesh("OBJ/Soldier/New Leg/leg_000044.obj");
	legs[44].loadMesh("OBJ/Soldier/New Leg/leg_000045.obj");
	legs[45].loadMesh("OBJ/Soldier/New Leg/leg_000046.obj");
	legs[46].loadMesh("OBJ/Soldier/New Leg/leg_000047.obj");
	legs[47].loadMesh("OBJ/Soldier/New Leg/leg_000048.obj");
	legs[48].loadMesh("OBJ/Soldier/New Leg/leg_000049.obj");
	legs[49].loadMesh("OBJ/Soldier/New Leg/leg_000050.obj");
	legs[50].loadMesh("OBJ/Soldier/New Leg/leg_000051.obj");
	legs[51].loadMesh("OBJ/Soldier/New Leg/leg_000052.obj");
	legs[52].loadMesh("OBJ/Soldier/New Leg/leg_000053.obj");
	legs[53].loadMesh("OBJ/Soldier/New Leg/leg_000054.obj");
	legs[54].loadMesh("OBJ/Soldier/New Leg/leg_000055.obj");
	legs[55].loadMesh("OBJ/Soldier/New Leg/leg_000056.obj");
	legs[56].loadMesh("OBJ/Soldier/New Leg/leg_000057.obj");
	legs[57].loadMesh("OBJ/Soldier/New Leg/leg_000058.obj");
	legs[58].loadMesh("OBJ/Soldier/New Leg/leg_000059.obj");
	legs[59].loadMesh("OBJ/Soldier/New Leg/leg_000060.obj");
	legs[60].loadMesh("OBJ/Soldier/New Leg/leg_000061.obj");
	legs[61].loadMesh("OBJ/Soldier/New Leg/leg_000062.obj");
	legs[62].loadMesh("OBJ/Soldier/New Leg/leg_000063.obj");
	legs[63].loadMesh("OBJ/Soldier/New Leg/leg_000064.obj");
	legs[64].loadMesh("OBJ/Soldier/New Leg/leg_000065.obj");
	legs[65].loadMesh("OBJ/Soldier/New Leg/leg_000066.obj");
	legs[66].loadMesh("OBJ/Soldier/New Leg/leg_000067.obj");
	legs[67].loadMesh("OBJ/Soldier/New Leg/leg_000068.obj");
	legs[68].loadMesh("OBJ/Soldier/New Leg/leg_000069.obj");
	legs[69].loadMesh("OBJ/Soldier/New Leg/leg_000070.obj");



	bodyPlayer.loadMesh("OBJ/Soldier/uBody.obj");
	bodyPlayer.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/body.bmp"));


	arm.loadMesh("OBJ/Soldier/arm.obj");
	arm.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/body.bmp"));

	pistol.loadMesh("OBJ/Pistol/m19.obj");
	pistol.loadMeshTex(LoadTextureRAW("OBJ/Pistol/m19.bmp"));

	head.loadMesh("OBJ/Soldier/head.obj");
	head.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/head.bmp"));

	eyes.loadMesh("OBJ/Soldier/eyes.obj");
	eyes.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/eyes.bmp"));

	navy.loadMesh("OBJ/Soldier/navy.obj");
	navy.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/navy.bmp"));


	sumka.loadMesh("OBJ/Soldier/sumka.obj");
	sumka.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/sumka.bmp"));


	leftHand.loadMesh("OBJ/Soldier/leftHand.obj");
	leftHand.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/hand.bmp"));


	rightHand.loadMesh("OBJ/Soldier/rightHand.obj");
	rightHand.loadMeshTex(LoadTextureRAW("OBJ/Soldier/Textures/hand.bmp"));





}
void lightSettings ()
{



	GLfloat ambient[] = {1, 1, 1, 1.0 };
	GLfloat diffuse[] = {1.0 ,1.0 ,1.0 ,1.0};
	GLfloat specular[] = {1.0 ,1.0 ,1.0 ,1.0};

	/* MAIN LIGHT */
	glLightfv(GL_LIGHT0, GL_AMBIENT,ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	GLfloat lightCenter[] = {biggerCircle->getX() ,biggerCircle->getY()  , player->getHeight()*7, 1.0 };// Light at center of arena
	GLfloat lightAbovePlayer[] = {player->getBody()->getX(),player->getBody()->getY() , player->getHeight()*2, 1.0 }; // Light above player
	switch(lightMode)
	{
		case 1:
			glLightfv(GL_LIGHT0, GL_POSITION, lightCenter);
			break;
		case 2:
			glLightfv(GL_LIGHT0, GL_POSITION, lightAbovePlayer);
			break;

	}



	glLightfv(GL_LIGHT0, GL_AMBIENT,ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);



	/* SPOT LIGHT */

	Vertec *spotLight = getSpotPosition();
	GLfloat spotPos[] = {spotLight->X, spotLight->Y, spotLight->Z,1};
	GLfloat spotLightDir[] = {spotLight->dX,spotLight->dY,spotLight->dZ,0.0};

	GLfloat ambientSpot[] = {1, 1, 1, 1.0 };
	GLfloat diffuseSpot[] = {1.0 ,1.0 ,1.0 ,1.0};
	GLfloat specularSpot[] = {1.0 ,1.0 ,1.0 ,1.0};



	glLightfv(GL_LIGHT1, GL_POSITION,spotPos);



	glLightfv(GL_LIGHT1, GL_AMBIENT,ambientSpot);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseSpot);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularSpot);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spotLightDir);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT,25 );



	/* MATERIALS */
	GLfloat materialEmission[] = {0, 0, 0 , 1};
	GLfloat materialColorAmb[] = { 0.5, 0.5, 0.5, 1};
	GLfloat materialColorDiff[] = { 600, 600, 600, 1};
	GLfloat mat_specular[] = { 1, 1, 1, 1};
	GLfloat mat_shininess[] = { 100.0 };



	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, materialEmission);

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, materialColorAmb);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialColorDiff);

	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);




}

Vertec* getSpotPosition ()
{
	Vertec *spotLight = new Vertec();
	Vertec spotGlobalPosition;

	spotGlobalPosition = scale(bulletPosition,scalePistol,scalePistol,scalePistol);
	spotGlobalPosition = translate(spotGlobalPosition,gunPosition.X,gunPosition.Y, gunPosition.Z);
	spotGlobalPosition = rotate_YZ(spotGlobalPosition, player->getAngleArmX());
	spotGlobalPosition = rotate_XY(spotGlobalPosition, player->getAngleArmZ());
	spotGlobalPosition = translate(spotGlobalPosition, upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
	spotGlobalPosition = scale(spotGlobalPosition, player->getHeight(),player->getHeight(),player->getHeight());
	spotGlobalPosition = rotate_XY(spotGlobalPosition, player->getBody()->getAngle());
	spotGlobalPosition = translate(spotGlobalPosition, player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());

	Vertec spotGlobalDirection;
	spotGlobalDirection = scale(bulletDirection,scalePistol,scalePistol,scalePistol);
	spotGlobalDirection = translate(spotGlobalDirection,gunPosition.X,gunPosition.Y, gunPosition.Z);
	spotGlobalDirection = rotate_YZ(spotGlobalDirection, player->getAngleArmX());
	spotGlobalDirection = rotate_XY(spotGlobalDirection, player->getAngleArmZ());
	spotGlobalDirection = translate(spotGlobalDirection, upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
	spotGlobalDirection = scale(spotGlobalDirection, player->getHeight(),player->getHeight(),player->getHeight());
	spotGlobalDirection = rotate_XY(spotGlobalDirection, player->getBody()->getAngle());
	spotGlobalDirection = translate(spotGlobalDirection, player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());




	spotLight->X = spotGlobalPosition.X;
	spotLight->Y = spotGlobalPosition.Y;
	spotLight->Z = spotGlobalPosition.Z;

	spotLight->dX = spotGlobalDirection.X - spotGlobalPosition.X;
	spotLight->dY = spotGlobalDirection.Y - spotGlobalPosition.Y;
	spotLight->dZ = spotGlobalDirection.Z - spotGlobalPosition.Z;

	GLfloat module = sqrt(pow(spotLight->dX,2) + pow(spotLight->dY,2) + pow(spotLight->dZ,2));

	spotLight->dX /= module;
	spotLight->dY /= module;
	spotLight->dZ /= module;




	return spotLight;
}

void display (void)
{

	glEnable(GL_SCISSOR_TEST);

	/* Main Camera */
	glScissor(0, 0, 500, 500);
	glViewport (0, 0, 500, 500);
	glClear(GL_COLOR_BUFFER_BIT |
			  GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glClearColor (0 , 0 , 0 , 0);


	changeCameras (); /* First and Third Person Camera */
	lightSettings();
	drawAll(1);


	/* Eye Camera */
	glScissor(0, 500, 500, 200);
	glViewport (0, 500, 500, 200);

	glClear(GL_COLOR_BUFFER_BIT |
			  GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glClearColor (0 , 0 , 0 , 0);

	cameraEye(); // Eye Camera
	lightSettings();
	drawAll(2);

	glFlush();
    glutSwapBuffers();
}

/*
********************
***** IDLE FUNC
********************
*/

void glutIdle(void)
{
	currentTime = glutGet(GLUT_ELAPSED_TIME);
	GLfloat dTimeIdle = (currentTime - lastIdleTime);

	if (keyFlags['p'] && !player->isJumping())
	{
		player->setJumpedTime( glutGet(GLUT_ELAPSED_TIME)); // Get Jump Time
		player->setJumping(true);

		if(player->isOverObstacle())
			player->setJumpedOverObstacle(true);

		glutPostRedisplay();
	}

	if (keyFlags['w'])
	{
		player->walk(1, dTimeIdle,false);

		if(player->checkCollision())
			player->walk(-1 ,dTimeIdle,true);


		if(player->getIndexLeg() == 69)
			player->setIndexLeg(9);
		else
			player->setIndexLeg( player->getIndexLeg() + 1);

		timeStopedPlayer = currentTime;

	}

	if (keyFlags['s'])
	{
		player->walk(-1,dTimeIdle,false);
		if(player->checkCollision())
			player->walk(1,dTimeIdle,true);

		if(player->getIndexLeg() == 9 || player->getIndexLeg() ==0)
			player->setIndexLeg(69);
		else
			player->setIndexLeg(player->getIndexLeg() -1 );

		timeStopedPlayer = currentTime;
	}

	if (keyFlags['d'])
	{
		player->rotate(-1, dTimeIdle);
	}

	if (keyFlags['a'])
	{
		player->rotate(1, dTimeIdle);
	}


	if((currentTime - timeStopedPlayer)/1000.0 >= 1.0 )
		player->setIndexLeg(0);


	player->Jumping();

	for (auto& enem: enemies)
		enem->Jumping();

	bots (dTimeIdle);
	bulletsMoviment(dTimeIdle);
	collisionShotEnemies (dTimeIdle);

	lastIdleTime = currentTime;

	frames++;

	glutPostRedisplay();
}
void bulletsMoviment (GLfloat dTimeIdle)
{
	bool freed;
	for(auto& shts : shots)
	{
		freed = false;
		shts->X = shts->X + player->getBulletSpeed() * dTimeIdle * shts->dX;
		shts->Y = shts->Y + player->getBulletSpeed() * dTimeIdle * shts->dY;
		shts->Z = shts->Z + player->getBulletSpeed() * dTimeIdle * shts->dZ;

		GLfloat dist;
		for(auto& obs: obstacles)  // Check if a player's shot hits an obstacle
		{
			dist = euclidianDistance(obs->getX(), obs->getY(), shts->X,shts->Y );

			if(dist < obs->getRadius() && shts->Z <= obstacleHeight)
			{
				shots.erase(shts);
				free(shts);
				freed = true;
				break;
			}
		}
		if(freed)
			continue;


		//Checks if a shot left the arena
		if( biggerCircle->getX() - biggerCircle->getRadius() > shts->X  ||
			biggerCircle->getX() + biggerCircle->getRadius() < shts->X  ||
			biggerCircle->getY() - biggerCircle->getRadius() > shts->Y  ||
			biggerCircle->getY() + biggerCircle->getRadius() < shts->Y    )
		{
			shots.erase(shts);
			free(shts);
			freed = true;
			break;
		}
		if(freed)
			continue;

		dist = euclidianDistance(shts->X,shts->Y,centerCircle->getX(), centerCircle->getY());

		if(dist < centerCircle->getRadius())
		{
			shots.erase(shts);
			free(shts);
			freed = true;
			break;
		}
		if(freed)
			continue;

		for(auto& ene: enemies) // Check if a player's shot hits some enemy
		{
			if( euclidianDistance( shts->X,shts->Y,
								   ene->getBody()->getX(), ene->getBody()->getY()) <=  ene->getCollisionCircle() )
			{
				if( ene->getBody()->getZ() <= shts->Z  && shts->Z <= ene->getBody()->getZ() + ene->getHeight()*1.7 )
				{
					defEnemies++;
					enemies.erase(ene);
					free(ene);
					shots.erase(shts);
					free(shts);

					if(defEnemies == numberEnemies)
						endGame = true;
					break;
				}
			}
		}


	}
}

/*
********************
***** CAMERA FUNC
********************
*/

void changeCameras () {


	if(toggleCam == 1) /* Camera Above Gun */
	{
		Vertec eye ;
		eye = scale(cameraAboveGun,scalePistol,scalePistol,scalePistol);
		eye = translate(eye,gunPosition.X,gunPosition.Y, gunPosition.Z);
		eye = rotate_YZ(eye, player->getAngleArmX());
		eye = rotate_XY(eye, player->getAngleArmZ());
		eye = translate(eye, upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
		eye = scale(eye, player->getHeight(),player->getHeight(),player->getHeight());
		eye = rotate_XY(eye, player->getBody()->getAngle());
		eye = translate(eye, player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());

		Vertec center ;
		center = scale(directionCameraAboveGun,scalePistol,scalePistol,scalePistol);
		center = translate(center,gunPosition.X,gunPosition.Y, gunPosition.Z);
		center = rotate_YZ(center, player->getAngleArmX());
		center = rotate_XY(center, player->getAngleArmZ());
		center = translate(center, upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
		center = scale(center, player->getHeight(),player->getHeight(),player->getHeight());
		center = rotate_XY(center, player->getBody()->getAngle());
		center = translate(center, player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());

		Vertec normal ;
		normal = scale(normalCameraAboveGun,scalePistol,scalePistol,scalePistol);
		normal = translate(normal,gunPosition.X,gunPosition.Y, gunPosition.Z);
		normal = rotate_YZ(normal, player->getAngleArmX());
		normal = rotate_YZ(normalCameraAboveGun, player->getAngleArmX());
		normal = rotate_XY(normal, player->getAngleArmZ());
		normal = translate(normal, upperBody_Arm.X, upperBody_Arm.Y,upperBody_Arm.Z);
		normal = scale(normal, player->getHeight(),player->getHeight(),player->getHeight());
		normal = rotate_XY(normal, player->getBody()->getAngle());
		normal = translate(normal, player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());



		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		/* FOV , Aspect Ratio , Near , Far */
		gluPerspective(100, 1, 1, biggerCircle->getRadius()*2);
		glMatrixMode(GL_MODELVIEW);
		gluLookAt (
				eye.X ,
				eye.Y ,
				eye.Z,
			center.X,
			center.Y,
			center.Z,
			normal.X - eye.X,
			normal.Y - eye.Y,
			normal.Z - eye.Z
		);

		cameraPosition.X = eye.X;
		cameraPosition.Y = eye.Y;
		cameraPosition.Z = eye.Z;

		cameraPosition.dX = center.X;
		cameraPosition.dY = center.Y;
		cameraPosition.dZ = center.Z;




	}
	else
		if(toggleCam == 2) /* Third person camera */
		{
			/* Third Person Camera */
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			/* FOV , Aspect Ratio , Near , Far */
			gluPerspective(100, 1, 10, biggerCircle->getRadius()*2);
			glMatrixMode(GL_MODELVIEW);


			GLfloat dist = 100; // Distance between player's position and camera

			GLfloat lookAtX = player->getBody()->getX() + cos(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
			GLfloat lookAtY = player->getBody()->getY() + sin(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
			GLfloat lookAtZ = 80 + longitudeCam3 + player->getCollisionCircle()*0.4;

			GLfloat distArena = sqrt(pow(lookAtX - biggerCircle->getX(),2) + pow (lookAtY - biggerCircle->getY(),2));

			if(distArena >= biggerCircle->getRadius()) // Checks if camera leaves arena
			{
				dist = biggerCircle->getRadius() - euclidianDistance(player->getBody()->getX(), player->getBody()->getY(),
																	 biggerCircle->getX()     , biggerCircle->getY()) ;

				lookAtX = player->getBody()->getX() + cos(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
				lookAtY = player->getBody()->getY() + sin(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
			} else
			{
				GLfloat distCenter = sqrt(pow(lookAtX - centerCircle->getX(),2) + pow (lookAtY - centerCircle->getY(),2));
				if(distCenter < centerCircle->getRadius())
				{
					dist =  euclidianDistance(player->getBody()->getX(), player->getBody()->getY(),
											 centerCircle->getX()     , centerCircle->getY()) - centerCircle->getRadius() ;

					lookAtX = player->getBody()->getX() + cos(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
					lookAtY = player->getBody()->getY() + sin(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
				}
				else
				{
					for(auto& obs : obstacles)
					{
						distCenter = sqrt(pow(lookAtX - obs->getX(),2) + pow (lookAtY - obs->getY(),2));
						if(distCenter < obs->getRadius() && lookAtZ<= obstacleHeight)
						{
							dist =  euclidianDistance(player->getBody()->getX(), player->getBody()->getY(),
														obs->getX()     , obs->getY()) - obs->getRadius() ;

							lookAtX = player->getBody()->getX() + cos(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
							lookAtY = player->getBody()->getY() + sin(player->getBody()->getAngle()*PI/180 + PI/2 + latitudeCam3*PI/180)*dist;
						}
					}
				}
			}


			gluLookAt (
					lookAtX ,
					lookAtY ,
					lookAtZ,
				player->getBody()->getX(),
				player->getBody()->getY(),
				player->getBody()->getZ(),
				0, 0, 1
			);

			cameraPosition.X = lookAtX;
			cameraPosition.Y = lookAtY;
			cameraPosition.Z = lookAtZ;

			cameraPosition.dX = player->getBody()->getX() - lookAtX;
			cameraPosition.dY = player->getBody()->getY() - lookAtY;
			cameraPosition.dZ = player->getBody()->getZ() - lookAtZ;
	}
}
void cameraEye ()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* FOV , Aspect Ratio , Near , Far */
	gluPerspective(100, 500/200, 2, biggerCircle->getRadius()*2);
	glMatrixMode(GL_MODELVIEW);


	Vertec eye;
	eye = scale(cameraEyes, player->getHeight(),player->getHeight(),player->getHeight());
	eye = rotate_XY(eye, player->getBody()->getAngle());
	eye = translate(eye,player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());

	Vertec direction;
	direction = scale(cameraEyesDirection, player->getHeight(),player->getHeight(),player->getHeight());
	direction = rotate_XY(direction, player->getBody()->getAngle());
	direction = translate(direction,player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());


	Vertec up;
	up = scale(cameraEyesUp, player->getHeight(),player->getHeight(),player->getHeight());
	up = rotate_XY(up, player->getBody()->getAngle());
	up = translate(up,player->getBody()->getX(),player->getBody()->getY(),player->getBody()->getZ());



	gluLookAt (
			eye.X ,
			eye.Y ,
			eye.Z,
		direction.X,
		direction.Y,
		direction.Z,
		0,0,1
	);

}

void		fpsCount				(GLfloat time)
{

	if((time - fpsTime) > 1000.0)
	{
		fps = frames*1000.0/(time - fpsTime);
		fpsTime = time;
		frames = 0.0;
	}


	printText(5, settings.height - 30,
			new string("FPS: " + to_string(fps)),1,1,1 );




}

/*
********************
***** MOUSE FUNC
********************
*/

void mouseClick(int button, int state, int x, int y)
{
	lastButton = button;

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(win)
			shots.insert(player->shoot());
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		buttonDown = false;

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		lastX = x;
		lastY = y;
		buttonDown = true;

	}



}
void mouseMotion (int x, int y)
{
	if (!buttonDown)
		return;

	latitudeCam3 += x - lastX;
	longitudeCam3 += y - lastY;

	if(longitudeCam3 > 90)
		longitudeCam3 = 90;
	else
		if(longitudeCam3 < -90)
			longitudeCam3 = -90;

	if(latitudeCam3 > 180)
			latitudeCam3 = 180;
		else
			if(latitudeCam3 < -180)
				latitudeCam3 = -180;




	lastX = x;
	lastY = y;
}

void mousePassiveMotion (int x, int y)
{
//	player->setAngleGun(x +  biggerCircle->getX() - biggerCircle->getRadius(), y + biggerCircle->getY() - biggerCircle->getRadius());
	player->setAngleArmZ((x - lastXPassive)*0.4);
	player->setAngleArmX((y - lastYPassive)*0.4);

	lastXPassive = x;
	lastYPassive = y;
}



/*
********************
***** KEYBOARD FUNCdd
*/

void keyUp (unsigned char key, int x, int y )
{
	keyFlags[tolower(key)] = 0;
}


void keyPress (unsigned char key, int x, int y )
{
	keyFlags[tolower(key)] = 1;
	checkKeyPress();

}

void checkKeyPress ()
{
	if(keyFlags['l'])
	{
		if(lightOn)
		{
			glDisable(GL_LIGHT0);
			lightOn = false;

			textMode[0] = "LIGHT: OFF";
			textTime = currentTime;
		}
		else
		{
			glEnable(GL_LIGHT0);
			lightOn = true;

			textMode[0] = "LIGHT: ON";
			textTime = currentTime;
		}
	}

	if(keyFlags['n'])
	{
		if(spotLightOn)
		{
			glDisable(GL_LIGHT1);
			glEnable(GL_LIGHT0);
			spotLightOn = false;

			textMode[0] = "FLASHLIGHT: OFF";
			textTime = currentTime;
		}
		else
		{
			glEnable(GL_LIGHT1);
			glDisable(GL_LIGHT0);
			spotLightOn = true;

			textMode[0] = "FLASHLIGHT: ON";
			textTime = currentTime;
		}
	}
	if(keyFlags['t'])
	{
		if(textureOn)
		{
			glDisable(GL_TEXTURE_2D);
			textureOn = false;


			textMode[0] = "TEXTURE: OFF";
			textTime = currentTime;
		}
		else
		{
			glEnable(GL_TEXTURE_2D);
			textureOn = true;

			textMode[0] = "TEXTURE: ON";
			textTime = currentTime;
		}
	}

	if(keyFlags['c'])
	{
		if(lightMode == 1)
		{
			lightMode = 2;

			textMode[0] = "LIGHT MODE: 2";
			textTime = currentTime;
		}
		else
		{
			lightMode = 1;

			textMode[0] = "LIGHT MODE: 1";
			textTime = currentTime;
		}
	}

	if(keyFlags['1'])
	{
		toggleCam = 1;

		textMode[0] = "CAMERA MODE: FIRST PERSON";
		textTime = currentTime;
	}

	if(keyFlags['2'])
	{
		toggleCam = 2;

		textMode[0] = "CAMERA MODE: THIRD PERSON";
		textTime = currentTime;
	}
}

/*
********************
***** COLLISION & BOT FUNC
********************
*/




void collisionShotEnemies	(GLfloat dTimeIdle)
{
	bool freed = false;
	for (auto& shts: enemiesShots)
	{
		freed = false;
		shts->X = shts->X + speedShotEnem * dTimeIdle * shts->dX;
		shts->Y = shts->Y + speedShotEnem * dTimeIdle * shts->dY;
		shts->Z = shts->Z + speedShotEnem * dTimeIdle * shts->dZ;


		GLfloat dist = euclidianDistance (shts->X, shts->Y, player->getBody()->getX(), player->getBody()->getY());

		if (	dist <= player->getCollisionCircle()) // Checks If An Enemy Shot Hits The Player
		{
			endGame = true;
			win = false;
		}

		for (auto& obs: obstacles) // Checks If An Enemy Shot Hit An Obstacle
		{

			GLfloat dist = euclidianDistance (shts->X, shts->Y, obs->getX(), obs->getY());

			if (dist <= obs->getRadius() )
			{
				enemiesShots.erase(shts);
				free(shts);
				freed = true;
				break;
			}
		}
		if(freed)
			continue;

		dist = euclidianDistance(shts->X,shts->Y,centerCircle->getX(), centerCircle->getY());

		if(dist < centerCircle->getRadius())
		{
			enemiesShots.erase(shts);
			free(shts);
			freed = true;
			break;
		}
		if(freed)
			continue;

		for (auto& enem: enemies)
		{

			GLfloat dist = euclidianDistance (shts->X, shts->Y, enem->getBody()->getX(), enem->getBody()->getY());

			if (dist <= enem->getCollisionCircle() )
			{
				enemiesShots.erase(shts);
				free(shts);
				freed = true;
				break;
			}
		}
		if(freed)
			continue;

		// Checks If An Enemy Shot Left The Arena
		if (	biggerCircle->getX() - biggerCircle->getRadius() > shts->X ||
					biggerCircle->getX() + biggerCircle->getRadius() < shts->X ||
					biggerCircle->getY() - biggerCircle->getRadius() > shts->Y ||
					biggerCircle->getY() + biggerCircle->getRadius() < shts->Y	)
		{
			enemiesShots.erase(shts);
			free(shts);

		}
	}
}

void bots(GLfloat dTimeIdle)
{
	srand (time(NULL));

	for(auto& enem: enemies)
	{
		if((currentTime - enem->getLastTimeShot())/1000.0 >= 1/enem->getFreqShot())
		{
			enemiesShots.insert(enem->shoot());//Enemies shooting
			enem->setLastTimeShot(glutGet(GLUT_ELAPSED_TIME));
		}


		if(enem->isOverObstacle())//Walk forward if it's over some obstacle
		{
			enem->walk(1, dTimeIdle ,false);
			if(enem->checkCollision())
				enem->walk(-1, dTimeIdle ,false);
			continue;
		}


		int randNumber = rand() % 20;

		if(randNumber < 10)
		{
			if(randNumber < 5)
				enem->rotate(1,dTimeIdle);
			else
				enem->rotate(-1,dTimeIdle);
		}


		if(enem->getFactor() == 1)
		{

			enem->walk(-1, dTimeIdle ,false);
			if(enem->checkCollision())
				enem->walk(1, dTimeIdle ,false);

			if(enem->getIndexLeg() == 9 || enem->getIndexLeg() == 0)
				enem->setIndexLeg(69);
			else
				enem->setIndexLeg(enem->getIndexLeg() -1 );

			enem->rotate(-1,dTimeIdle);


		}
		else
		{

			enem->walk(1, dTimeIdle ,false);
			if(enem->checkCollision())
				enem->walk(-1, dTimeIdle ,false);

			if(enem->getIndexLeg() == 69)
				enem->setIndexLeg(9);
			else
				enem->setIndexLeg( enem->getIndexLeg() + 1);




		}



	}

}



/*
********************
***** DRAW POLYGON FUNC
********************
*/

void drawAll (int cameraMode)
{
	/* DRAW FLOOR */
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, textureGround);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
		glTranslated(biggerCircle->getX(),biggerCircle->getY(),0);
		drawDisk(biggerCircle->getRadius(),false);
	glPopMatrix();

	/* DRAW ROOF */
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, textureSky);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
		glTranslated(biggerCircle->getX(),biggerCircle->getY(),player->getHeight()*8);
		drawDisk(biggerCircle->getRadius(),true);
	glPopMatrix();


	/*  DRAW OBSTACLES ROOF  */
	for (auto& obs : obstacles)
	{
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, textureObstacles);
			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
			glTranslated(obs->getX(),obs->getY(),obstacleHeight);
			drawDisk(obs->getRadius(),false);
		glPopMatrix();
	}
	/* DRAW OBSTACLES ROOF */
	for (auto& obs : obstacles) // Obstacles - Black Circle
	{
		glPushMatrix();
			glTranslatef(obs->getX(),obs->getY(),0);
			glScalef(obs->getRadius(), obs->getRadius(),obstacleHeight);
			drawObstacle(textureObstacles,1.0,1.0,1.0);
		glPopMatrix();


	}

	/* DRAW 3D ARENA */
	glPushMatrix();
		glTranslatef(biggerCircle->getX(),biggerCircle->getY(),0);
		glScalef(biggerCircle->getRadius(), biggerCircle->getRadius(),player->getHeight()*8);
		drawArena(textureArenaWall,1.0,1.0,1.0);
	glPopMatrix();

	/* DRAW 3D CENTER OF ARENA */
	glPushMatrix(); //3d Center of Arena
		glTranslatef(centerCircle->getX(), centerCircle->getY(), 0);
		glScalef(centerCircle->getRadius(), centerCircle->getRadius(),player->getHeight()*8);
		drawCenterArena(textureCenterArena,1.0, 1.0, 1.0);
	glPopMatrix();



	/* DRAW ENEMIES */
	for (auto& ene : enemies) // Enemies - Red Circle
		ene->drawPlayer();

	/* DRAW ENEMY SHOTS */
	for(auto& eShts : enemiesShots)
	{
		glPushMatrix();
			glTranslated(eShts->X,eShts->Y,eShts->Z);
			glScaled(0.75,0.75,0.75);
			glutSolidSphere(1,64,64);
		glPopMatrix();
	}




	/* DRAW PLAYER */
	if(win)
	{
		player->drawPlayer();

		/* DRAW PLAYER SHOTS */
		for(auto& shts : shots)
		{
			glPushMatrix();
				glTranslated(shts->X,shts->Y,shts->Z);
				glScaled(0.75,0.75,0.75);
				glutSolidSphere(1,64,64);
			glPopMatrix();
		}
	}

	if(cameraMode == 1) // If it's drawing in Main Camera then draw score, minimap and end game message
	{
		printText(settings.width - 200,settings.height - 30, //Score
				new string("Defeated Enemies: " +  to_string(defEnemies) + "/" + to_string(numberEnemies)),
				1,1,1);

		drawMiniMap(settings.width - biggerCircle->getRadius()*0.1857 ,biggerCircle->getRadius()*0.042); // Minimap
		fpsCount(currentTime); // FPS Counter

		if((currentTime - textTime)/1000.0 < 2.5) // Text of toggling some functionality, disappears after 2.5 s
		{
			printText(10,10,
						textMode,
						0,0,1);
		}



		if(endGame)
		{
			if(win)
				printEndMsg(settings.width/2 - 120,settings.height - 120,
							new string("You Win!!"),
							0,0,1);
			else
			{
				printEndMsg(settings.width/2 - 120,settings.height - 120,
							new string("You Lose..."),
							1,0,0);
			}


		}
	}


}

void drawCircle (Circle *circle, GLfloat radius, int mode)
{
    float  np = 500; //Number of points
	glColor3f(circle->getColorR(),circle->getColorG(),circle->getColorB());

    if(mode == 1)
    	glBegin(GL_POLYGON);
    else
    	glBegin(GL_POINTS);
    		glNormal3b(0,0,1);
			glVertex2f(circle->getX() , circle->getY()  );
			int i;

			for (i = 0; i <= np; i++)
			{
			  GLfloat angle = 2.0f * PI * float(i) / float(np);
			  glNormal3b(0,0,1);
			  glVertex2f (
					radius * cos(angle) + circle->getX(),
					radius * sin(angle) + circle->getY()
				);
			}
    glEnd();
}







GLuint LoadTextureRAW( const char * filename )
{
	GLuint texture;

	Image* image = loadBMP(filename);

	glGenTextures( 1, &texture );
	glBindTexture( GL_TEXTURE_2D, texture );
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );

	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
							 0,                            //0 for now
							 GL_RGB,                       //Format OpenGL uses for image
							 image->width, image->height,  //Width and height
							 0,                            //The border of the image
							 GL_RGB, //GL_RGB, because pixels are stored in RGB format
							 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
											   //as unsigned numbers
							 image->pixels);               //The actual pixel data
	delete image;

	return texture;
}



/*
********************
***** 3d Objects
********************
*/
void drawArena(GLuint texture,GLfloat R, GLfloat G, GLfloat B)
{

	glBindTexture (GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	drawCylinder(true);

}

void drawObstacle(GLuint texture,GLfloat R, GLfloat G, GLfloat B)
{


	 glBindTexture (GL_TEXTURE_2D, texture);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	 drawCylinder(false);
}

void drawCenterArena(GLuint texture,GLfloat R, GLfloat G, GLfloat B)
{

	glBindTexture (GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



	 drawCylinder(false);
}


void drawCylinder(bool inside)
{

	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();


	gluQuadricDrawStyle(quadratic,  GLU_FILL);
	gluQuadricNormals(quadratic, GLU_SMOOTH  );

	if(inside)
		gluQuadricOrientation(quadratic, GLU_INSIDE);
	else
		gluQuadricOrientation(quadratic, GLU_OUTSIDE);


	gluQuadricTexture(quadratic, GL_TRUE);
	gluCylinder(quadratic,1, 1, 1, 64, 64);

	gluDeleteQuadric(quadratic);



}
void drawDisk (GLfloat radius, bool inside)
{
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();



	gluQuadricNormals(quadratic, GLU_SMOOTH  );

	gluQuadricDrawStyle(quadratic,  GLU_FILL);
	if(inside)
		gluQuadricOrientation(quadratic, GLU_INSIDE);
	else
		gluQuadricOrientation(quadratic, GLU_OUTSIDE);




	gluQuadricTexture(quadratic, GL_TRUE);
	gluDisk(quadratic,0, radius,200, 80);

	gluDeleteQuadric(quadratic);
}
/*
********************
***** 2D TEXT AND MINIMAP
********************
*/
void		printText			(GLfloat x, GLfloat y, string *text, GLfloat R, GLfloat G, GLfloat B)
{
	glPushAttrib(GL_ENABLE_BIT);

		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_DEPTH_TEST);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0,settings.width,0.0,settings.height);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
				glLoadIdentity();
				glColor3f(R,G,B);
				glRasterPos2f(x,y);

				for(unsigned int i=0;i<text->size();i++)
				{
					glutBitmapCharacter(GLUT_BITMAP_9_BY_15, text->at(i));
				}
			glPopMatrix();
		glPopMatrix();
	glPopAttrib();

}
void printEndMsg (GLfloat x, GLfloat y, std::string *text, GLfloat R, GLfloat G, GLfloat B)
{
	glPushAttrib(GL_ENABLE_BIT);

		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_DEPTH_TEST);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0,settings.width,0.0,settings.height);
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
				glLoadIdentity();
				glColor3f(R,G,B);
				glTranslatef(x, y,0);
				glScalef(0.4,0.4,0);
				for(unsigned int i=0;i<text->size();i++)
				{

					glutStrokeCharacter(GLUT_STROKE_ROMAN, text->at(i));
				}
			glPopMatrix();
		glPopMatrix();
	glPopAttrib();
}
void drawMiniMap (GLfloat x, GLfloat y)
{
	glPushAttrib(GL_ENABLE_BIT);

		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_DEPTH_TEST);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			gluOrtho2D(0.0,settings.width,0.0,settings.height - 200);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

				glPushMatrix(); // Arena
					glTranslatef(x,y,0);
					glScaled(0.1,0.1,0.1);
					drawCircle(biggerCircle,700,2);

					drawCircle(centerCircle,centerCircle->getRadius(),1);

					for(auto& obs : obstacles)
						drawCircle(obs, obs->getRadius(),1);

					for(auto& enem : enemies)
						drawCircle(enem->getBody(), enem->getBody()->getRadius(),1);
					if(win)
						drawCircle(player->getBody(),player->getBody()->getRadius(),1);



				glPopMatrix();

		glPopMatrix();
	glPopAttrib();
}
/*
********************
***** TRANSFORMATIONS
********************
*/

Vertec translate (Vertec v,GLfloat dx,GLfloat dy,GLfloat dz)
{
	Vertec result;


	result.X = v.X + dx;
	result.Y = v.Y + dy;
	result.Z = v.Z + dz;

	return result;
}

Vertec scale (Vertec v, GLfloat sx,GLfloat sy,GLfloat sz)
{

	Vertec result;

	result.X = v.X * sx;
	result.Y = v.Y * sy;
	result.Z = v.Z * sz;

	return result;

}

Vertec rotate_XY (Vertec v, GLfloat angle)
{
	Vertec result;
	GLfloat radians = angle*M_PI/180;


	result.X = cos(radians) * v.X + -sin(radians) * v.Y;
	result.Y = sin(radians) * v.X +  cos(radians) * v.Y;
	result.Z = v.Z;


	return result;
}

Vertec rotate_YZ (Vertec v, GLfloat angle)
{
	Vertec result;

	GLfloat radians = angle*M_PI/180;

	result.X = v.X;
	result.Y = cos(radians) * v.Y + -sin(radians) * v.Z;
	result.Z = sin(radians) * v.Y +  cos(radians) * v.Z;

	return result;

}

Vertec rotate_ZX (Vertec v, GLfloat angle)
{

	Vertec result;

	GLfloat radians = angle*M_PI/180;

	result.X =  cos(radians) * v.X +  sin(radians) * v.Z;
	result.Y = v.Y;
	result.Z = -sin(radians) * v.X +  cos(radians) * v.Z;


	return result;
}




/*
********************
***** MATH FUNC
********************
*/

double euclidianDistance (double x1, double y1, double x2, double y2) {
	return sqrt ( pow (x1 - x2, 2) + pow (y1 - y2, 2) );
}
