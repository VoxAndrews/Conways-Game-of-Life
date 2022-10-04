#pragma once

#define GLFW_INCLUDE_NONE //Stops the inclusion of development environment header

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <string>
#include <iostream>

class Window
{
public:
	Window(const std::string& inputTitle, int inputWidth, int inputHeight);

	~Window();

	void InitializeWindow();

	void Window::WindowRunning();
private:
	GLFWwindow* glfwWindow;

	std::string windowTitle;

	int windowWidth;
	int windowHeight;
};