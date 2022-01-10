#include "sort.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> Sortowanie::wypisz(vector<int> wypisuj, int zakres)
{
	for (int i = 0; i < zakres; i++)
	{
		cout << wypisuj[i] << "\t";
	}
	return wypisuj;
}

vector<int> Sortowanie::wyczysc(vector<int> czysc, int zakres)
{
	for (int i = 0; i < zakres; i++)
	{
		czysc.pop_back();
	}
	return czysc;
}

vector<int> Sortowanie::bubblesort(vector<int> tablica, int zakres)
{
	for (int i = 0; i < zakres - 1; i++)
	{
		for (int j = 0; j < zakres - 1; j++)
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

vector<int> Sortowanie::losowanie(vector<int> losuj, int zakres, int max_value)
{
	srand(time(NULL));

	for (int i = 0; i < zakres; i++)
	{
		losuj.push_back(rand() % max_value + 1);
	}
	return losuj;
}

vector<int> Sortowanie::karciane(vector<int> wstaw, int zakres)
{

	int x, d = 0;
	for (int i = 1; i < zakres; i++)
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

vector<int> Sortowanie::selection(vector<int> selection, int zakres)
{
	int i, j, minIndex = 0;
	for (j = 0; j < selection.size() - 1; j++)
	{
		minIndex = j;
		for (i = j + 1; i < selection.size(); i++)
		{
			if (selection[i] < selection[minIndex])
			{
				minIndex = i;
			}
		}
		swap(selection[minIndex], selection[j]);
	}
	return selection;
}

vector<int> Sortowanie::estede(vector<int> estede)
{
	sort(estede.begin(), estede.end());
	return estede;
}