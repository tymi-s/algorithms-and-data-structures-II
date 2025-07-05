#include <iostream>
using namespace std;


struct drzewoBST {

	drzewoBST* lewa;
	drzewoBST* prawa;
	drzewoBST* ojciec;
	int wartosc;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dodaj(drzewoBST*& korzen, int n,drzewoBST* p = nullptr) {

	if (korzen == nullptr) {
		drzewoBST* tmp = new drzewoBST; 
		tmp->wartosc = n;
		tmp->lewa = nullptr;
		tmp->prawa = nullptr;
		tmp->ojciec = p;
		korzen = tmp;
	}
	else if (korzen->wartosc <= n) {
		
		dodaj(korzen->prawa, n,korzen);

	}
	else if (korzen->wartosc > n) {
		
		dodaj(korzen->lewa, n,korzen);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void wyszukiwanie(drzewoBST*& korzen, int n) {

	if (korzen == nullptr) {
		cout << "\nNIE MA TAKIEJ WARTOSCI W DRZEWIE BST!\n";
		return;
	}
	if (korzen->wartosc > n) {
		wyszukiwanie(korzen->lewa,n);
	}
	if(korzen->wartosc <n){
		wyszukiwanie(korzen->prawa,n);
	}
	
	if (korzen->wartosc == n) {
		cout << "\nznaleziono wartosc " << n << " :D !!!\n";
		return;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void  wypisywanie_inorder(drzewoBST*& korzen) {
		if (korzen == nullptr  ) {
		return;
		}
	
	wypisywanie_inorder(korzen->lewa);
		
	
	cout << korzen->wartosc << "->";
	wypisywanie_inorder(korzen->prawa);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

drzewoBST* min_drzewaBST(drzewoBST*& korzen) {
	if (korzen == nullptr) {

		return nullptr;
	}
	if (korzen->lewa == nullptr) {
		cout << "\nMIN: " << korzen->wartosc;
		cout << "\n ojciec: " << korzen->ojciec->wartosc;
		return korzen;
	}
	if (korzen != nullptr) {
		min_drzewaBST(korzen->lewa);
		
		
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

drzewoBST* max_drzewaBST(drzewoBST*& korzen) {
	if (korzen == nullptr) {
		return nullptr ;
	}

	if (korzen->prawa == nullptr) {
		cout << "\nMAX: " << korzen->wartosc << endl;
		cout << "ojciec: " << korzen->ojciec->wartosc << endl;

		return korzen;

	}
	
	if (korzen != nullptr) {
		max_drzewaBST(korzen->prawa);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void usuwanie_lisci(drzewoBST*& korzen) {

	if (korzen == nullptr) {
		return;
	}

	if (korzen->lewa == nullptr && korzen->prawa == nullptr) {
		if (korzen->wartosc > korzen->ojciec->wartosc) {
			korzen->ojciec->prawa = nullptr;
		}
		else if (korzen->wartosc < korzen->ojciec->wartosc) {
			korzen->ojciec->lewa = nullptr;
		}

		delete korzen;
		korzen = nullptr;
		return;
	}

		usuwanie_lisci(korzen->prawa);
		usuwanie_lisci(korzen->lewa);
	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 3 mo¿liwoœci - 1 korzen jest lisciem - 2 korzen ma jedno dziecko - 3 korzen ma dwujke dzieci
drzewoBST* usuwanie_wezla(drzewoBST*& korzen, int x) {

	if (korzen == nullptr) {
		return korzen;
	}

	if (korzen->wartosc > x) {
		korzen->lewa = usuwanie_wezla(korzen->lewa,x);
	}
	if (korzen->wartosc < x) {
		korzen->prawa = usuwanie_wezla(korzen->prawa, x);
	}
	if (korzen->wartosc == x) {
		

		// wezel to lisc:
		if (korzen->lewa == nullptr && korzen->prawa == nullptr) {
			delete korzen;
			korzen = nullptr;
			return nullptr;
		}

		// tylko prawe dziecko:
		if (korzen->lewa == nullptr ) {
			
			drzewoBST* tmp = korzen->prawa;
			delete korzen;
			return tmp;
		}
		// tylko lewe dziecko:
		if (korzen->prawa == nullptr) {
			drzewoBST* tmp = korzen->lewa;
			delete korzen;
			return tmp;
		}
		// wezel ma lewe i prawe dziecko:
		if (korzen->prawa != nullptr && korzen->lewa != nullptr) {
			drzewoBST* tmp = min_drzewaBST(korzen->prawa);
			korzen->wartosc = tmp->wartosc;
			korzen->prawa = usuwanie_wezla(korzen->prawa, tmp->wartosc);
			return korzen;

		}

	}
		

	

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

drzewoBST* rotacja_prawo(drzewoBST* korzen) {

	drzewoBST* x = korzen->lewa;
	drzewoBST* y = korzen->lewa->prawa;
	x->prawa = korzen;
	korzen->lewa = y;

	x->ojciec = korzen->ojciec;
	korzen->ojciec= x;
	

	if (y != nullptr) {
		y->ojciec = korzen;
	}
	return x;
}

drzewoBST* rotacja_lewo(drzewoBST* korzen) {

	drzewoBST* x = korzen->prawa;
	drzewoBST* y = korzen->prawa->lewa;

	x->lewa = korzen;
	x->lewa->prawa = y;

	x->ojciec = korzen->ojciec;
	korzen->ojciec = x;

	if (y != nullptr) {
		y->ojciec = korzen;
	}

	return x;
}


drzewoBST* rotacja_lewo_prawo(drzewoBST* korzen) {
	korzen->lewa = rotacja_lewo(korzen->lewa);
	korzen = rotacja_prawo(korzen);
	return korzen;

}
drzewoBST* rotacja_prawo_lewo(drzewoBST* korzen) {
	korzen->prawa = rotacja_prawo(korzen->prawa);
	korzen = rotacja_lewo(korzen);
	return korzen;

}
int main() {
	drzewoBST* tree = nullptr;
	dodaj(tree, 20);
	dodaj(tree, 29);
	dodaj(tree, 15);
	dodaj(tree, 16);
	dodaj(tree, 17);
	dodaj(tree, 10);
	dodaj(tree, 11);
	dodaj(tree, 2);
	dodaj(tree, 27);
	dodaj(tree,38);
	dodaj(tree, 100);

	wypisywanie_inorder(tree);

	wyszukiwanie(tree,100);

	min_drzewaBST(tree);
	cout << endl;
	max_drzewaBST(tree);

	usuwanie_wezla(tree, 29);
	cout << "\n\n";
	wypisywanie_inorder(tree);

	// do rotacji:

	drzewoBST* drzewo = nullptr;
	dodaj(drzewo, 10);
	dodaj(drzewo, 5);
	dodaj(drzewo, 2);
	
	cout << "\n\n\nkorzen->lewa  " << drzewo->lewa->wartosc;
	drzewo = rotacja_lewo(drzewo);
	cout << "\n\n\nkorzen->lewa  " << drzewo->lewa->wartosc;
	return 0;
}