#pragma once
#include <vector>

// Define a class named Grid.
class Grid{
    public:
        // This is the constructor for the Grid class. It takes three parameters: width, height, and cellsize.
        // The constructor initializes the rows, columns, cellsize, and cells members.
        Grid(int width, int height, int cellsize): 
            rows(height/cellsize), //The rows are calculated by dividing the height by the cell size.
            columns(width/cellsize), //The columns are calculated by dividign the width by the cell size.
            cellsize(cellsize), //cellsize is cellsize
            cells(rows, std::vector<int>(columns, 0)) {}; // The cells member is a 2D vector (a vector of vectors) that is initialized to have a size of rows x columns, with all elements set to 0.
        void Draw();
        void SetValueOfCells(int row, int column, int value);
        void UpdateSand();
        //Check if the cell is within bounds
        bool isWithinBounds(int row, int column);
    private:
        // rows and columns store the number of rows and columns in the grid.
        int rows, columns;
        // cellsize stores the size of each cell in the grid.
        int cellsize;
        // cells is a 2D vector that represents the grid. Each element in cells corresponds to a cell in the grid.
        std::vector<std::vector<int>> cells;
};