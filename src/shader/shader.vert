#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;

out vec4 vertexColor;
uniform float uni_sin;

void main()
{
	float ns=(uni_sin + 1.0f)/2.0f;
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
	
	vertexColor = vec4(ns,ns,ns,1);
}