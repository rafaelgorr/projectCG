/*
 * functions.h
 *
 *  Created on: 21 de out de 2017
 *      Author: rafael
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include "Circle.h"
#include "structs.h"
#include "Vertec.h"
#include <vector>

/*GLUT FUNCTIONS */
void      		init					(void);
void        	display             	(void);
void      		glutIdle	      		(void);
	/* KEYBOARD FUNCTIONS */
	void     		keyUp               	(unsigned char key, int x, int y );
	void      		keyPress    	 		(unsigned char key, int x, int y );
	void			checkKeyPress			();

	/* MOUSE FUNCTIONS */
	void		    mouseClick				(int button, int state, int x, int y);
	void			mouseMotion				(int x, int y);
	void		    mousePassiveMotion		(int x, int y);

/***/


/* DRAW FUNCTIONS */
void			drawAll					(int cameraMode); //Camera mode 1 is Main Camera
															  //Camera mode 2 is Camera Eye
	/* 2D OBJECTS */
	void    	  	drawCircle	    		(Circle *circle, GLfloat radius, int mode); // Mode 1 draw circle with polygons
																						// Mode 2 draw circle with points




	/* 3D OBJECTS */
	void			drawCylinder			(bool inside);
	void			drawDisk				(GLfloat radius, bool inside);
	void			drawObstacle			(GLuint texture,GLfloat R, GLfloat G, GLfloat B);
	void			drawArena				(GLuint texture,GLfloat R, GLfloat G, GLfloat B);
	void			drawCenterArena			(GLuint texture,GLfloat R, GLfloat G, GLfloat B);
/***/

/* LIGHT FUNCTIONS */
void			lightSettings			();
Vertec*			getSpotPosition			();

/* CAMERA FUNCTIONS */
void    		changeCameras			();
void			cameraEye				();

/* 2D TEXT AND MINIMAP */
void		    printText				(GLfloat x, GLfloat y, std::string *text, GLfloat R, GLfloat G, GLfloat B);
void		    printEndMsg				(GLfloat x, GLfloat y, std::string *text, GLfloat R, GLfloat G, GLfloat B);
void			drawMiniMap				(GLfloat x, GLfloat y);

/* BOT AND PLAYER SHOTS FUNCTIONS */
void		    collisionShotEnemies	(GLfloat dTimeIdle);
void		    bots					(GLfloat dTimeIdle);
void			bulletsMoviment			(GLfloat dTimeIdle); // And check shots collision



/* TRANSFORMATIONS */
Vertec			translate				(Vertec v, GLfloat dx,GLfloat dy,GLfloat dz);
Vertec			scale					(Vertec v, GLfloat sx,GLfloat sy,GLfloat sz);
Vertec			rotate_XY				(Vertec v, GLfloat angle);
Vertec			rotate_YZ				(Vertec v, GLfloat angle);
Vertec			rotate_ZX				(Vertec v, GLfloat angle);



/* BLENDER */
bool 			loadMesh				(std::string path);
void			loadOBJ					();

/* TEXTURES */
GLuint			LoadTextureRAW			( const char * filename );


/* EXTRA FUNCTIONS */

double     		euclidianDistance		(double x1, double y1, double x2, double y2);
void			fpsCount				(GLfloat time);


#endif /* FUNCTIONS_H_ */
