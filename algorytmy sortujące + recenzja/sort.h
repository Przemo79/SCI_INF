#pragma once
#include <vector>

using namespace std;

class Sortowanie
{
public:
	vector<int> wypisz(vector<int> liczby, int zakres);
	vector<int> losowanie(vector<int> liczby, int zakres, int max_value);
	vector<int> bubblesort(vector<int> liczby, int zakres);
	vector<int> karciane(vector<int> liczby, int zakres);
	vector<int> selection(vector<int> liczby, int zakres);
	vector<int> estede(vector<int> liczby);
	vector<int> wyczysc(vector<int> liczby, int zakres);
};