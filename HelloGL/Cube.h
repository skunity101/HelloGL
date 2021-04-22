#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:
	static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;
	static int numVertices, numColors, numIndices;
	GLfloat _rotation;
	Vector3 _position;
	//static Vertex vertices[];
	//static Color colors[];

public:
	Cube(float x, float y, float z);
	~Cube();
	static bool Load(char* path);

	void Update();
	void DrawIdexedCube();
	void DrawCube();
	void DrawCubeArray();
};
