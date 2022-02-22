#include <iostream>
#include <vector>
#include "Class.h"

MyVector::MyVector()
{
	size = 10;
	tablica = new int[size];

	for (int i = 0; i < size; i++)
	{
		tablica[i] = i;
	}
	
}

MyVector::MyVector(int size)
{
	this->size = size;
	tablica = new int[size];

	for (int i = 0; i < size; i++)
	{
		tablica[i] = i;
	}
	
}

MyVector::~MyVector()
{
	delete[] tablica;
}

void MyVector::wypisz()
{
	std::cout << "\n--------------------------";
	std::cout << "\nTablica ma " << size << " elementow.";
	std::cout << "\n--------------------------";

	for (int i = 0; i < size; i++)
	{
		std::cout << "\ntablica[" << i << "] = " << tablica[i];
	}
}

void MyVector::dodaj()
{
	size++;
	int* tempTab = new int[size];
	int value = 0;
	std::cout << "\nPodaj wartosc do dodania: ";
	std::cin >> value;

	for (int i = 0; i < size - 1; i++)
	{
		tempTab[i] = tablica[i];
	}

	tempTab[size - 1] = value;
	delete[] tablica;
	tablica = tempTab;
}

void MyVector::usun()
{
	size--;
	int* tempTab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tempTab[i] = tablica[i];
	}

	delete[] tablica;
	tablica = tempTab;
}

void MyVector::pokaCoMaszPodTymIndexem()
{
	int index = 0;
	std::cout << "\nPodaj nr indexu: ";
	std::cin >> index;

	if (index >= 0 && index < size)
	{
		std::cout << "\ntablica[" << index << "] = " << tablica[index];
	}
	else
	{
		std::cout << "\nZly index!";
	}
}

void MyVector::dodaj_pod_index()
{
	int value = 0;
	int index = 0;
	std::cout << "\nPodaj wartosc do dodania: ";
	std::cin >> value;
	std::cout << "\nPodaj numer indexu: ";
	std::cin >> index;

	if (index >= 0 && index <= size)
	{
		size++;
		int* tempTab = new int[size];
		for (int i = 0; i < index; i++)
		{
			tempTab[i] = tablica[i];
		}

		tempTab[index] = value;

		for (int i = index; i < size - 1; i++)
		{
			tempTab[i + 1] = tablica[i];
		}

		delete[] tablica;
		tablica = tempTab;
	}
	else
	{
		std::cout << "\nZly index!";
	}
}

void MyVector::usun_spod_indexu()
{
	int index = 0;
	std::cout << "\nPodaj numer indexu: ";
	std::cin >> index;

	if (index >= 0 && index <= size)
	{
		size--;
		int* tempTab = new int[size];
		for (int i = 0; i < index; i++)
		{
			tempTab[i] = tablica[i];
		}

		for (int i = index; i < size; i++)
		{
			tempTab[i] = tablica[i + 1];
		}

		delete[] tablica;
		tablica = tempTab;
	}
	else
	{
		std::cout << "\nZly index!";
	}
}

/*void MyVector::dodaj_elementy_auto_tab()
{
	for (int i = 0; i < 10000; i++)
	{
		tablica[i] = i;
	}
}

void MyVector::dodaj_elementy_auto_vec()
{
	for (int i = 0; i < 10000; i++)
	{
		vec.push_back(i);
	}
}*/