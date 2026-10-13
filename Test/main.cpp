#include <iostream>

using namespace std;

bool CheckWin(int cells[9])
{
	//LINES
	if (cells[0] == cells[1] && cells[0] == cells[2])
		return true;

	if (cells[3] == cells[4] && cells[3] == cells[5])
		return true;

	if (cells[6] == cells[7] && cells[6] == cells[8])
		return true;

	//COLUMNS
	if (cells[0] == cells[3] && cells[0] == cells[6])
		return true;

	if (cells[1] == cells[4] && cells[1] == cells[7])
		return true;

	if (cells[2] == cells[6] && cells[2] == cells[8])
		return true;

	//DIAGONAL 1
	if (cells[0] == cells[4] && cells[0] == cells[8])
		return true;

	//DIAGONAL 2
	if (cells[2] == cells[4] && cells[2] == cells[6])
		return true;


	return false;
}

int main()
{
	int cells[9];

	for (int i = 0; i < 9; i++)
	{
		cells[i] = i + 1;
	}

	cells[0] = -2;
	cells[4] = -2;
	cells[8] = -2;

	bool win = CheckWin(cells);
	if (win) 
	{
		cout << "OK" << endl;
	}
	else 
	{
		cout << "ERROR" << endl;
	}

	return 0;
}