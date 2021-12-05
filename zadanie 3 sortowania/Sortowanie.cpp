#include "sortowanie.h"
#include <vector>
#include <iostream>
#define SIZE 100

using namespace std;

vector<int> Sortowanie::wypisz(vector<int> wypisuj)
{
	for (int i = 0; i < 100; i++)
	{
		cout << wypisuj[i] << "\t";
	}
	return wypisuj;
}

vector<int> Sortowanie::bubblesort(vector<int> tablica)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - 1; j++)
		{
			if (tablica[j] > tablica[j + 1])
			{
				int temp = tablica[j];
				tablica[j] = tablica[j + 1];
				tablica[j + 1] = temp;
			}
		}
	}
	return tablica;
}

vector<int> Sortowanie::losowanie(vector<int> losuj)
{
	srand(time(NULL));

	vector<int> liczby;

	for (int i = 0; i < 100; i++)
	{
		losuj.push_back(rand() % 1000 + 1);
	}
	return losuj;
}

vector<int> Sortowanie::karciane(vector<int> wstaw)
{

	int x, d = 0;
	for (int i = 1; i < SIZE; i++)
	{
		int d = i - 1;
		x = wstaw[i];

		while (d >= 0 && wstaw[d] > x)
		{
			wstaw[d + 1] = wstaw[d];
			d--;
		}
		wstaw[d + 1] = x;
	}
	return wstaw;
}