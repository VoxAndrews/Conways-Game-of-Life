#include "window.h"

Window::Window(const std::string& inputTitle)
{
	//Set parameters
	this->glfwWindow = nullptr;

	this->windowTitle = inputTitle;

	std::cout << "Set Grid/Window Width: ";
	std::cin >> windowWidth;
	std::cout << std::endl;

	std::cout << "Set Grid/Window Height: ";
	std::cin >> windowHeight;
	std::cout << std::endl;

	InitialiseWindow(); //Initialize Window/GLFW
}

Window::~Window()
{
	glfwDestroyWindow(glfwWindow); //Destroys the window & context
	
	glfwTerminate(); //Terminate GLFW
}

void Window::InitialiseWindow()
{
	glfwInit(); //Attempts to initialize GLFW
	
	if (!glfwInit()) //If GLFW hasn't been initialized
	{
		std::cout << "ERROR: GLFW unable to be initialized" << std::endl;
		
		return; //Return out of the function
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); //Sets the maximum OpenGL version needed for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2); //Sets the minimum OpenGL version needed for GLFW

	glfwWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL); //Creates a window

	if (!glfwWindow) //If the window hasn't been initialized
	{
		std::cout << "ERROR: Window unable to be initialized" << std::endl;

		return; //Return out of the function
	}

	glfwMakeContextCurrent(glfwWindow); //Makes the window the current OpenGL context

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) //Checks to see if GLAD has loaded
	{
		std::cout << "ERROR: GLAD unable to be initialized" << std::endl;

		return; //Return out of the function
	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Sets the background colour to black

	WindowRunning(); //Moves into running the window
}

void Window::WindowRunning()
{
	//AWAKE STATE
	Cell CellSimulation(windowHeight, windowWidth); //Sets the size of the simulation to be the size of the window

	//UPDATE LOOP
	while(!glfwWindowShouldClose(glfwWindow)) //Keeps running until the Window Close flag has been reached
	{
		glViewport(0, 0, windowWidth, windowHeight); //Sets the viewport position and size
		
		glClear(GL_COLOR_BUFFER_BIT); //Clears the screen buffer

		glfwSwapBuffers(glfwWindow); //Swaps the front and back buffers
	}

	//END STATE

	glfwDestroyWindow(glfwWindow); //Destroys the window & context
	glfwTerminate(); //Terminate GLFW
}