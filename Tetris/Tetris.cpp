#include "raylib.h"
#include "Grid.h"


int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(600, 900, "RaylibTetris");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	while(WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(DarkBlue);
		grid.Draw();
		EndDrawing();
	}

	CloseWindow();
}