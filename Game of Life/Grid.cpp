#include "Grid.h"


Grid::Grid(int x, int y, bool* seed)
{
	length = x;
	height = y;
	grid.reserve(length*height);
	for (int count = 0; count < (x*y); count++)
	{
		grid[count].setState(seed[count]);
	}
}


Grid::~Grid()
{
}


void Grid::print()
{
	for (int i = 0; i < length; i + length)
	{
		for (int j = 0; j < height; j++)
		{
			if (grid[i + j].getState)
			{
				std::cout << "# ";
			}
			else
				std::cout << ". ";
		}
		std::cout << "\n";
	}
}

void Grid::iterate(int n)
{
	for (int count = 0; count < n; count++)
	{
		for (int i = 0; i < length; i + length)
		{
			for (int j = 0; j < height; j++)
			{
				grid[i + j].evolve();
			}
		}
	}
}