#include <iostream>
using namespace std;

struct drzewoAVL {

	drzewoAVL* lewa;
	drzewoAVL* prawa;
	drzewoAVL* ojciec;
	int wartosc;	


};


drzewoAVL* dodaj(drzewoAVL*& korzen,int n, drzewoAVL* x = nullptr) {
	if (korzen == nullptr) {
		drzewoAVL* tmp = new drzewoAVL;
		tmp->wartosc = n;
		tmp->lewa = nullptr;
		tmp->prawa = nullptr;
		tmp->ojciec = x;
		korzen = tmp;
		return korzen;
		
	}
	else if (korzen->wartosc <= n) {
		dodaj(korzen->prawa,n,korzen);
	}
	else if (korzen->wartosc > n) {
		dodaj(korzen->lewa, n, korzen);
	}



	// ROTACJE 
	int balance = wez_balans(korzen);

	if (balance > 1 && n < korzen->lewa->wartosc) {
		
		return ROTACJA_W_PRAWO(korzen);;
	}


	if (balance < -1 && n > korzen->prawa->wartosc) {
		
		return ROTACJA_W_LEWO(korzen);;
	}

	if (balance < -1 && n < korzen->prawa->wartosc) {
		korzen->prawa = ROTACJA_W_PRAWO(korzen->prawa);

	}

	if (balance > 1 && n > korzen->lewa->wartosc) {
		korzen->lewa = ROTACJA_W_LEWO(korzen->lewa);
		return ROTACJA_W_PRAWO(korzen);
	}

	return korzen;
}



drzewoAVL* ROTACJA_W_PRAWO(drzewoAVL*& korzen) {

	drzewoAVL* x = korzen->lewa;
	drzewoAVL* y = korzen->lewa->prawa;


	x->prawa = korzen;
	korzen->lewa = y;
	return x;
}

drzewoAVL* ROTACJA_W_LEWO(drzewoAVL*& korzen) {
	drzewoAVL* x = korzen->prawa;
	drzewoAVL* y = korzen->prawa->lewa;


	x->lewa = korzen;
	korzen->prawa = y;
	return x;
}

int wysokosc(drzewoAVL*& korzen) {

	if (korzen == nullptr) {
		return -1;
	}
	else {
		int lw = wysokosc(korzen->lewa);
		int pw = wysokosc(korzen->prawa);
		if (lw > pw) {
			return (lw + 1);
		}
		else {
			return (pw + 1);
		}
	}
	
}

//
int wez_balans(drzewoAVL*& korzen) {
	if (korzen == nullptr){
		return -1;
	}
	else {
		return wysokosc(korzen->lewa) - wysokosc(korzen->prawa);
	}
}



int main() {
		
	drzewoAVL* korzen = nullptr;


	korzen = dodaj(korzen, 10);
	korzen = dodaj(korzen, 20);
	korzen = dodaj(korzen, 5);
	korzen = dodaj(korzen, 6);
	korzen = dodaj(korzen, 8);

	return 0;
}