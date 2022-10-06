#include "cell.h"

Cell::Cell(unsigned numOfColumns, unsigned numOfRows)
{
    std::vector<unsigned __int8> tmpRow(numOfColumns, 0); //Creates a temporary vector of the length of rows
    std::vector<std::vector<unsigned __int8>> tmpGrid(numOfRows, tmpRow); //Creates a temporary 2D vector to use later

    for (unsigned r = 0; r < numOfRows; r++) //Loops through all of the columns
    {
        for (unsigned c = 0; c < numOfColumns; c++) //Loops through all of the rows
        {
            tmpGrid[r][c] = rand() % 2; //Sets a random number between 0 and 1
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
    for (unsigned row = 0; row < currentGen.size(); row++) //Loops through all of the rows
    {
        for (unsigned column = 0; column < currentGen[0].size(); column++) //Loops through all of the columns
        {
            unsigned numOfNeighbours = 0; //The current number of neighbours surrounding a given cell
            
            //Loops through all of the neighbours surrounding the cell (Includes the Cell also)
            for (unsigned i = -1; i <= 1; i++)
            {
                for (unsigned j = -1; j <= 1; j++)
                {
                    numOfNeighbours += currentGen[row + i][column + j]; //Adds up the states of the neighbours surrounding the cell
                }
            }

            numOfNeighbours -= currentGen[row][column]; //Removes the cell state from the neighbour count, so it is not included if it is 1

            if ((currentGen[row][column] == 1) && (numOfNeighbours < 2)) //Alive & Less than two neighbours = Dead
            {
                nextGen[row][column] = 0;
            }
            else 
                if ((currentGen[row][column] == 1) && (numOfNeighbours > 3)) //Alive & More than three neighbours = Dead
                {
                    nextGen[row][column] = 0;
                }
                else 
                    if ((currentGen[row][column] == 0) && (numOfNeighbours == 3)) //Dead & Exactly three neighbours = Born/Alive
                    {
                        nextGen[row][column] = 1;
                    }
                    else 
                        nextGen[row][column] = currentGen[row][column]; //Stays the same
        }
    }

    currentGen = nextGen; //Set the current generation to be the next generation
}