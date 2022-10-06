#pragma once

#include <glad/gl.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/**
* @class Shader
* @brief Handles the loading of shaders and updating their parameters
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 06/10/2022
*/

class Shader
{
public:
		/**
		* @brief Shader Constructor
		*
		* One of the constructors for the Shader class, takes in a vertex and fragment shader path
		*
		* @param const char* vertexShaderPath - The file path to the vertex shader
		* @param const char* fragmentShaderPath - The file path to the fragment shader
		*/
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
		/**
		* @brief Shader Constructor
		*
		* One of the constructors for the Shader class, takes in a vertex, fragment and compute shader path
		*
		* @param const char* vertexShaderPath - The file path to the vertex shader
		* @param const char* fragmentShaderPath - The file path to the fragment shader
		* @param const char* computeShaderPath - The file path to the compute shader
		*/
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath, const char* computeShaderPath);
		/**
		* @brief Activate Shader
		*
		* Uses the shader that has been loaded into the class
		*
		* @return void
		*/
	void ActivateShader();
		/**
		* @brief Set Boolean Value
		*
		* Sets a given uniform boolean value within the shader
		* 
		* @param const std::string& variableName - The name of the uniform variable to be changed
		* @param float newValue - The new value the variable will be changed to
		*
		* @return void
		*/
    void SetBooleanVariable(const std::string& variableName, bool newValue) const;
		/**
		* @brief Set Integer Value
		*
		* Sets a given uniform Integer value within the shader
		* 
		* @param const std::string& variableName - The name of the uniform variable to be changed
		* @param float newValue - The new value the variable will be changed to
		*
		* @return void
		*/
    void SetIntegerVariable(const std::string& variableName, int newValue) const;
		/**
		* @brief Set Float Value
		*
		* Sets a given uniform float value within the shader
		* 
		* @param const std::string& variableName - The name of the uniform variable to be changed
		* @param float newValue - The new value the variable will be changed to
		*
		* @return void
		*/
    void SetFloatVariable(const std::string& variableName, float newValue) const;
		/**
		* @param unsigned shaderID - The ID number of the shader
		*/
    unsigned shaderID;
private:
};