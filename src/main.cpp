#include<glad/glad.h>
#include<glfw3.h>
#include<iostream>
#include<cstring>
#include"model.h"
#include"shader.h"
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
	//Set clear color and clear screen
	glClearColor(0.2f, 0.2f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void renderObject(StaticModel &model, Shader &shader)
{
	float timeValue = glfwGetTime();
	float sinValue = sin(timeValue);
	float cosValue = cos(timeValue);

	//Use given shader program
	shader.use(); 

	//Inject essential data to shader program
	shader.setFloat("uni_time", timeValue);
	shader.setFloat("uni_sin", sinValue);
	shader.setFloat("uni_cos", cosValue);

	//Draw target model
	model.render(); 
}

int main()
{
	GLFWwindow* glfwWindow = initGlfwEnv();
	if (glfwWindow == NULL)
		return -1;

	//Prepare model and shader
	StaticModel model;
	model.setVerticesData(vertices, verticesSize);
	model.setIndicesData(indices, indicesSize);

	string rootPath = shaderSourcePath;
	string vertexPath = rootPath + vertexShaderName;
	string fragmentPath = rootPath + fragmentShaderName;
	Shader shader(vertexPath.c_str(), fragmentPath.c_str());

	while (!glfwWindowShouldClose(glfwWindow))
	{
		processInput(glfwWindow);

		renderBackground();
		renderObject(model, shader);

		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}