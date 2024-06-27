#include "grid.hpp"
#include "raylib.h"

void Grid::Draw(){
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            int r = row + 20;
            r = (r > 255) ? 255 : r; // Ensure r does not exceed 255
            int g = 30;
            int b = 90;
            unsigned char red = static_cast<unsigned char>(r);
            unsigned char green = static_cast<unsigned char>(g);
            unsigned char blue = static_cast<unsigned char>(b);

            //Set the color of the alive cell
            Color colorsOfCells = cells[row][column] ? Color{red, green, blue, 255} : Color{55, 55, 55, 255};
            //Draw the squares/cells
            DrawRectangle(column * cellsize, row * cellsize, cellsize, cellsize, colorsOfCells);
        }
    }
}

bool Grid::isWithinBounds(int row, int column)
{
    //Checks if the values are within the grid
    if (row >= 0 && row < rows && column >= 0 && column < columns){
        return true;
    }
    return false;
}

void Grid::SetValueOfCells(int row, int column, int value)
{
    //Check if the values are within the grid
    if (isWithinBounds(row, column)){
        //If they are within the grid, set the value
        cells[row][column] = value;
    }
}

void Grid::UpdateSand()
{
    // Loop over each row
    for (int row = rows - 1; row >= 0; row--) {
        //Loop over each column
        for (int column = 0; column < columns; column++) {
            // If the current cell contains sand
            if (cells[row][column] == 1) {
                // If the cell below is empty and within bounds
                if (row < rows - 1 && cells[row + 1][column] == 0) {
                    // Move the sand down
                    cells[row][column] = 0;
                    cells[row + 1][column] = 1;
                }
                // If the cell below and to the right is empty and within bounds
                else if (row < rows - 1 && column < columns - 1 && cells[row + 1][column + 1] == 0) {
                    // Move the sand down
                    cells[row][column] = 0;
                    //Move the sand to the right
                    cells[row + 1][column + 1] = 1;
                }
                // If the cell below and to the left is empty and within bounds
                else if (row < rows - 1 && column > 0 && cells[row + 1][column - 1] == 0) {
                    // Move the sand down
                    cells[row][column] = 0;
                    //Move the sand to the left
                    cells[row + 1][column - 1] = 1;
                }
            }
        }
    }
}
