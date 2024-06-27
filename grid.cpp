#include "grid.hpp"
#include "raylib.h"

void Grid::Draw(){
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            int r = 0 + row + 20;
            int g = 10;
            int b = 100;
            if(r > 255 || b > 255){
                r = 0;
                g = 10;
                b = 100;
            }
            unsigned char red = static_cast<unsigned char>(r);
            unsigned char green = static_cast<unsigned char>(g);
            unsigned char blue = static_cast<unsigned char>(b);

            // If cell is alive set the color to the calculated gradient color, else set the color to a light gray.};
            //If cell is alive set the color to green, else set the color to a light gray.
            Color colorsOfCells = cells[row][column] ? Color{red, 10, blue, 255} : Color{55, 55, 55, 255};
            //Draw the squares/cells, make the cells a bit smaller than cellSize so it doesn't cover up the entire screen giving us "lines" 
            //because we calulated the cellsize in away that it covers the entire screen, so instead of just drawing lines we use this method instead.
            //made it smaller by subtracting by 1
            DrawRectangle(column * cellsize, row * cellsize, cellsize - 1, cellsize - 1, colorsOfCells);
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
