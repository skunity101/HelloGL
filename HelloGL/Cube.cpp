#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "Cube.h"

Vertex Cube::indexedVertices[] = { 0.5, 0.5, 1,  -0.5, 0.5, 0.5,  // v0,v1,
				-0.5,-0.5, 0.5,   0.5,-0.5, 0.5,   // v2,v3
				0.5,-0.5,-0.5,   0.5, 0.5,-0.5,    // v4,v5
				-0.5, 0.5,-0.5,   -0.5,-0.5,-0.5 }; // v6,v7

Color Cube::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
				1, 0, 0,   1, 0, 1,   // v2,v3
				0, 0, 1,   0, 1, 1,   // v4,v5
				0, 1, 0,   0, 0, 0 }; //v6,v7

GLushort Cube::indices[] = { 0, 0.5, 1,  1, 1.5, 0,      // front
				0, 1.5, 2,  2, 2.5, 0,      // right
				0, 2.5, 3,  3, 0.5, 0,      // top
				0.5, 3, 3.5,  3.5, 1, 0.5,      // left
				3.5, 2, 1.5,  1.5, 1, 3.5,      // bottom
				2, 3.5, 3,  3.5, 2.5, 2 };    // back


void Cube::Update()
{
	_rotation += 0.1f;
}

void Cube::DrawIdexedCube()
{
	glPushMatrix();

	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
		glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	}
	glEnd();
}
