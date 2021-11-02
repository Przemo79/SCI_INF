#include <iostream>
#include <string>
using namespace std;

string pierwsze(string pierwsze)
{
	unsigned int oile = 0;
	cout << "\nO ile przesunac litery? (max 26): ";
	cin >> oile;
	if (oile > 0 && oile < 27)
	{
		for (unsigned int i = 0; i < pierwsze.length(); i++)
		{
			pierwsze[i] = pierwsze[i] + oile;
			if (pierwsze[i] > 122)
			{
				pierwsze[i] = pierwsze[i] - 26;
			}
		}
		return pierwsze;
	}
	else
	{
		cout << "\nBledna wartosc!";
	}
}

string czwarte(string czwarte1)
{
	unsigned int oile = 0;
	for (int j = 0; j < 26; j++)
	{
		for (unsigned int i = 0; i < czwarte1.length(); i++)
		{
			czwarte1[i] = czwarte1[i] - j;
			if (czwarte1[i] < 97)
			{
				czwarte1[i] = czwarte1[i] + 26;
			}
		}
		return czwarte1;

	}
}


string drugie(string drugie)
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

int main()
{
	string text;
	int wyb = 0;
	cout << "\nPodaj tekst zapisany malymi literami: ";
	getline(cin, text);

	cout << "\nWybierz metode szyfrowania:\n  1. Szyfr podstawieniowy.\n  2. Szyfr przestawieniowy.\n  3. Szyfr podstawieniowy i przestawieniowy.\n  4. Odszyfrowywanie.";
	cout << "\nTwoj wybor: ";
	cin >> wyb;

	if (wyb == 1)
	{
		cout << "\nTwoj tekst: " << pierwsze(text);
	}
	else if (wyb == 2)
	{
		cout << "\nTwoj tekst: " << drugie(text);
	}
	else if (wyb == 3)
	{
		string trzecie;
		trzecie = pierwsze(text);
		cout << "\nTwoj tekst: " << drugie(trzecie);
	}
	else if (wyb == 4)
	{
		cout << "\nTwoj tekst: " << czwarte(text);
	}
	else
	{
		cout << "Bledna wartosc!";
	}

}