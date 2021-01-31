#include<glad/glad.h>
#include<glfw3.h>
#include<iostream>
#include<cstring>
#include"model.h"
#include"shader_program.h"
#include"consts.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

GLFWwindow* initGlfwEnv()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return NULL;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return NULL;
	}

	glViewport(0, 0, 800, 600);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	return window;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


void renderBackground()
{
	glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void renderObject(StaticModel model, ShaderProgram shaderProgram)
{
	shaderProgram.use(); //Give shading program
	model.render(); //Give shading model data
}

int main()
{
	GLFWwindow* glfwWindow = initGlfwEnv();
	if (glfwWindow == NULL)
		return -1;

	//Prepare model data and shading program
	StaticModel staticModel;
	staticModel.setVerticesData(vertices, verticesSize);
	staticModel.setIndicesData(indices, indicesSize);

	ShaderProgram shaderProgram;
	string rootPath = shaderSourcePath;
	string vertexPath = rootPath + vertexShaderName;
	string fragmentPath = rootPath + fragmentShaderName;
	shaderProgram.createShaderProgramFromFile(vertexPath.c_str(), fragmentPath.c_str());

	while (!glfwWindowShouldClose(glfwWindow))
	{
		processInput(glfwWindow);

		renderBackground();
		renderObject(staticModel, shaderProgram);

		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}