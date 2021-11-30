#include <iostream>
#include <utility>
#include <string>
//Dodałem też generator liczb pierwszych by kicajsky z githuba;

using namespace std;

bool pierwsza(int liczba)
{
	if (liczba == 0 || liczba == 1)
		return false;
	else if (liczba == 2)
		return true;
	else if (liczba % 2 == 0)
		return false;

	for (int i = 3; i < liczba; i += 2)
	{
		if (liczba % i == 0)
			return false;
	}
	return true;
}

/*void test()
{
	if (pierwsza(1) != false) std::cout << "1 not ok" << std::endl;
	if (pierwsza(2) != true) std::cout << "2 not ok" << std::endl;
	if (pierwsza(3) != true) std::cout << "3 not ok" << std::endl;
	if (pierwsza(4) != false) std::cout << "4 not ok" << std::endl;
	if (pierwsza(5) != true) std::cout << "5 not ok" << std::endl;
}*/

int modInverse(int a, int m)
{
	for (int x = 1; x < m; x++)
		if (((a % m) * (x % m)) % m == 1)
			return x;
}

int main()
{
	srand(time(NULL));

	int tablica_liczb_pierwszych[5] = { 0 };

	//test();
	int licznik = 0;

	for (int liczba = 0; liczba < 12; liczba++)  //generuje liczby pierwsze w zakresie do 12,
	{											 //a że tych liczb jest 5, dlatego tablica ma 5 elementów.
		if (pierwsza(liczba) == true)
		{
			tablica_liczb_pierwszych[licznik] = liczba;
			licznik++;
		}
	}

	cout << "Liczby pierwsze: ";
	for (int i = 0; i < licznik; i++)
	{
		cout << tablica_liczb_pierwszych[i] << "\t";  //wypisuje liczby pierwsze z tablicy
	}

	pair <int, int> pierwsze(tablica_liczb_pierwszych[rand() % licznik], tablica_liczb_pierwszych[rand() % licznik]);  //losuje wartości
	//pair <int, int> pierwsze(13, 11); //próbne wartości
	cout << endl << "Wylosowane liczby pierwsze: " << pierwsze.first << "\t" << pierwsze.second << endl; 

	int Euler = (pierwsze.first - 1) * (pierwsze.second - 1);
	//cout << Euler << endl;

	int n = pierwsze.first * pierwsze.second;
	//cout << n << endl;

	int e = 7;
	/*for (int i = n - 1; i > 1; i--) //próba losowania e
	{
		
	*/

	int d = modInverse(e, Euler);
	//cout << d << endl;

	cout << "\nKlucz publiczny: " << e << "\t" << n << endl;
	cout << "Klucz prywatny:  " << d << "\t" << n << endl;
}