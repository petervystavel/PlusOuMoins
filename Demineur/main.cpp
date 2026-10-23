#include <iostream>

#define HIDDEN -3
#define MINE -1

const int LINES = 9;
const int COLUMNS = 9;
const int TOTAL_SIZE = LINES * COLUMNS;

const int MINE_COUNT = TOTAL_SIZE * 0.15f;

using namespace std;

int GetIndex(int line, int col)
{
	return line * COLUMNS + col;
}

bool IsInArray(int line, int col)
{
	if (line < 0 || line >= LINES)
		return false;

	if (col < 0 || col >= COLUMNS)
		return false;

	return true;
}

int* GetCell(int cells[TOTAL_SIZE], int line, int col)
{
	if (IsInArray(line, col) == false)
		return nullptr;

	int index = GetIndex(line, col);
	return &cells[index];
}

void DisplayCell(int cell)
{
	switch (cell)
	{
	case HIDDEN:
		cout << "-";
		break;
	case MINE:
		cout << "*";
		break;
	default:
		cout << cell;
	}
}

void DisplayGrid(int cells[TOTAL_SIZE])
{
	for (int i = 0; i < LINES; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			int index = GetIndex(i, j);
			cout << "[";
			DisplayCell(cells[index]);
			cout << "]";
		}

		cout << endl;
	}
}

void IncrementNeighbors(int cells[TOTAL_SIZE], int line, int col)
{
	int direction[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1} };

	for (int i = 0; i < 8; i++)
	{
		int nline = line + direction[i][0];
		int ncol = col + direction[i][1];

		int* cell = GetCell(cells, nline, ncol);

		if (cell != nullptr && *cell != MINE) 
		{
			(*cell)++;
		}
	}
}

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

void AskCell(int cells[TOTAL_SIZE], int* line, int* col)
{
	while (true)
	{
		cout << "Choisir une ligne" << endl;
		*line = AskInt(1, LINES);
		(*line)--;

		cout << "Choisir une column" << endl;
		*col = AskInt(1, COLUMNS);
		(*col)--;

		int index = GetIndex(*line, *col);
		if (cells[index] == HIDDEN)
			return;

		cout << "Case non disponible" << endl;
	}
}

void Reveal(int grid[TOTAL_SIZE], int datas[TOTAL_SIZE], int line, int col )
{
	int* c = GetCell(grid, line, col);
	int* d = GetCell(datas, line, col);

	if (c == nullptr)
		return;

	if (*c != HIDDEN)
		return;

	*c = *d;

	if (*d != 0)
		return;

	int direction[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1} };

	for (int i = 0; i < 8; i++)
	{
		int nline = line + direction[i][0];
		int ncol = col + direction[i][1];

		int* cell = GetCell(datas, nline, ncol);
		if (cell == nullptr)
			continue;

		Reveal(grid, datas, nline, ncol);
	}
}

int main()
{
	srand(time(NULL));

	int datas[TOTAL_SIZE] = { 0 };
	int grid[TOTAL_SIZE];

	for (int i = 0; i < TOTAL_SIZE; i++) 
	{
		grid[i] = HIDDEN;
	}

	//TODO : better algo (not based on random)
	for (int i = 0; i < MINE_COUNT;)
	{
		int random = rand() % TOTAL_SIZE;
		if (datas[random] != MINE)
		{
			int line = random / COLUMNS;
			int col = random % COLUMNS;

			IncrementNeighbors(datas, line, col);

			datas[random] = MINE;
			i++;
		}
	}

	while (true) 
	{
		DisplayGrid(grid);

		int line;
		int col;
		AskCell(grid, &line, &col);
		
		int* cell = GetCell(datas, line, col);
		if ( *cell == MINE )
		{
			cout << "Perdu" << endl;
			//TODO tout révéler
			break;
		}
	
		Reveal(grid, datas, line, col);
	}
	
	return 0;
}