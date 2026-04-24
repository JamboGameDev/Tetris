#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
	double currentTime = GetTime();
	if (currentTime - lastUpdateTime >= interval)
	{
		lastUpdateTime = currentTime;
		return true;
	}
	return false;
}

int main()
{
	InitWindow(500, 620, "RaylibTetris");
	SetTargetFPS(60);

	Font font = GetFontDefault();

	Game game = Game();

	while(WindowShouldClose() == false)
	{
		game.HandleInput();

		if (EventTriggered(0.2))
		{
			game.MoveBlockDown();
		}

		BeginDrawing();
		ClearBackground(darkBlue);
		DrawText("Score", 365, 15, 38, WHITE);
		DrawText("Next", 370, 175, 38, WHITE);

		if (game.gameOver)
		{
			DrawText("GameOver", 320, 450, 38, WHITE);
		}
		
		DrawRectangleRounded(Rectangle{ 320, 55, 170, 60 }, 0.3f, 6, lightBlue);

		char scoreText[10];
		sprintf_s(scoreText, sizeof(scoreText), "%d", game.score); // %d формат для целого числа (int)
		Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); //используется для измерения размера текста, позиционирование текста

		
		DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65}, 38, 2, WHITE);
		DrawRectangleRounded(Rectangle{ 320, 215, 170, 180 }, 0.3f, 6, lightBlue);
		game.Draw();
		EndDrawing();
	}

	CloseWindow();
}