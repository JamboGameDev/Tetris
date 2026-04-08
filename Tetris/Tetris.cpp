#include "raylib.h"
#include "Grid.h"
#include "blocks.cpp"


int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "RaylibTetris");
	SetTargetFPS(60);

	Grid grid = Grid();
	grid.Print();

	TBlock block = TBlock();
	block.Move(4, 3);

	while(WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(DarkBlue);
		grid.Draw();
		block.Draw();
		EndDrawing();
	}

	CloseWindow();
}