#pragma once
#include <Windows.h> //required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#define REFRESHRATE 16 //Pace of the application

struct Vector3
{
	float x;
	float y;
	float z;

};
struct Camera {
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};
struct Color {
	GLfloat r, g, b;
};
struct Vertex {
	GLfloat x, y, z;
};



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
	static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
};




