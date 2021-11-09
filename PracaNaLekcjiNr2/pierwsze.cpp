#include "pierwsze.h"
#include <iostream>
using namespace std;


string Pierwsze::pierwsze(string pierwsze)
{
	unsigned int oile = 0;
	cout << "\nO ile przesunac litery? (max 26): ";
	cin >> oile;
	if (oile > 0 && oile < 27)
	{
		for (unsigned int i = 0; i < pierwsze.length(); i++)
		{
			if (pierwsze[i] != 32)
			{
				pierwsze[i] = pierwsze[i] + oile;
				if (pierwsze[i] > 122 || pierwsze[i] < 97)
				{
					pierwsze[i] = pierwsze[i] - 26;
				}
			}
		}
		return pierwsze;
	}
	else
	{
		return "\nBledna wartosc!";
	}
}