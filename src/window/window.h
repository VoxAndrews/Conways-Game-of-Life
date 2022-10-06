#pragma once

#define GLFW_INCLUDE_NONE //Stops the inclusion of development environment header

#include <GLFW/glfw3.h>
#include <glad/gl.h>
#include <string>
#include <iostream>

#include "cells/cell.h"

/**
* @class Window
* @brief Initialises and manages the GLFW Window for the project
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 01/10/2022
*/

class Window
{
public:
		/**
		* @brief Window Constructor
		*
		* This is a default construct for the Window Class, which takes input variables
		* 
		* @param const std::string& inputTitle - The name of the window
		*/
	Window(const std::string& inputTitle);
		/**
		* @brief Window Destructor
		*
		* This is a default destructor for the Window Class
		*/
	~Window();
		/**
		* @brief Initialise Window
		*
		* This function initialises the GLFW context and the window the the project works from
		* 
		* @return void
		*/
	void InitialiseWindow();
		/**
		* @brief Window Running
		*
		* This function runs in a loop until the program is told to stop. It handles function calls for the different functions of the program
		* 
		* @return void
		*/
	void Window::WindowRunning();
private:
		/**
		* @param GLFWwindow* glfwWindow - A pointer to a GLFW window, used for the currently running window to update parameters
		*/
	GLFWwindow* glfwWindow;
		/**
		* @param std::string windowTitle - A string which contains the title of the window
		*/
	std::string windowTitle;
		/**
		* @param int windowWidth - The current width, in pixels, of the GLFW window
		*/
	int windowWidth;
		/**
		* @param int windowHeight - The current height, in pixels, of the GLFW window
		*/
	int windowHeight;
};