// 3d.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <cstdlib>
#include <GLFW\glfw3.h>
#include <gl\GL.h>
#include <gl\GLU.h>
//#pragma comment( lib, "glfw3.lib" )

void update(GLFWwindow* window, int width, int height)
{
	GLfloat ratio;
	ratio = width / (float) height;
	glViewport( 0, 0, width, height );
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, ratio, 1, 300);
	gluLookAt(0,0,-20,0,0,0,0,2,0);
	//glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
}

void draw(GLFWwindow* window)
{
	//glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef((float) glfwGetTime() * 50.f, 0, 1.f, 0);

	glBegin(GL_LINES); // draw axes
	glVertex3f(0,0,0); glVertex3f(1,0,0);
	glVertex3f(0,0,0); glVertex3f(0,1,0);
	glVertex3f(0,0,0); glVertex3f(0,0,1);
	glEnd();

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
	/*
	glBegin(GL_QUADS); 
        glVertex3f( 0, 0,  20);
        glVertex3f( 0, 50,  20);
        glVertex3f( 0, 50, -20);
        glVertex3f( 0, 0, -20);
    glEnd();
	*/
	glfwSwapBuffers(window);
	glfwPollEvents();
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

	glfwSetWindowSizeCallback(window, update);

	glfwMakeContextCurrent(window);
	//glfwSetKeyCallback(window, key_callback);
	
	update(window, 640, 480);

	while (!glfwWindowShouldClose(window))
	{
		draw(window);
		
	}
	printf("end");
}

