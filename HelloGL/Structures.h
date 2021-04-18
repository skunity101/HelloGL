#pragma once
#include <Windows.h> //required for OpenGL on windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library

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

