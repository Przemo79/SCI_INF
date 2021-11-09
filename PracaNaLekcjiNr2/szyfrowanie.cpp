#include <iostream>
#include <string>
#include "pierwsze.h"
#include "drugie.h"
#include "czwarte.h"
using namespace std;

int main()
{
	string text;
	Pierwsze obj1;
	Drugie obj2;
	Czwarte obj4;
	int wyb = 0;
	cout << "\nPodaj tekst zapisany malymi literami: ";
	getline(cin, text);

	cout << "\nWybierz metode szyfrowania:\n  1. Szyfr podstawieniowy.\n  2. Szyfr przestawieniowy.\n  3. Szyfr podstawieniowy i przestawieniowy.\n  4. Odszyfrowywanie.";
	cout << "\n\nTwoj wybor: ";
	cin >> wyb;

	if (wyb == 1)
	{
		cout << "\nTwoj tekst: " << obj1.pierwsze(text) << endl;
	}
	else if (wyb == 2)
	{
		cout << "\nTwoj tekst: " << obj2.drugie(text) << endl;
	}
	else if (wyb == 3)
	{
		string trzecie;
		trzecie = obj1.pierwsze(text);
		cout << "\nTwoj tekst: " << obj2.drugie(trzecie) << endl;
	}
	else if (wyb == 4)
	{
		for (int i = 0; i < 26; i++)
		{
			cout << "\nOdszyfrowywanie: " << obj4.czwarte(text, i);
		}
	}
	else
	{
		cout << "Bledna wartosc!";
	}

}