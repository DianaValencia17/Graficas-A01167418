
	/*********************************************************
	Materia: Graficas computacionales
	Fecha: 14 de agosto de 2017
	Autor: Diana Laura Valencia Dominguez A01167418
	*********************************************************/
	//
	//  Tarea1 Diana Valencia.cpp
	//  DianaValenciaTarea1
	//
	//  Created by Diana Valencia  on 2017-08-14.
	//
	//
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp> 
#include <vector> 


float x(float gradosX);

float y(float gradosY);




	GLuint vao;


void Initialize()
{

	std::vector<glm::vec2> positions;
	positions.push_back(glm::vec2(0.0f, 1.0f));
	positions.push_back(glm::vec2(x, y));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);


	GLuint positionsVBO;
 
	glGenBuffers(1, &positionsVBO);

	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(), positions.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);



	glBindVertexArray(0);


}

void MainLoop()
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glBindVertexArray(vao);


	glDrawArrays(GL_TRIANGLES, 0, 3);

	

	glBindVertexArray(0);





	glutSwapBuffers();
}

int main(int argc, char* argv[])
{

	glutInit(&argc, argv);

	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
.
	glutInitWindowSize(400, 400);
	
	glutCreateWindow("Hello World OpenGL");

	glutDisplayFunc(MainLoop);


	glewInit();


	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	Initialize();

	glutMainLoop();

	return 0;
}



float x(float gradosX)
{
	glm::radians (gradosX) 

}
