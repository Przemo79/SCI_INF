#pragma once
#include <vector>

using namespace std;

class Sortowanie
{
public:
	vector<int> wypisz(vector<int> liczby);
	vector<int> losowanie(vector<int> liczby);
	vector<int> bubblesort(vector<int> liczby);
	vector<int> karciane(vector<int> liczby);
};

