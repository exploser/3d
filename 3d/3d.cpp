// 3d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <cstdlib>
#include <GLFW\glfw3.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <math.h>

double camT = -10; // more globals pls
double camP = 0;
double camR = 14;

double lastmX = 0;
double lastmY = 0;
double mX = 0;
double mY = 0;

void update(GLFWwindow* window, int width, int height)
{
	GLfloat ratio;
	ratio = width / (float) height;
	glViewport( 0, 0, width, height );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 1, 300);
	gluLookAt(camR * cos(camT) * cos(camP),camR * sin(camT),camR * cos(camT) * sin(camP),0,0,0,0,2,0);
	//glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f); // orthographic cam sucks
}

void radius_update(GLFWwindow* window, double xamount, double yamount)
{
	camR -= yamount;
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	update(window,width,height);
}

void angle_update(GLFWwindow* window)
{
	if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT))
		if(lastmX == 0 && lastmY == 0)
			glfwGetCursorPos(window, &lastmX, &lastmY); // init
		else
		{
			glfwGetCursorPos(window, &mX, &mY);
			camP -= (lastmX - mX)*0.01f;
			camT += (lastmY - mY)*0.01f;
			lastmX = mX;
			lastmY = mY;
			int width, height;
			glfwGetWindowSize(window, &width, &height);
			update(window,width,height);
		}
}

void drawAxes(GLFWwindow* window)
{

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_LINES); // draw axes
	glColor3f (1, 0, 0);
	glVertex3f(0,0,0); glVertex3f(1,0,0);
	glColor3f (0, 1, 0);
	glVertex3f(0,0,0); glVertex3f(0,1,0);
	glColor3f (0, 0, 1);
	glVertex3f(0,0,0); glVertex3f(0,0,1);
	glEnd();

	glPopMatrix();
}


void drawGrid(GLFWwindow* window)
{

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_LINES); // draw axes
	glColor4f (.5, .5, .5, .02);
	int size = 100;
	for(int i = 0; i<=size; i++)
	{
		glVertex3f(i-size/2,0,-size/2); glVertex3f(i-size/2,0,size/2);
		glVertex3f(-size/2,0,i-size/2); glVertex3f(size/2,0,i-size/2); 
	}
	glEnd();

	glPopMatrix();
}

