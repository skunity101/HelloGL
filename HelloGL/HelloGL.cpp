#include "HelloGL.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"


HelloGL::HelloGL(int argc, char* argv[])
{
	camera = new Camera();
	for (int i = 0; i < 200; i++) {
		cube = new Cube(((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}
	//camera->eye.x = 5.0f; camera->eye.y = 5.0f; camera->eye.z = -5.0f;
	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f;
	//camera->center.x = 5.0f; camera->center.y = 5.0f; camera->center.z = 5.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	//camera->up.x = 5.0f; camera->up.y = 5.0f; camera->up.z = 5.0f;
	rotation = 0.0f;
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(650, 550);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glViewport(0, 0, 650, 650); //set the viewport to be the entire window
	gluPerspective(45, 1, 0, 1000); //set the correct perspective
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK); 
	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //this clears the scene
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, 0.0f, 0.0f);
	//drawTriangle();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 1.0f);
	glRotatef(rotation, 0.0f, 0.0f, 4.0f);
	//drawPolygon()
	//DrawCubeArray();                
	//DrawIdexedCube();
	Cube::Load((char*)"cube.txt");
	//cube->DrawIdexedCube();
	glPopMatrix();
	glFlush(); //flushes the scene drawn to the graphics card
	glutSwapBuffers();
}
void HelloGL::drawPolygon() {
	glBegin(GL_POLYGON); { //starts to draw a polygon
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f); //colors the polygon draw
		glVertex2f(-0.75, 0.5); //define the first point of the polygon, top left
		glVertex2f(0.75, 0.5); //top right
		glVertex2f(0.75, -0.5); //bottom right
		glVertex2f(-0.75, -0.5); //bottom left
		glEnd(); //defines the end of the draw
	}
}
void HelloGL::drawTriangle() {
	glBegin(GL_TRIANGLES); {//equalateral trangle
		glColor4f(1.0f, 0.0f, 1.0f, 0.0f); //colors the triangle draw
		glVertex3f(-0.6, 0.8, 0.0);
		glVertex3f(-0.8, 0.4, 0.0);
		glVertex3f(-0.4, 0.4, 0.0);
		glEnd();
	}
	/*glBegin(GL_TRIANGLES); { //scalene triangle
		glColor4f(0.0f, 0.0f, 1.0f, 0.0f); //colors the triangle draw
		glVertex3f(-0.8, -0.4, 0.0);
		glVertex3f(-0.9, -0.7, 0.0);
		glVertex3f(-0.4, -0.8, 0.0);
		glEnd();
	}
	glBegin(GL_TRIANGLES); { //isometrical triangle
		glColor4f(0.0f, 1.0f, 0.0f, 0.0f); //colors the triangle draw
		glVertex3f(0.0, 0.8, 0.0);
		glVertex3f(-0.15, 0.4, 0.0);
		glVertex3f(0.15, 0.4, 0.0);
		glEnd();
	}
	glBegin(GL_TRIANGLES); { //acute triangle
		glColor4f(1.0f, 1.0f, 1.0f, 0.0f); //colors the triangle draw
		glVertex3f(-0.1, -0.4, 0.0);
		glVertex3f(-0.2, -0.8, 0.0);
		glVertex3f(0.2, -0.8, 0.0);
		glEnd();
	}
	glBegin(GL_TRIANGLES); { //right-angle triangle
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f); //colors the triangle draw
		glVertex3f(0.4, 0.4, 0.0);
		glVertex3f(0.8, 0.4, 0.0);
		glVertex3f(0.8, 0.8, 0.0);
		glEnd();
	}
	glBegin(GL_TRIANGLES); { //obtuse triangle
		glColor4f(0.5f, 1.0f, 1.0f, 1.0f); //colors the triangle draw
		glVertex3f(0.9, -0.4, 0.0);
		glVertex3f(0.4, -0.8, 0.0);
		glVertex3f(0.7, -0.8, 0.0);
		glEnd();
	}*/
}


HelloGL::~HelloGL(void)
{
	Camera;
}

void HelloGL::Update() 
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);
	glutPostRedisplay();
	if (rotation >= 360.0f)
		rotation = 0.0f;
	cube->Update();
	//Sleep(10);
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		rotation += 0.5f;
	if (key == 'a')
		rotation += -0.5f;
}


/*Vertex HelloGL::indexedVertices[] = { 0.5, 0.5, 1,  -0.5, 0.5, 0.5,  // v0,v1,
				-0.5,-0.5, 0.5,   0.5,-0.5, 0.5,   // v2,v3
				0.5,-0.5,-0.5,   0.5, 0.5,-0.5,    // v4,v5
				-0.5, 0.5,-0.5,   -0.5,-0.5,-0.5 }; // v6,v7

//Color HelloGL::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
				1, 0, 0,   1, 0, 1,   // v2,v3
				0, 0, 1,   0, 1, 1,   // v4,v5
				0, 1, 0,   0, 0, 0 }; //v6,v7

//GLushort HelloGL::indices[] = { 0, 0.5, 1,  1, 1.5, 0,      // front
				0, 1.5, 2,  2, 2.5, 0,      // right
				0, 2.5, 3,  3, 0.5, 0,      // top
				0.5, 3, 3.5,  3.5, 1, 0.5,      // left
				3.5, 2, 1.5,  1.5, 1, 3.5,      // bottom
				2, 3.5, 3,  3.5, 2.5, 2 };    // back*/


