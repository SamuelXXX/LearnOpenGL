#ifndef _MODEL_H_
#define _MODEL_H_

class StaticModel
{
protected:
	bool _initialized = false;
	unsigned int _vao = 0;
	unsigned int _indicesCount = 0;
	void _setCurrentContext();
public:
	
	void setVerticesData(const float vertices[], const unsigned int verticesSize);
	void setIndicesData(const unsigned int indices[], const unsigned int indicesSize);
	void render();
};

#endif // !_MODEL_H_

