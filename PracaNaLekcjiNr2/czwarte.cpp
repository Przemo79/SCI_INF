#include "czwarte.h"
#include <iostream>
using namespace std;

string Czwarte::czwarte(string czwarte1, int il)
{
	for (int i = 0; i < czwarte1.length(); i++)
	{
		if (czwarte1[i] != 32)
		{
			czwarte1[i] = czwarte1[i] - il;
			if (czwarte1[i] < 97)
			{
				czwarte1[i] = czwarte1[i] + 26;
			}
		}
	}
	return czwarte1;

}