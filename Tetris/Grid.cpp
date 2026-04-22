#include "Grid.h"
#include <iostream>
#include "colors.h"

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

bool Grid::IsCellOutSide(int row, int column)
{
	if (row >= 0 && row < NumRows && column >= 0 && column < NumCols)
	{
		return false;
	}
	return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
	if (grid[row][column] == 0)
	{
		return true;
	}
	return false;
}


