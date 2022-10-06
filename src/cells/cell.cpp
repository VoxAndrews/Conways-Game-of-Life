#include "cell.h"

Cell::Cell()
{
    unsigned numOfColumns = 500; 
    unsigned numOfRows = 500;

    time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()); //The time on the users system
    std::default_random_engine randomNumber(currentTime); //A random number, with the current time being used as the seed for said number

    //auto means the compiler will determine the best variable type from its initialiser
    auto generatedNumber = std::bind(std::uniform_int_distribution<>(0, 1), randomNumber); //Floors the random number so it fits within a range of 0 and `
    
    //std::cout << "Set Grid Width: ";
    //std::cin >> numOfRows;
    //std::cout << std::endl;

    //std::cout << "Set Grid Height: ";
    //std::cin >> numOfColumns;
    //std::cout << std::endl;
    
    std::vector<bool> tmpRow(numOfColumns, 0); //Creates a temporary vector of the length of rows
    std::vector<std::vector<bool>> tmpGrid(numOfRows, tmpRow); //Creates a temporary 2D vector to use later

    for (unsigned r = 0; r < numOfRows; r++) //Loops through all of the columns
    {
        for (unsigned c = 0; c < numOfColumns; c++) //Loops through all of the rows
        {
            tmpGrid[r][c] = generatedNumber(); //Sets a random number between 0 and 1 (False or True)
        }
    }

    currentGen = tmpGrid; //Sets the currentGen vector to be equal to the tmpGrid Vector
    nextGen = tmpGrid; //Sets the nextGen vector to be equal to the tmpGrid Vector (Will be overwritten when updating)
}

unsigned __int8 Cell::GetCurrentState(unsigned columnPosition, unsigned rowPosition)
{
    return currentGen[rowPosition][columnPosition];
}

void Cell::SetNextState()
{
    for (unsigned row = 1; row < currentGen.size() - 1; row++) //Loops through all of the columns
    {
        for (unsigned column = 1; column < currentGen[0].size() - 1; column++) //Loops through all of the rows
        {
            unsigned numOfNeighbours = 0; //The current number of neighbours surrounding a given cell
            
            //Loops through all of the neighbours surrounding the cell (Includes the Cell also)
            for (__int8 i = -1; i <= 1; i++)
            {
                for (__int8 j = -1; j <= 1; j++)
                {
                    numOfNeighbours += currentGen[row + i][column + j]; //Adds up the states of the neighbours surrounding the cell
                }
            }

            numOfNeighbours -= currentGen[row][column]; //Removes the cell state from the neighbour count, so it is not included if it is 1

            if ((currentGen[row][column] == 1) && (numOfNeighbours < 2)) //Alive & Less than two neighbours = Dead
            {
                nextGen[row][column] = false;
            }
            else 
                if ((currentGen[row][column] == 1) && (numOfNeighbours > 3)) //Alive & More than three neighbours = Dead
                {
                    nextGen[row][column] = false;
                }
                else 
                    if ((currentGen[row][column] == 0) && (numOfNeighbours == 3)) //Dead & Exactly three neighbours = Born/Alive
                    {
                        nextGen[row][column] = true;
                    }
                    else 
                        nextGen[row][column] = currentGen[row][column]; //Stays the same
        }
    }

    currentGen = nextGen; //Set the current generation to be the next generation
}