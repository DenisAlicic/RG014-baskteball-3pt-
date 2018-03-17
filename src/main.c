#include <stdlib.h>
#include <GL/glut.h>
#include "callback_functions.h"

int main(int argc, char **argv)
{
	/* Initialization of GLUT */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	/* Creation of window */
	glutInitWindowSize(900, 650);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("3pt_contest!");

	/* Registration of callback function */
	glutKeyboardFunc(on_keyboard);
	glutReshapeFunc(on_reshape);
	glutDisplayFunc(on_display);

	/* OpenGL initialization */
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glLineWidth(2);

	/* Program get into main loop */
	glutMainLoop();

	return 0;
}
