#include "ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
	_programHandle = 0;
	
}

ShaderProgram::~ShaderProgram()
{
	DeleteProgram();

}

void ShaderProgram::CreateProgram()
{
	_programHandle = glCreateProgram();

}

void ShaderProgram::AttatchShader(std::string path, GLenum type)
{
	// Create and add the shaders to a list
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));
}

void ShaderProgram::LinkProgram()
{
	for (int i = 0; i < _attachedShaders.size(); i++)
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
	glLinkProgram(_programHandle);
	DeleteAndDetachShaders();

}

void ShaderProgram::Activate()
{
	glUseProgram(_programHandle);
}

void ShaderProgram::Deactivate()
{
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name)
{
	glBindAttribLocation(_programHandle, locationIndex,  name.c_str());
}

void ShaderProgram::SetUniformf(std::string name, float value)
{

}

void ShaderProgram::SetUniformf(std::string name, float x, float y)
{
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z)
{
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w)
{
}

void ShaderProgram::DeleteAndDetachShaders()
{
	for (int i = 0; i < _attachedShaders.size(); i++)
		glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());
	_attachedShaders.clear();


}

void ShaderProgram::DeleteProgram()
{
	DeleteAndDetachShaders()
		glDeleteProgram(_programHandle);


}
