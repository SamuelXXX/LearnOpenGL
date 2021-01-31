float vertices[] = {
	-0.5f,-0.5f,0.0f,
	0.5f,-0.5f,0.0f,
	0.0f,0.5f,0.0f,
	1.0f,1.0f,0.0f,
	-1.0f,0.0f,0.0f
};
unsigned int verticesSize = sizeof(vertices);

unsigned int indices[] = {
	0,1,2,
	1,2,3,
	0,3,4
};
unsigned int indicesSize = sizeof(indices);

const char* shaderSourcePath = R"(G:\_Projects\LearnOpenGL\src\shader\)";
const char* fragmentShaderName = "fragment.shader";
const char* vertexShaderName = "vertex.shader";