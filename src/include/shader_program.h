#ifndef _SHADER_PROGRAM_H_
#define _SHADER_PROGRAM_H_

#define MAX_SHADER_BYTES 100000

class ShaderProgram
{
protected:
	bool _initialized = false;
	unsigned int _shaderProgramObject = 0;
	void readShaderSourceFile(const char* filePath, char dest[]);
public:
	void createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
	void createShaderProgramFromFile(const char* vertexShaderPath, const char* fragmentShaderPath);
	void use();
};

#endif // !_SHADER_PROGRAM_H_

