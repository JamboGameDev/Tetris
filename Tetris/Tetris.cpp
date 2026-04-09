#include "raylib.h"
#include "game.h"


int main()
{
	Color DarkBlue = { 44, 44, 127, 255 };
	InitWindow(300, 600, "RaylibTetris");
	SetTargetFPS(60);

	Game game = Game();

	while(WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(DarkBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}