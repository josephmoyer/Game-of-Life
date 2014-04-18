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
	if (UpRightNeighbor - getState())
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

	if (live < 2)
		setState(dead);
	else if (live < 4)
		setState(alive);
	else if (live>3)
		setState(dead);

	if (live == 3 && !getState())
		setState(alive);
}

void Cell::setTopNeighbors(Cell* Neighbor)
{
	UpNeighbor = Neighbor;
	UpLeftNeighbor = Neighbor - 1;
	UpRightNeighbor = Neighbor + 1;
}

void Cell::setSideNeighbors()
{

	LeftNeighbor = this - 1;
	RightNeighbor = this + 1;
}
void Cell::setBottomNeighbors(Cell* Neighbor)
{
	DownNeighbor = Neighbor;
	DownLeftNeighbor = Neighbor - 1;
	DownRightNeighbor = Neighbor + 1;
}