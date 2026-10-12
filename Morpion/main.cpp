#include <iostream>

using namespace std;

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

void PrintCell(int c) 
{
	cout << "[";
	if (c == -1)
	{
		cout << "X";
	}
	else
	{
		cout << c;
	}
	cout << "]";
}

int main()
{
	cout << "Bienvenue sur le Morpion" << endl;

	int cells[9];

	for (int i = 0; i < 9; i++) 
	{
		cells[i] = i + 1;
	}

	while (true)
	{
		for (int i = 0; i < 9; i++) 
		{
			PrintCell(cells[i]);

			if ((i + 1) % 3 == 0)
				cout << endl;
		}

		cout << "Choisir une case" << endl;
		int index = AskInt(1, 9);
		system("cls");
		cells[index - 1] = -1;
	}

	return 0;
}