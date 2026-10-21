#include <iostream>

const int SIZE = 9;
const int TOTAL_SIZE = SIZE * SIZE;

using namespace std;

int GetIndex(int line, int col) 
{
	return line * SIZE + col;
}

int* GetCell(int line, int col, int* grid) 
{
	if (line < 0 || line >= SIZE)
		return nullptr;

	if (col < 0 || col >= SIZE)
		return nullptr;

	int index = GetIndex(line, col);
	return &grid[index];
}

void Function(int count) 
{
	if (count == 0)
		return;

	cout << "Avant" << endl;

	int n = count - 1;
	Function(n);

	cout << "Apres" << endl;
}

int main() 
{
	int grid[TOTAL_SIZE] = { 0 };

	int* cell = GetCell(0, 0, grid);
	if (cell != nullptr)
		*cell = 10;

	Function(9);

	return 0;
}