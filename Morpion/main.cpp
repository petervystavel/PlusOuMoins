#include <iostream>

using namespace std;

const int SIZE = 3;
const int TOTAL_SIZE = SIZE * SIZE;

int AskInt(int min, int max)
{
	int value;
	while (true)
	{
		cin >> value;
		if (value >= min && value <= max)
			break;

		cout << "Erreur saisie" << endl;
	}

	return value;
}

int GetIndex(int line, int column) 
{
	return line * SIZE + column;
}

int AskCell(int cells[TOTAL_SIZE])
{
	while (true)
	{
		cout << "Choisir une ligne" << endl;
		int line = AskInt(1, SIZE);
		line--;

		cout << "Choisir une column" << endl;
		int column = AskInt(1, SIZE);
		column--;

		int index = GetIndex(line, column);
		if (cells[index] != -1 && cells[index] != -2)
			return index;

		cout << "Case non disponible" << endl;
	}
}

int GetSymbol(int playerID)
{
	return -(playerID + 1);
}

bool CheckWinOptimized(int cells[TOTAL_SIZE], int playerID, int indexPlayed)
{
	bool found = true;
	int symbol = GetSymbol(playerID);
	int linePlayed = indexPlayed / SIZE;
	int columnPlayed = indexPlayed % SIZE;
	for (int column = 0; column < SIZE; column++)
	{
		int index = GetIndex(linePlayed, column);
		if (cells[index] != symbol)
		{
			found = false;
			break;
		}
	}

	if (found)
		return true;

	for (int line = 0; line < SIZE; line++)
	{
		int index = GetIndex(line, columnPlayed);
		if (cells[index] != symbol)
		{
			found = false;
			break;
		}
	}

	if (found)
		return true;

	//DIAGONAL 1
	if (columnPlayed == linePlayed)
	{
		int line = 0;
		int column = 0;
		bool found = true;
		for (int i = 0; i < SIZE; i++)
		{
			int index = GetIndex(line, column);
			if (cells[index] != symbol)
			{
				found = false;
				break;
			}

			line++;
			column++;
		}

		if (found)
			return true;
	}

	//DIAGONAL 2
	if (columnPlayed + linePlayed == SIZE - 1)
	{
		int line = 0;
		int column = SIZE - 1;
		bool found = true;
		for (int i = 0; i < SIZE; i++)
		{
			int index = GetIndex(line, column);
			if (cells[index] != symbol)
			{
				found = false;
				break;
			}

			line++;
			column--;
		}

		if (found)
			return true;
	}

}

bool CheckWin(int cells[TOTAL_SIZE], int playerID) 
{
	int symbol = GetSymbol(playerID);

	//LINES
	for (int line = 0; line < SIZE; line++) 
	{
		bool found = true;
		for (int column = 0; column < SIZE; column++) 
		{
			int index = GetIndex(line, column);
			if (cells[index] != symbol) 
			{
				found = false;
				break;
			}
		}

		if (found)
			return true;
	}

	//COLUMN
	for (int column = 0; column < SIZE; column++)
	{
		bool found = true;
		for (int line = 0; line < SIZE; line++)
		{
			int index = GetIndex(line, column);
			if (cells[index] != symbol)
			{
				found = false;
				break;
			}
		}

		if (found)
			return true;
	}

	//DIAGONAL 1
	{
		int line = 0;
		int column = 0;
		bool found = true;
		for (int i = 0; i < SIZE; i++)
		{
			int index = GetIndex(line, column);
			if (cells[index] != symbol)
			{
				found = false;
				break;
			}

			line++;
			column++;
		}

		if (found)
			return true;
	}
	
	//DIAGONAL 2
	{
		int line = 0;
		int column = SIZE - 1;
		bool found = true;
		for (int i = 0; i < SIZE; i++)
		{
			int index = GetIndex(line, column);
			if (cells[index] != symbol)
			{
				found = false;
				break;
			}

			line++;
			column--;
		}

		if (found)
			return true;
	}


	return false;
}

void PrintCell(int c) 
{
	cout << "[";
	if (c == -1)
	{
		cout << "X";
	}
	else if (c == -2)
	{
		cout << "O";
	}
	else
	{
		cout << c;
	}
	cout << "]";
}

int main()
{
	srand(time(NULL));

	cout << "Bienvenue sur le Morpion" << endl;

	int cells[TOTAL_SIZE];

	for (int i = 0; i < 9; i++) 
	{
		cells[i] = i + 1;
	}

	int availableCells = 9;

	int playerID = 0;
	while (true)
	{
		for (int i = 0; i < TOTAL_SIZE; i++) 
		{
			PrintCell(cells[i]);

			if ((i + 1) % SIZE == 0)
				cout << endl;
		}

		int index;
		
		//player
		if (playerID == 0) 
		{
			index = AskCell(cells);
		}
		//bot
		else 
		{
			while (true) 
			{
				index = rand() % TOTAL_SIZE;
				if (cells[index] != -1 && cells[index] == -2)
					break;
			}
		}
		
		system("cls");

		cells[index] = GetSymbol(playerID);

		bool win = CheckWin(cells);
		if (win) 
		{
			cout << "Player " << (playerID + 1) << " a gagne" << endl;
			break;
		}

		availableCells--;
		if (availableCells == 0) 
		{
			cout << "EGALITE" << endl;
		}

		playerID++;
		playerID = playerID % 2;
	}

	return 0;
}