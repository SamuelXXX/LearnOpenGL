#ifndef _SHADER_H_
#define _SHADER_H_

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
protected:
	unsigned int ID = 0;
public:
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	void use();
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setVector2(const std::string& name, float x, float y) const;
	void setVector3(const std::string& name, float x, float y,float z) const;
	void setVector4(const std::string& name, float x, float y, float z, float w) const;

};

#endif // !_SHADER_PROGRAM_H_

