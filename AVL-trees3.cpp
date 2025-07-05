#include <iostream>
using namespace std;


struct drzewoAVL {

	drzewoAVL* lewa;
	drzewoAVL* prawa;
	drzewoAVL* ojciec;
	int wartosc;
};




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int wysokosc_drzewa(drzewoAVL*& korzen) {
	if (korzen == nullptr)
		return 0;
	else {
		int l = wysokosc_drzewa(korzen->lewa);
		int p = wysokosc_drzewa(korzen->prawa);
		return max(l, p) + 1;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


drzewoAVL* rotacja_prawo(drzewoAVL* korzen) {
	drzewoAVL* x = korzen->lewa;
	drzewoAVL* y = korzen->lewa->prawa;


	x->prawa = korzen;
	x->prawa->lewa = y;

	x->ojciec = korzen->ojciec;
	korzen->ojciec = x;

	if (y != nullptr) {
		y->ojciec = korzen;
	}

	return x;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
drzewoAVL* rotacja_lewo(drzewoAVL* korzen) {

	drzewoAVL* x = korzen->prawa;
	drzewoAVL* y = korzen->prawa->lewa;

	x->lewa = korzen;
	x->lewa->prawa = y;

	x->ojciec = korzen->ojciec;
	korzen->ojciec = x;

	if (y != nullptr) {
		y->ojciec = korzen;
	}


	return x;

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void wypisz_inorder(drzewoAVL*& korzen) {


	if (korzen == nullptr) {
		return;
	}


	wypisz_inorder(korzen->lewa);
	cout << korzen->wartosc << "->";
	wypisz_inorder(korzen->prawa);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int wez_balans(drzewoAVL*& korzen) {
	if (korzen == nullptr) {
		return 0;
	}
	else {
		int l = wysokosc_drzewa(korzen->lewa);
		int p = wysokosc_drzewa(korzen->prawa);
		return l - p;
	}
}
// bf = bL-bR , moze byæ tylko (-1,0,1)
drzewoAVL* dodaj(drzewoAVL*& korzen, int n, drzewoAVL* x = nullptr) {

	if (korzen == nullptr) {
		drzewoAVL* tmp = new drzewoAVL;
		tmp->wartosc = n;
		tmp->lewa = nullptr;
		tmp->prawa = nullptr;
		tmp->ojciec = x;
		korzen = tmp;
		return korzen;
	}

	else if (korzen->wartosc > n) {
		korzen->lewa = dodaj(korzen->lewa, n, korzen);
	}
	else if (korzen->wartosc <= n) {
		korzen->prawa = dodaj(korzen->prawa, n, korzen);
	}

	int bf = wez_balans(korzen);

	// WYKONANIE ROTACJI W RAZIE BALANSU RÓ¯NEGO OD -1,0,1:
	// 
	// ROTACJA PRAWO:
	if (bf > 1 && n < korzen->lewa->wartosc) {
		korzen = rotacja_prawo(korzen);
	}
	// ROTACJA LEWO:
	if (bf<-1 && n > korzen->prawa->wartosc) {
		korzen = rotacja_lewo(korzen);
	}

	//ROTACJA LEWO->PRAWO:

	if (bf > 1 && n > korzen->lewa->wartosc) {
		korzen->lewa = rotacja_lewo(korzen->lewa);
		korzen = rotacja_prawo(korzen);
	}
	//ROTACJA PRAWO-LEWO:

	if (bf < -1 && n < korzen->prawa->wartosc) {
		korzen->prawa = rotacja_prawo(korzen->prawa); 
		korzen = rotacja_lewo(korzen);
	}
	return korzen;
}



int main() {
	drzewoAVL* tree = nullptr;
	dodaj(tree, 5);
	dodaj(tree, 3);
	dodaj(tree, 4);
	dodaj(tree, 1);
	cout << endl;
	wypisz_inorder(tree);
	cout << "\n\n" << tree->wartosc;
	cout << "\n\n" << tree->lewa->wartosc;
	cout << "\n\n" << tree->prawa->wartosc;
	return 0;
}