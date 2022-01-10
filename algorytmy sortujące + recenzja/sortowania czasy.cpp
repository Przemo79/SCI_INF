#include <iostream>
#include <time.h>
#include <vector>
#include <chrono>
#include <fstream>
#include "sort.h"
#define ilosc 5
#define zakres_dla_scalania 200000      // Wielkosc tablicy pomocniczej musi byc taka sama jak wielkosc wektora z wartosciami,
										 // poniewaz bedziemy scalac wartosci z tych zbiorow, wiec msuza byc takie same.
using namespace std;
vector<int> szybki_vector;
vector<int> scalony_vector;              // tworzę zbiór głowny dla sortowania przez scalanie
int pomocniczy[zakres_dla_scalania];     // tworzę pusty zbiór tymczasowy

void mergeSort(int pierwszy_mlody, int ostatni_stary)  // pierwszy_młody - pierwszy element mniejszego zbioru
{													   // ostatni_stary - ostatni element większego zbioru
	int index = 0;    // indeks elementów w zbiorze pomocniczym

	int pierwszy_stary = (pierwszy_mlody + ostatni_stary + 1) / 2;   // szukam pierwszego elementu większego zbioru, a żeby to zrobić wystarczy
																	 // znaleźć połowę zbioru głownego i pójść jeden element w górę.
	if (pierwszy_stary - pierwszy_mlody > 1)
		mergeSort(pierwszy_mlody, pierwszy_stary - 1);  // te if'y sprawdzamją, czy dana połówka zbioru zawiera więcej niż jeden element.
														// Jeśli tak, to rekurencyjnie sortujemy ją tym samym algorytmem.
	if (ostatni_stary - pierwszy_stary > 0)
		mergeSort(pierwszy_stary, ostatni_stary);
	
	int elementy_w_mlodym = pierwszy_mlody;   // jak już program podzielił zbiór na dwie połowy, to teraz nadaje im indexy,
	int elementy_w_starym = pierwszy_stary;	  // które odpowiadają za pierwszy element w tych podzbiorach
	
	for (index = pierwszy_mlody; index <= ostatni_stary; index++)  // do indexa przypisujemy pierwszy element w mniejszym zbiorze 
	{
		if ((elementy_w_mlodym == pierwszy_stary) || ((elementy_w_starym <= ostatni_stary) && (scalony_vector[elementy_w_mlodym] > scalony_vector[elementy_w_starym])))
		{
			pomocniczy[index] = scalony_vector[elementy_w_starym];  // w tym if'ie sprawdzamy, czy któryś z podzbiorów jest wyczerpany. Jeśli nie jest,
			elementy_w_starym++;									// to porównujemy kolejne elementy z tych podzbiorów według indeksów. Do tablicy tymczasowej wpisujemy
		}															// mniejszy element, dzięku temu liczby się sortują. Następnie indexy są zwiększane o 1,
		else														// aby porównywać kolejne elementy w podzbiorach i przypisywać je do kolejnych miejsc w tablicy
		{
			pomocniczy[index] = scalony_vector[elementy_w_mlodym];
			elementy_w_mlodym++;
		}
	}
	
	for (index = pierwszy_mlody; index <= ostatni_stary; index++)   // posortowane liczby przepisujemy z tablicy tymczasowej do głównej tablicy,
		scalony_vector[index] = pomocniczy[index];					// z której program odczyta wynik.
}

void quickSort(int left, int right)
{
	int i, j, piwot;

	i = (left + right) / 2;
	piwot = szybki_vector[i];
	szybki_vector[i] = szybki_vector[right];

	for (j = i = left; i < right; i++)
	{
		if (szybki_vector[i] < piwot)
		{
			swap(szybki_vector[i], szybki_vector[j]);
			j++;
		}
	}

	szybki_vector[right] = szybki_vector[j];
	szybki_vector[j] = piwot;

	if (left < j - 1)
		quickSort(left, j - 1);

	if (j + 1 < right)
		quickSort(j + 1, right);
}

