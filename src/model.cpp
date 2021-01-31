#include<glad/glad.h>
#include<glfw3.h>
#include<iostream>
#include"model.h"

using namespace std;

void StaticModel::_setCurrentContext()
{
	if (!_initialized)
	{
		glGenVertexArrays(1, &_vao);
		_initialized = true;
	}
	glBindVertexArray(_vao);
}

void StaticModel::setVerticesData(const float vertices[], const unsigned int verticesSize)
{
	_setCurrentContext();
	//Create VBO
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	//Bind to Context
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Set context content
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void StaticModel::setIndicesData(const unsigned int indices[], const unsigned int indicesSize)
{
	_setCurrentContext();
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
	_indicesCount = indicesSize / sizeof(unsigned int);
}

void StaticModel::render()
{
	glBindVertexArray(_vao);
	glDrawElements(GL_TRIANGLES, _indicesCount, GL_UNSIGNED_INT, 0);
}