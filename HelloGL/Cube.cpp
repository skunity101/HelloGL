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


Cube::Cube(float x, float y, float z)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;
}

Cube::~Cube()
{
}

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
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	}
	glEnd();
}
/*void Cube::DrawCube() {
	glBegin(GL_TRIANGLES); {
		// face v0-v1-v2
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, 0.5);
		glColor3f(1, 1, 0);
		glVertex3f(-0.5, 0.5, 0.5);
		glColor3f(1, 0, 0);
		glVertex3f(-0.5, -0.5, 0.5);
		// face v2-v3-v0
		glColor3f(1, 0, 0);
		glVertex3f(-0.5, -0.5, 0.5);
		glColor3f(1, 0, 1);
		glVertex3f(0.5, -0.5, 0.5);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, 0.5);

		// face v0-v3-v4
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, 0.5);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, -0.5, 0.5);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, -0.5, -0.5);
		// face v4-v5-v0
		glColor3f(1, 1, 1);
		glVertex3f(0.5, -0.5, -0.5);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, -0.5);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, 0.5);

		// face v0-v5-v6
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, 0.5);
		glColor3f(0, 1, 1);
		glVertex3f(0.5, 0.5, -0.5);
		glColor3f(0, 1, 0);
		glVertex3f(-0.5, 0.5, -0.5);
		// face v6-v1-v0
		glColor3f(0, 1, 0);
		glVertex3f(-0.5, 0.5, -0.5);
		glColor3f(1, 1, 0);
		glVertex3f(-0.5, 0.5, 0.5);
		glColor3f(1, 1, 1);
		glVertex3f(0.5, 0.5, 0.5);

		// face  v1-v6-v7
		glColor3f(1, 1, 0);
		glVertex3f(-0.5, 0.5, 0.5);
		glColor3f(0, 1, 0);
		glVertex3f(-0.5, 0.5, -0.5);
		glColor3f(0, 0, 0);
		glVertex3f(-0.5, -0.5, -0.5);
		// face v7-v2-v1
		glColor3f(0, 0, 0);
		glVertex3f(-0.5, -0.5, -0.5);
		glColor3f(1, 0, 0);
		glVertex3f(-0.5, -0.5, 0.5);
		glColor3f(1, 1, 0);
		glVertex3f(-0.5, 0.5, 0.5);

		// face v7-v4-v3
		glColor3f(0, 0, 0);
		glVertex3f(-0.5, -0.5, -0.5);
		glColor3f(0, 0, 1);
		glVertex3f(0.5, -0.5, -0.5);
		glColor3f(1, 0, 1);
		glVertex3f(0.5, -0.5, 0.5);
		// face v3-v2-v7
		glColor3f(1, 0, 1);
		glVertex3f(0.5, -0.5, 0.5);
		glColor3f(1, 0, 0);
		glVertex3f(-0.5, -0.5, 0.5);
		glColor3f(0, 0, 0);
		glVertex3f(-0.5, -0.5, -0.5);

		// face v4-v7-v6
		glColor3f(0, 0, 1);
		glVertex3f(0.5, -0.5, -0.5);
		glColor3f(0, 0, 0);
		glVertex3f(-0.5, -0.5, -0.5);
		glColor3f(0, 1, 0);
		glVertex3f(-0.5, 0.5, -0.5);
		// face v6-v5-v4
		glColor3f(0, 1, 0);
		glVertex3f(-0.5, 0.5, -0.5);
		glColor3f(0, 1, 1);
		glVertex3f(0.5, 0.5, -0.5);
		glColor3f(0, 0, 1);
		glVertex3f(0.5, -0.5, -0.5);

		glEnd();
	}
}

void Cube::DrawCubeArray()
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++)
	{
		//glColor3f(colors[i].r, colors[i].g, colors[i].b);
		//glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}
	glEnd();
	glPopMatrix();
}*/

