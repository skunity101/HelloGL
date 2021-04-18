#pragma once
#include <Windows.h> //required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "Structures.h"
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
	void DrawCube();
	void DrawCubeArray();
	void DrawIdexedCube();
private:
	float rotation;
	Camera* camera;
	//static Vertex vertices[];
	//static Color colors[];
};




