#include <iostream>
#include <vector>
#include <chrono>
#include "Class.h"
#define IL 1000;

using namespace std;

int main() {

	MyVector object;

	int wyb2 = 0;
	cout << "Program MyVector\n\t1 - edycja MyVectora\n\t2 - porownania\n\nTwoj wybor: ";
	cin >> wyb2;
	
	if (wyb2 == 1)
	{
		object.wypisz();
		int wyb = 0;
		do {
			cout << "\n-------------------\n\t0 - zakoncz\n\t1 - wypisz zawartosc tablicy\n\t2 - dodaj wartosc na koniec tablicy\n\t3 - usun ostatnia wartosc"
				<< "\n\t4 - wywolywanie wartosci po indexie\n\t5 - dodaj pod konkretny index\n\t6 - usun konkretny index\n\nTwoj wybor: ";
			cin >> wyb;

			system("cls");

			if (wyb == 0)
				cout << "\nProgram zakonczyl dzialanie.";
			else if (wyb == 1)
				object.wypisz();
			else if (wyb == 2) {
				object.dodaj();
				object.wypisz();
			}
			else if (wyb == 3) {
				object.usun();
				object.wypisz();
			}
			else if (wyb == 4) {
				object.pokaCoMaszPodTymIndexem();
				object.wypisz();
			}
			else if (wyb == 5) {
				object.dodaj_pod_index();
				object.wypisz();
			}
			else if (wyb == 6) {
				object.usun_spod_indexu();
				object.wypisz();
			}
			else
				cout << "\nZla wartosc!";
		} while (wyb != 0);
	}
	else if (wyb2 == 2)
	{
		vector<int> wektor[1];
		int* wektor_dyn = new int[1];
		cout << "\nWektor z std::vector wazy " << sizeof(wektor);
		cout << "\nWektor z tablicy dynamicznej wazy " << sizeof(wektor_dyn) << "\n";
		delete[] wektor_dyn;

		/*int il = 0;
		cout << "\n\nPodaj ilosc wartosci do dodania do tablicy zeby sprawdzic czasy: ";
		cin >> il;*/

		/*int* tablica = new int[10000];
		auto begin = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			tablica[i] = i;
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - begin);

		std::vector<int> vec;
		auto begin2 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			vec.push_back(i);
		}
		auto end2 = std::chrono::high_resolution_clock::now();
		auto elapsed2 = std::chrono::duration_cast<std::chrono::seconds>(end2 - begin2);

		auto begin4 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			
		}
		auto end4 = std::chrono::high_resolution_clock::now();
		auto elapsed4 = std::chrono::duration_cast<std::chrono::seconds>(end4 - begin4);

		std::vector<int> vec;
		auto begin3 = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			vec.pop_back();
		}
		auto end3 = std::chrono::high_resolution_clock::now();
		auto elapsed3 = std::chrono::duration_cast<std::chrono::seconds>(end3 - begin3);

		delete[] tablica;

		cout << "\n\nDla tablicy dynamicznej dodanie 10000 elementow zajelo " << elapsed.count();
		cout << "\nDla wektora dodanie 10000 elementow wynioslo " << elapsed.count() << "\n";
		cout << "\nDla tablicy dynamicznej usuwanie 10000 elementow zajelo " << elapsed.count();
		cout << "\nDla wektora usuwanie 10000 elementow wynioslo " << elapsed.count() << "\n";*/
	}
	else
		cout << "\nZla wartosc!";

	return 0;
}