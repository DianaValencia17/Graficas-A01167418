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
#include<GL/freeglut.h>
#include <glm/glm.hpp> //libreria de matematicas de open gl
#include <vector> //libreria de c++ una lista de elementos

//Identificador de manager de VBOs para una geometria (conjunto de vertices)
//nunca hacer, es malo jiji 
GLuint vao;

//Función que va a inicializar toda la memoria del programa
void Initialize()
{
	//posiciones del triángulo
	//vamos a crear una lista que va a almacenar las posiciones 
	//en dos dimensiones de un triangulo 
	//Esto es en CPU y RAM
	std::vector<glm::vec2> positions;
	//en sentido contrario de las manecillas del reloj
	positions.push_back(glm::vec2(-1.0f, -1.0f));
	positions.push_back(glm::vec2(1.0f, -1.0f));
	positions.push_back(glm::vec2(0.0f, 1.0f));

	std::vector<glm::vec3> colors;
	colors.push_back(glm::vec3(1.0f, 0.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
	colors.push_back(glm::vec3(0.0f, 0.0f, 1.0f));

	//creamos un VAO y almacenamos el id en la varible vao.
	//este es el manager de VBOs
	glGenVertexArrays(1, &vao);
	//le decimmos a OpenGL que lo queremos utilizar
	//todos los VBOs que creemos a partir de ahora y hasta que lo desactivemos (este VAO), se van a asociar a este manager
	glBindVertexArray(vao);


	//donde guardar el identificador
	//equivale a un entero sin signo : unsigned int numero entero
	//identificador de VBO de posiciones. aqui lo vamos a almacenar
	GLuint positionsVBO;
	//creamos un VBO y almacenamos el id en la variable positionsVBO
	// &: mandar variable como referencia 
	glGenBuffers(1, &positionsVBO);
	//le decimos a OpenGL que lo queremos utilizar como un atributo (GL_ARRAY_BUFFER)
	glBindBuffer(GL_ARRAY_BUFFER, positionsVBO);
	//asignamoslos datos al buffer y los mandamos a la tarjeta de video -> guardar una sola vez y leerlo muchas veces (GL_STATIC_DRA)
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * positions.size(), positions.data(), GL_STATIC_DRAW);
	//quiero activar el atributo con indice 0 en la tarjeta de video (un arreglo y el primero como un atributo)
	glEnableVertexAttribArray(0);
	//configuramos el atributo con indice 0 en la tarjeta de video (cada dos elementos hacen un atributo, son un float)
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	//desactivar el uso de VBO de positions
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	GLuint colorsVBO;
	glGenBuffers(1, &colorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, colorsVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * colors.size(), colors.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//ya no quiero utilizar el VAO, los VBOs ya no se asocian con este VAO
	glBindVertexArray(0);


}

void MainLoop()
{
	// Borramos el buffer de color y profundidad siempre al inicio de un nuevo frame.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// TODO: hacer el render
	//Paso 1: no se puede hacer aun
	//Paso 2: Activar un VAO
	glBindVertexArray(vao);
	
	//Paso 3: dibugamos

	glDrawArrays(GL_TRIANGLES, 0, 3);

	//Paso 4: desactivamos el VAO

	glBindVertexArray(0);

	//Paso 5: aun no se puede hacer


	// Intercambiar los buffers (el que se estaba rendereando con el que se estaba
	// mostrando).
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	// Inicializamos freeglut. 
	// Freeglut se encarga de generar y manejar ventanas.
	// Utilizamos freeglut para crear una ventana donde vamos a dibujar.
	glutInit(&argc, argv);
	// Tenemos que informar que queremos trabajar con el pipeline
	// clásico (OpenGL viejito).
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	// Freeglut nos permite configurar eventos que ocurren en la ventana.
	// Un evento que nos interesa es cuando alguien cierra la ventana.
	// En este caso, simplemente dejamos de renderear y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	// Configuramos el framebuffer. En este caso estamos solicitando un buffer
	// de color true color RGBA, un buffer de profundidad y un segundo buffer 
	// para rendererar (evitamos parpadeos al renderear).
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	// Solicitamos una ventana de 400x400 pixeles.
	glutInitWindowSize(400, 400);
	// Creamos y abrimos la ventana con un título personalizado.
	glutCreateWindow("Hello World OpenGL");
	// Asociar una función de render. Esta función se mandará a llamar para 
	// dibujar un frame.
	glutDisplayFunc(MainLoop);

	// Inicializamos GLEW. Esta librería se encarga de obtener el API
	// de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT.
	glewInit();

	// COnfigurar OpenGL. Este es el color por default del buffer de color
	// en el framebuffer.
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);

	//configurar la memoria que la aplicacion va a necesitar 
	Initialize();

	// Iniciamos la aplicacion gráfica. El main se pausará en estea línea
	// hasta que se cierre la ventana de OpenGL.
	glutMainLoop();

	return 0;
}