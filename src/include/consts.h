#ifndef _CONSTS_H_
#define _CONSTS_H_

struct position {
	float x;
	float y;
	float z;
};

struct color {
	float r;
	float g;
	float b;
	float a;
};

struct vertex {
	position pos;
	color col;
};

extern vertex vertices[];
extern unsigned int verticesSize;

extern unsigned int indices[];
extern unsigned int indicesSize;

extern const char* shaderSourcePath;
extern const char* fragmentShaderName;
extern const char* vertexShaderName;

#endif // !_MODEL_H_
