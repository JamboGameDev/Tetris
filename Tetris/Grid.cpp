#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	NumRows = 20;
	NumCols = 10;
	CellSize = 30;
	Initialize();
	colors = GetCellColors(); 
	// присваиваем вектору colors результат функции
	// здесь копируется список цветов в colors
}

void Grid::Initialize()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			grid[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			std::cout << grid[row][column] << " ";
		}
		std::cout << std::endl;
	}
}

std::vector<Color> Grid::GetCellColors() // функция создаёт и ВОЗВРАЩАЕТ std::vector<Color>
{
	Color darkGrey = { 26, 31, 40, 255 };
	Color green = { 47, 230, 23, 255 };
	Color red = { 232, 18, 18, 255 };
	Color orange = { 226, 116, 17, 255 };
	Color yellow = { 237, 234, 4, 255 };
	Color purple = { 166, 0, 247, 255 };
	Color cyan = { 21, 204, 209, 255 };
	Color blue = { 13, 64, 216, 255 };

	return { darkGrey, green, red, orange, yellow, purple, cyan, blue };
	// создаётся временный vector<Color> и заполняется этими значениями
	// порядок важен: индекс = номер цвета
}

void Grid::Draw()
{
	for (int row = 0; row < NumRows; row++)
	{
		for (int column = 0; column < NumCols; column++)
		{
			int CellValue = grid[row][column];
			DrawRectangle(column * CellSize, row * CellSize, CellSize - 1, CellSize - 1, colors[CellValue]);
			// доступ к элементу вектора по индексу
				// CellValue используется как индекс:
				// 0 → darkGrey
				// 1 → green
				// 2 → red
				// и т.д.
		}
	}
}


