#include <iostream>
#include <string>
using namespace std;



struct lista{

	lista* glowa;
	lista* nastepnik;
	string imie;
	

};

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int haszujaca(string imie) {
	int suma{};
	
	for (char i : imie) {

		suma = i + suma;
	}
		cout << "HASZ DLA '" << imie << "': " << suma%13 << endl;
	return suma % 13;
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void dodaj(int x , string im,lista* tablica[]) {

	
		lista* tmp = new lista;
		tmp->imie = im;
		tmp->nastepnik = tablica[x];
		tablica[x] = tmp;
		
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void szukajaca(int x,string im, lista* tablica[],lista* p) {
	
	if (tablica[x] == nullptr) {
		cout << "KOMORKA NR "<<x<< " NIE MA IMION !\n";
		return; 
	}
	if (p == nullptr) {
		cout << "NIE MA IMIENIA '" << im << "' W KOMORCE NUMER " << x << " :(\n";
		return;
	}
	if (p->imie == im)
	{
		cout << "IMIE '" << im << "' JEST W TABLICY W KOMURCE NUMER: " << x << endl;
		return;
	}
	szukajaca(x, im, tablica, p->nastepnik);
	
}


/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void usuwajaca(lista* tablica[],int i,string u) {



	if (tablica == nullptr) {
		return;
	}
	else if(tablica[i]->imie == u) {
		lista* tmp = tablica[i];
		tablica[i] = tablica[i]->nastepnik;
		delete tmp;
		tmp = nullptr;
		return;
	}

	else
	{
		lista* tmp = nullptr;
		lista* tmp1= nullptr;

		while (tablica[i]->imie != u)
		{
			tmp1 = tablica[i];
			tablica[i] = tablica[i]->nastepnik;

		}
		tmp = tablica[i];
		tmp1->nastepnik = tablica[i]->nastepnik;
		delete tmp;
		tmp = nullptr;

		tablica[i] = tmp1;
		return;
	}
	
	

	
	
}

lista* zwracajaca_poprzednika(lista* tablica[], int x, string name,lista *p ) {

	return nullptr;
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void wypisujaca(lista* tablica) {

	if (tablica == nullptr) {
		cout << "null->";
		return;
	}
	else {
		cout << tablica->imie << "->";
		wypisujaca(tablica->nastepnik);
	}
}

/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {

	lista ** tablica = new lista * [13];

	for (int i = 0; i < 13;i++) {
		tablica[i] = nullptr;
	}



	string imiona[15] = { "Tymon","Jakub","Martyna","Nela","Dagmara","Pawel","Szymon","Fela","Bartek","Yamal","Messi","Garnaho","Faker","Showmaker","Jezus"};// szymon = 6 , yamal = 9 ,messi = 10

	for (int i = 0; i < 11; i++) {
		int x = haszujaca(imiona[i]);
		dodaj(x, imiona[i], tablica);
	}
	cout << endl;
	cout << "KOMURKA NR 0:   "; wypisujaca(tablica[0]); cout << endl;
	cout << "KOMURKA NR 1:   "; wypisujaca(tablica[1]); cout << endl;
	cout << "KOMURKA NR 2:   "; wypisujaca(tablica[2]); cout << endl;
	cout << "KOMURKA NR 3:   "; wypisujaca(tablica[3]); cout << endl;
	cout << "KOMURKA NR 4:   "; wypisujaca(tablica[4]); cout << endl;
	cout << "KOMURKA NR 5:   "; wypisujaca(tablica[5]); cout << endl;
	cout << "KOMURKA NR 6:   "; wypisujaca(tablica[6]); cout << endl;
	cout << "KOMURKA NR 7:   "; wypisujaca(tablica[7]); cout << endl;
	cout << "KOMURKA NR 8:   "; wypisujaca(tablica[8]); cout << endl;
	cout << "KOMURKA NR 9:   "; wypisujaca(tablica[9]); cout << endl;
	cout << "KOMURKA NR 10:   "; wypisujaca(tablica[10]); cout << endl;
	cout << "KOMURKA NR 11:   "; wypisujaca(tablica[11]); cout << endl;
	cout << "KOMURKA NR 12:   "; wypisujaca(tablica[12]); cout << endl;


	cout << "\n SZUKANIE: \n";
	int y = haszujaca(imiona[6]);
	szukajaca(y, imiona[6], tablica, tablica[y]); cout << endl;
	cout << "\n SZUKANIE MARKA KTOREGO NIMA: \n";
	string imie2 = "Marek"; // marka nima
	int z = haszujaca(imie2);
	szukajaca(z, imie2, tablica, tablica[z]); cout << endl;

	cout << "\nUSUWANIE YAMAL'a:\n";
	usuwajaca(tablica, 6, "Yamal");

	cout <<"" << "KOMURKA NR 6 po usunieciu Yamal'a:   ";
	wypisujaca(tablica[6]);
	cout << endl;


	return 0;
}