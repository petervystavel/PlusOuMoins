#include <iostream>

using namespace std;

int main()
{
	int grid[9];

	for (int i = 0; i < 9; i++)
	{
		grid[i] = 0;
	}

	int playerTurn = 1;

	while (true)
	{
		for (int i = 0; i < 9; i++)
		{
			cout << "[" << grid[i] << "]";

			if ((i + 1) % 3 == 0)
				cout << endl;
		}

		cout << "choisir un index a modifier (1-9)";
		int index;
		cin >> index;
		index--;
		grid[index] = playerTurn;

		//alterner entre 1 et 2 dans la variable playerTurn
		if (playerTurn == 1)
		{
			playerTurn = 2;
		}
		else if (playerTurn == 2)
		{
			playerTurn = 1;
		}
	}

	return 0;
}

