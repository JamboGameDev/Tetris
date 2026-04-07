#pragma once
#include <vector>
#include "raylib.h"


class Grid
{
public:
	Grid();
	void Initialize();
	void Print();
	void Draw();

	int grid[20][10];

private:
	std::vector<Color> GetCellColors(); // функция возвращает ВЕКТОР (список) цветов
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> colors; // вектор, который хранит все цвета клеток (динамический массив Color)

};