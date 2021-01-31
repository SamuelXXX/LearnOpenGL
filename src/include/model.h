#ifndef _MODEL_H_
#define _MODEL_H_

#include"consts.h"

class StaticModel
{
protected:
	bool _initialized = false;
	unsigned int ID = 0;
	unsigned int _indicesCount = 0;
	void setActive();
public:
	StaticModel();
	void setVerticesData(const vertex vertices[], const unsigned int verticesSize);
	void setIndicesData(const unsigned int indices[], const unsigned int indicesSize);
	void render();
};

#endif // !_MODEL_H_

