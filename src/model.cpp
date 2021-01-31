#include<glad/glad.h>
#include<glfw3.h>
#include<iostream>
#include"model.h"
#include"consts.h"

using namespace std;

void StaticModel::setActive()
{
	glBindVertexArray(ID);
}

StaticModel::StaticModel()
{
	//Create a VAO id
	glGenVertexArrays(1, &ID);
}

void StaticModel::setVerticesData(const vertex vertices[], const unsigned int verticesSize)
{
	setActive();
	//Create VBO
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	//Bind to Context
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//Set context content
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)sizeof(position));
	glEnableVertexAttribArray(1);
}

void StaticModel::setIndicesData(const unsigned int indices[], const unsigned int indicesSize)
{
	setActive();
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesSize, indices, GL_STATIC_DRAW);
	_indicesCount = indicesSize / sizeof(unsigned int);
}

void StaticModel::render()
{
	glBindVertexArray(ID);
	glDrawElements(GL_TRIANGLES, _indicesCount, GL_UNSIGNED_INT, 0);
}