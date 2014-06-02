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