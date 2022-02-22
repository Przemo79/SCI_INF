#pragma once
#include <vector>
class MyVector {

public:
	MyVector();
	MyVector(int size);
	~MyVector();
	void wypisz();
	void dodaj();
	void usun();
	void pokaCoMaszPodTymIndexem();
	void dodaj_pod_index();
	void usun_spod_indexu();

private:
	int size;
	int *tablica;
};