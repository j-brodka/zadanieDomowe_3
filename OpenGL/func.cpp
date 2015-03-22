#include <iostream>
#include <stdio.h>
#include <math.h>
#include "func.h"
#define PI 3.1415926535897932384626433832795
using namespace std;

#include <GL/freeglut.h>


float ox1,oy1, ox2,oy2, ox3,oy3, r1,r2,r3;
int wybor=0;
int ksztalt1=0, ksztalt2=0, ksztalt3=0;
int klr1=0, klr2=0, klr3=0;
int klr1a=1, klr2a=1, klr3a=1;


void handleKeypress(unsigned char key, int x, int y)
{
	if(key=='q')
	{
		wybor+=1;
		if(wybor==4)
			wybor=1;
	}
	else if(key=='e')
	{
		wybor-=1;
		if (wybor==0)
			wybor=3;
	}

	if(wybor==1)
	{
		switch (key)
		{
			case 'w':
			 oy1 += 0.1; break;
			case 's':
			 oy1 -= 0.1; break;
			case 'a':
			 ox1 -= 0.1; break;
			case 'd':
			 ox1 += 0.1; break;
		}
		if(key=='i')
			ksztalt1=0;
		else if(key=='o')
			ksztalt1=1;
		else if(key=='p')
			ksztalt1=2;
	}
	else if(wybor==2)
	{
		switch (key)
		{
			case 'w':
			 oy2 += 0.1; break;
			case 's':
			 oy2 -= 0.1; break;
			case 'a':
			 ox2 -= 0.1; break;
			case 'd':
			 ox2 += 0.1; break;
		}
		if(key=='i')
			ksztalt2=0;
		else if(key=='o')
			ksztalt2=1;
		else if(key=='p')
			ksztalt2=2;
	}
	else if(wybor==3)
	{
		switch (key)
		{
			case 'w':
			 oy3 += 0.1; break;
			case 's':
			 oy3 -= 0.1; break;
			case 'a':
			 ox3 -= 0.1; break;
			case 'd':
			 ox3 += 0.1; break;
		}
		if(key=='i')
			ksztalt3=0;
		else if(key=='o')
			ksztalt3=1;
		else if(key=='p')
			ksztalt3=2;
	}
	kolor();
}

void kolor()
{
	if(wybor==1)
	{
		klr1=1;
		klr1a=0;
		klr2=0;
		klr2a=1;
		klr3=0;
		klr3a=1;
	}
	else if(wybor==2)
	{
		klr1=0;
		klr1a=1;
		klr2=1;
		klr2a=0;
		klr3=0;
		klr3a=1;
	}
	else if(wybor==3)
	{
		klr1=0;
		klr1a=1;
		klr2=0;
		klr2a=1;
		klr3=1;
		klr3a=0;
	}
}

void DrawObject1(void)
{
	double height = 0.5;
	double width = 0.5;

	glPushMatrix();
	
	glTranslated(-1+ox1, oy1, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0+r1, 0.0, 0.0, 1.0);

	glColor3d(klr1, 0.0, klr1a);
	if(ksztalt1==0)
	{
		glBegin(GL_POLYGON);
		{
			glVertex3d(-width / 2, height / 2, 0);
			glVertex3d(width / 2, height / 2, 0);
			glVertex3d(width / 2, -height / 2, 0);
			glVertex3d(-width / 2, -height / 2, 0);
		}
		glEnd();
	}
	else if(ksztalt1==1)
	{
		glBegin(GL_POLYGON);
		{
			for(double i = 0; i < 2 * PI; i += PI / 3)
 					glVertex3f(cos(i)*0.3, sin(i)*0.3, 0.0);
		}
		glEnd();
	}
	else if(ksztalt1==2)
	{
		glBegin(GL_POLYGON);
		{
			for(double i = 0; i < 2 * PI; i += PI / 30)
 					glVertex3f(cos(i)*0.3, sin(i)*0.3, 0.0);
		}
		glEnd();
	}

	glPopMatrix();
}

void DrawObject2(void)
{
	double height = 0.5;
	double width = 0.5;

	glPushMatrix();
	
	glTranslated(ox2, oy2, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0+r2, 0.0, 0.0, 1.0);

	glColor3d(klr2, 0.0, klr2a);

	if(ksztalt2==0)
	{
		glBegin(GL_POLYGON);
		{
			glVertex3d(-width / 2, height / 2, 0);
			glVertex3d(width / 2, height / 2, 0);
			glVertex3d(width / 2, -height / 2, 0);
			glVertex3d(-width / 2, -height / 2, 0);
		}
		glEnd();
	}

	else if(ksztalt2==1)
	{
		glBegin(GL_POLYGON);
		{
			for(double i = 0; i < 2 * PI; i += PI / 3)
 					glVertex3f(cos(i)*0.3, sin(i)*0.3, 0.0);
		}
		glEnd();
	}
	else if(ksztalt2==2)
	{
		glBegin(GL_POLYGON);
		{
			for(double i = 0; i < 2 * PI; i += PI / 30)
 					glVertex3f(cos(i)*0.3, sin(i)*0.3, 0.0);
		}
		glEnd();
	}

	glPopMatrix();
}

void DrawObject3(void)
{
	double height = 0.5;
	double width = 0.5;

	glPushMatrix();
	
	glTranslated(1+ox3, oy3, 0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0+r3, 0.0, 0.0, 1.0);

	glColor3d(klr3, 0.0, klr3a);
	
	if(ksztalt3==0)
	{
		glBegin(GL_POLYGON);
		{
			glVertex3d(-width / 2, height / 2, 0);
			glVertex3d(width / 2, height / 2, 0);
			glVertex3d(width / 2, -height / 2, 0);
			glVertex3d(-width / 2, -height / 2, 0);
		}
		glEnd();
	}

	else if(ksztalt3==1)
	{
		glBegin(GL_POLYGON);
		{
			for(double i = 0; i < 2 * PI; i += PI / 3)
 					glVertex3f(cos(i)*0.3, sin(i)*0.3, 0.0);
		}
		glEnd();
	}
	else if(ksztalt3==2)
	{
		glBegin(GL_POLYGON);
		{
			for(double i = 0; i < 2 * PI; i += PI / 30)
 					glVertex3f(cos(i)*0.3, sin(i)*0.3, 0.0);
		}
		glEnd();
	}

	glPopMatrix();
}

