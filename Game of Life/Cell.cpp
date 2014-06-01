#include "Cell.h"


Cell::Cell(bool status)
{
	setState(status);
}


Cell::~Cell()
{
}

void Cell::setState(bool status)
{
	state = status;
}

bool Cell::getState()
{
	return state;
}

void Cell::evolve()
{
	int live=0;
	if (UpLeftNeighbor->getState())
		live++;
	if (UpNeighbor->getState())
		live++;
	if (UpRightNeighbor ->getState())
		live++;
	if (LeftNeighbor->getState())
		live++;
	if (RightNeighbor->getState())
		live++;
	if (DownLeftNeighbor->getState())
		live++;
	if (DownNeighbor->getState())
		live++;
	if (DownRightNeighbor->getState())
		live++;

	if (getState())
	{
		if (live < 2)
			setState(dead);
		else if (live > 3)
			setState(dead);
	}
	else if (live == 3)
		setState(alive);
}

void Cell::setUpRightNeighbor(Cell* neighbor)
{
	UpRightNeighbor = neighbor;
}
void Cell::setUpNeighbor(Cell* neighbor) 
{
	UpNeighbor = neighbor;
}
void Cell::setUpLeftNeighbor(Cell* neighbor)
{
	UpLeftNeighbor = neighbor;
}
void Cell::setLeftNeighbor(Cell* neighbor)
{
	LeftNeighbor = neighbor;
}
void Cell::setRightNeighbor(Cell* neighbor)
{
	RightNeighbor = neighbor;
}
void Cell::setDownLeftNeighbor(Cell* neighbor)
{
	DownLeftNeighbor = neighbor;
}
void Cell::setDownNeighbor(Cell* neighbor)
{
	DownNeighbor = neighbor;
}
void Cell::setDownRightNeighbor(Cell* neighbor)
{
	DownRightNeighbor = neighbor;
}