void drawMichael(GLFWwindow* window)
{
	glPushMatrix(); // independent rotation!

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef((float) glfwGetTime() * 30.f, 0, 1.f, 0);

	glBegin(GL_TRIANGLE_FAN); // draw Michael's silhouette
	glColor3f (1, 1, 1);
	glVertex3f(5.92f,5,    0);
	glVertex3f(5.89f,-1,0);
	glVertex3f(4.57f,-1,0);
	glVertex3f(4.97f,-0.76f,0);
	glVertex3f(4.75f,-0.45f,0);
	glVertex3f(4.39f,-0.49f,0);
	glVertex3f(3.87f,-0.48f,0);
	glVertex3f(3.59f,-0.59f,0);
	glVertex3f(3.34f,-0.50f,0);
	glVertex3f(3.26f,-0.28f,0);
	glVertex3f(3.29f,-0.08f,0);
	glVertex3f(3.03f,-4.63f+5,0); // too much vodka inside to explain what the fuck i am doing
	glVertex3f(3.09f,-4.49f+5,0);
	glVertex3f(2.92f,-4.27f+5,0);
	glVertex3f(2.85f,-3.99f+5,0);
	glVertex3f(2.67f,-3.95f+5,0);
	glVertex3f(2.41f,-3.61f+5,0);
	glVertex3f(2.64f,-3.34f+5,0);
	glVertex3f(2.84f,-2.75f+5,0);
	glVertex3f(2.63f,-2.26f+5,0);
	glVertex3f(2.64f,-1.94f+5,0);
	glVertex3f(1.42f,-1.82f+5,0);
	glVertex3f(1.07f,-1.62f+5,0);
	glVertex3f(1.12f,-1.26f+5,0);
	glVertex3f(1.59f,-1+5,    0);
	glVertex3f(2.28f,-0.77f+5,0);
	glVertex3f(2.34f,-0.60f+5,0);
	glVertex3f(2.42f,-0.55f+5,0);
	glVertex3f(2.42f,5,    0);

	//glVertex3f(4.57f,-1,0);
	glEnd();
	glBegin(GL_TRIANGLE_FAN); // draw Michael's hat
	glColor3f (.1f, .1f, .1f);
	glVertex3f(5.92f,5,    0);
	glVertex3f(2.42f,5,    0);
	glVertex3f(2.42f,-0.55f+5,0);
	glVertex3f(2.34f,-0.60f+5,0);
	glVertex3f(2.28f,-0.77f+5,0);
	glVertex3f(1.59f,-1+5,    0);
	glVertex3f(1.12f,-1.26f+5,0);
	glVertex3f(1.07f,-1.62f+5,0);
	glVertex3f(1.42f,-1.82f+5,0);
	glVertex3f(2.46f,-1.95+5,0); // where did the -f postfix go?
	glVertex3f(3.42f,-1.99+5,0);
	glVertex3f(4.26f,-1.98+5,0);
	glVertex3f(4.35f,-2.91+5,0);
	glVertex3f(5.20f,-3.77+5,0);
	glVertex3f(5.90f,-4.06+5,0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // draw Michael's glasses
	glColor3f (.1f, .1f, .1f);
	glVertex3f(3.09f,-2.81+5,0);
	glVertex3f(2.97f,-2.50+5,0);
	glVertex3f(2.73f,-2.37+5,0);
	glVertex3f(2.66f,-2.55+5,0);
	glVertex3f(2.85f,-3.33+5,0);
	glVertex3f(3.09f,-3.59+5,0);
	glVertex3f(3.22f,-3.53+5,0);
	glVertex3f(3.16f,-3.05+5,0); // svali iz moix soröov naxyi
	glVertex3f(3.11f,-2.89+5,0);
	glVertex3f(4.42f,-2.46+5,0);
	glVertex3f(4.41f,-2.41+5,0);
	glEnd();

	glBegin(GL_LINE_STRIP); // eyelid
	glColor3f (.1f, .1f, .1f);
	glVertex3f(3.04f,-3.07+5,0);
	glVertex3f(3.14f,-2.94+5,0);
	glVertex3f(3.27f,-2.90+5,0);
	glVertex3f(3.46f,-2.93+5,0);
	glVertex3f(3.56f,-2.89+5,0);
	glVertex3f(3.43f,-3.05+5,0);
	glVertex3f(3.32f,-3.08+5,0);
	glVertex3f(3.20f,-3.07+5,0);
	glVertex3f(3.12f,-3.08+5,0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // eye
	glColor3f (.1f, .1f, .1f);
	glVertex3f(3.25f,-2.90+5,0);
	glVertex3f(3.31f,-2.97+5,0);
	glVertex3f(3.31f,-3.08+5,0);
	glVertex3f(3.18f,-3.06+5,0);
	glVertex3f(3.15f,-3.01+5,0);
	glVertex3f(3.16f,-2.92+5,0);
	glEnd();

	glBegin(GL_TRIANGLE_FAN); // lips
	glColor3f(0.8823, 0.702, 0.745);
	glVertex3f(3.51f,-4.31f+5,0);
	glVertex3f(3.03f,-4.36f+5,0);
	glVertex3f(2.91f,-4.26f+5,0);
	glVertex3f(3.46f,-4.18f+5,0);
	glVertex3f(3.56f,-4.33f+5,0);
	glVertex3f(3.22f,-4.72f+5,0);
	glVertex3f(3.05f,-4.74f+5,0);
	glVertex3f(3.00f,-4.57f+5,0);
	glEnd();

	glPopMatrix();
}

int _tmain(int argc, _TCHAR* argv[])
{
	GLFWwindow* window;
	//glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);


	window = glfwCreateWindow(640, 480, "epic3d", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetWindowSizeCallback(window, update); // swag
	glfwSetScrollCallback(window, radius_update);
	//glfwSetWindowPosCallback(window, window_pos_callback);

	glfwMakeContextCurrent(window);
	//glfwSetKeyCallback(window, key_callback);

	update(window, 640, 480);


	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		drawGrid(window);
		drawAxes(window);
		drawMichael(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
		angle_update(window);
		/*																																																											*/if(glfwGetTime()>5)/*
		draw_misc(window);																																																							*/if((int)ceil(glfwGetTime())%2==0)/*
		printf("%f", glfwGetTime());																																																				*/glfwSetWindowTitle(window, "EGOR");/*
																																																													*/else/*
		*/																																																											glfwSetWindowTitle(window, "HOHOL");
	}
	glfwTerminate();
	printf("end");
}

