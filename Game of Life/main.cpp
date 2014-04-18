#include "Cell.h"
#include <iostream>
using namespace std;

const int SIZE = 10;
void print(Cell array[SIZE][SIZE]);
void setNeighbors(Cell array[SIZE][SIZE]);
void iterate(Cell array[SIZE][SIZE]);
int main()
{
	cout << "*********************\n Game Of Life\n*********************\n";

	//Initialize
	Cell FirstArray[SIZE][SIZE]=
	{
		{ 0, 0, 0, 1, 0, 1, 1, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 0, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	setNeighbors(FirstArray);
	while (true){

		print(FirstArray);
		iterate(FirstArray);
		_sleep(1000);
	}

	
	
	char tmpe_input;
	cout << "\nPress any key and enter to exit.\n";
	cin >> tmpe_input;
	return 0;
}

void print(Cell array[SIZE][SIZE])
{
	system("cls");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (array[i][j].getState())
				cout << "& ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}
void setNeighbors(Cell array[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			Cell* top = &array[i-10][j];
			array[i][j].setSideNeighbors();
			array[i][j].setTopNeighbors(top);
			array[i][j].setBottomNeighbors(&array[i + 10][j]);
		}
		cout << "\n";
	}
}

void iterate(Cell array[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			array[i][j].evolve();
		}
		cout << "\n";
	}
}