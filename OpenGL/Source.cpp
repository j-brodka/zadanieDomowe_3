#include <iostream>
#include <stdio.h>
#include <math.h>
#include "func.h"
#define PI 3.1415926535897932384626433832795
using namespace std;

#include <GL/freeglut.h>

const int glutWindowWidth = 1024;
const int glutWindowHeight = 768;

float proportion = (float)glutWindowWidth / (float)glutWindowHeight;

static void resize(int width, int height)
{
	
	const float ar = (float)width / (float)height;
	proportion = ar;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle(void)
{
	glutPostRedisplay();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	DrawObject1();
	DrawObject2();
	DrawObject3();
	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(240, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("zadanieDomowe_3");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glutKeyboardFunc(&handleKeypress);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();

	return 0;
}