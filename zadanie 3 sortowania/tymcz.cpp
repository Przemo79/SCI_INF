#include <iostream>
#include <time.h>
#include <vector>
#include "sort.h"
#define SIZE 100

using namespace std;

int main()
{
	srand(time(NULL));

	Sortowanie losowanie_obj;
	vector<int> liczby;

	liczby = losowanie_obj.losowanie(liczby);

	cout << "Wylosowane liczby:\t";
	losowanie_obj.wypisz(liczby);

	int wyb = 0;
	cout << "\n\nWybierz rodzaj sortowania:\n  1 - babelkowe,\n  2 - wstawieniowe\nTwoj wybor: ";
	cin >> wyb;

	if (wyb == 1)
	{
		
		liczby = losowanie_obj.bubblesort(liczby);

		cout << "\nBubble sort:\t";
		losowanie_obj.wypisz(liczby);
	}
	else if (wyb == 2)
	{
		
		liczby = losowanie_obj.karciane(liczby);

		cout << "\nSortowanie wstawieniowe:\t";
		losowanie_obj.wypisz(liczby);
	}
	else
	{
		cout << "\nZla wartosc!";
	}
}