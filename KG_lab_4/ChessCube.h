#pragma once
#include <GL/glew.h>
#include <GL/glut.h>
#include "stb_image.h"
#include <iostream>

class ChessCube
{
private:

	GLint size;
	GLfloat* color;

	void drawBox(GLfloat size, GLenum type);
public:

	ChessCube(const GLint size = 5);
	~ChessCube();

	void display();
	void reshape(const GLint width, const GLint height);
	void textureGenerator();
};

