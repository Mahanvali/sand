#include "raylib.h"
#include "grid.hpp"

const int screenWidth = 800;
const int screenHeight = 800;
const int sizeCell = 3;

Grid grid(screenWidth, screenHeight, sizeCell);
Color backgroundColor = {30, 30, 30, 255};

void HandleInput();

int main(){
    InitWindow(screenWidth, screenHeight, "sand simulation");
    SetTargetFPS(120);
    while(!WindowShouldClose()){
        HandleInput();
        grid.UpdateSand();
        BeginDrawing();
            ClearBackground(backgroundColor);
            grid.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void HandleInput()
{
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.y / sizeCell;
        int column = mousePosition.x / sizeCell;
        // Set the value of cells in a circle area around the clicked cell
        int radius = 6;
        for (int i = -radius; i <= radius; i++) {
            for (int j = -radius; j <= radius; j++) {
                //Equation for circle in 2D grid
               if (i * i + j * j <= radius * radius && grid.isWithinBounds(row + i, column + j)) {
                    grid.SetValueOfCells(row + i, column + j, 1);
               }
            }
        }
    }
}
