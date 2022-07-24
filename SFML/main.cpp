#include <SFML/System/Vector3.hpp>
#include <cstdio>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "ogldev_math_3d.h"
#include "ogldev_util.h"
#include "glut.h"
#include "glm/glm.hpp"
#include "glfx.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "ogldev_engine_common.h"
#include "freeglut_std.h"
#include <GL/gl.h>

GLuint VBO;
GLuint TVO;

static void RenderSceneCB() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, 0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 3);
	glBindBufferBase(GL_UNIFORM_BUFFER, VBO, TVO);
	glEnable(GL_TEXTURE_2D);
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
	glDrawBuffer(GL_UNIFORM_BUFFER);	
	glDisableVertexAttribArray(0);
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

static void CreateVertexBuffer() {
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glCullFace(GL_FRONT);
	sf::Vector3f Vertices[3];
	Vertices[0] = sf::Vector3f(.999f, .999f, 0.f);
	Vertices[1] = sf::Vector3f(-0.999f, .999f, 0.f);
	Vertices[2] = sf::Vector3f(-0.999f, -0.999f, 0.f);

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_UNIFORM_BUFFER, TVO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glBufferData(GL_UNIFORM_BUFFER, sizeof(!VBO), NULL, GL_STREAM_DRAW);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    int width = 800;
	int height = 600;
	glutInitWindowSize(width, height);

	int x = 200, y = 100;
	glutInitWindowPosition(x, y);
	int win = glutCreateWindow("SFML - OpenGL");
	printf("window id: %d\n", win);

	GLenum res = glewInit();
	if (res != GLEW_OK) {
    fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
    return 1;
	}

	GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);	

	CreateVertexBuffer();

	glutDisplayFunc(RenderSceneCB);

	glutMainLoop();

    return 0;
}