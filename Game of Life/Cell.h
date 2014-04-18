#pragma once
enum life
{
	dead, alive
};

class Cell
{
public:
	Cell(bool status=0);
	~Cell();
	void setState(bool);
	bool getState();
	void setTopNeighbors(Cell*);
	void setSideNeighbors();
	void setBottomNeighbors(Cell*);

	void evolve();
private:
	bool state; //1=alive, 0=dead.

	Cell* UpRightNeighbor;
	Cell* UpNeighbor;
	Cell* UpLeftNeighbor;
	Cell* LeftNeighbor;
	Cell* RightNeighbor;
	Cell* DownLeftNeighbor;
	Cell* DownNeighbor;
	Cell* DownRightNeighbor;
};

