#pragma once
#include <Windows.h> //required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "Structures.h"
#include "Cube.h"
#define REFRESHRATE 16 //Pace of the application




class HelloGL
{
public:
	//constructor definition
	HelloGL(int argc, char* argv[]);
	//destructor
	~HelloGL(void);
	void Display();
	void drawPolygon();
	void drawTriangle();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
private:
	float rotation;
	Camera* camera;
	Cube* cube;
};




