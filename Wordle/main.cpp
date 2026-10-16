#include <iostream>

using namespace std;

#define GREEN "\033[32m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"

void Play(const char* word) 
{
	cout << "Deviner le mot" << endl;

	int maxTries = 6;
	while (true)
	{
		char guess[6];
		cin >> guess;

		bool win = true;
		for (int i = 0; i < 5; i++)
		{
			if (guess[i] == word[i])
			{
				cout << GREEN << guess[i] << DEFAULT;
			}
			else
			{
				win = false;
				cout << RED << guess[i] << DEFAULT;
			}
		}

		cout << endl;

		if (win)
		{
			cout << "Bravo" << endl;
			break;
		}

		maxTries--;
		if (maxTries == 0)
		{
			cout << "Perdu" << endl;
			break;
		}

		cout << "Il vous reste " << maxTries << " essais" << endl;
	}
}

int main()
{
	srand(time(NULL));

	const char* words[] = { "TABLE", "ARBRE", "POMME" };
	int wordCount = sizeof(words) / sizeof(char*);

	int wordIndex = 0;

	for( int i = 0; i < wordCount; i++)
	{
		int randIndex = rand() % wordCount;
		Play(words[randIndex]);
	}
	
	cout << "Merci d'avoir joue" << endl;

	return 0;
}

