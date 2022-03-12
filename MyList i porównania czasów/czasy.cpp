#include <iostream>
#include <time.h>
#include <chrono>
#include <vector>
#include <list>
#define ILOSC 10000

std::vector<int> vec;
std::list<int> list;

class ListElement
{
public:
	int value;
	ListElement* nextElement;
};

class MyVector {

public:
	MyVector();
	MyVector(int size);
	~MyVector();
	void wypisz();
	void dodaj(int size);
	void usun();

private:
	int size;
	int* tablica;
};

class List
{
	ListElement* head, * tail;

public:
	List();
	~List();
	void dodaj(int value);
	void wypisz();
	void usun();
	void po_indexie(int index);
};
//-------------------------------------------------

List::List() {
	head = nullptr;
	tail = nullptr;
}

List::~List() {}
// --------------------------------------------
void List::dodaj(int val) {

	for (int i = 0; i < val; i++)
	{
		ListElement* wsk_temp = new ListElement();
		wsk_temp->nextElement = nullptr;
		wsk_temp->value = i;

		if (head == nullptr) {
			head = wsk_temp;
			tail = wsk_temp;
		}
		else {
			tail->nextElement = wsk_temp;
			tail = wsk_temp;
		}
	}
}

MyVector::MyVector()
{
	size = ILOSC;
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

void List::wypisz() {

	std::cout << '\n';
	ListElement* wsk_temp = head;
	while (wsk_temp != nullptr)
	{
		//std::cout << "\t" << wsk_temp->value;
		wsk_temp = wsk_temp->nextElement;
	}
}

void MyVector::wypisz()
{
	std::cout << '\n';
	for (int i = 0; i < ILOSC; i++)
	{
		//std::cout << "\ttablica[" << i << "] = " << tablica[i];
	}
}

void MyVector::dodaj(int size)
{
	int* tempTab = new int[size];

	for (int i = 0; i < size; i++)
	{
		tempTab[i] = tablica[i];
	}
	delete[] tablica;
	tablica = tempTab;
}

void dodaj_vec()
{
	for (int i = 0; i < ILOSC; i++)
	{
		vec.push_back(i);
	}
}

void dodaj_list()
{
	for (int i = 0; i < ILOSC; i++)
	{
		list.push_back(i);
	}
}

void wypisz_vec()
{
	for (int i = 0; i < ILOSC; i++)
	{
		vec[i];
	}
}

void wypisz_list()
{
	for (int i : list)
	{
		i;
	}
}

//---------------------------------------------

int main()
{
	List list_obj;
	MyVector MyVector_obj;

	int wyb = 0;

	std::cout << "Program porownuje czas dodawania i odczytywania " << ILOSC << " elementow\nza pomoca MyVector, std::vector, MyList, std::list.";

	auto start = std::chrono::steady_clock::now();
	MyVector_obj.dodaj(ILOSC);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second = end - start;
	std::cout << "\n\nDodawanie " << ILOSC << " elementow MyVector trwalo " << elapsed_second.count() << "sekund";

	auto start2 = std::chrono::steady_clock::now();
	list_obj.dodaj(ILOSC);
	auto end2 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second2 = end2 - start2;
	std::cout << "\n\nDodawanie " << ILOSC << " elementow MyList trwalo " << elapsed_second2.count() << "sekund";

	auto start8 = std::chrono::steady_clock::now();
	dodaj_vec();
	auto end8 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second8 = end8 - start8;
	std::cout << "\n\nDodawanie " << ILOSC << " elementow std::vector trwalo " << elapsed_second8.count() << "sekund";

	auto start5 = std::chrono::steady_clock::now();
	dodaj_list();
	auto end5 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second5 = end5 - start5;
	std::cout << "\n\nDodawanie " << ILOSC << " elementow std::list trwalo " << elapsed_second5.count() << "sekund";

	auto start3 = std::chrono::steady_clock::now();
	MyVector_obj.wypisz();
	auto end3 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second3 = end3 - start3;
	std::cout << "\nWypisywanie MyVector trwalo " << elapsed_second3.count() << "sekund";

	auto start4 = std::chrono::steady_clock::now();
	list_obj.wypisz();
	auto end4 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second4 = end4 - start4;
	std::cout << "\nWypisywanie MyList trwalo " << elapsed_second4.count() << "sekund";

	auto start6 = std::chrono::steady_clock::now();
	wypisz_vec();
	auto end6 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second6 = end6 - start6;
	std::cout << "\n\nWypisywanie std::vector trwalo " << elapsed_second6.count() << "sekund";

	auto start7 = std::chrono::steady_clock::now();
	wypisz_list();
	auto end7 = std::chrono::steady_clock::now();
	std::chrono::duration<double> elapsed_second7 = end7 - start7;
	std::cout << "\n\nWypisywanie std::list trwalo " << elapsed_second7.count() << "sekund" << '\n';
}