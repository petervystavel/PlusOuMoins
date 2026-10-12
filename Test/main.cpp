#include <iostream>

using namespace std;

#define DEFAULT "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"

void function(int t[500])
{
}

int main()
{
	int tab[500];
	function(tab);

	int t;

	t = 5;

	for (int i = 0; i < 500; i++) 
	{
		tab[i] = 0;
	} 

	for (int i = 0; i < 500; i++)
	{
		cout << "[" << tab[i] << "]";
	}

	return 0;
}