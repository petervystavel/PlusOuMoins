#include <iostream>

using namespace std;

void Divide(int a, int b, int* p, int* r) 
{
	*p = a / b;
	*r = a % b;
}

void Convert(int total, int* s, int* m, int* h) 
{
	*m = total / 60;
	*s = total % 60;
	*h = *m / 60;
	*m = *m % 60;
}

void Convert2(int total, int* s, int* m, int* h)
{
	Divide(total, 60, m, s);
	Divide(*m, 60, h, m);
}

void Swap(int* a, int* b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int a = 10;
	int b = 3;

	int p;
	int r;

	Divide(a, b, &p, &r);

	cout << "partie entiere: " << p << " reste: " << r << endl;

	int total = 3663;
	int s;
	int m;
	int h;

	Convert(total, &s, &m, &h);

	cout << h << "h " << m << "min " << s << "s" << endl;

	int i = 5;
	int j = 10;

	Swap(&i, &j);

	cout << i << " " << j << endl;

	return 0;
}

