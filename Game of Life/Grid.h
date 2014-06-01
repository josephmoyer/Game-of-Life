#pragma once
#include "Cell.h"
#include <vector>
#include <iostream>
class Grid
{
public:
	Grid(int, int, bool*);
	~Grid();
	void print();
	void setNeighbors();
	void iterate(int n = 1);

private:
	std::vector<Cell> grid;
	int length;
	int height;

};

