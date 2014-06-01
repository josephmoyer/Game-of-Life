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
	void setUpRightNeighbor(Cell*);
	void setUpNeighbor(Cell*);
	void setUpLeftNeighbor(Cell*);
	void setLeftNeighbor(Cell*);
	void setRightNeighbor(Cell*);
	void setDownLeftNeighbor(Cell*);
	void setDownNeighbor(Cell*);
	void setDownRightNeighbor(Cell*);

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

