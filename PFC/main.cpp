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

void PrintChoice(int index)
{
	if (index == 0)
	{
		cout << "Pierre";
	}
	else if (index == 1)
	{
		cout << "Feuille";
	}
	else
	{
		cout << "Ciseaux";
	}
}

int GetDistance(int a, int b)
{
	int out = a - b;
	if (out < 0)
		return -out;

	return out;
}

int main()
{
	srand(time(NULL));

	cout << "Bienvenue sur le jeu du Pierre Feuille Ciseaux" << endl;

	int playerScore = 0;
	int botScore = 0;
	int tiesCount = 0;
	int result;

	while (true)
	{
		cout << "Pierre(1), Feuille(2), Ciseaux(3) ?" << endl;

		int playerChoice = AskInt(1, 3);
		playerChoice--;
		system("cls");
		int botChoice = rand() % 3;

		PrintChoice(playerChoice);
		cout << " VS ";
		PrintChoice(botChoice);
		cout << endl;
		if (playerChoice == botChoice)
		{
			cout << "Egalite" << endl;
			tiesCount++;
		}
		else if ((botChoice + 1) % 3 == playerChoice)
		{
			cout << "Gagne" << endl;
			playerScore++;
		}
		else
		{
			cout << "Perdu" << endl;
			botScore++;
		}

		cout << "Player : " << playerScore << endl;
		cout << "Bot : " << botScore << endl;
		cout << "Egalite : " << tiesCount << endl;

		int gap = GetDistance(playerScore, botScore);

		if (gap >= 2)
		{
			if (playerScore >= 3)
			{
				cout << "Tu as Gagne!" << endl;
				break;
			}
			else if (botScore >= 3)
			{
				cout << "Tu as perdu!" << endl;
				break;
			}
		}
	}

	return 0;
}