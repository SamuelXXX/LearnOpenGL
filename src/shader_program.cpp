#include<glad/glad.h>
#include<glfw3.h>
#include<iostream>
#include<fstream>
#include"model.h"
#include"shader_program.h"

using namespace std;

char vertexShaderSource[MAX_SHADER_BYTES];
char fragmentShaderSource[MAX_SHADER_BYTES];

void ShaderProgram::createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	if (_initialized)	
		return;
	
	//Create vertex shader
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	//Create fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//Create shader program
	_shaderProgramObject = glCreateProgram();
	glAttachShader(_shaderProgramObject, vertexShader);
	glAttachShader(_shaderProgramObject, fragmentShader);
	glLinkProgram(_shaderProgramObject);

	//Dispose shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	_initialized = true;
}

void ShaderProgram::readShaderSourceFile(const char* filePath, char dest[])
{
	ifstream infile;
	infile.open(filePath);
	const string text((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));
	strcpy(dest, text.c_str());
	infile.close();
}

void ShaderProgram::createShaderProgramFromFile(const char* vertexShaderPath, const char* fragmentShaderPath)
{
	readShaderSourceFile(vertexShaderPath, vertexShaderSource);
	readShaderSourceFile(fragmentShaderPath, fragmentShaderSource);

	createShaderProgram(vertexShaderSource, fragmentShaderSource);
}

void ShaderProgram::use()
{
	glUseProgram(_shaderProgramObject);
}