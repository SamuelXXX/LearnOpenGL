#include"consts.h"

vertex vertices[] = {
	{
		{-0.5f,-0.5f,0.0f},
		{1.0f,0.0f,0.0f,1.0f}
	},//vertex 1
	{
		{0.5f,-0.5f,0.0f},
		{0.0f,0.0f,1.0f,1.0f}
	},//vertex 2
	{
		{0.0f,0.5f,0.0f},
		{0.0f,1.0f,0.0f,1.0f},
	}//vertex 3
};
unsigned int verticesSize = sizeof(vertices);


unsigned int indices[] = {
	0,1,2
};
unsigned int indicesSize = sizeof(indices);

const char* shaderSourcePath = R"(G:\_Projects\LearnOpenGL\src\shader\)";
const char* fragmentShaderName = "shader.frag";
const char* vertexShaderName = "shader.vert";