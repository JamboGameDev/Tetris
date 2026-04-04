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

	int grid[20][20];

private:
	std::vector<Color> GetCellColors();
	int NumRows;
	int NumCols;
	int CellSize;
	std::vector<Color> colors;

};