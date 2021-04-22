#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "Cube.h"
#include <iostream>
#include <fstream>

Vertex* Cube::indexedVertices = nullptr;

Color* Cube::indexedColors = nullptr; 


GLushort* Cube::indices = nullptr;


int Cube::numVertices = 0;
int Cube::numColors = 0;
int Cube::numIndices = 0;  

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
	if (indexedVertices != nullptr && indexedColors != nullptr) {
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
}
bool Cube::Load(char* path)
{
	std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "Can't open text file " << path << std::endl;
		return false;
	}

	inFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}
	inFile >> numColors;
	indexedColors = new  Color[numColors];
	for (int i = 0; i < numColors; i++)
	{
			inFile >> indexedColors[i].r;
			inFile >> indexedColors[i].g;
			inFile >> indexedColors[i].b;
	}
	inFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int i = 0; i < numIndices; i++)
	{
		inFile >> indices[i];
	}

	inFile.close();

	return true;
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

