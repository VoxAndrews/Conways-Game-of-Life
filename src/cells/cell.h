#pragma once

#include <vector>
#include <random>
#include <chrono>
#include <functional>
#include <iostream>

/**
* @class Cell
* @brief Handles the functionality of the Cells within the Game of Life
*
* @author Darcy Lyndon Cukrov Wilson
* @version 01
* @date 01/10/2022
*/

class Cell
{
public:
		/**
		* @brief Cell Constructor
		*
		* This is a default construct for the Cell Class, which takes input variables
		*/
	Cell();
		/**
		* @brief Get Current State
		*
		* This function gets the state of the current cell at a specified grid point
		* 
		* @param unsigned columnPosition - The column position of the 2D array to be checked
		* @param unsigned rowPosition - The row position of the 2D array to be checked
		* 
		* @return bool
		*/
	unsigned __int8 GetCurrentState(unsigned columnPosition, unsigned rowPosition);
		/**
		* @brief Set Next State
		*
		* This function sets the state of the next generation of cells within the 2D Array each update cycle
		* 
		* @return void
		*/
	void SetNextState();
private:
		/**
		* @param std::vector<std::vector<bool>> currentGen - A 2D Array of unsigned integers (Current Cell generation)
		*/
	std::vector<std::vector<bool>> currentGen;
		/**
		* @param std::vector<std::vector<bool>> nextGen - A 2D Array of unsigned integers (The following Cell generation)
		*/
	std::vector<std::vector<bool>> nextGen;
};