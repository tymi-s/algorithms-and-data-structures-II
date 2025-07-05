#include <iostream>
#include <cmath>

using namespace std;



struct drzewo {

	drzewo* lewa;
	drzewo* prawa;
	drzewo* ojciec;
	int godz;
	int min;
};

void dodaj(drzewo*& korzen, int g,int m,drzewo* p=nullptr) {

	if (korzen == nullptr) {
		drzewo* tmp = new drzewo;
		tmp->lewa = nullptr;
		tmp->prawa = nullptr;
		tmp->godz = g;
		tmp->min = m;
		tmp->ojciec = p;
		korzen = tmp;
		return;
	}

	else {
		if (korzen->godz == g && korzen->min == m) {
			cout << "\n NIE MOZNA ZAREZERWOWAC GODZINY "<< g <<":"<<m<< ". TA GODZINA JEST JUZ ZAREZERWOWANA!";
			return;
		}
		else if(korzen->godz == g && abs(korzen->min - m) <30){
			cout << "\n NIE MOZNA ZAREZERWOWAC GODZINY " << g << ":" << m << ". ODSTEP MIEDZY REZERWACJAMI MUSI WYNOSIC CO NAJMNIEJ 30 MIN!";
			return;
		}
		else if (g - korzen->godz == 1 && (60 - korzen->min + m) < 30) {
			cout << "\n NIE MOZNA ZAREZERWOWAC GODZINY " << g << ":" << m << ". ODSTEP MIEDZY REZERWACJAMI MUSI WYNOSIC CO NAJMNIEJ 30 MIN!";
			return;
		}
		else if (korzen->godz - g == 1 && (60 - m + korzen->min) < 30) {
			cout << "\n NIE MOZNA ZAREZERWOWAC GODZINY " << g << ":" << m << ". ODSTEP MIEDZY REZERWACJAMI MUSI WYNOSIC CO NAJMNIEJ 30 MIN!";
			return;
		}
		else {
			if (korzen->godz > g || (korzen->godz == g &&korzen->min > m)) {
				dodaj(korzen->lewa,g,m,korzen);
			}
			if (korzen->godz < g || (korzen->godz == g && korzen->min < m)) {
				dodaj(korzen->prawa, g, m, korzen);
			}
		}

	}
}


void wypisz(drzewo*& korzen) {

	if (korzen == nullptr) {
		return;
	}
	wypisz(korzen->lewa);
	cout << endl << korzen->godz << ":" << korzen->min;
	wypisz(korzen->prawa);
}

int main() {
	drzewo* tree = nullptr;
	dodaj(tree, 15, 15);
	dodaj(tree, 14, 15);
	dodaj(tree, 14,45);


	cout << "\n\nZAREZERWOWANE GODZINY:";
	wypisz(tree);
	

	return 0;
}