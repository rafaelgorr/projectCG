#include "headers.h"
#include "globals.h"


int main(int argc, char** argv) {

	if(argc != 2) {
		std::cerr << "ERRO: numero invalido de argumentos." << '\n';
		exit(1);
	}

	Reader reader;
	reader.readXML (argc,argv);

	settings.width = 500;
	settings.height = 700;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(settings.width,settings.height);
	glutInitWindowPosition(0,0);
	glutCreateWindow(settings.title.c_str());
	glutDisplayFunc(display);
	glutKeyboardFunc(keyPress);
	glutKeyboardUpFunc(keyUp);
	glutIdleFunc(glutIdle);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);
	glutPassiveMotionFunc(mousePassiveMotion);

	init();

	glutMainLoop();

	return EXIT_SUCCESS;

}
