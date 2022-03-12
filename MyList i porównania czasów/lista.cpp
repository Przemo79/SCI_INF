#include <iostream>

class ListElement
{
public:
	int value;
	ListElement* nextElement;
};

class List
{
	ListElement* head, *tail;

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

	ListElement* wsk_temp = new ListElement();
	wsk_temp->nextElement = nullptr;
	wsk_temp->value = val;

	if (head == nullptr) {
		head = wsk_temp;
		tail = wsk_temp;
	}
	else {
		tail->nextElement = wsk_temp;
		tail = wsk_temp;
	}
}

void List::wypisz() {

	ListElement* wsk_temp = head;
	while (wsk_temp != nullptr)
	{
		std::cout << "\n\t" << wsk_temp->value;
		wsk_temp = wsk_temp->nextElement;
	}
}

void List::usun() { //nie można usuwac jak jest 0 lub 1 element w liscie bo errora wywala

	ListElement* wsk_temp = head;
	ListElement* wsk_temp2;
	wsk_temp2 = wsk_temp->nextElement;
	
	while (wsk_temp2->nextElement) {
		wsk_temp = wsk_temp->nextElement;
		wsk_temp2 = wsk_temp2->nextElement;
	}
	
	if (wsk_temp != nullptr) {
		delete[] wsk_temp2;
		wsk_temp->nextElement = nullptr;
		tail = wsk_temp;
	}
	else {
		std::cout << "\nNie mozna pozostawic zmiennej pustej!";
	}
}

void List::po_indexie(int index) {

	ListElement* wsk_temp = head;
	for (int i = 0; i < index; i++) {
		wsk_temp = wsk_temp->nextElement;
	}
	std::cout << "\nPod tym indexem jest wartsc " << wsk_temp->value << '\n';
}

//---------------------------------------------

int main()
{
	List list_obj;

	int wyb = 0;

	do {
		if (wyb != 3) {
			system("cls");
			list_obj.wypisz();
		}
		std::cout << "\n\nCo chcesz zrobic?:\n\t0 - zakoncz\n\t1 - dodaj element na koniec\n\t2 - usun z konca\n\t3 - znajdz po indeksie\n\nTwoj wybor: ";
		std::cin >> wyb;

		if (wyb == 0) {}
		else if (wyb == 1) {
			int nowa_val = 0;
			std::cout << "\nPodaj wartosc do dodania: ";
			std::cin >> nowa_val;
			list_obj.dodaj(nowa_val);
		}
		else if (wyb == 2) {
			list_obj.usun();
		}
		else if (wyb == 3) {
			int index = 0;
			std::cout << "\nPodaj wartosc indeksu: ";
			std::cin >> index;
			list_obj.po_indexie(index);
		}
	} while (wyb != 0);
}