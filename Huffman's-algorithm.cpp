#include <iostream>
#include <string>
using namespace std;



// dodawanie usuwanie poprzednik nastepnik - BST
// dodawanie usuwanie - rotacje pojedyncze , podwójne - AVL
// kodowanie Huffmana


struct BST {

	BST* prawa;
	BST* lewa;
	char literka;
};
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct lista {

	lista* nastepnik;
	lista* poprzednik;
	lista* ostatni;
	int wartosc;
	BST* korzen;
};

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

lista* ostatni(lista*& glowa) {
	if (glowa == nullptr) {
		return nullptr;
	}
	if (glowa->nastepnik == nullptr) {
		glowa->ostatni = glowa;
		cout << "\nOSTATNI: " << glowa->wartosc;
		return  glowa;
	}
	else {
		ostatni(glowa->nastepnik);
	}
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dodaj_lista(lista*& glowa,int n,lista* p = nullptr,string tablica[][],int i) {

	if (glowa == nullptr) {
		lista* tmp = new lista;
		BST* tmp1 = new BST;

		tmp1->lewa = nullptr;
		tmp1->prawa = nullptr;
		tmp1->literka = tablica[i][0];


		tmp->wartosc = n;
		tmp->nastepnik = nullptr;
		tmp->poprzednik = p;
		tmp->korzen = tmp1;
		glowa = tmp;
		return;
	}
	else {
		dodaj_lista(glowa->nastepnik, n,glowa);

	}
}


/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void usuwanie_lista(lista*& glowa) {
	delete glowa;
	glowa = nullptr;
	return;
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void wypisz_lista(lista*& glowa) {
	if (glowa == nullptr) {
		return;
	}
	else {
		cout << glowa->wartosc<<","<<glowa->korzen->literka << "-->";
		wypisz_lista(glowa->nastepnik);

	}
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

	lista* l = nullptr;
	BST* drzewo = nullptr;
	char tablica[8][2] = { {"A","92"}, {"D","53"}, {"E","3"}, {"F","28"}, {"G","3"}, {"S","58"}, {"W","1"}, {"X","2"} };


	
	
	//dodanie do listy:
	for (int i = 0; i < 8; i++)
	{
	
		int b = stoi(tablica[i][1]);
		dodaj_lista(l, b,nullptr,tablica[i][0],i);
	}
	wypisz_lista(l);

	l->ostatni = ostatni(l);	
	cout << "\n\n OSTATNIIIIIII: " << l->ostatni->wartosc;


	return 0;
}