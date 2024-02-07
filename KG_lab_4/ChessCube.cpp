#include "ChessCube.h"

void ChessCube::drawBox(GLfloat size, GLenum type)
{
	static GLfloat n[6][3] =
	{
	  {-1.0, 0.0, 0.0},
	  {0.0, 1.0, 0.0},
	  {1.0, 0.0, 0.0},
	  {0.0, -1.0, 0.0},
	  {0.0, 0.0, 1.0},
	  {0.0, 0.0, -1.0}
	};
	static GLint faces[6][4] =
	{
	  {0, 1, 2, 3},
	  {3, 2, 6, 7},
	  {7, 6, 5, 4},
	  {4, 5, 1, 0},
	  {5, 6, 2, 1},
	  {7, 4, 0, 3}
	};
	GLfloat v[8][3];
	GLint i;

	v[0][0] = v[1][0] = v[2][0] = v[3][0] = -size / 2;
	v[4][0] = v[5][0] = v[6][0] = v[7][0] = size / 2;
	v[0][1] = v[1][1] = v[4][1] = v[5][1] = -size / 2;
	v[2][1] = v[3][1] = v[6][1] = v[7][1] = size / 2;
	v[0][2] = v[3][2] = v[4][2] = v[7][2] = -size / 2;
	v[1][2] = v[2][2] = v[5][2] = v[6][2] = size / 2;

	for (i = 5; i >= 0; i--) {
		glBegin(type);
		glNormal3fv(&n[i][0]);
		glVertex3fv(&v[faces[i][0]][0]);
		glVertex3fv(&v[faces[i][1]][0]);
		glVertex3fv(&v[faces[i][2]][0]);
		glVertex3fv(&v[faces[i][3]][0]);
		glEnd();
	}
}

ChessCube::ChessCube(const GLint size)
	:size(size), color(new GLfloat[3])
{
	*this->color = 1.0f;
	*(this->color + 1) = 0.5f;
	*(this->color + 2) = 0.0f;
}

ChessCube::~ChessCube()
{
	delete[] this->color;
	this->color = nullptr;
}

void ChessCube::display()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	GLdouble aspect{ static_cast<GLdouble>(*(viewport + 2)) / static_cast<GLdouble>(*(viewport + 3)) };
	gluPerspective(60, aspect, 1, 100);

	static GLfloat angle{0.0};
	angle += 1.0f;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
		glTranslatef(0, 0, -30);
		glRotatef(angle, 0.0f, 0.0f, 0.1f);
		glRotatef(45, 0.2f, 0.5f, 0.0f);
		glColor3fv(this->color);
		this->drawBox(this->size, GL_QUADS);
		//glutSolidCube(this->size);
	glPopMatrix();
}

void ChessCube::reshape(const GLint width, const GLint height)
{
	glViewport(0, 0, width, height);
}

void ChessCube::textureGenerator()
{
	GLint width{ 0 };
	GLint height{ 0 };
	GLint nrChannels{ 0 };
}

