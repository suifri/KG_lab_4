#include "ChessCube.h"

const GLint WIDTH = 500;
const GLint HEIGHT = 500;

ChessCube* test{ new ChessCube() };

void init()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
}

void reshape(const GLint width, const GLint height)
{
	test->reshape(width, height);
}

void timer(int extra)
{
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	test->display();
	glutSwapBuffers();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Lab 4");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);

	init();

	glutMainLoop();

	return 0;
}