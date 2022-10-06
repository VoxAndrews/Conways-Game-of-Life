#version 460 core

layout (location = 0) in vec3 inputPos; //The current position of a vertex

void main() 
{
	gl_Position = vec4(inputPos, 1.0f); //Setting the position of the vertex
}