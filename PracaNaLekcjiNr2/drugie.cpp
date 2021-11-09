#include "drugie.h"
#include <iostream>
using namespace std;

string Drugie::drugie(string drugie)
{
	char tym = 0;
	if (drugie.length() / 2 == 0)
	{
		for (int i = 0; i < drugie.length(); i = i + 2)
		{
			tym = drugie[i];
			drugie[i] = drugie[i + 1];
			drugie[i + 1] = tym;
		}
	}
	else
	{
		for (int i = 0; i < drugie.length() - 1; i = i + 2)
		{
			tym = drugie[i];
			drugie[i] = drugie[i + 1];
			drugie[i + 1] = tym;
		}
	}

	return drugie;
}