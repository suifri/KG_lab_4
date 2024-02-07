#include <GL/glut.h>

const GLint WIDTH = 500;
const GLint HEIGHT = 500;

void init()
{

}

void reshape(const GLint width, const GLint height)
{

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Lab 4");

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	glutMainLoop();

	return 0;
}