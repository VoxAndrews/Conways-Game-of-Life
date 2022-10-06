#include "window.h"

Window::Window(const std::string& inputTitle)
{
	//Set parameters
	this->glfwWindow = nullptr;

	this->windowWidth = 600;
	this->windowHeight = 600;
	this->windowTitle = inputTitle;

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
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); //Sets GLFW to run in compatability mode
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); //Stops the window from being resized

	glfwWindow = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), NULL, NULL); //Creates a window

	if (!glfwWindow) //If the window hasn't been initialized
	{
		std::cout << "ERROR: Window unable to be initialized" << std::endl;

		return; //Return out of the function
	}

	glfwMakeContextCurrent(glfwWindow); //Makes the window the current OpenGL context

	if (!gladLoadGL(glfwGetProcAddress)) //Checks to see if GLAD has loaded
	{
		std::cout << "ERROR: GLAD unable to be initialized" << std::endl;

		return; //Return out of the function
	}

	WindowRunning(); //Moves into running the window
}

void Window::WindowRunning()
{
	//AWAKE STATE
	Cell CellSimulation; //Sets the size of the simulation to be the size of the window
	Shader BasicShader("SimpleShaderVS.glsl", "SimpleShaderPS.glsl");

	glViewport(0, 0, windowWidth, windowHeight); //Sets the viewport position and size

	//UPDATE LOOP
	while(!glfwWindowShouldClose(glfwWindow)) //Keeps running until the Window Close flag has been reached
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Sets the background colour to black
		glClear(GL_COLOR_BUFFER_BIT); //Clears the screen buffer

		CellSimulation.SetNextState();

		glfwSwapBuffers(glfwWindow); //Swaps the front and back buffers

		glfwPollEvents(); //Polls for Keyboard/Mouse events
	}

	//END STATE
}