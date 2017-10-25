#include "Shader.h"
#include "InputFile.h"
#include <iostream>

Shader::Shader()
{
	_shaderHandle = 0;

}

Shader::~Shader()
{
	glDeleteShader(_shaderHandle);
}

void Shader::CreateShader(std::string path, GLenum type)
{
	InputFile ifile;

	ifile.Read(path);
	//Obtenemos los contenidos leidos y los almacenamos en 
	//un string vertexSource
	std::string vertexSource = ifile.GetContents();
	//hacemos una conversion del dato (cast)
	//porque no podemos mandar strings a openGL,
	//se le manda un const GLchar*
	const GLchar *vertexSource_c =
		(const GLchar*)vertexSource.c_str();
	//creamos un shader tipo Vertex Shader y guardamos su id 
	//en la variable vertexShaderHandle

	_shaderHandle = glCreateShader(type);
	//Le mandamos el codigo fuente que leimos previamente en OpenGL
	glShaderSource(_shaderHandle, 1, &vertexSource_c, nullptr);
	//le pedimos que lo compile.
	glCompileShader(_shaderHandle);


	GLint vertexShaderCompileSuccess = 0;
	glGetShaderiv(_shaderHandle, GL_COMPILE_STATUS, &vertexShaderCompileSuccess);
	if (vertexShaderCompileSuccess == GL_FALSE);
	{
		GLint logLenght = 0;
		glGetShaderiv(_shaderHandle, GL_INFO_LOG_LENGTH, &logLenght);
		if (logLenght > 0)
		{
			std::vector<GLchar> compileLog(logLenght);
			glGetShaderInfoLog(_shaderHandle, logLenght, &logLenght, &compileLog[0]);

			for (int i = 0; i < logLenght; i++)
			{
				std::cout << compileLog[i];
			}
			std::cout << std::endl;
		}
		std::cout << "Shader" <<path<< " did not compiled" << std::endl;
	}
}

GLuint Shader::GetHandle()
{
	return _shaderHandle;
}

