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

int Grid::edgecasehelp(int x, int y)
{
	//1=topedge,2=Rightedge,3=toprightcorner,4=leftedge,5=topleftcorner,6=bottomedge,8=bottomrightcorner,10=bottomleftcorner
	int total=0;
	if ((x + y) < length) //Top edge
	{
		total+=1;
	}
	else if ((x + y + 1) % length == 0) //Right edge
	{
		total+=2;
	}
	else if ((x + y) % length == 0) //Left Edge
		total += 4;
	else if ((x + y) > (length*height - 1))//Bottom edge
		total += 6;
	else
		total = -1;

	return total;
}

void Grid::setNeighbors()
{
	Cell* array = grid.data();
	for (int i = 0; i < length; i + length)
	{
		for (int j = 0; j < height; j++)
		{
			
			switch (edgecasehelp(i, j))
			{
			case -1:
				grid[i + j].setUpLeftNeighbor(&array[i - length + j - 1]);
				grid[i + j].setUpNeighbor(&array[i - length + j]);
				grid[i + j].setUpRightNeighbor(&array[i - length + j + 1]);
				grid[i + j].setLeftNeighbor(&array[i + j - 1]);
				grid[i + j].setRightNeighbor(&array[i + j + 1]);
				grid[i + j].setDownLeftNeighbor(&array[i + length + j - 1]);
				grid[i + j].setDownNeighbor(&array[i + length + j]);
				grid[i + j].setDownRightNeighbor(&array[i + length + j + 1]);
				break;
			case 1:
				grid[i + j].setUpLeftNeighbor(&array[i + (height-1) + j - 1]);
				grid[i + j].setUpNeighbor(&array[i + (height - 1) + j]);
				grid[i + j].setUpRightNeighbor(&array[i + (height - 1) + j + 1]);
				grid[i + j].setLeftNeighbor(&array[i + j - 1]);
				grid[i + j].setRightNeighbor(&array[i + j + 1]);
				grid[i + j].setDownLeftNeighbor(&array[i + length + j - 1]);
				grid[i + j].setDownNeighbor(&array[i + length + j]);
				grid[i + j].setDownRightNeighbor(&array[i + length + j + 1]);
				break;
			case 2:
				grid[i + j].setUpLeftNeighbor(&array[i - length + j - 1]);
				grid[i + j].setUpNeighbor(&array[i - length + j]);
				grid[i + j].setUpRightNeighbor(&array[i - length - length + j + 1]);
				grid[i + j].setLeftNeighbor(&array[i + j - 1]);
				grid[i + j].setRightNeighbor(&array[i -length + j + 1]);
				grid[i + j].setDownLeftNeighbor(&array[i + length + j - 1]);
				grid[i + j].setDownNeighbor(&array[i + length + j]);
				grid[i + j].setDownRightNeighbor(&array[i - length + length + j + 1]);
				break;
			case 3:
				grid[i + j].setUpLeftNeighbor(&array[i + (height - 1) + j - 1]);
				grid[i + j].setUpNeighbor(&array[i + (height - 1) + j]);
				grid[i + j].setUpRightNeighbor(&array[i + (height - 1) - length + j + 1]);
				grid[i + j].setLeftNeighbor(&array[i + j - 1]);
				grid[i + j].setRightNeighbor(&array[0]);
				grid[i + j].setDownLeftNeighbor(&array[i + length + j - 1]);
				grid[i + j].setDownNeighbor(&array[i + length + j]);
				grid[i + j].setDownRightNeighbor(&array[0+length]);
				break;
			case 4:
				grid[i + j].setUpLeftNeighbor(&array[i + length + j - 1]);
				grid[i + j].setUpNeighbor(&array[i - length + j]);
				grid[i + j].setUpRightNeighbor(&array[i - length + j + 1]);
				grid[i + j].setLeftNeighbor(&array[i + length + j - 1]);
				grid[i + j].setRightNeighbor(&array[i + j + 1]);
				grid[i + j].setDownLeftNeighbor(&array[i + length + length + j - 1]);
				grid[i + j].setDownNeighbor(&array[i + length + j]);
				grid[i + j].setDownRightNeighbor(&array[i + length + j + 1]);
				break;
			case 5:  //Not finished
				grid[i + j].setUpLeftNeighbor(&array[i - length + j - 1]);
				grid[i + j].setUpNeighbor(&array[i - length + j]);
				grid[i + j].setUpRightNeighbor(&array[i - length + j + 1]);
				grid[i + j].setLeftNeighbor(&array[i + j - 1]);
				grid[i + j].setRightNeighbor(&array[i + j + 1]);
				grid[i + j].setDownLeftNeighbor(&array[i + length + j - 1]);
				grid[i + j].setDownNeighbor(&array[i + length + j]);
				grid[i + j].setDownRightNeighbor(&array[i + length + j + 1]);
				break;
			}
		}
	}
}