int main()
{
	srand(time(NULL));

	ofstream plik;
	plik.open("czasy.txt", ios::app);

	Sortowanie losowanie_obj;
	Sortowanie wypisz_obj;
	Sortowanie wyczysc_obj;
	Sortowanie bubblesort_obj;
	Sortowanie wstawieniowe_obj;
	Sortowanie selection_obj;
	Sortowanie estede_obj;

	cout << "\nProgram posortuje zbior liczb losowo ulozonych w " << ilosc << " rozmiarach podanych przez uzytkownika szescioma\nalgorytmami sortujacymi i zmierzy czasy sortowan.";
	
	vector<int> size;
	vector<int> max_value;
	int temp = 0;
	for (int i = 0; i < ilosc; i++)
	{
		cout << "\nPodaj zakres nr " << i + 1 << ": ";
		cin >> temp;
		if (temp != 0 && temp > 0)
		{
			size.push_back(temp);
			max_value.push_back(temp * 10);
		}
		else {
			cout << "\nZla wartosc! (wypelniono przez 1)\n";
			size.push_back(1);
			max_value.push_back(1 * 10);
		}
	}

	vector<int> liczby;
	vector<int> bubble_liczby;
	vector<int> karciane_liczby;
	vector<int> selection_liczby;
	vector<int> estede_liczby;

	plik << "\n\nCzasy sortowan (sekundy):\n";

	for (int zakresy = 0; zakresy < ilosc; zakresy++)
	{
		liczby = losowanie_obj.losowanie(liczby, size[zakresy], max_value[zakresy]);
		//wypisz_obj.wypisz(liczby, size[zakresy]);

		bubble_liczby = liczby;
		karciane_liczby = liczby;
		selection_liczby = liczby;
		estede_liczby = liczby;
		szybki_vector = liczby;

		vector<int> pomocniczy{ size[zakresy] };

		cout << "\n\nZakres nr " << zakresy + 1 << ". Sortuje " << size[zakresy] << " liczb:";

		auto start = chrono::steady_clock::now();
		bubble_liczby = bubblesort_obj.bubblesort(liczby, size[zakresy]);
		auto end = chrono::steady_clock::now();
		chrono::duration<double> elapsed_second = end - start;

		cout << "\nBubble sort " << zakresy + 1 << ":\t\t\t" << elapsed_second.count() << "sec\t";
		plik << "\n";
		plik << elapsed_second.count() << "   \t";
		//wypisz_obj.wypisz(bubble_liczby, size[zakresy]);
		//------------------------------------------------------------------------------------------------------

		auto start2 = chrono::steady_clock::now();
		karciane_liczby = wstawieniowe_obj.karciane(liczby, size[zakresy]);
		auto end2 = chrono::steady_clock::now();
		chrono::duration<double> elapsed_second2 = end2 - start2;

		cout << "\nSortowanie wstawieniowe " << zakresy + 1 << ":\t" << elapsed_second2.count() << "sec\t";
		plik << elapsed_second2.count() << "   \t";
		//wypisz_obj.wypisz(karciane_liczby, size[zakresy]);
		//------------------------------------------------------------------------------------------------------

		auto start3 = chrono::steady_clock::now();
		selection_liczby = selection_obj.selection(liczby, size[zakresy]);
		auto end3 = chrono::steady_clock::now();
		chrono::duration<double> elapsed_second3 = end3 - start3;

		cout << "\nSortowanie przez wybor " << zakresy + 1 << ":\t" << elapsed_second3.count() << "sec\t";
		plik << elapsed_second3.count() << "   \t";
		//wypisz_obj.wypisz(selection_liczby, size[zakresy]);
		//------------------------------------------------------------------------------------------------------

		auto start4 = chrono::steady_clock::now();
		estede_liczby = estede_obj.estede(liczby);
		auto end4 = chrono::steady_clock::now();
		chrono::duration<double> elapsed_second4 = end4 - start4;

		cout << "\nSortowanie std " << zakresy + 1 << ":\t\t" << elapsed_second4.count() << "sec\t";
		plik << elapsed_second4.count() << "   \t";
		//wypisz_obj.wypisz(estede_liczby, size[zakresy]);
		//------------------------------------------------------------------------------------------------------

		auto start5 = chrono::steady_clock::now();
		quickSort(0, size[zakresy] - 1);
		auto end5 = chrono::steady_clock::now();
		chrono::duration<double> elapsed_second5 = end5 - start5;

		cout << "\nSzybkie sortowanie " << zakresy + 1 << ":\t\t" << elapsed_second5.count() << "sec\t";
		plik << elapsed_second5.count() << "   \t";
		//wypisz_obj.wypisz(szybki_vector, size[zakresy]);
		//------------------------------------------------------------------------------------------------------

		liczby = wyczysc_obj.wyczysc(liczby, size[zakresy]);
		bubble_liczby = wyczysc_obj.wyczysc(bubble_liczby, size[zakresy]);
		karciane_liczby = wyczysc_obj.wyczysc(karciane_liczby, size[zakresy]);
		selection_liczby = wyczysc_obj.wyczysc(selection_liczby, size[zakresy]);
		estede_liczby = wyczysc_obj.wyczysc(estede_liczby, size[zakresy]);
		szybki_vector = wyczysc_obj.wyczysc(szybki_vector, size[zakresy]);
	}
	
	liczby = losowanie_obj.losowanie(liczby, zakres_dla_scalania, zakres_dla_scalania * 10);   // w algorytmie operuję na tablicy, której wielkość musi zmienną stałą, znaną kompilatortowi
	scalony_vector = liczby;																   // przy uruchamianiu programu, dlatego nie mogę zmieniać jej wielkości do tej, podanej przez użytkownika

	auto start6 = chrono::steady_clock::now();
	mergeSort(0, zakres_dla_scalania - 1);        // wywołuję funkcję sortowania przez scalania podając jako argumenty indexy pierwszego i ostatniego elementu w zbiorze
	auto end6 = chrono::steady_clock::now();
	chrono::duration<double> elapsed_second6 = end6 - start6;

	cout << "\nSortowanie przez scalanie (" << zakres_dla_scalania << " wartosci):\t" << elapsed_second6.count() << "sec\t";
	//wypisz_obj.wypisz(scalony_vector, zakres_dla_scalania);
	plik.close();
}