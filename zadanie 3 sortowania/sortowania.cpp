#include <iostream>
#include <time.h>
#include <vector>
#include "Sortowanie.h"
#define SIZE 100

using namespace std;

int main()
{
	srand(time(NULL));

	Sortowanie losowanie_obj;
	Sortowanie wypisz_obj;
	vector<int> liczby;

	liczby = losowanie_obj.losowanie(liczby);

	cout << "Wylosowane liczby:\t";
	wypisz_obj.wypisz(liczby);

	int wyb = 0;
	cout << "\n\nWybierz rodzaj sortowania:\n  1 - babelkowe,\n  2 - wstawieniowe\nTwoj wybor: ";
	cin >> wyb;

	if (wyb == 1)
	{
		Sortowanie bubblesort_obj;

		liczby = bubblesort_obj.bubblesort(liczby);

		cout << "\nBubble sort:\t";
		wypisz_obj.wypisz(liczby);
	}
	else if (wyb == 2)
	{
		Sortowanie wstawieniowe_obj;

		liczby = wstawieniowe_obj.karciane(liczby);

		cout << "\nSortowanie wstawieniowe:\t";
		wypisz_obj.wypisz(liczby);
	}
	else
	{
		cout << "\nZla wartosc!";
	}
}